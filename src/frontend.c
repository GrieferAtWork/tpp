/* Copyright (c) 2017 Griefer@Work                                            *
 *                                                                            *
 * This software is provided 'as-is', without any express or implied          *
 * warranty. In no event will the authors be held liable for any damages      *
 * arising from the use of this software.                                     *
 *                                                                            *
 * Permission is granted to anyone to use this software for any purpose,      *
 * including commercial applications, and to alter it and redistribute it     *
 * freely, subject to the following restrictions:                             *
 *                                                                            *
 * 1. The origin of this software must not be misrepresented; you must not    *
 *    claim that you wrote the original software. If you use this software    *
 *    in a product, an acknowledgement in the product documentation would be  *
 *    appreciated but is not required.                                        *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#define TPP(x) x /* Global namespace. */
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS

#if defined(_MSC_VER) && defined(_DEBUG)
/* Make use of MSVC's builtin memory leak detector. */
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

#include "tpp.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <fcntl.h>
#include <unistd.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define STR2(x) #x
#define STR(x) STR2(x)
#if defined(_MSC_FULL_VER) && defined(__cplusplus)
#   define TPP_COMPILER "VC++ " STR(_MSC_FULL_VER)
#elif defined(_MSC_FULL_VER)
#   define TPP_COMPILER "VC " STR(_MSC_FULL_VER)
#elif defined(__clang__) && defined(__cplusplus)
#   define TPP_COMPILER "clang++ " STR(__clang__)
#elif defined(__clang__)
#   define TPP_COMPILER "clang " STR(__clang__)
#elif defined(__GNUC__) && defined(__cplusplus)
#   define TPP_COMPILER "g++ " STR(__GNUC__) "." STR(__GNUC_MINOR__) "." STR(__GNUC_PATCHLEVEL__)
#elif defined(__GNUC__)
#   define TPP_COMPILER "gcc " STR(__GNUC__) "." STR(__GNUC_MINOR__) "." STR(__GNUC_PATCHLEVEL__)
#elif defined(__TINYC__)
#   define TPP_COMPILER "tcc " STR(__TINYC__)
#elif defined(__cplusplus)
#   define TPP_COMPILER "Unknown c++ compiler"
#else
#   define TPP_COMPILER "Unknown c compiler"
#endif


#define OUTLINE_MODE_NONE 0
#define OUTLINE_MODE_TOK  1 /* Outline with [...] */
#define OUTLINE_MODE_ZERO 2 /* Separate with '\0' */
static int outline_tokens     = OUTLINE_MODE_NONE;
static int no_magic_tokens    = 1; /*< Disable ~magic~ tokens for small line-shifts to prevent a #line being emit. */
static int no_line_directives = 0; /*< Disable #line directives being emit. */

#ifdef _WIN32
static stream_t stdout_handle;
#define write(fd,p,s) (void)WriteFile(fd,p,s,NULL,NULL)
#else
#define stdout_handle  STDOUT_FILENO
#endif
/* We prefer using unbuffered I/O to not create
 * bottlenecks when running in immediate mode.
 * Also: Window's libc does some weird $h1t to linefeeds,
 *       inserting a magic '\r' character before every '\n'...
 *      (You can probably turn that off, but I'm not even gonna bother)
 */
#define out_write(p,s) write(stdout_handle,p,s)

static int is_at_linefeed;
static int current_line;

void put_line(void) {
 static char const *last_filename = NULL;
 size_t      filename_size;
 char const *filename_text;
 struct TPPFile *f;
 int line; char buffer[16];
 if (no_line_directives) return;
 f = TPPLexer_Textfile();
 if (TPPLexer_Current->l_token.t_file == f) {
  /* Try to use the start of the current token.
   * NOTE: Something like 'f->f_oldpos' would be more
   *       appropriate to use, but we don't track that... */
  line = TPPFile_LineAt(f,TPPLexer_Current->l_token.t_begin);
 } else {
  /* Fallback: Use the current position within the file. */
  line = TPPFile_LineAt(f,f->f_pos);
 }
 filename_text = TPPFile_Filename(f,&filename_size);
 if (current_line == line && last_filename == filename_text) return;
 if (outline_tokens != OUTLINE_MODE_ZERO && !no_magic_tokens &&
     last_filename == filename_text && current_line <= line-1 &&
     current_line >= line-2) {
  /* Optimization: For smaller line-offsets of less than 2, it is usually
   *               easier to simply emit the linefeeds individually.
   * WARNING: We can't do this in ZERO-mode though, as in this mode linefeeds
   *          must only be emit when they actually exist
   */
  size_t offset = line-current_line;
  current_line = line;
  if (outline_tokens == OUTLINE_MODE_TOK) {
   out_write("[\n][\n]",(offset*3)*sizeof(char));
  } else {
   out_write("\n\n",offset*sizeof(char));
  }
  return;
 }
 if (!is_at_linefeed) out_write("\n",sizeof(char));
 current_line = line;
 out_write("#line ",6*sizeof(char));
 out_write(buffer,(TPP_Itos(buffer,(int_t)(line+1))-buffer)*sizeof(char));
 if (last_filename != filename_text) {
  char *quote_buffer;
  size_t quote_size;
  last_filename = filename_text;
  out_write(" \"",2);
  quote_size = TPP_SizeofEscape(filename_text,filename_size);
  quote_buffer = (char *)malloc(quote_size*sizeof(char));
  if (quote_buffer) {
   TPP_Escape(quote_buffer,filename_text,filename_size);
   out_write(quote_buffer,quote_size*sizeof(char));
   free(quote_buffer);
  }
  out_write(outline_tokens == OUTLINE_MODE_ZERO
            ? "\"\0" : "\"\n",2*sizeof(char));
 } else {
  out_write(outline_tokens == OUTLINE_MODE_ZERO
            ? "\0" : "\n",sizeof(char));
 }
 is_at_linefeed = 1;
}

TPP_LOCAL size_t get_file_offset(char *p) {
 struct TPPFile *f = TPPLexer_Current->l_token.t_file;
 size_t result = p-f->f_begin;
 if (f->f_kind == TPPFILE_KIND_TEXT) {
  result += (f->f_textfile.f_rdata-f->f_text->s_size);
 }
 return result;
}

TPP_LOCAL int
count_linefeeds(char const *iter, char const *end) {
 int result = 0;
 while (iter != end) {
  if (*iter == '\r') {
   if (iter != end-1 &&
       iter[1] == '\n') ++iter;
   ++result;
  } else if (*iter == '\n') ++result;
  ++iter;
 }
 return result;
}

static char const version[] =
"tpp version "
STR(TPP_API_VERSION) "/"
STR(TPP_PREPROCESSOR_VERSION) " - New Tiny PreProcessor - "
"Copyright (C) 2017 Griefer@Work "
"["
#if TPP_CONFIG_DEBUG
"DEBUG|"
#endif /* TPP_CONFIG_DEBUG */
#if TPP_CONFIG_ONELEXER
"ONE|"
#endif /* TPP_CONFIG_ONELEXER */
#ifdef __TPP_VERSION__
"TPP " STR(__TPP_VERSION__) "|"
#endif
TPP_COMPILER
#if defined(__TIME__) && defined(__DATE__)
"|" __TIME__ " " __DATE__
#endif
"]\n\n";

struct tpp_extension {
 char const *e_name;
 size_t      e_size;
 uint64_t    e_flag;
};
extern struct tpp_extension const tpp_extensions[];
extern char const *const wgroup_names[WG_COUNT+1];

void usage(char *appname, char *subject) {
 if (subject) {
  if (!strcmp(subject,"extensions")) {
   struct tpp_extension const *iter;
   for (iter = tpp_extensions; iter->e_name; ++iter) {
    fprintf(stderr,"-f%s%s\n",(TPPLexer_Current->l_extensions&iter->e_flag) ? "" : "no-",iter->e_name);
   }
  } else if (!strcmp(subject,"warnings")) {
   char const *const *iter;
#define getstate(wid) \
 (wstate_t)((TPPLexer_Current->l_warnings.w_curstate->ws_state[(wid)/(8/TPP_WARNING_BITS)] \
        >> (((wid)%(8/TPP_WARNING_BITS))*TPP_WARNING_BITS)) & 3)
   for (iter = wgroup_names; *iter; ++iter) {
    fprintf(stderr,"-W%s%s\n",getstate(iter-wgroup_names) == WSTATE_DISABLE ? "no-" : "",*iter);
   }
#undef getstate
  } else {
   fprintf(stderr,"Unknown subject: %s\n",subject);
  }
  return;
 }
 fprintf(stderr,"Usage: %s [options...] [-o outfile] [infile]\n"
                "       %s [options...] [-o outfile] -i string...\n"
                "options:\n"
                "\t" "-o <name>                   Redirect output to a given file (defauls to STDOUT).\n"
                "\t" "-i <text>                   Preprocess the remained of the commandline\n"
                "\t" "-Idir                       Adds 'dir' to the list of #include <...> paths\n"
                "\t" "-Dsym[=val=1]               Defines 'sym' as 'val'\n"
                "\t" "-Usym                       Undefine a previously defined symbol 'sym'\n"
                "\t" "-Apred=answer               Define an assertion 'pred' as 'answer'\n"
                "\t" "-A-pred[=answer]            Delete 'answer' or all assertions previously made about 'pred'\n"
                "\t" "-P                          Disable emission of #line adjustment directives (Default: on).\n"
                "\t" "-M                          Instead of emitting preprocessor output, emit a make-style list of dependencies.\n"
                "\t" "-MM                         Similar to '-M', but don't include system headers.\n"
                "\t" "-MG                         Similar to '-M', but include missing files as dependencies, assuming generated files.\n"
                "\t" "-MF <file>                  Enable dependency tracking and emit its output to <file>, but also preprocess regularly.\n"
                "\t" "-trigraphs                  Enable recognition of trigraph character sequences.\n"
                "\t" "-undef                      Disable all builtin macros.\n"
                "\t" "--tok                       Outline all tokens using the [...] notation (Default: off).\n"
                "\t" "--pp                        Enable preprocess-mode, which emits all tokens separated by '\\0'-bytes.\n"
                "\t" "-f[no-]spc                  Configure emission of SPACE tokens (Default: on).\n"
                "\t" "-f[no-]lf                   Configure emission of LF tokens (Default: on).\n"
                "\t" "-f[no-]comments             Configure emission of COMMENT tokens (Default: off).\n"
                "\t" "-f[no-]magiclf              Enable/Disable magic linefeeds sometimes used in place of #line (Default: off).\n"
                "\t" "-f[no-]longstring           Enable/Disable string continuation between lines (Default: off).\n"
                "\t" "-f[no-]<extension>          Enable/Disable a given 'extension' (s.a.: '--help extensions').\n"
                "\t" "-W[no-]<warning>            Enable/Disable a given 'warning' group (s.a.: '--help warnings').\n"
                "\t" "                            Enabling this option also disabled SPACE and LF tokens, though\n"
                "\t" "                            they can be re-enabled using the -spc and -lf switches.\n"
                "\t" "--name <name>               Set the name used for __FILE__ by INFILE (Useful when INFILE is stdin).\n"
                "\t" "--help [subject]            Display this help and exit.\n"
                "\t" "                            When specified, subject may be one of {extensions|warnings}\n"
                "\t" "--version                   Display version information and exit.\n"
#ifdef _WIN32
                "\t" "--message-format={msvc|gcc} Set the format for error message (Default: msvc).\n"
#else
                "\t" "--message-format={msvc|gcc} Set the format for error message (Default: gcc).\n"
#endif
                "infile:\n"
                "\t" "-                When not specified or set to '-', use STDIN as input\n"
                "\t" "<filename>       The name of a file to preprocess, as well as the default value for '--name'\n"
         ,appname,appname);
}

static /*ref*/struct TPPString *
merge_argv_str(int argc, char **argv) {
 struct TPPString *result;
 char **iter,**end,*dest;
 size_t total_size;
 if (!argc) return TPPString_New("",0);
 total_size = argc-1; /* All arguments are separated by ' '. */
 end = (iter = argv)+argc;
 for (; iter != end; ++iter) total_size += strlen(*iter);
 result = TPPString_NewSized(total_size);
 if (!result) return NULL;
 dest = result->s_text;
 for (iter = argv; iter != end; ++iter) {
  size_t len = strlen(*iter);
  memcpy(dest,*iter,len*sizeof(char));
  dest += len;
  *dest++ = ' ';
 }
 return result;
}

static /*ref*/struct TPPFile *
merge_argv(int argc, char **argv) {
 struct TPPString *argv_string;
 struct TPPFile *result;
 argv_string = merge_argv_str(argc,argv);
 if (!argv_string) return NULL;
 result = (struct TPPFile *)malloc(TPPFILE_SIZEOF_TEXT);
 if (!result) goto err_argv_string;
 result->f_refcnt                 = 1;
 result->f_kind                   = TPPFILE_KIND_TEXT;
 result->f_prev                   = NULL;
 result->f_name                   = strdup("<commandline>");
 if (!result->f_name) goto err_r;
 result->f_namesize               = 13;
#if __SIZEOF_POINTER__ == 8
 result->f_namehash = 12182544704004658106ull;
#else
 result->f_namehash = 3330511802ul;
#endif
 result->f_text                   = argv_string; /* Inherit reference. */
 result->f_begin                  = argv_string->s_text;
 result->f_end                    = argv_string->s_text+argv_string->s_size;
 result->f_pos                    = argv_string->s_text;
 result->f_textfile.f_cacheentry  = NULL;
 result->f_textfile.f_usedname    = NULL;
 result->f_textfile.f_lineoff     = 0;
 result->f_textfile.f_stream      = TPP_STREAM_INVALID;
 result->f_textfile.f_ownedstream = TPP_STREAM_INVALID;
 result->f_textfile.f_guard       = NULL;
 result->f_textfile.f_cacheinc    = 0;
 result->f_textfile.f_rdata       = argv_string->s_size;
 result->f_textfile.f_prefixdel   = '\0';
 result->f_textfile.f_flags       = TPP_TEXTFILE_FLAG_NOGUARD;
 result->f_textfile.f_newguard    = NULL;
 return result;
err_r:           free(result);
err_argv_string: TPPString_Decref(argv_string);
 return NULL;
}

static void pp_normal(void) {
 struct TPPFile *last_token_file;
 char *last_token_end; size_t file_offset;
 /* Initial values to simulate the last token
  * ending where the first file starts. */
 last_token_file = NULL; // infile; /* Force a line directive at the first token. */
 last_token_end  = TPPLexer_Current->l_token.t_file->f_begin;
 file_offset     = 0;
 current_line    = 0;
 is_at_linefeed  = 1;
 while (TPPLexer_Yield() > 0) {
  if (last_token_file != TPPLexer_Current->l_token.t_file ||
     (last_token_end != TPPLexer_Current->l_token.t_begin &&
      file_offset != get_file_offset(TPPLexer_Current->l_token.t_begin))) {
   /* The file changed, or there is a difference in the in-file position
    * between the end of the last token and the start of this one.
    * >> In any case, we must update the #line offset. */
   put_line();
  }
  last_token_file = TPPLexer_Current->l_token.t_file;
  last_token_end  = TPPLexer_Current->l_token.t_end;
  file_offset     = get_file_offset(last_token_end);
  if (outline_tokens == OUTLINE_MODE_TOK) out_write("[",sizeof(char));
  out_write(TPPLexer_Current->l_token.t_begin,
           (size_t)(TPPLexer_Current->l_token.t_end-
                    TPPLexer_Current->l_token.t_begin)*
            sizeof(char));
  /* Track what we expect the current line number to be,
   * which is them compared to the actual line number. */
  current_line += count_linefeeds(TPPLexer_Current->l_token.t_begin,
                                  TPPLexer_Current->l_token.t_end);
  switch (outline_tokens) {
   case OUTLINE_MODE_ZERO: out_write("\0",sizeof(char)); is_at_linefeed = 1; break;
   case OUTLINE_MODE_TOK:  out_write("]",sizeof(char)); is_at_linefeed = 0; break;
   default: 
    is_at_linefeed = last_token_end[-1] == '\n' ||
                     last_token_end[-1] == '\r';
    break;
  }
 }
}

static stream_t dep_outfile = TPP_STREAM_INVALID;
static int dep_nonsystem_only = 0;
static void pp_depprint(char *filename, size_t filename_size) {
 if (dep_outfile == TPP_STREAM_INVALID) return;
 write(dep_outfile," \\\n\t",4*sizeof(char));
 write(dep_outfile,filename,filename_size*sizeof(char));
}
static int pp_depcallback(struct TPPFile *file, int is_system_header) {
 /* Don't emit entries for system header if we're not supposed to. */
 if (is_system_header && dep_nonsystem_only) return 1;
 pp_depprint(file->f_name,file->f_namesize);
 return 1;
}
static struct TPPFile *
pp_depunknown(char *filename, size_t filename_size) {
 pp_depprint(filename,filename_size);
 return NULL;
}
static int pp_depfirst(struct TPPFile *file) {
 char *used_filename,*filename_extension,old;
 if (dep_outfile == TPP_STREAM_INVALID) return 1;
 used_filename = file->f_name;
 filename_extension = strrchr(used_filename,'.');
 if (!filename_extension) {
  size_t filename_size = file->f_namesize;
  used_filename = (char *)malloc((filename_size+2)*sizeof(char));
  if (!used_filename) return 0;
  memcpy(used_filename,file->f_name,filename_size*sizeof(char));
  filename_extension = used_filename+filename_size;
  *filename_extension = '.';
 }
 old = filename_extension[1],filename_extension[1] = 'o';
 write(dep_outfile,used_filename,((filename_extension-used_filename)+2)*sizeof(char));
 write(dep_outfile,":",1*sizeof(char));
 filename_extension[1] = old;
 if (used_filename != file->f_name) free(used_filename);
 return pp_depcallback(file,0);
}
static void pp_deponly(void) {
 /* fallback: Use stdout as output file for dependencies if no other file was set.
  * HINT: stdout may have previously been redireced with the '-o' option. */
 if (dep_outfile == TPP_STREAM_INVALID) dep_outfile = stdout_handle;
 while (TPPLexer_Yield() > 0);
 write(dep_outfile,"\n",1*sizeof(char));
}

#ifdef _WIN32
#define close_stream  CloseHandle
#else
#define close_stream  close
#endif
static stream_t open_out_file(char const *filename) {
 stream_t result;
 if (!strcmp(filename,"-")) return stdout_handle;
#ifdef _WIN32
 result = CreateFileA(filename,GENERIC_WRITE,
                      FILE_SHARE_READ|FILE_SHARE_WRITE|FILE_SHARE_DELETE,
                      NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
 if (!result) result = TPP_STREAM_INVALID;
#else
 result = open(output_filename,O_CREAT|O_WRONLY,0644);
#endif
 if (result == TPP_STREAM_INVALID) {
  fprintf(stderr,"Failed to create output file: \"%s\"\n",filename);
  fflush(stderr);
  _exit(1);
 }
 return result;
}


#define PPMODE_NORMAL     0
#define PPMODE_DEPENDENCY 1
int main(int argc, char *argv[]) {
 struct TPPFile *infile; int result = 0;
 int pp_mode = PPMODE_NORMAL;
 char *output_filename = NULL,*appname,*firstname = NULL;
#ifdef _WIN32
 stdout_handle = GetStdHandle(STD_OUTPUT_HANDLE);
#endif
 if (!TPP_INITIALIZE()) return 1;
 if (argc) appname = argv[0],--argc,++argv; else appname = "tpp";
 TPPLexer_Current->l_flags |= (TPPLEXER_FLAG_WANTSPACE|
                               TPPLEXER_FLAG_WANTLF|
#ifdef _WIN32
                               TPPLEXER_FLAG_MSVC_MESSAGEFORMAT|
#endif
                               TPPLEXER_FLAG_TERMINATE_STRING_LF|
                               TPPLEXER_EXTENSION_RECMAC);
 while (argc && argv[0][0] == '-') {
  char *arg = argv[0]+1;
  /* TODO: All those source dependency switches (-M, -MM, -MF, -MG, -MP, -MT, -MQ, -MD, -MMD) */
  /* TODO: Look at the arguments 'cpp' can take and try to implement them all (or most).
   *       >> This new version of TPP is meant as a drop-in replacement for cpp! */
       if (!strcmp(arg,"-tok")) outline_tokens = OUTLINE_MODE_TOK;
  else if (!strcmp(arg,"fspc")) TPPLexer_Current->l_flags |= TPPLEXER_FLAG_WANTSPACE;
  else if (!strcmp(arg,"fno-spc")) TPPLexer_Current->l_flags &= ~(TPPLEXER_FLAG_WANTSPACE);
  else if (!strcmp(arg,"flf")) TPPLexer_Current->l_flags |= TPPLEXER_FLAG_WANTLF;
  else if (!strcmp(arg,"fno-lf")) TPPLexer_Current->l_flags &= ~(TPPLEXER_FLAG_WANTLF);
  else if (!strcmp(arg,"fcomments")) TPPLexer_Current->l_flags |= TPPLEXER_FLAG_WANTCOMMENTS;
  else if (!strcmp(arg,"fno-comments")) TPPLexer_Current->l_flags &= ~(TPPLEXER_FLAG_WANTCOMMENTS);
  else if (!strcmp(arg,"fmagiclf")) no_magic_tokens = 0;
  else if (!strcmp(arg,"fno-magiclf")) no_magic_tokens = 1;
  else if (!strcmp(arg,"flongstring")) TPPLexer_Current->l_flags &= ~(TPPLEXER_FLAG_TERMINATE_STRING_LF);
  else if (!strcmp(arg,"fno-longstring")) TPPLexer_Current->l_flags |= TPPLEXER_FLAG_TERMINATE_STRING_LF;
  else if (!strcmp(arg,"trigraphs")) TPPLexer_Current->l_extensions |= TPPLEXER_EXTENSION_TRIGRAPHS;
#if !TPP_CONFIG_MINMACRO
  else if (!strcmp(arg,"undef")) TPPLexer_Current->l_extensions &= ~(TPPLEXER_EXTENSION_CPU_MACROS|
                                                                     TPPLEXER_EXTENSION_SYSTEM_MACROS|
                                                                     TPPLEXER_EXTENSION_UTILITY_MACROS);
#else /* !TPP_CONFIG_MINMACRO */
  else if (!strcmp(arg,"undef"));
#endif /* TPP_CONFIG_MINMACRO */
  else if (!strcmp(arg,"P")) no_line_directives = 0;
  else if (!strcmp(arg,"M") || 
           !strcmp(arg,"MM")) pp_mode = PPMODE_DEPENDENCY, /* Skip to dependency-only mode. */
                             (dep_outfile == TPP_STREAM_INVALID) ? dep_outfile = stdout_handle : 0, /* Change the output file to stdout. */
                              dep_nonsystem_only = !strcmp(arg,"MM"); /* Check if we're supposed to include system-headeres. */
  else if (!strcmp(arg,"MG")) TPPLexer_Current->l_callbacks.c_unknown_file = &pp_depunknown, /* Setup an unknown-file handler, assuming generated headers. */
                              TPPLexer_SetWarning(W_FILE_NOT_FOUND,WSTATE_DISABLE), /* Disable file-not-found warnings (We're assuming generated headers). */
                              pp_mode = PPMODE_DEPENDENCY; /* Switch to dependency-only mode. */
  else if (!strcmp(arg,"MF")) argc > 1 ? ((dep_outfile != TPP_STREAM_INVALID && dep_outfile != stdout_handle)
                                           ? close_stream(dep_outfile) : 0, /* Close a previously opened dependecy output stream. */
                                           dep_outfile = open_out_file(argv[1]),++argv,--argc) : 0;
  else if (!strcmp(arg,"o")) argc > 1 ? (output_filename = argv[1],++argv,--argc) : 0;
  else if (!strcmp(arg,"-name")) argc > 1 ? (firstname = argv[1],++argv,--argc) : 0;
  else if (!strcmp(arg,"-message-format=gcc")) TPPLexer_Current->l_flags &= ~(TPPLEXER_FLAG_MSVC_MESSAGEFORMAT);
  else if (!strcmp(arg,"-message-format=msvc")) TPPLexer_Current->l_flags |= TPPLEXER_FLAG_MSVC_MESSAGEFORMAT;
  else if (!strcmp(arg,"-help")) usage(appname,argc > 1 && argv[1][0] != '-' ? argv[1] : NULL),_exit(2);
  else if (!strcmp(arg,"-version")) fwrite(version,sizeof(char),sizeof(version)/sizeof(char)-1,stderr),_exit(2);
  else if (!strcmp(arg,"i")) { !argc || --argc,++argv; infile = merge_argv(argc,argv); goto use_infile; }
  else if (!strcmp(arg,"-pp"))
   /* Intermediate preprocessor mode:
    *  - Very useful for invoking tpp from another
    *    application to really just tokenize a file.
    *  - Emit tokens separated by '\0'-characters
    *  - Don't emit whitespace, or linefeeds.
    */
   TPPLexer_Current->l_flags &= ~(TPPLEXER_FLAG_WANTSPACE|
                                  TPPLEXER_FLAG_WANTLF),
   outline_tokens = OUTLINE_MODE_ZERO;
  else if (*arg == 'I') { if (!*++arg && argc > 1) arg = argv[1],++argv,--argc;
                          if (!TPPLexer_AddIncludePath(arg,strlen(arg))) _exit(1); }
  else if (*arg == 'D') { char *val;
                          if (!*++arg && argc > 1) arg = argv[1],++argv,--argc;
                          val = strchr(arg,'=');
                          if (val) *val++ = '\0'; else val = "1";
                          if (!TPPLexer_Define(arg,strlen(arg),val,strlen(val))) _exit(1); }
  else if (*arg == 'U') { if (!*++arg && argc > 1) arg = argv[1],++argv,--argc;
                          TPPLexer_Undef(arg,strlen(arg)); }
  else if (*arg == 'A') { int add = 1; char *val;
                          if (!*++arg && argc > 1) arg = argv[1],++argv,--argc;
                          if (*arg == '-') ++arg,add = 0;
                          val = strchr(arg,'=');
                          if (val) *val++ = '\0'; else if (add) goto noopt;
                          add ? TPPLexer_AddAssert(arg,strlen(arg),val,strlen(val))
                              : TPPLexer_DelAssert(arg,strlen(arg),val,val ? strlen(val) : 0); }
  else if (*arg == 'f') { int enable = 1; ++arg; /* Set an extension. */
                          if (!memcmp(arg,"no-",3)) arg += 3,enable = 0;
                          if (!TPPLexer_SetExtension(arg,enable)) goto noopt; }
  else if (*arg == 'W') { wstate_t state = WSTATE_ERROR; ++arg; /* Set an extension. */
                          if (!memcmp(arg,"no-",3)) arg += 3,state = WSTATE_DISABLE;
                          if (!TPPLexer_SetWarnings(arg,state)) goto noopt; }
#if 1 /* Backwards-compatibility with old TPP */
  else if (!strcmp(arg,"no-line")) no_line_directives = 1;
  else if (!strcmp(arg,"tok")) outline_tokens = OUTLINE_MODE_TOK;
#endif
  else {
noopt:
   fprintf(stderr,
           "Unknown option: \"%s\"\n"
           "See '%s --help' for more help\n",
           arg-1,appname);
   _exit(1);
  }
  --argc,++argv;
 }
 if (output_filename && strcmp(output_filename,"-")) {
  stream_t newout = open_out_file(output_filename);
  if (dep_outfile == stdout_handle) dep_outfile = newout;
#ifdef _WIN32
  stdout_handle = newout;
#else
  dup2(STDOUT_FILENO,newout);
#endif
 }

 if (argc && strcmp(argv[0],"-") != 0) {
  infile = TPPLexer_OpenFile(TPPLEXER_OPENFILE_MODE_NORMAL|
                             TPPLEXER_OPENFILE_FLAG_NOCASEWARN,
                             argv[0],strlen(argv[0]),NULL);
  if (infile) TPPFile_Incref(infile);
  if (infile && firstname) {
   infile->f_textfile.f_usedname = TPPString_New(firstname,strlen(firstname));
   if (!infile->f_textfile.f_usedname) _exit(1);
  }
  if (!infile) fprintf(stderr,"File not found: \"%s\"\n",argv[0]);
 } else {
  /* Fallback: Use stdin as input stream. */
  if (!firstname) firstname = "<stdin>";
#ifdef _WIN32
  infile = TPPFile_OpenStream(GetStdHandle(STD_INPUT_HANDLE),firstname);
#else
  infile = TPPFile_OpenStream(STDIN_FILENO,firstname);
#endif
 }
use_infile:
 if (!infile) goto err1;
 TPPLexer_PushFileInherited(infile);
 TPPLexer_Current->l_callbacks.c_new_textfile = &pp_depcallback;
 if (!pp_depfirst(infile)) goto err1;
 switch (pp_mode) {
  case PPMODE_DEPENDENCY: pp_deponly(); break;
  default               : pp_normal(); break;
 }
end:
 TPP_FINALIZE();
#ifdef _CRTDBG_MAP_ALLOC
 _CrtDumpMemoryLeaks();
#endif
 return result;
err1: result = 1; goto end;
}

#ifdef __cplusplus
}
#endif

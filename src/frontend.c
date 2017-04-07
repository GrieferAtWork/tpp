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

#define OUTLINE_MODE_NONE 0
#define OUTLINE_MODE_TOK  1 /* Outline with [...] */
#define OUTLINE_MODE_ZERO 2 /* Separate with '\0' */
static int outline_tokens     = OUTLINE_MODE_NONE;
static int no_magic_tokens    = 1; /*< Disable ~magic~ tokens for small line-shifts to prevent a #line being emit. */
static int no_line_directives = 0; /*< Disable #line directives being emit. */

#ifdef _WIN32
static HANDLE stdout_handle;
/* We prefer using unbuffered I/O to not create
 * bottlenecks when running in immediate mode.
 * Also: Window's libc does some weird $h1t to linefeeds,
 *       inserting a magic '\r' character before every '\n'...
 *      (You can probably turn that off, but I'm not even gonna bother)
 */
static void out_write(void const *p, size_t s) {
 WriteFile(stdout_handle,p,s,NULL,NULL);
}
#else
#define out_write(p,s) write(STDOUT_FILENO,p,s)
#endif

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

void usage(char *appname) {
 fprintf(stderr,"usage: %s [ARGS...] [INFILE]\n"
                "ARGS:\n"
                "\t" "--tok                       Outline all tokens using the [...] notation (Default: off).\n"
                "\t" "--pp                        Enable preprocess-mode, which emits all tokens separated by '\\0'-bytes.\n"
                "\t" "-f[no-]spc                  Configure emission of SPACE tokens (Default: on).\n"
                "\t" "-f[no-]lf                   Configure emission of LF tokens (Default: on).\n"
                "\t" "-f[no-]line                 Configure emission of #line adjustment directives (Default: on).\n"
                "\t" "-f[no-]comments             Configure emission of COMMENT tokens (Default: off).\n"
                "\t" "-f[no-]magiclf              Enable/Disable magic linefeeds sometimes used in place of #line (Default: off).\n"
                "\t" "-f[no-]longstring           Enable/Disable string continuation between lines (Default: off).\n"
                "\t" "                            Enabling this option also disabled SPACE and LF tokens, though\n"
                "\t" "                            they can be re-enabled using the -spc and -lf switches.\n"
                "\t" "-o <name>                   Redirect output to a given file (defauls to STDOUT).\n"
                "\t" "--name <name>               Set the name used for __FILE__ in INFILE (Useful when INFILE is stdin).\n"
                "\t" "--help                      Display this help and exit.\n"
#ifdef _WIN32
                "\t" "--message-format={msvc|gcc} Set the format for error message (Default: msvc).\n"
#else
                "\t" "--message-format={msvc|gcc} Set the format for error message (Default: gcc).\n"
#endif
                "INFILE:\n"
                "\t" "-                When not specified or set to '-', use STDIN as input\n"
                "\t" "<filename>       The name of a file to preprocess, as well as the default value for '--name'\n"
         ,appname);
}

int main(int argc, char *argv[]) {
 struct TPPFile *infile,*last_token_file;
 int result = 0; char *last_token_end;
 size_t file_offset; char *output_filename = NULL,*appname,*firstname = NULL;
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
  /* TODO: -I */
  /* TODO: -D */
  /* TODO: Look at the arguments 'cpp' can take and try to implement them all (or most).
   *       >> This new version of TPP is meant as a drop-in replacement for cpp! */
       if (!strcmp(arg,"-tok")) outline_tokens = OUTLINE_MODE_TOK;
  else if (!strcmp(arg,"fspc")) TPPLexer_Current->l_flags |= TPPLEXER_FLAG_WANTSPACE;
  else if (!strcmp(arg,"fno-spc")) TPPLexer_Current->l_flags &= ~(TPPLEXER_FLAG_WANTSPACE);
  else if (!strcmp(arg,"flf")) TPPLexer_Current->l_flags |= TPPLEXER_FLAG_WANTLF;
  else if (!strcmp(arg,"fno-lf")) TPPLexer_Current->l_flags &= ~(TPPLEXER_FLAG_WANTLF);
  else if (!strcmp(arg,"fline")) no_line_directives = 0;
  else if (!strcmp(arg,"fno-line")) no_line_directives = 1;
  else if (!strcmp(arg,"fcomments")) TPPLexer_Current->l_flags |= TPPLEXER_FLAG_WANTCOMMENTS;
  else if (!strcmp(arg,"fno-comments")) TPPLexer_Current->l_flags &= ~(TPPLEXER_FLAG_WANTCOMMENTS);
  else if (!strcmp(arg,"fmagiclf")) no_magic_tokens = 0;
  else if (!strcmp(arg,"fno-magiclf")) no_magic_tokens = 1;
  else if (!strcmp(arg,"flongstring")) TPPLexer_Current->l_flags &= ~(TPPLEXER_FLAG_TERMINATE_STRING_LF);
  else if (!strcmp(arg,"fno-longstring")) TPPLexer_Current->l_flags |= TPPLEXER_FLAG_TERMINATE_STRING_LF;
  else if (!strcmp(arg,"o")) argc > 1 ? (output_filename = argv[1],++argv,--argc) : 0;
  else if (!strcmp(arg,"-name")) argc > 1 ? (firstname = argv[1],++argv,--argc) : 0;
  else if (!strcmp(arg,"-message-format=gcc")) TPPLexer_Current->l_flags &= ~(TPPLEXER_FLAG_MSVC_MESSAGEFORMAT);
  else if (!strcmp(arg,"-message-format=msvc")) TPPLexer_Current->l_flags |= TPPLEXER_FLAG_MSVC_MESSAGEFORMAT;
  else if (!strcmp(arg,"-help")) usage(appname),_exit(2);
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
  else if (*arg == 'I') { if (!arg[1] && argc > 1) arg = argv[1],++argv,--argc;
                          
  } else {
   fprintf(stderr,
           "Unknown option: \"%s\"\n"
           "See '%s --help' for more help\n",
           arg-1,appname);
   _exit(1);
  }
  --argc,++argv;
 }
 if (output_filename && strcmp(output_filename,"-")) {
#ifdef _WIN32
  stdout_handle = CreateFileA(output_filename,GENERIC_WRITE,
                              FILE_SHARE_READ|FILE_SHARE_WRITE|FILE_SHARE_DELETE,
                              NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
  if (!stdout_handle || stdout_handle == INVALID_HANDLE_VALUE)
#else
  int newhandle = open(output_filename,O_CREAT|O_WRONLY,0644);
  if (newhandle != -1) newhandle = dup2(STDOUT_FILENO,newhandle);
  if (newhandle == -1)
#endif
  {
   fprintf(stderr,"Failed to create output file: \"%s\"\n",output_filename);
   _exit(1);
  }
 }

 if (argc && strcmp(argv[0],"-") != 0) {
  infile = TPPLexer_OpenFile(TPPLEXER_OPENFILE_MODE_NORMAL,
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
 if (!infile) { result = 1; goto end; }
 infile->f_prev = TPPLexer_Current->l_token.t_file;
 TPPLexer_Current->l_token.t_file = infile;
 /* Initial values to simulate the last token
  * ending where the first file starts. */
 last_token_file = NULL; // infile; /* Force a line directive at the first token. */
 last_token_end  = infile->f_begin;
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
end:
 TPP_FINALIZE();
#ifdef _CRTDBG_MAP_ALLOC
 _CrtDumpMemoryLeaks();
#endif
 return result;
}


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
#ifndef GUARD_TPP_H
#define GUARD_TPP_H 1

/* TPP Configuration. (Extensions can be enabled/disabled at runtime). */
#ifndef TPP_CONFIG_DEBUG
#ifdef NDEBUG
#define TPP_CONFIG_DEBUG      0
#else
#define TPP_CONFIG_DEBUG      1
#endif
#endif
#ifndef TPP_CONFIG_ONELEXER
#define TPP_CONFIG_ONELEXER   1 /* Globally provide only one lexer (faster, but more restrictive). */
#endif

#define TPP_PREPROCESSOR_VERSION 200 /* Preprocessor version. */
#define TPP_API_VERSION          200 /* Api version (Version of this api). */



/* WARNING: This new version of TPP uses global variables that prevent it from
 *          being fully thread-safe. - For that reason, you must either provide
 *          your own lock when attempting to use TPP with multiple threads, as
 *          well as having to compile with '-DTPP_CONFIG_ONELEXER=0' and exchanging
 *          the current TPP lexer whenever switching between threads. */


//////////////////////////////////////////////////////////////////////////
// Supported features/extension
//////////////////////////////////////////////////////////////////////////
//SYNTAX:
// [//]           //Comment                     /*< Recognize c++-style comments. */
// [/**/]         /*Comment*/                   /*< Recognize c-style comments. */
// ["#"]          #Comment                      /*< Recognize assembler-style comments (WARNING: May create ambiguity with preprocessor directives). */
// ["??="]        ??=define foo bar             /*< Recognize and interprete trigraph character sequences. */
// ["%:"]         %:define foo bar              /*< Recognize and interprete digraph character sequences. */
// ["foo"[:-1]]   #if "foo"[1:] == "oo"         /*< Use strings in preprocessor expressions, and support python-style sub-string or character access. */
// [defined(foo)] #if defined(foo)              /*< Recognize 'defined' in preprocessor expressions. */
// [foo ?: bar]   #if foo ?: bar                /*< Recognize gcc's 'a ?: b' as alias for 'a ? a : b'. */
// ["\e"]         printf("\e[10mHello\e[0m\n"); /*< Recognize \e in strings as alias for '\33' (ESC). */
//
//PREPROCESSOR DIRECTIVES:
// [#]             #[LF]             /*< Ignore empty (NULL) directives. */
// [#!]            #!/bin/bash       /*< Ignore shebang-style script arguments. */
// [#if]           #if foobar        /*< Recognize all types of STD-C conditional preprocessor blocks (#if,#ifdef,#ifndef,#elif,#else,#endif). */
// [#pragma]       #pragma once      /*< Recognize #pragma preprocessor directives (unknown pragmas are re-emit). */
// [#define]       #define foo 42    /*< Recognize #define used to declare new macros. */
// [#undef]        #undef foo        /*< Recognize #undef used to undefine user macros. */
// [#include]      #include ...      /*< Recognize #include used to include other files (follows system/caller/CWD-relative path rules). */
// [#include_next] #include_next ... /*< Recognize #include_next used to include the next file not already being included. */
// [#import]       #import ...       /*< Recognize #import used to include files only once (so long as only everything uses #import to include them). */
// [#line]         #line 42 "foo"    /*< Recognize #line used to set the next line number, as well as a custom file name. */
// [#error]        #error "nope"     /*< Recognize #error used to emit a preprocessor error. */
// [#warning]      #warning "$h1t"   /*< Recognize #warning used to emit a preprocessor warning. */
//
//USER-DEFINED MACROS:
// [#str]         #define str(x)           #x                              /*< STD-C macro argument stringification. */
// [c##at]        #define cat(a,b)         a##b                            /*< STD-C macro argument concat. */
// [__VA_ARGS__]  #define foo(...)         __VA_ARGS__                     /*< STD-C varargs macros. */
// [#@chr]        #define chr(x)           #@x                             /*< macro argument charification. */
// [args...]      #define bar(args...)     args                            /*< GCC varargs macros. */
// [,##args]      #define baz(fmt,args...) printf(fmt,##args)              /*< GCC va_comma. */
// [__VA_COMMA__] #define liz(fmt,args...) printf(fmt __VA_COMMA__ args)   /*< TPP __VA_COMMA__. */
// [__VA_NARGS__] #define sum(args...)     _sum##__VA_NARGS__(__VA_ARGS__) /*< Expands to an integral representation of the number of variadic arguments (_very_ useful for overloading macros by argument count). */
// [#!noexp]      #define noexp(x)         #!x                             /*< Insert a macro argument without expansion (Don't say it doesn't work unless you _really_ understand what it's supposed to do!). */
// [<recursion>]  #define inc(x)           inc(x+1)                        /*< Recursively allow macros to expand themself (Must be enabled using pragmas; Inconjunction with __TPP_EVAL, very useful for creating loops). */
//
//BUILTIN MACROS:
// [__FILE__]          printf("%s\n",__FILE__);          /*< Expand to the string representation of the current file. */
// [__LINE__]          printf("%d\n",__LINE__);          /*< Expand to the integral representation of the current line. */
// [__BASE_FILE__]     printf("%s\n",__BASE_FILE__);     /*< Expand to the name of the original source file used to startup the preprocessor. */
// [__INCLUDE_LEVEL__] printf("%d\n",__INCLUDE_LEVEL__); /*< Expand to the integral representation of how many files away the original source file is (this counter starts at '0'). */
// [__COUNTER__]       printf("%d\n",__COUNTER__);       /*< Expand to the integral representation an integral that increments by 1 every time it is expanded (starts at '0'). */
// [_Pragma]           _Pragma("once")                   /*< STD-C style pragma with a string as argument (unknown pragmas are re-emit). */
// [__pragma]          __pragma(once)                    /*< MSVC style pragma with the argument not being a string (unknown pragmas are re-emit). */
// [__TPP_EVAL]        __TPP_EVAL(10+20)                 /*< Evaluate an expression as used by '#if'. This macro expands to the string/decimal representation of that expression's value. */
// [__TPP_UNIQUE]      #define __TPP_UNIQUE(keyword)     /*< A unique integral number associated with 'keyword'; new keywords have greater numbers. */
//
//PRAGMA EXTENSIONS:
// [once]              #pragma once                      /*< Mark a file that should only be #includ-ed once (same as defining and setting a unique #include-guard for that file). */
// [push_macro]        #pragma push_macro("foo")         /*< Store the definition of a macro, later to-be restored. */
// [pop_macro]         #pragma pop_macro("foo")          /*< Restore a previously stored definition of a macro. */
// [{end}region]       #pragma {end}region my region     /*< Highlight named regions of code in IDEs (the preprocessor must, and does simply ignore this directive). */
// [message]           #pragma message "Hello"           /*< Emit a message to 'stderr' from inside the preprocessor (NOTE: Also supports optional parenthesis surrounding the text). */


#if defined(GUARD_TPP_C) && \
    defined(_MSC_VER) && TPP_CONFIG_DEBUG
/* Make use of MSVC's builtin memory leak detector. */
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#ifdef _MSC_VER
#define TPP_SYMARRAY_SIZE 4096
#define TPP_MACRO_FALSE   0,0
#else
#define TPP_SYMARRAY_SIZE 1
#define TPP_MACRO_FALSE   0
#endif

#ifndef TPPFUN
#define TPPFUN  extern
#endif
#define TPP_LOCAL            static inline
#define TPP_OFFSETOF(m,s)    ((size_t)(&((m *)0)->s))
#define TPP_OFFSETAFTER(m,s) ((size_t)(&((m *)0)->s+1))

#ifdef __cplusplus
extern "C" {
#endif

#ifndef TPP
#define TPP_NAMESPACE_DEFINED
#define TPP(x) TPP_##x
#endif

/* OS-specific data type for a stream handle. */
#ifdef _WIN32
typedef /*HANDLE*/void *TPP(stream_t);
#define TPP_STREAM_INVALID  ((TPP(stream_t))(size_t)-1)
#else
typedef int TPP(stream_t);
#define TPP_STREAM_INVALID  -1
#endif

typedef int    TPP(tok_t);  /* Unique token id. */
typedef size_t TPP(hash_t); /* Hash-value of a string. */

struct TPPFile;
struct TPPKeyword;

struct TPPString {
 unsigned int s_refcnt; /*< String reference counter. */
 size_t       s_size;   /*< Size of the text in characters. */
 char         s_text[TPP_SYMARRAY_SIZE]; /*< [s_size] ZERO-terminated text. */
};
#define TPPString_Incref(self) (void)(++(self)->s_refcnt)
#define TPPString_Decref(self) (void)(--(self)->s_refcnt || (free(self),0))

//////////////////////////////////////////////////////////////////////////
// Concat two given string and drop ONE(1) references from each.
// @return: * :   A reference to a string containing the sum of what is given.
// @return: NULL: Not enough available memory.
TPPFUN /*ref*/struct TPPString *
TPPString_Cat(/*ref*/struct TPPString *lhs,
              /*ref*/struct TPPString *rhs);

//////////////////////////////////////////////////////////////////////////
// Returns a new string from the given text.
// @return: * :   A reference to a string containing the given text.
// @return: NULL: Not enough available memory.
TPPFUN /*ref*/struct TPPString *
TPPString_New(char const *text, size_t size);


struct TPPTextFile {
 /* [owned((:f_name) = true]
  * HINT: ':f_name' usually is the string passed to the
  *        system for opening a stream for this file.
  *        Though this doesn't necessarily have to hold up,
  *        as pipe text files don't need to follow this rule. */
 /*ref*/struct TPPFile   *f_cacheentry;  /*< [0..1] Used when the copy of a file is loaded onto the #include-stack (points to the original version of the file)
                                          *   NOTE: When non-NULL, always a textfile and this pointer also owns a reference to the associated textfile's 'f_cacheinc' field. */
 /*ref*/struct TPPString *f_usedname;    /*< [0..1] When non-NULL, an override to the used filename (as set by '#line') */
 int                      f_lineoff;     /*< Offset of 'f_begin' from the original start of the file in lines. */
 TPP(stream_t)            f_stream;      /*< Stream handle for reading more data. */
 TPP(stream_t)            f_ownedstream; /*< Usually equal to 'f_stream', the stream that should be closed when it's EOF is reached (set of 'TPP_STREAM_INVALID' if TPP shouldn't close the stream). */
 /* NOTE: ':f_end' may not be equal to the end of ':f_text'.
  *        The difference between the two should be prefixed to the next chunk. */
 struct TPPKeyword       *f_guard;       /*< [0..1] Name of the #include guard for this file, or NULL if unknown. */
 size_t                   f_cacheinc;    /*< Used to track how often a given file is loaded onto the #include-stack.
                                          * (Only used for cached entires themself; aka. when 'f_cacheentry == NULL'). */
 size_t                   f_rdata;       /*< (In bytes) The amount of data already read from the stream. */
 char                     f_prefixdel;   /*< The original character at ':f_end' that was overwritten with a '\0' */
};

/* HINT: something like
 * >> #define cat(a,b) a ## b
 * is simply implemented as:
 * >> {
 * >>   {TPP_FUNOP_INS,{0,1}}, // Without expanding, insert 'a' and override 1 character ("a")
 * >>   {TPP_FUNOP_INS,{1,5}}, // Without expanding, insert 'b' and override 5 characters (" ## b")
 * >> } */
#define TPP_FUNOP_END      0x00 /*< [0] End of command list. */
#define TPP_FUNOP_ADV      0x01 /*< [1] Advance the text pointer by ARG(0) characters. */
#define TPP_FUNOP_INS      0x02 /*< [2] Insert argument ARG(0), override ARG(1) characters and put the text pointer after the inserted text. */
#define TPP_FUNOP_INS_EXP  0x03 /*< [2] Same as 'TPP_FUNOP_INS', but expand macros within the argument text before inserting it. */
#define TPP_FUNOP_INS_STR  0x04 /*< [2] Same as 'TPP_FUNOP_INS', but encode the argument as a single-token string. */
#define TPP_FUNOP_INS_CHR  0x05 /*< [2] Same as 'TPP_FUNOP_INS', but encode the argument as a single-token character. */
#define TPP_FUNOP_DEL      0x06 /*< [1] Delete ARG(0) characters (doesn't advance the text pointer). */
#define TPP_FUNOP_VA_COMMA 0x07 /*< [1] Delete ARG(0) characters and insert a ',' if the variadic portion of the argument list is non-empty (NOTE: When inserting, the text-pointer is advanced). */
#define TPP_FUNOP_VA_NARGS 0x08 /*< [1] Delete ARG(0) characters and insert a decimal representation of the variadic argument size (NOTE: When inserting, the text-pointer is advanced). */
typedef uint8_t TPP(funop_t);
typedef int64_t TPP(int_t);

struct TPP(arginfo_t) {
 TPP(tok_t) ai_id;       /*< Token ID associated with this argument name. */
 size_t     ai_ins;      /*< Amount of times the argument is inserted without expansion. */
 size_t     ai_ins_exp;  /*< Amount of times the argument is inserted after expansion. */
 size_t     ai_ins_str;  /*< Amount of times the argument is inserted in its escaped form. */
#if TPP_CONFIG_DEBUG
 char      *ai_name;     /*< [1..1] Name of this macro (Weakly references the names from the keyword list). */
 size_t     ai_namesize; /*< Size of this argument's name (in characters) */
#endif
};


struct TPPMacroFile {
 /* [owned(f_name) = m_flags&TPP_MACROFILE_FLAG_OWNSNAME] */
#define TPP_MACROFILE_KIND                   0x000000ff
#define TPP_MACROFILE_KIND_HASCOMMON(k)   (((k)&TPP_MACROFILE_KIND) != TPP_MACROFILE_KIND_EXPANDED)
#define TPP_MACROFILE_FLAG_OWNSNAME          0x00001000 /*< The associated "f_name" member is owned. */
#define TPP_MACROFILE_KIND_KEYWORD           0x00000000 /*< Keyword-style macro (without string/concat operations). */
#define TPP_MACROFILE_KIND_FUNCTION          0x00000001 /*< Function-style macro. */
#define TPP_MACROFILE_FLAG_FUNC_VARIADIC     0x00000100 /*< The last argument of the function is variadic. */
#define TPP_MACROFILE_FLAG_FUNC_SELFEXPAND   0x00000200 /*< After being expanded, this function is allowed to re-invoke itself and be
                                                         *  expanded, when the generated text is not identical to a previous iteration. */
#define TPP_MACROFILE_MASK_FUNC_STARTCH      0x0000f000 /*< The character that should be recognized as start of an argument list (one of the macros below). */
#define TPP_MACROFILE_FUNC_START_LPAREN      0x00000000 /*< '(...)' */
#define TPP_MACROFILE_FUNC_START_LBRACKET    0x00001000 /*< '[...]' */
#define TPP_MACROFILE_FUNC_START_LBRACE      0x00002000 /*< '{...}' */
#define TPP_MACROFILE_FUNC_START_LANGLE      0x00003000 /*< '<...>' */
#define TPP_MACROFILE_FUNC_START(ch) \
 ((ch) == '(' ? TPP_MACROFILE_FUNC_START_LPAREN :\
  (ch) == '[' ? TPP_MACROFILE_FUNC_START_LBRACKET :\
  (ch) == '{' ? TPP_MACROFILE_FUNC_START_LBRACE :\
                TPP_MACROFILE_FUNC_START_LANGLE)
#define TPP_MACROFILE_KIND_EXPANDED        0x00000002 /*< Expanded version of a function macro. */
 uint32_t               m_flags;         /*< [const] Macro flags. */
 /*ref*/struct TPPFile *m_deffile;       /*< [const][0..1][(!= NULL) == (m_textref != NULL)] The file that originally defined this macro (or NULL if predefined, or from the commandline). */
 int                    m_defline;       /*< [const] Line in which this macro was defined (based on first character of macro name) */
 /*ref*/struct TPPFile *m_pushprev;      /*< [0..1] Previous version of a pushed macro. */
 size_t                 m_pushcount;     /*< The amount of times this macro was pushed (used to handle multiple calls to 'push_macro'). */
 /* The following */
union{struct{
}                       m_keyword;       /*< [TPP_MACROFILE_KIND_KEYWORD] */
struct{
 size_t                 f_argc;          /*< [const] Amount of arguments this function takes. */
 size_t                 f_expansions;    /*< The amount of existing expansions of this macro.
                                          *  NOTE: Depending on the 'TPP_MACROFILE_FLAG_FUNC_SELFEXPAND' flag,
                                          *        this value may not be allowed to exceed ONE(1). */
 TPP(funop_t)          *f_expand;        /*< [const][1..1][owned] Chain of text commands invoked to expand a function macro. */
 struct TPP(arginfo_t) *f_arginfo;       /*< [const][0..f_argc][owned] Vector of argument information (used for fast calculation of the expanded macro's size) */
 size_t                 f_deltotal;      /*< [const][<= (:f_end-:f_begin)] The total amount of characters removed during expansion (minus those added). */
 size_t                 f_n_vacomma;     /*< [const] Amount of times 'TPP_FUNOP_VA_COMMA' is used in 'f_expand'. */
 size_t                 f_n_vanargs;     /*< [const] Amount of times 'TPP_FUNOP_VA_NARGS' is used in 'f_expand'. */
 void                  *f_argbuf;        /*< [0..1][owned] Internal preallocated cache for a required temporary buffer used during expansion.
                                          *   NOTE: Implementation-wise, this is a vector of 'argcache_t' (internal, hidden data structure). */
}                       m_function;      /*< [TPP_MACROFILE_KIND_KEYWORD]. */
struct {
 /*ref*/struct TPPFile *e_expand_origin; /*< [const][1..1] Original macro-file that was expanded.
                                          *   NOTE: This pointer also holds a reference to 'e_expand_origin->f_macro.m_function.f_onstack'. */
}                       m_expand;        /*< [TPP_MACROFILE_KIND_EXPANDED]. */
};
};

/* Minimum malloc-sizes of various kinds of TPP files types. */
#define TPPFILE_SIZEOF_TEXT           TPP_OFFSETAFTER(struct TPPFile,f_textfile)
#define TPPFILE_SIZEOF_MACRO_KEYWORD  TPP_OFFSETAFTER(struct TPPFile,f_macro.m_keyword)
#define TPPFILE_SIZEOF_MACRO_FUNCTION TPP_OFFSETAFTER(struct TPPFile,f_macro.m_function)
#define TPPFILE_SIZEOF_MACRO_EXPANDED TPP_OFFSETAFTER(struct TPPFile,f_macro.m_expand)
#define TPPFILE_SIZEOF_PROXY          TPP_OFFSETAFTER(struct TPPFile,f_proxy)
#define TPPFILE_SIZEOF_EXPLICIT       TPP_OFFSETOF(struct TPPFile,f_textfile)

struct TPPFile {
 /* Input file/user macro. */
 unsigned int             f_refcnt;    /*< File reference counter. */
#define TPPFILE_KIND_TEXT     0 /*< Input file. */
#define TPPFILE_KIND_MACRO    1 /*< Macro file. */
#define TPPFILE_KIND_EXPLICIT 2 /*< An explicit file, that is the result of manually inserting text, such as resulting from expanding builtin macros. */
 unsigned int             f_kind;      /*< [const] The kind of file (One of 'TPPFILE_KIND_*') */
 /*C:ref*/struct TPPFile *f_prev;      /*< [0..1][caller_ref] Previous entry in the #include-stack chain or NULL if base-file or macro not part of the include stack. */
 char                    *f_name;      /*< [const][1..f_namesize][owned_if(...)] Name of this file.
                                        *   WARNING: Except for text files, this may not be '\0'-terminated
                                        *            and may contain non-escaped linefeeds and trigraphs. */
 size_t                   f_namesize;  /*< [const] Size of 'f_name' in characters. */
 size_t                   f_namehash;  /*< [const] Hash of 'f_name..f_namesize'. */
 /*ref*/struct TPPString *f_text;      /*< [1..1] Reference to a chunk of text containing the 'f_begin', 'f_end' and 'f_pos' pointers.
                                        *   NOTE: For regular text-files, this block always ends after a non-escaped linefeed ("[LF]\0"; never "\\[LF]\0").
                                        *   NOTE: If the original input-file doesn't terminate with this pattern, it may be missing. */
 char                    *f_begin;     /*< [const][1..1] Raw, unformatted text start. */
 char                    *f_end;       /*< [const][1..1] End of the text associated with this file (NOTE: Always dereferences to a '\0'-character). */
 char                    *f_pos;       /*< [1..1] Current position between 'f_begin..f_end'. */
 union {
  struct TPPTextFile      f_textfile;  /*< [if(f_kind == TPPFILE_KIND_TEXT)] Text-specific data. */
  struct TPPMacroFile     f_macro;     /*< [if(f_kind == TPPFILE_KIND_MACRO)] Macro-specific data. */
 };
};

#define TPPFile_Incref(self)          (void)(++(self)->f_refcnt)
#define TPPFile_Decref(self)          (void)(--(self)->f_refcnt || (TPPFile_Destroy(self),0))
TPPFUN void TPPFile_Destroy(struct TPPFile *__restrict self);


//////////////////////////////////////////////////////////////////////////
// Create a new explicit text file by inherited the given 'inherited_text'.
TPPFUN /*ref*/struct TPPFile *
TPPFile_NewExplicitInherited(/*ref*/struct TPPString *__restrict inherited_text);

//////////////////////////////////////////////////////////////////////////
// Returns the zero-based line index of a given text pointer.
// NOTE: The returned line index is always absolute to
//       the original text file and continues to be valid
//       even when the given file is a macro defined within.
TPPFUN int
TPPFile_LineAt(struct TPPFile const *__restrict self,
               char const *__restrict text_pointer);

//////////////////////////////////////////////////////////////////////////
// Similar to 'TPPFile_LineAt', but instead returns the column number.
TPPFUN int
TPPFile_ColumnAt(struct TPPFile const *__restrict self,
                 char const *__restrict text_pointer);

//////////////////////////////////////////////////////////////////////////
// Returns the human-readable filename of a given file.
// NOTE: For macro files, the returned filename continues
//       to referr to the file that the macro was defined
//       within.
// NOTE: Returns NULL if no name is associated with the
//       given file, such as for predefined macros.
TPPFUN char const *
TPPFile_Filename(struct TPPFile const *__restrict self,
                 size_t *opt_filename_length);

//////////////////////////////////////////////////////////////////////////
// Copy the given file for use as #include-stack entry.
// WARNING: The caller is responsible for only passing text files.
// NOTE: Calling this function
TPPFUN /*ref*/struct TPPFile *
TPPFile_CopyForInclude(struct TPPFile *__restrict self);


//////////////////////////////////////////////////////////////////////////
// Opens a file and caches the first block of data.
// NOTE: The given filename is what will appear as text when expanding __FILE__
// @return: NULL: Failed to open the given file (see 'errno' either set to ENOMEM or ENOENT)
TPPFUN /*ref*/struct TPPFile *TPPFile_Open(char const *filename);

//////////////////////////////////////////////////////////////////////////
// Similar to 'TPPFile_Open', but allows the caller to specify a stream,
// allowing them to use this function for opening things like STD handles.
// @return: NULL: Not enough available memory.
TPPFUN /*ref*/struct TPPFile *TPPFile_OpenStream(TPP(stream_t) stream, char const *name);

//////////////////////////////////////////////////////////////////////////
// Parse a #define-style preprocessor command, expecting the
// current lexer's token to point at the name of the macro.
// NOTE: This function will also register the macro in the keyword list.
// WARNING: This function expects the 'TPPLEXER_FLAG_WANTLF' flag to be set.
// WARNING: This function does _not_ return a reference.
TPPFUN struct TPPFile *TPPFile_NewDefine(void);

//////////////////////////////////////////////////////////////////////////
// Create a new keyword-style macro, as provided from the commandline.
// NOTE: The NULL is passed for 'text', an internally optimized
//       string equal to "1" is installed as text instead.
//       Otherwise whitespace is truncated from the given text.
// WARNING: The caller may choose to specify 'f_macro.m_deffile',
//          which is initialized to NULL.
TPPFUN /*ref*/struct TPPFile *
TPPFile_NewKWMacro(char const *name, size_t name_size,
                   char const *text, size_t text_size);


//////////////////////////////////////////////////////////////////////////
// Advances the given file to its next chunk.
// NOTE: When 'extend' is non-ZERO(0), instead of dropping already-read data
//       from the existing chunk, new data will be appended to that chunk,
//       meaning that the resulting stream contains both old and new data,
//       allowing for higher-level data lookahead while still remaining
//       as unbuffered as possible.
// Returns 0 if the file's EOF was already reached. 1 otherwise.
TPPFUN int TPPFile_NextChunk(struct TPPFile *__restrict self, int extend);



/* Escape/Unescape a given block of data.
 * NOTE: 'TPP_Unescape/TPP_Escape' will return the surrounding  */
TPPFUN char *TPP_Unescape(char *buf, char const *data, size_t size);
TPPFUN char *TPP_Escape(char *buf, char const *data, size_t size);
TPPFUN char *TPP_Itos(char *buf, TPP(int_t) i);
TPPFUN size_t TPP_SizeofUnescape(char const *data, size_t size);
TPPFUN size_t TPP_SizeofEscape(char const *data, size_t size);
TPPFUN size_t TPP_SizeofItos(TPP(int_t) i);


enum{
 /* Special tokens. */
 TPP(TOK_EOF)       = '\0',
 TPP(TOK_CHAR)      = '\'', /*< 'f'. */
 TPP(TOK_STRING)    = '\"', /*< "foobar". */
 TPP(TOK_INT)       = '0',  /*< 42 */
 TPP(TOK_FLOAT)     = 'f',  /*< 42.0 */
 TPP(TOK_LF)        = '\n',
 TPP(TOK_SPACE)     = ' ',
 TPP(TOK_COMMENT)   = 'c',  /*< like this one! */
 TPP(TOK_ERR)       = (TPP(tok_t))-1,   /*< An error occurred. */

 /* Single-character tokens. */
 TPP(TOK_ADD)       = '+',
 TPP(TOK_AND)       = '&',
 TPP(TOK_ASSIGN)    = '=',
 TPP(TOK_AT)        = '@',
 TPP(TOK_BACKSLASH) = '\\',
 TPP(TOK_COLLON)    = ':',
 TPP(TOK_COMMA)     = ',',
 TPP(TOK_DIV)       = '/',
 TPP(TOK_DOT)       = '.',
 TPP(TOK_HASH)      = '#',
 TPP(TOK_LANGLE)    = '<',
 TPP(TOK_LBRACE)    = '{',
 TPP(TOK_LBRACKET)  = '[',
 TPP(TOK_LPAREN)    = '(',
 TPP(TOK_MOD)       = '%',
 TPP(TOK_MUL)       = '*',
 TPP(TOK_NOT)       = '!',
 TPP(TOK_OR)        = '|',
 TPP(TOK_QUESTION)  = '?',
 TPP(TOK_RANGLE)    = '>',
 TPP(TOK_RBRACE)    = '}',
 TPP(TOK_RBRACKET)  = ']',
 TPP(TOK_RPAREN)    = ')',
 TPP(TOK_SEMICOLON) = ';',
 TPP(TOK_SUB)       = '-',
 TPP(TOK_TILDE)     = '~',
 TPP(TOK_XOR)       = '^',

 /* Double(or more)-character tokens. */
 TPP(TOK_TWOCHAR_BEGIN) = 256,
 TPP(TOK_SHL),           /*< "<<". */
 TPP(TOK_SHR),           /*< ">>". */
 TPP(TOK_EQUAL),         /*< "==". */
 TPP(TOK_NOT_EQUAL),     /*< "!=". */
 TPP(TOK_GREATER_EQUAL), /*< ">=". */
 TPP(TOK_LOWER_EQUAL),   /*< "<=". */
 TPP(TOK_DOTS),          /*< "...". */
 TPP(TOK_ADD_EQUAL),     /*< "+=". */
 TPP(TOK_SUB_EQUAL),     /*< "-=". */
 TPP(TOK_MUL_EQUAL),     /*< "*=". */
 TPP(TOK_DIV_EQUAL),     /*< "/=". */
 TPP(TOK_MOD_EQUAL),     /*< "%=". */
 TPP(TOK_SHL_EQUAL),     /*< "<<=". */
 TPP(TOK_SHR_EQUAL),     /*< ">>=". */
 TPP(TOK_AND_EQUAL),     /*< "&=". */
 TPP(TOK_OR_EQUAL),      /*< "|=". */
 TPP(TOK_XOR_EQUAL),     /*< "^=". */
 TPP(TOK_GLUE),          /*< "##". */
 TPP(TOK_LAND),          /*< "&&". */
 TPP(TOK_LOR),           /*< "||". */
 TPP(TOK_LXOR),          /*< "^^". */
 TPP(TOK_INC),           /*< "++". */
 TPP(TOK_DEC),           /*< "--". */
 TPP(TOK_POW),           /*< "**". */
 TPP(TOK_POW_EQUAL),     /*< "**=". */
 TPP(TOK_TILDE_TILDE),   /*< "~~". */
 TPP(TOK_ARROW),         /*< "->". */
 TPP(TOK_COLLON_EQUAL),  /*< ":=". */
 TPP(TOK_COLLON_COLLON), /*< "::". */
 TPP(TOK_KEYWORD_BEGIN),

 /* Name aliases */
 TPP(TOK_POS)     = TPP(TOK_ADD),
 TPP(TOK_NEG)     = TPP(TOK_SUB),
 TPP(TOK_LOWER)   = TPP(TOK_LANGLE),
 TPP(TOK_GREATER) = TPP(TOK_RANGLE),
 /* TODO: The old TPP has many more names... */
};

#define TPP_ISKEYWORD(id)     ((id) >= TPP(TOK_KEYWORD_BEGIN))
#define TPP_ISUSERKEYWORD(id) ((id) >= TPP(_KWD_BACK))
TPPFUN int TPP_ISBUILTINMACRO(TPP(tok_t) id);

enum{
 TPP(_KWD_FRONT) = TPP(TOK_KEYWORD_BEGIN)-1,
#define KWD(name,str) TPP(name),
#include "tpp-defs.inl"
#undef KWD
 TPP(_KWD_BACK),
 TPP(_KWD_COUNT) = (TPP(_KWD_BACK)-TPP(_KWD_FRONT))-1,
};

typedef enum { /* Warning states. */
 TPP(WSTATE_DISABLE)  = -2,
 TPP(WSTATE_ERROR)    = -1,
 TPP(WSTATE_WARN)     = 0,
 TPP(WSTATE_SUPPRESS) = 1, /* To suppress more than once, use > 1 */
} TPP(wstate_t);

enum{
#define WGROUP(name,str) TPP(name),
#include "tpp-defs.inl"
#undef WGROUP
};

enum{
#define WARNING(name,group,default) TPP(name),
#include "tpp-defs.inl"
#undef WARNING
};

struct TPPIfdefStackSlot {
#define TPP_IFDEFMODE_FALSE 0
#define TPP_IFDEFMODE_TRUE  1 /*< FLAG: The block is enabled. */
#define TPP_IFDEFMODE_ELSE  2 /*< FLAG: The block follows an #else. */
 int             iss_mode; /*< Slot mode (Used to differentiate between #if, #elif and #else regions). */
 int             iss_line; /*< ZERO-based line in which this slot was last updated (Used in warning messages). */
 struct TPPFile *iss_file; /*< [1..1] The file that owns this #ifdef slot
                            *   NOTE: This file _must_ be part of the #include stack!
                            *   WARNING: This is not a reference and relies on the file
                            *            being kept alive through the #include stack.
                            *   HINT: Also used to pop all unclosed blocks when a file ends. */
};
struct TPPIfdefStack {
 size_t                    is_slotc; /*< Amount of #ifdef slots in use. */
 size_t                    is_slota; /*< Allocated amount of #ifdef slots. */
 struct TPPIfdefStackSlot *is_slotv; /*< [0..is_slotc|alloc(is_slota)][owned] Vector of #ifdef slots. */
};


struct TPPIncludePath {
 /* NOTE: A special #include-path exists that is only a '.'.
  *       This path refers to the current directory itself. */
 size_t ip_size; /*< Length of the path in characters. */
 char  *ip_path; /*< [0..ip_size][owned] Normalized include path (without trailing slash).
                  *   WARNING: Outside of debug-mode, this string is not necessarily zero-terminated. */
};
struct TPPIncludeList {
 /* List of sanitized #include paths. */
 size_t                 il_pathc; /*< Amount of elements in the vector below. */
 struct TPPIncludePath *il_pathv; /*< [0..il_pathc][owned] Vector of sanitized #include path. */
};

struct TPPRareKeyword {
 /* Keyword-specific data that is only rarely used. */
 /*ref*/struct TPPFile    *kr_file;     /*< [0..1] Set if this keyword is actually the name of a file, when that file was already included.
                                         *         Used to track recursive file-inclusion, as well as quickly dismiss guarded files and
                                         *         speed up determining the correct filename for 'include_next'.
                                         *   NOTE: Sadly, this cannot simply be made into a union with 'k_macro',
                                         *         as a filename could potentially be equal to a keyword (e.g.: '#include "header"' vs. '#define header 42') */
 /*ref*/struct TPPFile    *kr_oldmacro; /*< [0..1][linked_list(->f_hashnext...)] Linked list of old (aka. pushed) version of this macro. */
 TPP(int_t)                kr_counter;  /*< Counter value used by '__TPP_COUNTER()' */
#define TPP_KEYWORDFLAG_NONE                   0x00000000
#define TPP_KEYWORDFLAG_IMPORTED               0x80000000 /*< Set for for files after they've been #import-ed. */
 /* NOTE: These flags share their values with those
  *       from the old TPP for backwards compatibility. */
#define TPP_KEYWORDFLAG_HAS_ATTRIBUTE          0x00000001
#define TPP_KEYWORDFLAG_HAS_BUILTIN            0x00000002
#define TPP_KEYWORDFLAG_HAS_CPP_ATTRIBUTE      0x00000004
#define TPP_KEYWORDFLAG_HAS_DECLSPEC_ATTRIBUTE 0x00000008
#define TPP_KEYWORDFLAG_HAS_EXTENSION          0x00000010
#define TPP_KEYWORDFLAG_HAS_FEATURE            0x00000020
#define TPP_KEYWORDFLAG_IS_DEPRECATED          0x00000040
#define TPP_KEYWORDFLAG_USERMASK               0x0000007f /*< Set of flags modifiable through pragmas. */
 uint32_t                  kr_flags;    /*< A set of 'TPP_KEYWORDFLAG_*'. */
};

struct TPPKeyword {
        struct TPPKeyword *k_next;     /*< [0..1][owned] Pointer to another keyword entry with the same hash. */
 /*ref*/struct TPPFile    *k_macro;    /*< [0..1] Macro currently associated with this keyword. */
 struct TPPRareKeyword    *k_rare;     /*< [0..1][owned] Rare keyword data. */
 TPP(tok_t)                k_id;       /*< [const] Unique token ID associated with this keyword. */
 size_t                    k_size;     /*< [const] Size of the keyword (in characters). */
 TPP(hash_t)               k_hash;     /*< [const] The hash-value of the keyword. */
 char                      k_name[TPP_SYMARRAY_SIZE]; /*< [const][k_size] name of this keyword (HINT: doesn't contain unescaped linefeeds). */
 //char                    k_zero;     /*< [const][== 0] Ensure ZERO-termination of the keyword name. */
};
#define TPPKeyword_ISDEFINED(self) ((self)->k_macro != NULL || TPP_ISBUILTINMACRO((self)->k_id))
#define TPPKeyword_MAKERARE(self) \
 ((self)->k_rare || ((self)->k_rare = (struct TPPRareKeyword *)\
   calloc(1,sizeof(struct TPPRareKeyword))) != NULL)

struct TPPKeywordMap {
 size_t              km_entryc;  /*< Amount of keyword entries stored. */
 size_t              km_bucketc; /*< Used amount of buckets. */
 struct TPPKeyword **km_bucketv; /*< [0..1][owned][0..km_bucketc][owned]
                                  *   Resizeable keyword hash-map vector. */
};
/* When this evaluates to true, TPP attempts to rehash the keyword map to 'km_entryc' entries. */
#define TPPKeywordMap_SHOULDHASH(self) \
 ((self)->km_entryc >= (self)->km_bucketc*2)

struct TPPToken {
        TPP(tok_t)         t_id;    /*< The symbol/keyword ID of this token. */
        unsigned long      t_num;   /*< The token number (incremented every time a new token is yielded). */
 /*ref*/struct TPPFile    *t_file;  /*< [1..1] File associated with this token. */
        char              *t_begin; /*< [1..1][<= t_end] Token text start pointer. */
        char              *t_end;   /*< [1..1][>= t_begin] Token text end pointer. */
        struct TPPKeyword *t_kwd;   /*< [0..1] Set when 't_id' is a keyword (WARNING: Not always updated during yield; check 'TPP_ISKEYWORD(t_id)' before using). */
};

/* Returns the top-level source locations (in-macro & everything)
 * NOTE: These are _not_ what you're probably looking for.
 *       You probably expect these to act like __FILE__ and __LINE__,
 *       but instead they will show the true source locations where
 *       the current token originates from (e.g.: from a macro definition.)
 *    >> To get information about the source file you must walk the
 *       current token's t_file->f_prev->... chain until you reach
 *       a text file. Then, taking that file, use it and its f_pos
 *       pointers to figure out what you actually want to know.
 */
#define TPPLexer_TRUE_FILE(plength) TPPFile_Filename(TPPLexer_Current->l_token.t_file,plength)
#define TPPLexer_TRUE_LINE()        TPPFile_LineAt(TPPLexer_Current->l_token.t_file,TPPLexer_Current->l_token.t_begin)
#define TPPLexer_TRUE_COLUMN()      TPPFile_ColumnAt(TPPLexer_Current->l_token.t_file,TPPLexer_Current->l_token.t_begin)

//////////////////////////////////////////////////////////////////////////
// Returns the top-most text file associated with the current lexer.
// NOTE: This function never returns NULL
TPPFUN struct TPPFile *TPPLexer_Textfile(void);
TPPFUN struct TPPFile *TPPLexer_Basefile(void);

#define TPPLexer_FILE(plength)     TPPFile_Filename(TPPLexer_Textfile(),plength)
#define TPPLexer_BASEFILE(plength) TPPFile_Filename(TPPLexer_Basefile(),plength)
TPP_LOCAL int TPPLexer_LINE(void) { struct TPPFile *f = TPPLexer_Textfile(); return TPPFile_LineAt(f,f->f_pos); }
TPP_LOCAL int TPPLexer_COLUMN(void) { struct TPPFile *f = TPPLexer_Textfile(); return TPPFile_ColumnAt(f,f->f_pos); }


#define TPPLEXER_FLAG_NONE                  0x00000000
#define TPPLEXER_FLAG_WANTCOMMENTS          0x00000001 /*< Emit COMMENT tokens. */
#define TPPLEXER_FLAG_WANTSPACE             0x00000002 /*< Emit SPACE tokens. */
#define TPPLEXER_FLAG_WANTLF                0x00000004 /*< Emit LF tokens. */
#define TPPLEXER_FLAG_NO_SEEK_ON_EOB        0x00000008 /*< Don't seek the next chunk when the current one ends (instead, signal EOF). */
#define TPPLEXER_FLAG_NO_POP_ON_EOF         0x00000010 /*< Don't pop the top file when an EOF occurs. */
#define TPPLEXER_FLAG_KEEP_MACRO_WHITESPACE 0x00000020 /*< Keep whitespace tokens around the front and back of macros. */
#define TPPLEXER_FLAG_TERMINATE_STRING_LF   0x00000040 /*< Terminate character/string sequences when a linefeed is detected (also emit a warning in that case). */
#define TPPLEXER_FLAG_NO_MACROS             0x00000080 /*< Disable expansion of macros (user defined only; builtin must be disabled explicitly with 'TPPLEXER_FLAG_NO_BUILTIN_MACROS'). */
#define TPPLEXER_FLAG_NO_DIRECTIVES         0x00000100 /*< Disable evaluation of preprocessor directives. */
#define TPPLEXER_FLAG_ASM_COMMENTS          0x00000400 /*< Suppress warnings for unknown/invalid preprocessor directives. */
#define TPPLEXER_FLAG_NO_BUILTIN_MACROS     0x00000800 /*< When set, don't expand builtin macros (such as __FILE__ and __LINE__). */
#define TPPLEXER_FLAG_DIRECTIVE_NOOWN_LF    0x00001000 /*< Linefeeds terminating preprocessor directives are not part of those directives and are instead re-emit.
                                                        *  WARNING: Using this flag is not recommended, as a freshly defined macro will re-use
                                                        *           text from the file and set the first character of that linefeed to '\0'. */
#define TPPLEXER_FLAG_MESSAGE_LOCATION      0x00002000 /*< Print the file+line location in messages from '#pragma message'. */
#define TPPLEXER_FLAG_MESSAGE_NOLINEFEED    0x00004000 /*< Don't print a linefeed following the user-provided message in '#pragma message'. */
#define TPPLEXER_FLAG_NO_TILDETILDE         0x00008000 /*< Disable recognition of '~~' tokens. */
#define TPPLEXER_FLAG_NO_ROOFROOF           0x00010000 /*< Disable recognition of '^^' tokens. */
#define TPPLEXER_FLAG_NO_COLLONCOLLON       0x00020000 /*< Disable recognition of '::' tokens. */
#define TPPLEXER_FLAG_INCLUDESTRING         0x00040000 /*< Parse strings as #include strings (without \-escape sequences). */
#define TPPLEXER_FLAG_KEEP_ARG_WHITESPACE   0x00080000 /*< When set, keep whitespace surrounding macro arguments. */
#define TPPLEXER_FLAG_MSVC_MESSAGEFORMAT    0x01000000 /*< Use msvc's file+line format '%s(%d,%d) : ' instead of GCC's '%s:%d:%d: '. */
#define TPPLEXER_FLAG_RANDOM_INITIALIZED    0x20000000 /*< Set when rand() has been initialized. */
#define TPPLEXER_FLAG_NO_WARNINGS           0x40000000 /*< Don't emit warnings. */
#define TPPLEXER_FLAG_ERROR                 0x80000000 /*< When set, the lexer is in an error-state in which calls to yield() will return TOK_ERR. */
#define TPPLEXER_FLAG_MERGEMASK             0xff000000 /*< A mask of flags that are merged (or'd together) during popf(). */
#define TPPLEXER_FLAG_DEFAULT               0x00000000 /*< Default set of flags (suitable for use with most token-based compilers). */

#define TPPLEXER_EXTENSION_NONE             0x0000000000000000ull
#define TPPLEXER_EXTENSION_TRIGRAPHS        0x0000000000000001ull /*< [FEATURE] Recognize trigraph character sequences. */
#define TPPLEXER_EXTENSION_DIGRAPHS         0x0000000000000002ull /*< [FEATURE] Recognize digraph character sequences. */
#define TPPLEXER_EXTENSION_GCC_VA_ARGS      0x0000000000000004ull /*< Recognize gcc's '#define foo(args...)' varargs syntax. */
#define TPPLEXER_EXTENSION_GCC_VA_COMMA     0x0000000000000008ull /*< Recognize gcc's ', ## __VA_ARGS__' syntax as '__VA_COMMA__' alternative. */
#define TPPLEXER_EXTENSION_GCC_IFELSE       0x0000000000000010ull /*< Recognize 'foo ? : 42' as alias for 'foo ? foo : 42'. */
#define TPPLEXER_EXTENSION_VA_COMMA         0x0000000000000020ull /*< Recognize '__VA_COMMA__' in variadic macros. */
#define TPPLEXER_EXTENSION_VA_NARGS         0x0000000000000040ull /*< Recognize '__VA_NARGS__' in variadic macros. */
#define TPPLEXER_EXTENSION_STR_E            0x0000000000000080ull /*< Recognize '\e' as alias for '\033' in strings/characters. */
#define TPPLEXER_EXTENSION_ALTMAC           0x0000000000000100ull /*< Recognize additional function-style macros: '[...]', '{...}' and '<...>'. */
#define TPPLEXER_EXTENSION_RECMAC           0x0000000000000200ull /*< Newly defined macros functions are allowed to recursively self-expand (This flag is copied into 'TPP_MACROFILE_FLAG_FUNC_SELFEXPAND' when defining new macros). */
#define TPPLEXER_EXTENSION_BININTEGRAL      0x0000000000000400ull /*< Allow the '0b' prefix in integral constants for binary values. */
#define TPPLEXER_EXTENSION_MSVC_PRAGMA      0x0000000000000800ull /*< Enable the use of __pragma(x) as alias for _Pragma(#x) (visual-c style). */
#define TPPLEXER_EXTENSION_STRINGOPS        0x0000000000001000ull /*< Enable special (non-c) operands for operating with strings in constant expressions (string compare, sub-string, string-length). */
#define TPPLEXER_EXTENSION_BASEFILE         0x0000000000002000ull /*< Enable the built-in macro '__BASE_FILE__'. */
#define TPPLEXER_EXTENSION_HASH_AT          0x0000000000004000ull /*< Enable support for "#@" in function macros to generate the character-representation of an argument. */
#define TPPLEXER_EXTENSION_HASH_XCLAIM      0x0000000000008000ull /*< Enable support for "#!" in function macros to reference an argument without expansion. */
#define TPPLEXER_EXTENSION_WARNING          0x0000000000010000ull /*< Recognize the #warning directive. */
#define TPPLEXER_EXTENSION_SHEBANG          0x0000000000020000ull /*< Ignore shebang-style directives ("#!..."). */
#define TPPLEXER_EXTENSION_INCLUDE_NEXT     0x0000000000040000ull /*< Recognize gcc's #include_next directive. */
#define TPPLEXER_EXTENSION_IMPORT           0x0000000000080000ull /*< Recognize #import directives. */
#define TPPLEXER_EXTENSION_INCLUDE_LEVEL    0x0000000000100000ull /*< Recognize __INCLUDE_LEVEL__ & __INCLUDE_DEPTH__ preprocessor macros. */
#define TPPLEXER_EXTENSION_COUNTER          0x0000000000200000ull /*< Recognize the __COUNTER__ preprocessor macro. */
#define TPPLEXER_EXTENSION_CLANG_FEATURES   0x0000000000400000ull /*< Recognize clang's __has_(feature|extension|attribute|...) and __is_(deprecated|{builtin_}identifier) special macros. */
#define TPPLEXER_EXTENSION_HAS_INCLUDE      0x0000000000800000ull /*< Recognize clang's __has_{next_}include special macros. */
#define TPPLEXER_EXTENSION_LXOR             0x0000000001000000ull /*< Allow the use of '^^' in expressions as logical xor. */
#define TPPLEXER_EXTENSION_DATEUTILS        0x0000000002000000ull /*< Recognize a set of macros to expand to integral parts of the current date. */
#define TPPLEXER_EXTENSION_TIMEUTILS        0x0000000004000000ull /*< Recognize a set of macros to expand to integral parts of the current time. */
#define TPPLEXER_EXTENSION_TIMESTAMP        0x0000000008000000ull /*< Recognize the '__TIMESTAMP__' preprocessor macro. */
#define TPPLEXER_EXTENSION_TPP_EVAL         0x0000000010000000ull /*< Enable the '__TPP_EVAL(...)' builtin macro. */
#define TPPLEXER_EXTENSION_TPP_UNIQUE       0x0000000020000000ull /*< Enable the '__TPP_UNIQUE(...)' builtin macro. */
#define TPPLEXER_EXTENSION_TPP_LOAD_FILE    0x0000000040000000ull /*< Enable the '__TPP_LOAD_FILE(...)' builtin macro. */
#define TPPLEXER_EXTENSION_TPP_COUNTER      0x0000000080000000ull /*< Enable the '__TPP_COUNTER(...)' builtin macro. */
#define TPPLEXER_EXTENSION_TPP_RANDOM       0x0000000100000000ull /*< Enable the '__TPP_RANDOM(...)' builtin macro. */
#define TPPLEXER_EXTENSION_TPP_STR_DECOMPILE 0x0000000200000000ull/*< Enable the '__TPP_STR_DECOMPILE(...)' builtin macro. */
#define TPPLEXER_EXTENSION_TPP_STR_PACK     0x0000000400000000ull /*< Enable the '__TPP_STR_PACK(...)' builtin macro. */
#define TPPLEXER_EXTENSION_DEFAULT          0xffffffffffffffffull /*< Enable all extensions. */

struct TPPLexer {
 struct TPPToken       l_token;      /*< The current token. */
 struct TPPFile       *l_eob_file;   /*< [0..1] When non-NULL prevent seek_on_eob when this file is atop the stack.
                                      *  >> NOTE: This does the same as 'TPPLEXER_FLAG_NO_SEEK_ON_EOB', but only for a specific file.
                                      *  >> Using this, you can restrict the lexer to a sub-space of file, allowing
                                      *     you to safely parse data until the current chunk of a given file ends. */
 struct TPPFile       *l_eof_file;   /*< [0..1] Similar to 'l_eob_file', but used for end-of-file instead. */
 uint32_t              l_flags;      /*< A set of 'TPPLEXER_FLAG_*' */
 uint64_t              l_extensions; /*< Enabled preprocessor features/extensions (A set of 'TPPLEXER_EXTENSION_*'). */
 struct TPPKeywordMap  l_keywords;   /*< Hash-map used to map keyword strings to their ids. */
 struct TPPIncludeList l_syspaths;   /*< List of paths searched when looking for system #include files. */
 size_t                l_limit_mrec; /*< Limit for how often a macro may recursively expand into itself. */
 size_t                l_limit_incl; /*< Limit for how often the same text file may exist on the #include stack. */
 tok_t                 l_noerror;    /*< Old token ID before 'TPPLEXER_FLAG_ERROR' was set. */
 int_t                 l_counter;    /*< Value returned the next time '__COUNTER__' is expanded (Initialized to ZERO(0)). */
 struct TPPIfdefStack  l_ifdef;      /*< #ifdef stack. */
};
#define TPPLEXER_DEFAULT_LIMIT_MREC 512 /* Even when generated text differs from previous version, don't allow more self-recursion per macro than this. */
#define TPPLEXER_DEFAULT_LIMIT_INCL 64  /* User attempts to #include a file more often that file will fail with an error message. */


#if TPP_CONFIG_ONELEXER
#define TPPLexer_Current  (&TPPLexer_Global)
TPPFUN struct TPPLexer TPPLexer_Global;
#else
/* [1..1] The currently selected lexer
 * >> When NULL, only certain parts of TPP can work without problems. */
TPPFUN struct TPPLexer *TPPLexer_Current;
#endif

//////////////////////////////////////////////////////////////////////////
// Initialize/Finalize the given TPP Lexer object.
// @return: 1: Successfully initialized the given lexer.
// @return: 0: Not enough available memory to setup builtin keywords.
TPPFUN int  TPPLexer_Init(struct TPPLexer *__restrict self);
TPPFUN void TPPLexer_Quit(struct TPPLexer *__restrict self);

//////////////////////////////////////////////////////////////////////////
// Searches the cache and opens a new file if not found.
// WARNING: If the caller intends to push the file onto the #include-stack,
//          additional steps must be taken when the file was already
//          located on the stack (in which case another stream must be opened,
//          and a file that is not cached must be pushed onto the #include-stack).
// WARNING: This function may modify the given 'filename..filename_size+1' area of memory.
// @param: pkeyword_entry: When non-NULL, the keyword entry associated with the filename is stored here.
// @return: * :   A pointer to the already-chached file (WARNING: This is not a reference)
// @return: NULL: File not found.
TPPFUN struct TPPFile *TPPLexer_OpenFile(int mode, char *filename, size_t filename_size,
                                         struct TPPKeyword **pkeyword_entry);
#define TPPLEXER_OPENFILE_MODE_NORMAL   0 /* Normal open (simply pass the given filename to TPPFile_Open, but still sanitize and cache the filename) */
#define TPPLEXER_OPENFILE_MODE_RELATIVE 1 /* #include "foo.h" (Search for the file relative to the path of every text file on the #include-stack in reverse. - If this fails, search in system folders). */
#define TPPLEXER_OPENFILE_MODE_SYSTEM   2 /* #include <stdlib.h> (Search through system folders usually specified with '-I' on the commandline). */
#define TPPLEXER_OPENFILE_FLAG_NEXT     4 /* FLAG: Only open a file not already part of the #include-stack
                                           * WARNING: May not be used for 'TPPLEXER_OPENFILE_MODE_NORMAL'! */

//////////////////////////////////////////////////////////////////////////
// Lookup or create a keyword entry for the given name.
// HINT: TPP also caches files inside the keyword hashmap.
// @return: NULL: [create_missing]  Not enough available memory.
// @return: NULL: [!create_missing] No keyword with the given name.
// @return: * :    The keyword entry associated with the given name.
TPPFUN struct TPPKeyword *
TPPLexer_LookupKeyword(char const *name, size_t namelen,
                       int create_missing);

//////////////////////////////////////////////////////////////////////////
// Looks up a keyword, given its ID
// WARNING: This function is _extremely_ slow and should only
//          be used if there is absolutely no other choice.
TPPFUN struct TPPKeyword *TPPLexer_LookupKeywordID(TPP(tok_t) id);

//////////////////////////////////////////////////////////////////////////
// Adds the given path to the list of system #include paths.
// WARNING: This function will modify the given path.
// WARNING: Be careful with absolute vs. relative paths!
//          TPP can not tell that they're the same and
//          '#pragma once' might break as a consequence!
//       >> As a solution, _always_ use either absolute
//          or relative paths for the same file/path.
//         (This also goes for #include directives)
// @return: 0: Not enough available memory.
// @return: 1: The given path was successfully added.
// @return: 2: The given path had already been added before.
TPPFUN int TPPLexer_AddIncludePath(char *path, size_t pathsize);

//////////////////////////////////////////////////////////////////////////
// Similar to 'TPPLexer_Yield' and used to implement it, but
// doesn't expand macros or execute preprocessor directives.
TPPFUN tok_t TPPLexer_YieldRaw(void);

//////////////////////////////////////////////////////////////////////////
// Similar to 'TPPLexer_Yield' and used to implement it, but
// doesn't expand macros.
TPPFUN tok_t TPPLexer_YieldPP(void);

//////////////////////////////////////////////////////////////////////////
// Advance the selected lexer by one token and return the id of the new one.
// HINT: Returns ZERO(0) if the true EOF was reached.
TPPFUN tok_t TPPLexer_Yield(void);

//////////////////////////////////////////////////////////////////////////
// Emit a given warning.
// @return: 0: The warning was critical (TPPLexer_SetErr() was called and you should try to abort)
// @return: 1: The warning was ignored, suppressed or simply non-fatal.
TPPFUN int TPPLexer_Warn(int wnum, ...);

//////////////////////////////////////////////////////////////////////////
// Set the lexer into an error-state in which
// calls to to any yield function return TOK_ERR.
// >> Called when an unrecoverable error occurrs.
// HINT: To recover after such an event, 'TPPLexer_UnsetErr()' should be called.
#define TPPLexer_SetErr() \
 ((TPPLexer_Current->l_flags&TPPLEXER_FLAG_ERROR) ? 0 : \
  (TPPLexer_Current->l_flags |= TPPLEXER_FLAG_ERROR,\
   TPPLexer_Current->l_noerror = TPPLexer_Current->l_token.t_id,\
   TPPLexer_Current->l_token.t_id = TPP(TOK_ERR),1))
#define TPPLexer_UnsetErr() \
 ((TPPLexer_Current->l_flags&TPPLEXER_FLAG_ERROR) ? \
  (TPPLexer_Current->l_flags &= ~TPPLEXER_FLAG_ERROR,\
   TPPLexer_Current->l_token.t_id = TPPLexer_Current->l_noerror,\
   1) : 0)


//////////////////////////////////////////////////////////////////////////
// Called after a given macro was referenced and
// the associated parenthesis was located.
// Expected to be called when the current token is the macro's name,
// this function will parse the macro's argument list remainder of the macro's
// argument list (including the terminating parenthesis), before 
// pushing a new file describing the expanded macro onto the include stack.
// @return: 0: A hard error occurred (such as not enough memory)
// @return: 1: Successfully expanded the macro.
// @return: 2: Missing argument list or illegal recursive expansion.
TPPFUN int TPPLexer_ExpandFunctionMacro(struct TPPFile *__restrict macro);


struct TPPConst {
#define TPP_CONST_INTEGRAL 0
#define TPP_CONST_STRING   1
 unsigned int c_kind; /*< Constant kind (One of 'TPP_CONST_*'). */
 union {
         TPP(int_t)        c_int;    /*< [TPP_CONST_INTEGRAL] Integral. */
  /*ref*/struct TPPString *c_string; /*< [TPP_CONST_STRING][1..1] String. */
 } c_data;
};
#define TPPConst_IsTrue(self) \
 ((self)->c_kind == TPP_CONST_STRING\
   ? ((self)->c_data.c_string->s_size != 0)\
   : ((self)->c_data.c_int != 0))
#define TPPConst_ToBool(self) \
do{\
 if ((self)->c_kind == TPP_CONST_STRING) {\
  int c_newval = (self)->c_data.c_string->s_size != 0;\
  TPPString_Decref((self)->c_data.c_string);\
  (self)->c_data.c_int = (TPP(int_t))c_newval;\
  (self)->c_kind = TPP_CONST_INTEGRAL;\
 } else {\
  (self)->c_data.c_int = !!(self)->c_data.c_int;\
 }\
}while(TPP_MACRO_FALSE)
#define TPPConst_ToInt(self) \
do{\
 if ((self)->c_kind == TPP_CONST_STRING) {\
  int c_newval = (self)->c_data.c_string->s_size != 0;\
  TPPString_Decref((self)->c_data.c_string);\
  (self)->c_data.c_int = (TPP(int_t))c_newval;\
  (self)->c_kind = TPP_CONST_INTEGRAL;\
 }\
}while(TPP_MACRO_FALSE)

#define TPPConst_ZERO(self) \
 (void)((self)->c_kind = TPP_CONST_INTEGRAL,\
        (self)->c_data.c_int = 0)
#define TPPConst_Quit(self) \
 (void)((self)->c_kind != TPP_CONST_STRING || \
        (TPPString_Decref((self)->c_data.c_string),1))

//////////////////////////////////////////////////////////////////////////
// Convert a given preprocessor constant into a string:
// >> The returned string can be used to create a file
//    that represents the constant's value as loaded
//    by the '__TPP_EVAL' extension.
// NOTE: If 'self' is a string, it will be escaped.
// @return: NULL: Not enough available memory.
TPPFUN /*ref*/struct TPPString *
TPPConst_ToString(struct TPPConst const *__restrict self);

//////////////////////////////////////////////////////////////////////////
// Evaluate a constant expression as found after '#if' or in '__TPP_EVAL(...)'
// NOTE: If 'result' is NULL, the expression's is
//       parsed, yet warnings will not be emit.
// NOTE: Expects the current token to point to the first one part of the expression.
//       Upon exit, that token will point to the first one past the expression.
// NOTE: Evaluation is compatible with standard c rules, but
//       ',' operators are not parsed at the highest level.
// @return: 1: Successfully parsed an expression
// @return: 0: An error occurred.
TPPFUN int TPPLexer_Eval(struct TPPConst *result);


//////////////////////////////////////////////////////////////////////////
// Parse the data block of a pragma.
// @param: endat: The id of a token that symbolically represents the end
//                of the token (usually either ')', '\n' or '\0')
// @return: 0: Unknown/errorous pragma.
// @return: 1: Successfully parsed the given pragma.
TPPFUN int TPPLexer_ParsePragma(TPP(tok_t) endat);


//////////////////////////////////////////////////////////////////////////
// Parse an evaluate a string from the current lexer.
// NOTE: This functions expects the current token to be a string token
//       and will continue parsing and concat-ing strings until the
//       next non-string token.
// @return: * :   A reference to the unescaped string that was parsed.
// @return: NULL: A lexer error occurred (TPPLexer_SetErr() was set).
TPPFUN /*ref*/struct TPPString *TPPLexer_ParseString(void);


#if TPP_CONFIG_ONELEXER
#define TPP_INITIALIZE() TPPLexer_Init(&TPPLexer_Global)
#define TPP_FINALIZE()   TPPLexer_Quit(&TPPLexer_Global)
#else
#define TPP_INITIALIZE() \
 (TPPLexer_Current = (struct TPPLexer *)malloc(sizeof(struct TPPLexer)),\
  TPPLexer_Current ? (TPPLexer_Init(TPPLexer_Current) ? 1 : (free(TPPLexer_Current),0)) : 0)
#define TPP_FINALIZE()  (TPPLexer_Quit(TPPLexer_Current),free(TPPLexer_Current))
#endif


#ifdef TPP_NAMESPACE_DEFINED
#undef TPP_NAMESPACE_DEFINED
#undef TPP
#endif

#ifdef __cplusplus
}
#endif


#endif /* !GUARD_TPP_H */

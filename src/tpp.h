/* Copyright (c) 2017-2025 Griefer@Work                                       *
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
 *    in a product, an acknowledgement (see the following) in the product     *
 *    documentation is required:                                              *
 *    Portions Copyright (c) 2017-2025 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef GUARD_TPP_H
#define GUARD_TPP_H 1

/* TPP Configuration options. */
/* #define TPP_CONFIG_DEBUG 0/1 */
/* #define TPP_CONFIG_ONELEXER 0/1 */
/* #define TPP_CONFIG_MINMACRO 0/1 */
/* #define TPP_CONFIG_GCCFUNC 0/1 */
/* #define TPP_CONFIG_MINGCCFUNC 0/1 */
/* #define TPP_UNESCAPE_MAXCHAR 1/2/4/8 */
/* #define TPP_UNESCAPE_ENDIAN 1234/4321 */
/* #define TPP_BYTEORDER 1234/4321 */
/* #define TPP_CONFIG_EXPORT 0/1 */
/* #define TPP_CONFIG_INLINE_SETERR */
/* #define TPP_CONFIG_USERSTREAMS */
/* #define TPP_CONFIG_LOCKED_KEYWORDS 0/1 */
/* #define TPP_CONFIG_RAW_STRING_LITERALS 0/1 */
/* #define TPP_CONFIG_FASTSTARTUP_KEYWORD_FLAGS 0/1 */
/* #define TPP_CONFIG_NONBLOCKING_IO */
/* #define TPP_CONFIG_NO_PRECACHE_TEXTLINES */
/* #   define TPP_USERSTREAM_TYPE                               <type> // typedef ... stream_t; */
/* #   define TPP_USERSTREAM_INVALID                            <expr> // static stream_t const TPP_STREAM_INVALID = ...; */
/* #   define TPP_USERSTREAM_FOPEN(filename)                    <expr> // stream_t *TPP_USERSTREAM_FCLOSE(char const *__restrict filename) { ... } */
/* #   define TPP_USERSTREAM_FCLOSE(stream)                     <expr> // void TPP_USERSTREAM_FCLOSE(stream_t stream) { ... } */
/* #   define TPP_USERSTREAM_FREAD(stream,buf,bufsize)          <expr> // size_t TPP_USERSTREAM_FREAD(stream_t stream, void *__restrict buffer, size_t bufsize) { ... } */
/* #   define TPP_USERSTREAM_FREAD_NONBLOCK(stream,buf,bufsize) <expr> // size_t TPP_USERSTREAM_FREAD_NONBLOCK(stream_t stream, void *__restrict buffer, size_t bufsize) { ... } */
/* NOTE: When `TPP_CONFIG_SET_API_ERROR' is enabled and `TPP_USERSTREAM_FREAD()' returns 0
 *       with the `TPPLEXER_FLAG_ERROR' flag set, `TPPFile_NextChunk()' will return -1. */
/* Static callback configuration. */
/* #define TPP_CONFIG_CALLBACK_WARNING          x // int x(int wnum, ...) { ... } -- A user-replacement for `TPPLexer_Warn' */
/* #define TPP_CONFIG_CALLBACK_PARSE_PRAGMA     x // int TPPCALL x(void) { ... } */
/* #define TPP_CONFIG_CALLBACK_PARSE_PRAGMA_GCC x // int TPPCALL x(void) { ... } */
/* #define TPP_CONFIG_CALLBACK_INS_COMMENT      x // int TPPCALL x(struct TPPString *__restrict comment) { ... } */
/* #define TPP_CONFIG_CALLBACK_NEW_TEXTFILE     x // int TPPCALL x(struct TPPFile *__restrict file, int is_system_header) { ... } */
/* #define TPP_CONFIG_CALLBACK_UNKNOWN_FILE     x // struct TPPFile *TPPCALL x(int mode, char *__restrict filename, size_t filename_size, struct TPPKeyword **pkeyword_entry) */
/* Disable support for certain callbacks. */
/* #define TPP_CONFIG_NO_CALLBACK_PARSE_PRAGMA     1 */
/* #define TPP_CONFIG_NO_CALLBACK_PARSE_PRAGMA_GCC 1 */
/* #define TPP_CONFIG_NO_CALLBACK_INS_COMMENT      1 */
/* #define TPP_CONFIG_NO_CALLBACK_NEW_TEXTFILE     1 */
/* #define TPP_CONFIG_NO_CALLBACK_UNKNOWN_FILE     1 */
/* When defined, api functions will set `TPPLEXER_FLAG_ERROR' upon error.
 * Function that comply with this explicitly state this in their documentation
 * by adding a `(TPP_CONFIG_SET_API_ERROR)' to documentation of a context in
 * which this behavior is performed. */
/* #define TPP_CONFIG_SET_API_ERROR                1 */
/* An optional callback that is invoked when an API is caused due to a bad allocation.
 * NOTE: The callback is only executed when the `TPPLexer_SetErr()' returned non-zero. */
/* #define TPP_CONFIG_SET_API_ERROR_BADALLOC       x // void x(size_t n_bytes); */

/* Statically defined TPP features (define as 0/1 to statically define).
 * NOTE: *_DEFAULT can be defined the same way to state how the
 *       extension should be pre-configured when chosen at runtime. */
/* #define TPP_CONFIG_FEATURE_TRIGRAPHS           1 = 0 */
/* #define TPP_CONFIG_FEATURE_DIGRAPHS            1 = 1 */
/* #define TPP_CONFIG_EXTENSION_GCC_VA_ARGS       1 = 1 */
/* #define TPP_CONFIG_EXTENSION_GCC_VA_COMMA      1 = 1 */
/* #define TPP_CONFIG_EXTENSION_GCC_IFELSE        1 = 1 */
/* #define TPP_CONFIG_EXTENSION_VA_COMMA          1 = 1 */
/* #define TPP_CONFIG_EXTENSION_VA_NARGS          1 = 1 */
/* #define TPP_CONFIG_EXTENSION_VA_OPT            1 = 1 */
/* #define TPP_CONFIG_EXTENSION_VA_ARGS           1 = 1 */
/* #define TPP_CONFIG_EXTENSION_STR_E             1 = 1 */
/* #define TPP_CONFIG_EXTENSION_ALTMAC            1 = 1 */
/* #define TPP_CONFIG_EXTENSION_RECMAC            1 = 0 */
/* #define TPP_CONFIG_EXTENSION_ARGSPACE          1 = 0 */
/* #define TPP_CONFIG_EXTENSION_BININTEGRAL       1 = 1 */
/* #define TPP_CONFIG_EXTENSION_MSVC_PRAGMA       1 = 1 */
/* #define TPP_CONFIG_EXTENSION_STRINGOPS         1 = 1 */
/* #define TPP_CONFIG_EXTENSION_HASH_AT           1 = 1 */
/* #define TPP_CONFIG_EXTENSION_HASH_XCLAIM       1 = 1 */
/* #define TPP_CONFIG_EXTENSION_WARNING           1 = 1 */
/* #define TPP_CONFIG_EXTENSION_SHEBANG           1 = 1 */
/* #define TPP_CONFIG_EXTENSION_INCLUDE_NEXT      1 = 1 */
/* #define TPP_CONFIG_EXTENSION_IMPORT            1 = 1 */
/* #define TPP_CONFIG_EXTENSION_IDENT_SCCS        1 = 1 */
/* #define TPP_CONFIG_EXTENSION_BASEFILE          1 = 1 */
/* #define TPP_CONFIG_EXTENSION_INCLUDE_LEVEL     1 = 1 */
/* #define TPP_CONFIG_EXTENSION_COUNTER           1 = 1 */
/* #define TPP_CONFIG_EXTENSION_CLANG_FEATURES    1 = 1 */
/* #define TPP_CONFIG_EXTENSION_HAS_INCLUDE       1 = 1 */
/* #define TPP_CONFIG_EXTENSION_LXOR              1 = 1 */
/* #define TPP_CONFIG_EXTENSION_MULTICHAR_CONST   1 = 1 */
/* #define TPP_CONFIG_EXTENSION_DATEUTILS         1 = 1 */
/* #define TPP_CONFIG_EXTENSION_TIMEUTILS         1 = 1 */
/* #define TPP_CONFIG_EXTENSION_TIMESTAMP         1 = 1 */
/* #define TPP_CONFIG_EXTENSION_COLUMN            1 = 1 */
/* #define TPP_CONFIG_EXTENSION_TPP_EVAL          1 = 1 */
/* #define TPP_CONFIG_EXTENSION_TPP_UNIQUE        1 = 1 */
/* #define TPP_CONFIG_EXTENSION_TPP_LOAD_FILE     1 = 1 */
/* #define TPP_CONFIG_EXTENSION_TPP_COUNTER       1 = 1 */
/* #define TPP_CONFIG_EXTENSION_TPP_RANDOM        1 = 1 */
/* #define TPP_CONFIG_EXTENSION_TPP_STR_DECOMPILE 1 = 1 */
/* #define TPP_CONFIG_EXTENSION_TPP_STR_SUBSTR    1 = 1 */
/* #define TPP_CONFIG_EXTENSION_TPP_STR_SIZE      1 = 1 */
/* #define TPP_CONFIG_EXTENSION_TPP_STR_PACK      1 = 1 */
/* #define TPP_CONFIG_EXTENSION_TPP_COUNT_TOKENS  1 = 1 */
/* #define TPP_CONFIG_EXTENSION_TPP_IDENTIFIER    1 = 1 */
/* #define TPP_CONFIG_EXTENSION_DOLLAR_IS_ALPHA   1 = 1 */
/* #define TPP_CONFIG_EXTENSION_ASSERTIONS        1 = 1 */
/* #define TPP_CONFIG_EXTENSION_CANONICAL_HEADERS 1 = 1 */
/* #define TPP_CONFIG_EXTENSION_EXT_ARE_FEATURES  1 = 1 */
/* #define TPP_CONFIG_EXTENSION_MSVC_FIXED_INT    1 = 1 */
/* #define TPP_CONFIG_EXTENSION_NO_EXPAND_DEFINED 1 = 1 */
/* #define TPP_CONFIG_EXTENSION_IFELSE_IN_EXPR    1 = 1 */
/* #define TPP_CONFIG_EXTENSION_EXTENDED_IDENTS   1 = 1 */
/* #define TPP_CONFIG_EXTENSION_TRADITIONAL_MACRO 1 = 0 */


/* TPP Configuration. (Extensions can be enabled/disabled at runtime). */
#ifndef TPP_CONFIG_DEBUG
#ifdef NDEBUG
#   define TPP_CONFIG_DEBUG      0
#else /* NDEBUG */
#   define TPP_CONFIG_DEBUG      1
#endif /* !NDEBUG */
#endif /* !TPP_CONFIG_DEBUG */

#ifndef TPP_CONFIG_ONELEXER
/* Globally provide only one lexer (faster, but more restrictive). */
#define TPP_CONFIG_ONELEXER 1
#endif /* !TPP_CONFIG_ONELEXER */

#ifndef TPP_CONFIG_MINMACRO
/* When configured to non-zero, don't define builtin macro
 * describing the host platform, cpu or standard c-types.
 * >> Basically, disable `EXT_*_MACROS' extensions. */
#define TPP_CONFIG_MINMACRO 0
#endif /* !TPP_CONFIG_MINMACRO */

#ifndef TPP_CONFIG_GCCFUNC
/* Add builtin support for various GCC functions available in expressions. */
#define TPP_CONFIG_GCCFUNC 1
#endif /* !TPP_CONFIG_GCCFUNC */

#ifndef TPP_CONFIG_MINGCCFUNC
#define TPP_CONFIG_MINGCCFUNC 0
#endif /* !TPP_CONFIG_MINGCCFUNC */

/* Don't define dedicated keywords for keyword flags, but compare
 * keyword names at runtime, thus decreasing memory overhead and
 * reducing startup time, however slowing down `TPPKeyword_GetFlags()'. */
#ifndef TPP_CONFIG_FASTSTARTUP_KEYWORD_FLAGS
#define TPP_CONFIG_FASTSTARTUP_KEYWORD_FLAGS 1
#endif /* !TPP_CONFIG_FASTSTARTUP_KEYWORD_FLAGS */


#define TPP_PREPROCESSOR_VERSION 200 /* Preprocessor version. */
#define TPP_API_VERSION          200 /* Api version (Version of this api). */


#undef TPP_CONFIG_NO_ASSERTIONS
#if defined(TPP_CONFIG_EXTENSION_ASSERTIONS) && !TPP_CONFIG_EXTENSION_ASSERTIONS
#define TPP_CONFIG_NO_ASSERTIONS 1
#endif /* !TPP_CONFIG_EXTENSION_ASSERTIONS */


/* WARNING: This new version of TPP uses global variables that prevent it from
 *          being fully thread-safe. - For that reason, you must either provide
 *          your own lock when attempting to use TPP with multiple threads, as
 *          well as having to compile with `-DTPP_CONFIG_ONELEXER=0' and exchanging
 *          the current TPP lexer whenever switching between threads. */


//////////////////////////////////////////////////////////////////////////
// Supported features/extension
//////////////////////////////////////////////////////////////////////////
//SYNTAX:
// [//]           //Comment                     /* Recognize c++-style comments. */
// [/**/]         /*Comment*/                   /* Recognize c-style comments. */
// ["#"]          #Comment                      /* Recognize assembler-style comments (WARNING: May create ambiguity with preprocessor directives). */
// ["??="]        ??=define foo bar             /* Recognize and interprete trigraph character sequences. */
// ["%:"]         %:define foo bar              /* Recognize and interprete digraph character sequences. */
// ["foo"[:-1]]   #if "foo"[1:] == "oo"         /* Use strings in preprocessor expressions, and support python-style sub-string or character access. */
// [defined(foo)] #if defined(foo)              /* Recognize `defined' in preprocessor expressions. */
// [foo ?: bar]   #if foo ?: bar                /* Recognize gcc's `a ?: b' as alias for `a ? a : b'. */
// ["\e"]         printf("\e[10mHello\e[0m\n"); /* Recognize `\e' in strings as alias for `\33' (ESC). */
// ['abc']        int x = 'abc';                /* Recognize multi-character char-constants. */
//
//PREPROCESSOR DIRECTIVES:
// [#]             #[LF|EOF]         /* Ignore empty (NULL) directives. */
// [#!]            #!/bin/bash       /* Ignore shebang-style script arguments. */
// [#if]           #if foobar        /* Recognize all types of STD-C conditional preprocessor blocks (#if,#ifdef,#ifndef,#elif,#else,#endif). */
// [#pragma]       #pragma once      /* Recognize #pragma preprocessor directives (unknown pragmas are re-emit). */
// [#define]       #define foo 42    /* Recognize #define used to declare new macros. */
// [#undef]        #undef foo        /* Recognize #undef used to undefine user macros. */
// [#include]      #include ...      /* Recognize #include used to include other files (follows system/caller/CWD-relative path rules). */
// [#include_next] #include_next ... /* Recognize #include_next used to include the next file not already being included. */
// [#import]       #import ...       /* Recognize #import used to include files only once (so long as only everything uses #import to include them). */
// [#line]         #line 42 "foo"    /* Recognize #line used to set the next line number, as well as a custom file name. */
// [#error]        #error "nope"     /* Recognize #error used to emit a preprocessor error. */
// [#warning]      #warning "$h1t"   /* Recognize #warning used to emit a preprocessor warning. */
//
//USER-DEFINED MACROS:
// [#str]         #define str(x)           #x                              /* STD-C macro argument stringification. */
// [c##at]        #define cat(a,b)         a##b                            /* STD-C macro argument concat. */
// [__VA_ARGS__]  #define foo(...)         __VA_ARGS__                     /* STD-C varargs macros. */
// [#@chr]        #define chr(x)           #@x                             /* macro argument charification. */
// [args...]      #define bar(args...)     args                            /* GCC varargs macros. */
// [,##args]      #define baz(fmt,args...) printf(fmt,##args)              /* GCC va_comma. */
// [__VA_COMMA__] #define liz(fmt,args...) printf(fmt __VA_COMMA__ args)   /* TPP __VA_COMMA__. */
// [__VA_NARGS__] #define sum(args...)     _sum##__VA_NARGS__(__VA_ARGS__) /* Expands to an integral representation of the number of variadic arguments (_very_ useful for overloading macros by argument count). */
// [#!noexp]      #define noexp(x)         #!x                             /* Insert a macro argument without expansion (Don't say it doesn't work unless you _really_ understand what it's supposed to do!) (Used for perfect forwarding of macro arguments). */
// [<recursion>]  #define inc(x)           inc(x+1)                        /* Recursively allow macros to expand themself (Must be enabled using pragmas; Inconjunction with __TPP_EVAL, very useful for creating loops). */
//
//BUILTIN MACROS:
// [__FILE__]            printf("%s\n",__FILE__);                    /* Expand to the string representation of the current file. */
// [__LINE__]            printf("%d\n",__LINE__);                    /* Expand to the integral representation of the current line. */
// [__TIME__]            printf("%s\n",__TIME__);                    /* Expand to the string representation of the current time. */
// [__DATE__]            printf("%s\n",__DATE__);                    /* Expand to the string representation of the current date. */
// [__BASE_FILE__]       printf("%s\n",__BASE_FILE__);               /* Expand to the name of the original source file used to startup the preprocessor. */
// [__INCLUDE_LEVEL__]   printf("%d\n",__INCLUDE_LEVEL__);           /* Expand to the integral representation of how many files away the original source file is (this counter starts at `0'). */
// [__COUNTER__]         printf("%d\n",__COUNTER__);                 /* Expand to the integral representation an integral that increments by 1 every time it is expanded (starts at `0'). */
// [__COLUMN__]          printf("%d\n",__COLUMN__);                  /* In the spirit of __FILE__ and __LINE__, return the currently effective column number. */
// [_Pragma]             _Pragma("once")                             /* STD-C style pragma with a string as argument (unknown pragmas are re-emit). */
// [__pragma]            __pragma(once)                              /* MSVC style pragma with the argument not being a string (unknown pragmas are re-emit). */
// [__TIME_*__]          printf("%d\n",__TIME_SEC__)                 /* Expand to the integral representation of the current `__TIME_SEC__', `__TIME_MIN__' or `__TIME_HOUR__'. */
// [__DATE_*__]          printf("%d\n",__DATE_DAY__)                 /* Expand to the integral representation of the current `__DATE_DAY__', `__DATE_WDAY__', `__DATE_YDAY__', `__DATE_MONTH__' or `__DATE_YEAR__'. */
// [__TPP_EVAL]          __TPP_EVAL(10+20)                           /* Evaluate an expression as used by `#if'. This macro expands to the string/decimal representation of that expression's value. */
// [__TPP_LOAD_FILE]     __TPP_LOAD_FILE(<stdlib.h>)                 /* Expand to the string representation of the unmodified contents of the given file. (NOTE: The file's name is a regular #include-string) */
// [__TPP_COUNTER]       __TPP_COUNTER(keyword)                      /* Similar to __COUNTER__, but instead of global, the current index increments individually for different given keywords. */
// [__TPP_RANDOM]        __TPP_RANDOM(count)|__TPP_RANDOM(begin,end) /* Expand to a random integral between `0..count-1' or `begin..end-1' (inclusive). */
// [__TPP_STR_DECOMPILE] __TPP_STR_DECOMPILE("foo bar foobar")       /* Re-parse the given string, yielding all tokens contained within (The example would expand to [foo][ ][bar][ ][foobar]). */
// [__TPP_STR_AT]        __TPP_STR_AT("foo",x,[y=1])                 /* Returns `y' characters from the given string, escaped and surrounded by `\'', starting at index `x'. */
// [__TPP_STR_SUBSTR]    __TPP_STR_SUBSTR("foo",x,[y=1])             /* Returns `y' characters from the given string, escaped and surrounded by `\"', starting at index `x'. */
// [__TPP_STR_PACK]      __TPP_STR_PACK(0x13 0x10 0x43)              /* Returns a string consisting of the string of packed integral expressions, where each expression describes the next character (The example is equivalent to "\x13\x10\x43"; aka. "\r\nC"). */
// [__TPP_STR_SIZE]      __TPP_STR_SIZE("foo")                       /* Returns the integral representation for the length of the given string (equivalent to `__TPP_EVAL(#(str))' and only kept for backwards-compatibility). */
// [__TPP_UNIQUE]        __TPP_UNIQUE(keyword)                       /* A unique integral number associated with `keyword', that remains consistent within the same token stream; new keywords have greater numbers. */
// [__TPP_COUNT_TOKENS]  __TPP_COUNT_TOKENS("->*")                   /* Expand to the integral representation of the number of tokens within the given string (NOTE: tokens inside the string are not macro-expanded). */
// [...]                 Various cpu-specific macros, such as `__i386__' or `__arm__'
// [...]                 Various system-specific macros, such as `_WIN32' or `__unix__'
// [...]                 Various GCC-style macros, such as `__SIZEOF_POINTER__' or `__INT32_C'
//
//PRAGMA EXTENSIONS:
// [once]                  #pragma once                             /* Mark a file that should only be #includ-ed once (same as defining and setting a unique #include-guard for that file). */
// [push_macro]            #pragma push_macro("foo")                /* Store the definition of a macro, later to-be restored. */
// [pop_macro]             #pragma pop_macro("foo")                 /* Restore a previously stored definition of a macro. */
// [{end}region]           #pragma {end}region my region            /* Highlight named regions of code in IDEs (the preprocessor must, and does simply ignore this directive). */
// [message]               #pragma message "Hello"                  /* Emit a message to `stderr' from inside the preprocessor (NOTE: Also supports optional parenthesis surrounding the text). */
// [error]                 #pragma error("Oh no!")                  /* Emit an error message (same as `#error Oh no!'). */
// [deprecated]            #pragma deprecated("foobar")             /* Declare a given identifier as deprecated, causing subsequent use to emit a deprecation warning. */
// [tpp_exec]              #pragma tpp_exec("#define foo 7")        /* Execute a string as preprocessor text, discarding output, but keeping changes to macros (can be used to by macros to re-/un-/define macros). */
// [tpp_set_keyword_flags] #pragma tpp_set_keyword_flags("foo",0x2) /* Set the flags associated with a keyword (A set of TPP_KEYWORDFLAG_* masking `TPP_KEYWORDFLAG_USERMASK'). */
// [warning]               #pragma warning(disable: 42)             /* Configure warnings MSVC-style by ID, or by GCC name. */
// [extension]             #pragma extension("-fmacro-recursion")   /* Configure active TPP extensions by name. */
// [TPP include_path]      #pragma TPP include_path("/usr/include") /* Push/pop/add/delete the current list of system #include-paths. */
// [GCC system_header]     #pragma GCC system_header                /* Disable warnings within the current file. */
// [GCC diagnostic]        #pragma GCC diagnostic push              /* Configure warnings GCC-style by name. */


/* NOTE: TPP adds a minor extension to #pragma push_macro/pop_macro:
 * >> #define foo 42
 * >> #define bar 12
 * >> #define baz 7
 * >> foo // 42
 * >> bar // 12
 * >> baz // 7
 * >> #pragma push_macro(undef,"foo","bar","baz") // Automatically undef the macros
 * >> foo // foo
 * >> bar // bar
 * >> baz // baz
 * >> #define foo FOOTEXT
 * >> #define bar BARTEXT
 * >> foo // FOOTEXT
 * >> bar // BARTEXT
 * >> baz // baz
 * >> #pragma pop_macro("foo")
 * >> foo // 42
 * >> #pragma pop_macro(undef,"bar")
 * >> bar // BARTEXT << The popped macro is not restored because a new definition was given
 * >> #pragma pop_macro(undef,"baz")
 * >> baz // 7 << The popped macro is restored because it was not defined before
 * Using this, you can very easily include headers and
 * automatically import new macro definitions from inside:
 * "/fixinclude/stdlib.h":
 * >> #if __has_include_next(<stdlib.h>)
 * >> // Push user-definitions for `malloc' and undef them
 * >> #pragma push_macro(undef,"malloc")
 * >> #include_next <stdlib.h>
 * >> // Pop the macro, and if `<stdlib.h>' didn't define
 * >> // its own `malloc' macro, restore user-definitions
 * >> // NOTE: If this weak re-declaration behavior is
 * >> //       not intended `undef' should be removed.
 * >> #pragma pop_macro(undef,"malloc")
 * >> #endif
 */

#if (defined(GUARD_TPP_C) && defined(_MSC_VER) && TPP_CONFIG_DEBUG)
/* Make use of MSVC's builtin memory leak detector. */
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif /* GUARD_TPP_C && _MSC_VER && TPP_CONFIG_DEBUG */

#include <stddef.h>
#include <stdint.h>
#ifndef TPP_NO_INCLUDE_STDLIB_H
#include <stdlib.h>
#endif /* !TPP_NO_INCLUDE_STDLIB_H */

#ifdef _MSC_VER
#ifndef TPP_SYMARRAY_SIZE
#define TPP_SYMARRAY_SIZE 4096
#endif /* !TPP_SYMARRAY_SIZE */
#define TPP_MACRO_FALSE 0, 0
#else /* _MSC_VER */
#ifndef TPP_SYMARRAY_SIZE
#define TPP_SYMARRAY_SIZE 1
#endif /* !TPP_SYMARRAY_SIZE */
#define TPP_MACRO_FALSE 0
#endif /* !_MSC_VER */

/* Special strings inserted into warnings. */
#ifndef TPP_WARNF_QUOTE_BEGIN
#define TPP_WARNF_QUOTE_BEGIN "`" /* Expected keyword, but got >`<...' */
#endif /* !TPP_WARNF_QUOTE_BEGIN */
#ifndef TPP_WARNF_QUOTE_END
#define TPP_WARNF_QUOTE_END   "'" /* Expected keyword, but got `...>'< */
#endif /* !TPP_WARNF_QUOTE_END */
#ifndef TPP_WARNF_WARN_BEGIN
#define TPP_WARNF_WARN_BEGIN  ""  /* ><W1234("-Wsyntax"): ... */
#endif /* !TPP_WARNF_WARN_BEGIN */
#ifndef TPP_WARNF_WARN_END
#define TPP_WARNF_WARN_END    ""  /* W1234("-Wsyntax")><: ... */
#endif /* !TPP_WARNF_WARN_END */
#ifndef TPP_WARNF_ERROR_BEGIN
#define TPP_WARNF_ERROR_BEGIN ""  /* ><E1234("-Wsyntax"): ... */
#endif /* !TPP_WARNF_ERROR_BEGIN */
#ifndef TPP_WARNF_ERROR_END
#define TPP_WARNF_ERROR_END   ""  /* E1234("-Wsyntax")><: ... */
#endif /* !TPP_WARNF_ERROR_END */

#ifndef TPPCALL
/* The standard calling convention used by TPP APIs */
#define TPPCALL /* nothing */
#endif /* !TPPCALL */

#ifndef TPPVCALL
/* The standard calling convention used by TPP APIs for variadic functions. */
#define TPPVCALL /* nothing */
#endif /* !TPPVCALL */

#ifndef TPPFUN
#define TPPFUN extern
#endif /* !TPPFUN */

#ifndef TPP_LOCAL
#if defined(__cplusplus) || defined(inline)
#define TPP_LOCAL static inline
#elif defined(_MSC_VER)
#define TPP_LOCAL static __inline
#elif defined(__GNUC__) || defined(__TCC__) || defined(__DCC_VERSION__)
#define TPP_LOCAL static __inline__
#else /* ... */
#define TPP_LOCAL static
#endif /* !... */
#endif /* !TPP_LOCAL */

#ifndef __has_attribute
#define __has_attribute(x) 0
#endif /* !__has_attribute */

#ifndef __has_builtin
#define __has_builtin(x) 0
#endif /* !__has_builtin */

#if defined(__GNUC__) || __has_builtin(__builtin_offsetof)
#define TPP_OFFSETOF __builtin_offsetof
#else /* ... */
#define TPP_OFFSETOF(m, s) ((size_t)(&((m *)0)->s))
#endif /* !... */

#define TPP_OFFSETAFTER(m, s) ((size_t)(&((m *)0)->s + 1))

#if ((defined(_MSC_VER) && (defined(_MSC_EXTENSIONS) || _MSC_VER >= 1400)) || \
     defined(__clang__) || defined(__DCC_VERSION__) ||                        \
     (defined(__GNUC__) && !defined(__DARWIN_NO_LONG_LONG)) ||                \
     (defined(__BORLANDC__) && __BORLANDC__ >= 0x561 && !defined(__NO_LONG_LONG)))
#define TPP_HAVE_LONGLONG 1
#else /* ... */
#define TPP_HAVE_LONGLONG 0
#endif /* !... */

#if defined(_MSC_VER)
#define TPP_HAVE_UNNAMED_UNION 1
#pragma warning(disable : 4201)
#elif defined(__DCC_VERSION__)
#define TPP_HAVE_UNNAMED_UNION 1
#elif ((defined(__GNUC__) && /* Anonymous unions support starts with gcc 2.96/g++ 2.95 */          \
        (__GNUC__ < 2 || (__GNUC__ == 2 && (__GNUC_MINOR__ < 95 ||                                 \
                                            (__GNUC_MINOR__ == 95 && !defined(__cplusplus)))))) || \
       defined(__SUNPRO_C) || defined(__SUNPRO_CC))
#define TPP_HAVE_UNNAMED_UNION 0
#else /* ... */
#define TPP_HAVE_UNNAMED_UNION 1
#endif /* !... */

#if TPP_HAVE_UNNAMED_UNION
#define TPP_UNNAMED_UNION_DEF(name) /* nothing */
#else /* TPP_HAVE_UNNAMED_UNION */
#define TPP_UNNAMED_UNION_DEF(name) name
#endif /* !TPP_HAVE_UNNAMED_UNION */

#if !defined(_WIN64) && defined(WIN64)
#define _WIN64 WIN64
#endif /* !_WIN64 && WIN64 */

#if !defined(_WIN32) && defined(WIN32)
#define _WIN32 WIN32
#endif /* !_WIN32 && WIN32 */

#if !defined(_WIN32) && defined(__WIN32__)
#define _WIN32 __WIN32__
#endif /* !_WIN32 && __WIN32__ */

#ifndef __SIZEOF_POINTER__
#if (defined(_WIN64) || defined(__LP64__) || \
     defined(_LP64) || defined(__x86_64__))
#define __SIZEOF_POINTER__ 8
#elif (defined(_WIN32) || defined(__i386__) || \
       defined(__i386) || defined(i386))
#define __SIZEOF_POINTER__ 4
#elif defined(_WIN16)
#define __SIZEOF_POINTER__ 2
#else
#include <hybrid/typecore.h>
#if !defined(__SIZEOF_POINTER__) && !defined(__DEEMON__)
#error FIXME
#endif /* !__SIZEOF_POINTER__ && !__DEEMON__ */
#endif
#endif /* !__SIZEOF_POINTER__ */

#ifndef __SIZEOF_SIZE_T__
#define __SIZEOF_SIZE_T__ __SIZEOF_POINTER__
#endif /* !__SIZEOF_SIZE_T__ */

#ifndef __SIZEOF_INT__
#define __SIZEOF_INT__ 4
#endif /* !__SIZEOF_INT__ */

#ifndef TPP_assert
#define TPP_assert assert
#endif /* !TPP_assert */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef TPP
#define TPP_NAMESPACE_DEFINED
#define TPP(x) TPP_##x /* Use TPP-specific namespace. */
#endif /* !TPP */

/* OS-specific data type for a stream handle. */
#ifdef TPP_CONFIG_USERSTREAMS
typedef TPP_USERSTREAM_TYPE TPP(stream_t);
#define TPP_STREAM_INVALID  TPP_USERSTREAM_INVALID
#elif defined(_WIN32)
typedef /*HANDLE*/void *TPP(stream_t);
#define TPP_STREAM_INVALID ((TPP(stream_t))(size_t)-1)
#elif defined(__unix__)
typedef int TPP(stream_t);
#define TPP_STREAM_INVALID (-1)
#else
typedef void *TPP(stream_t); /* FILE * */
#define TPP_STREAM_INVALID NULL
#endif

typedef int           TPP(tok_t);      /* Unique token id. */
typedef size_t        TPP(hash_t);     /* Hash-value of a string. */
typedef unsigned char TPP(encoding_t); /* File-encoding ID (One of `TPP_ENCODING_*'). */
typedef signed char   TPP(wgroup_t);   /* Warning group ID. */
typedef int           TPP(col_t);      /* Column number. */
typedef int           TPP(line_t);     /* Line number. */
typedef unsigned int  TPP(refcnt_t);   /* Reference counter. */
#if TPP_HAVE_LONGLONG
typedef long long     TPP(llong_t);
#else /* TPP_HAVE_LONGLONG */
typedef int64_t       TPP(llong_t);
#endif /* !TPP_HAVE_LONGLONG */
typedef ptrdiff_t (TPPCALL *TPP(printer_t))(void *closure, char const *__restrict buf, size_t bufsize);

#define TPP_ENCODING_UTF8     0
#define TPP_ENCODING_UTF16_BE 1
#define TPP_ENCODING_UTF16_LE 2
#define TPP_ENCODING_UTF32_BE 3
#define TPP_ENCODING_UTF32_LE 4

struct TPPFile;
struct TPPKeyword;

struct TPPString {
#ifdef __INTELLISENSE__
	    refcnt_t  s_refcnt; /* String reference counter. */
#else /* __INTELLISENSE__ */
	TPP(refcnt_t) s_refcnt; /* String reference counter. */
#endif /* !__INTELLISENSE__ */
	size_t        s_size;   /* Size of the text in characters. */
	char          s_text[TPP_SYMARRAY_SIZE]; /* [s_size] ZERO-terminated text. */
};
#define TPPString_TEXT(x)   ((x)->s_text)
#define TPPString_SIZE(x)   ((x)->s_size)
#define TPPString_Shared(x) ((x)->s_refcnt > 1)

#define TPPSTRING_DEF(name, value)                      \
	struct {                                            \
		TPP(refcnt_t) _r;                               \
		size_t        _s;                               \
		char          _t[sizeof(value) / sizeof(char)]; \
	} name = {                                          \
		0x80000000,                                     \
		(sizeof(value) / sizeof(char)) - 1,             \
		value                                           \
	}

#define TPPString_Incref(self) (void)(++(self)->s_refcnt)
#define TPPString_Decref(self) (void)(--(self)->s_refcnt || (free(self),0))

/* Concat two given string and drop ONE(1) references from each.
 * @return: * :   A reference to a string containing the sum of what is given.
 * @return: NULL: Not enough available memory. (TPP_CONFIG_SET_API_ERROR) */
TPPFUN /*ref*/struct TPPString *TPPCALL
TPPString_Cat(/*ref*/struct TPPString *__restrict lhs,
              /*ref*/struct TPPString *__restrict rhs);

/* Returns a new string from the given text.
 * @return: * :   A reference to a string containing the given text.
 * @return: NULL: Not enough available memory. (TPP_CONFIG_SET_API_ERROR) */
TPPFUN /*ref*/struct TPPString *TPPCALL TPPString_New(char const *__restrict text, size_t size);
TPPFUN /*ref*/struct TPPString *TPPCALL TPPString_NewSized(size_t size);
#define TPPString_NewEmpty() (TPPString_Incref(TPPFile_Empty.f_text), TPPFile_Empty.f_text)


struct TPPTextFile {
	/* [owned((:f_name) = true]
	 * HINT: `:f_name' usually is the string passed to the
	 *        system for opening a stream for this file.
	 *        Though this doesn't necessarily have to hold up,
	 *        as pipe text files don't need to follow this rule. */
	/*ref*/struct TPPFile   *f_cacheentry;  /* [0..1] Used when the copy of a file is loaded onto the #include-stack (points to the original version of the file)
	                                         * NOTE: When non-NULL, always a textfile and this pointer also owns a reference to the associated textfile's `f_cacheinc' field. */
	/*ref*/struct TPPString *f_usedname;    /* [0..1] When non-NULL, an override to the used filename (as set by `#line') */
	TPP(line_t)              f_lineoff;     /* Offset of `f_begin' from the original start of the file in lines. */
	TPP(stream_t)            f_stream;      /* Stream handle for reading more data. */
	TPP(stream_t)            f_ownedstream; /* Usually equal to `f_stream', the stream that should be closed when it's EOF is reached (set to `TPP_STREAM_INVALID' if TPP shouldn't close the stream). */
	/* NOTE: `:f_end' may not be equal to the end of `:f_text'.
	 *        The difference between the two should be prefixed to the next chunk. */
	struct TPPKeyword       *f_guard;       /* [0..1] Name of the #include guard for this file, or NULL if unknown. */
	size_t                   f_cacheinc;    /* Used to track how often a given file is loaded onto the #include-stack.
	                                         * (Only used for cached entires themself; aka. when `f_cacheentry == NULL'). */
	size_t                   f_rdata;       /* (In bytes) The amount of data already read from the stream. */
	char                     f_prefixdel;   /* The original character at `:f_end' that was overwritten with a `\0'. */
#define TPP_TEXTFILE_FLAG_NONE         0x00 /* No special flags. */
#define TPP_TEXTFILE_FLAG_NOGUARD      0x01 /* Set after a secondary #ifdef block was detected at the top level of this file:
                                             * >> // File: "myfile.h"
                                             * >> #ifndef foo // Potential include-guard?
                                             * >> #endif
                                             * >> #ifndef bar // This #ifndef will set `TPP_TEXTFILE_FLAG_NOGUARD'
                                             * >> #endif */
#define TPP_TEXTFILE_FLAG_SYSHEADER    0x02 /* This file is a system-header and all non-error warnings are suppressed. */
#ifdef TPP_CONFIG_NONBLOCKING_IO
#define TPP_TEXTFILE_FLAG_NONBLOCK     0x40 /* Do not block when reading file data.
                                             * NOTE: Still block if waiting for the end of a non-escaped
                                             *       linefeed, of the end of a comment, or string. */
#endif /* TPP_CONFIG_NONBLOCKING_IO */
#define TPP_TEXTFILE_FLAG_INTERNAL     0x80 /* This file is internal, meaning it shouldn't ~really~ represent a line/col number. */
	unsigned char            f_flags;       /* A set of `TPP_TEXTFILE_FLAG_*' */
	TPP(encoding_t)          f_encoding;    /* Encoding determined to-be used by this file. */
	char                     f_padding[1];  /* Padding data... */
	struct TPPKeyword       *f_newguard;    /* [0..1] The keyword of the #ifndef block that was determined to be located at
	                                         *        the start of the file. When the file is popped from the #include-stack,
	                                         *        this is non-NULL and `TPP_TEXTFILE_FLAG_NOGUARD' isn't set, this keyword
	                                         *        will be copied into the `f_guard' field if not already set. */
#ifndef TPP_CONFIG_NO_PRECACHE_TEXTLINES
	char const              *f_lfpos;       /* [?..?] Cached line-feed counter pointer.
	                                         * This pointer is only valid if it points
	                                         * into the file's current text-block. */
	size_t                   f_lfcnt;       /* [valid_if(is_valid(f_lfpos))] Number of line-feeds
	                                         * that can be found between the file's start and `f_lfpos'. */
#endif /* TPP_CONFIG_NO_PRECACHE_TEXTLINES */
#ifdef TPP_USERTEXTDATA
	TPP_USERTEXTDATA /* Optional user-defined data memory (when present, initialized to ZERO) */
#endif /* TPP_USERTEXTDATA */
};

/* HINT: something like
 * >> #define cat(a,b) a ## b
 * is simply implemented as:
 * >> {
 * >>     { TPP_FUNOP_INS, { 0, 1 } }, // Without expanding, insert `a' and override 1 character ("a")
 * >>     { TPP_FUNOP_INS, { 1, 5 } }, // Without expanding, insert `b' and override 5 characters (" ## b")
 * >> } */
#define TPP_FUNOP_END      0x00 /* [0] End of command list. */
#define TPP_FUNOP_ADV      0x01 /* [1] Advance the text pointer by ARG(0) characters. */
#define TPP_FUNOP_INS      0x02 /* [2] Insert argument ARG(0), override ARG(1) characters and put the text pointer after the inserted text. */
#define TPP_FUNOP_INS_EXP  0x03 /* [2] Same as `TPP_FUNOP_INS', but expand macros within the argument text before inserting it. */
#define TPP_FUNOP_INS_STR  0x04 /* [2] Same as `TPP_FUNOP_INS', but encode the argument as a single-token string. */
#define TPP_FUNOP_INS_CHR  0x05 /* [2] Same as `TPP_FUNOP_INS', but encode the argument as a single-token character. */
#define TPP_FUNOP_DEL      0x06 /* [1] Delete ARG(0) characters (doesn't advance the text pointer). */
#if (!defined(TPP_CONFIG_EXTENSION_VA_COMMA) || TPP_CONFIG_EXTENSION_VA_COMMA || \
     !defined(TPP_CONFIG_EXTENSION_GCC_VA_COMMA) || TPP_CONFIG_EXTENSION_GCC_VA_COMMA)
#define TPP_FUNOP_VA_COMMA 0x07 /* [1] Delete ARG(0) characters and insert a `,' if the variadic portion of the argument list is non-empty (NOTE: When inserting, the text-pointer is advanced). */
#endif /* TPP_CONFIG_EXTENSION_VA_COMMA || TPP_CONFIG_EXTENSION_GCC_VA_COMMA */
#if (!defined(TPP_CONFIG_EXTENSION_VA_NARGS) || TPP_CONFIG_EXTENSION_VA_NARGS)
#define TPP_FUNOP_VA_NARGS 0x08 /* [1] Delete ARG(0) characters and insert a decimal representation of the variadic argument size (NOTE: When inserting, the text-pointer is advanced). */
#endif /* TPP_CONFIG_EXTENSION_VA_NARGS */
#if (!defined(TPP_CONFIG_EXTENSION_VA_OPT) || TPP_CONFIG_EXTENSION_VA_OPT)
#define TPP_FUNOP_VA_OPT   0x09 /* [3] Delete ARG(0) characters, Delete (if varargs are empty) or Insert (otherwise) ARG(1) characters, Delete ARG(2) characters */
#endif /* TPP_CONFIG_EXTENSION_VA_OPT */
typedef uint8_t        TPP(funop_t);
typedef int_least64_t  TPP(tint_t);
typedef uint_least64_t TPP(tuint_t);
typedef long double    TPP(tfloat_t);

struct TPP(arginfo_t) {
	TPP(tok_t) ai_id;       /* Token ID associated with this argument name. */
	size_t     ai_ins;      /* Amount of times the argument is inserted without expansion. */
	size_t     ai_ins_exp;  /* Amount of times the argument is inserted after expansion. */
	size_t     ai_ins_str;  /* Amount of times the argument is inserted in its escaped form. */
#if TPP_CONFIG_DEBUG
	char      *ai_name;     /* [1..1] Name of this macro (Weakly references the names from the keyword list). */
	size_t     ai_namesize; /* Size of this argument's name (in characters) */
#endif /* TPP_CONFIG_DEBUG */
};

struct TPPLCInfo {
	/* TPP Line/Column information. */
#ifdef __INTELLISENSE__
	    line_t  lc_line; /* zero-based line index in the associated file. */
	    col_t   lc_col;  /* zero-based column index in the associated file (NOTE: Tabs are already expanded in this). */
#else /* __INTELLISENSE__ */
	TPP(line_t) lc_line; /* zero-based line index in the associated file. */
	TPP(col_t)  lc_col;  /* zero-based column index in the associated file (NOTE: Tabs are already expanded in this). */
#endif /* !__INTELLISENSE__ */
};


struct TPPMacroFile {
	/* [owned(f_name) = m_flags&TPP_MACROFILE_FLAG_OWNSNAME] */
#define TPP_MACROFILE_KIND                   0x000000ff
#define TPP_MACROFILE_KIND_HASCOMMON(k)      (((k) & TPP_MACROFILE_KIND) != TPP_MACROFILE_KIND_EXPANDED)
#define TPP_MACROFILE_KIND_KEYWORD           0x00000000 /* Keyword-style macro (without string/concat operations). */
#define TPP_MACROFILE_KIND_FUNCTION          0x00000001 /* Function-style macro. */
#define TPP_MACROFILE_FLAG_FUNC_VARIADIC     0x00000100 /* The last argument of the function is variadic. */
#define TPP_MACROFILE_FLAG_FUNC_SELFEXPAND   0x00000200 /* After being expanded, this function is allowed to re-invoke itself and be expanded, when
                                                         * the generated text is not identical to a previous iteration. (s.a.: `-fmacro-recursion') */
#define TPP_MACROFILE_FLAG_FUNC_KEEPARGSPC   0x00000400 /* When set, keep whitespace surrounding macro arguments during invication.
                                                         * WARNING: Also affects recursive macro expansion. */
#define TPP_MACROFILE_FLAG_OWNSNAME          0x00000800 /* The associated ":f_name" member is owned. */
#define TPP_MACROFILE_MASK_FUNC_STARTCH      0x00003000 /* The character that should be recognized as start of an argument list (one of the macros below). */
#define TPP_MACROFILE_FUNC_START_LPAREN      0x00000000 /* `(...)' */
#define TPP_MACROFILE_FUNC_START_LBRACKET    0x00001000 /* `[...]' */
#define TPP_MACROFILE_FUNC_START_LBRACE      0x00002000 /* `{...}' */
#define TPP_MACROFILE_FUNC_START_LANGLE      0x00003000 /* `<...>' */
#define TPP_MACROFILE_FUNC_START(ch)       \
	((ch) == '('                           \
	 ? TPP_MACROFILE_FUNC_START_LPAREN     \
	 : (ch) == '['                         \
	   ? TPP_MACROFILE_FUNC_START_LBRACKET \
	   : (ch) == '{'                       \
	     ? TPP_MACROFILE_FUNC_START_LBRACE \
	     : TPP_MACROFILE_FUNC_START_LANGLE)
#define TPP_MACROFILE_KIND_EXPANDED 0x00000002      /* Expanded version of a function macro. */
	uint32_t                       m_flags;         /* [const] Macro flags. */
	/*ref*/struct TPPFile         *m_deffile;       /* [const][0..1] The file that originally defined this macro (or NULL if predefined, or from the commandline). */
	struct TPPLCInfo               m_defloc;        /* [const] Line/col where this macro was defined (based on first character of the macro's text, aka. `:f_begin'). */
	/*ref*/struct TPPFile         *m_pushprev;      /* [0..1] Previous version of a pushed macro. */
	size_t                         m_pushcount;     /* The amount of times this macro was pushed (used to handle multiple calls to `push_macro'). */
	union {
		struct {
			size_t                 f_argc;          /* [const] Amount of arguments this function takes. */
			size_t                 f_expansions;    /* The amount of existing expansions of this macro.
			                                         * NOTE: Depending on the `TPP_MACROFILE_FLAG_FUNC_SELFEXPAND' flag,
			                                         *       this value may not be allowed to exceed ONE(1). */
			TPP(funop_t)          *f_expand;        /* [const][1..1][owned] Chain of text commands invoked to expand a function macro. */
			struct TPP(arginfo_t) *f_arginfo;       /* [const][0..f_argc][owned] Vector of argument information (used for fast calculation of the expanded macro's size) */
			size_t                 f_deltotal;      /* [const][<= (:f_end-:f_begin)] The total amount of characters removed during expansion (minus those added). */
#if defined(TPP_FUNOP_VA_COMMA) || defined(TPP_FUNOP_VA_OPT)
			size_t                 f_n_vacomma;     /* [const] Amount of times `TPP_FUNOP_VA_COMMA' is used in `f_expand' + amount of characters potentially inserted by `TPP_FUNOP_VA_OPT'. */
#endif /* TPP_FUNOP_VA_COMMA || TPP_FUNOP_VA_OPT */
#ifdef TPP_FUNOP_VA_NARGS
			size_t                 f_n_vanargs;     /* [const] Amount of times `TPP_FUNOP_VA_NARGS' is used in `f_expand'. */
#endif /* TPP_FUNOP_VA_NARGS */
			void                  *f_argbuf;        /* [0..1][owned] Internal preallocated cache for a required temporary buffer used during expansion.
			                                         * NOTE: Implementation-wise, this is a vector of `argcache_t' (an internal, hidden data structure). */
		}                          m_function;      /* [TPP_MACROFILE_KIND_KEYWORD]. */
		struct {
			/*ref*/struct TPPFile *e_expand_origin; /* [const][1..1] Original macro-file that was expanded.
			                                         * NOTE: While this file is part of the #include-stack of the current lexer, this pointer
			                                         *       also holds a reference to `e_expand_origin->f_macro.m_function.f_expansions'. */
		}                          m_expand;        /* [TPP_MACROFILE_KIND_EXPANDED]. */
	} TPP_UNNAMED_UNION_DEF(m_specific);
};

/* Minimum malloc-sizes of various kinds of TPP files types. */
#define TPPFILE_SIZEOF_TEXT           TPP_OFFSETAFTER(struct TPPFile, f_textfile)
#define TPPFILE_SIZEOF_MACRO_KEYWORD  TPP_OFFSETOF(struct TPPFile, f_macro.m_function)
#define TPPFILE_SIZEOF_MACRO_FUNCTION TPP_OFFSETAFTER(struct TPPFile, f_macro.m_function)
#define TPPFILE_SIZEOF_MACRO_EXPANDED TPP_OFFSETAFTER(struct TPPFile, f_macro.m_expand)
#define TPPFILE_SIZEOF_EXPLICIT       TPP_OFFSETOF(struct TPPFile, f_textfile)

struct TPPFile {
	/* Input file/user macro. */
	TPP(refcnt_t)            f_refcnt;    /* File reference counter. */
#define TPPFILE_KIND_TEXT     0           /* Input file. */
#define TPPFILE_KIND_MACRO    1           /* Macro file. */
#define TPPFILE_KIND_EXPLICIT 2           /* An explicit file, that is the result of manually inserting text, such as resulting from expanding builtin macros. */
	unsigned int             f_kind;      /* [const] The kind of file (One of `TPPFILE_KIND_*') */
	/*C:ref*/struct TPPFile *f_prev;      /* [0..1][caller_ref] Previous entry in the #include-stack chain or NULL if base-file or macro not part of the include stack. */
	char                    *f_name;      /* [1..f_namesize][owned_if(...)][const] Name of this file.
	                                       * WARNING: Except for text files, this may not be `\0'-terminated
	                                       *          and may contain non-escaped linefeeds and trigraphs. */
	size_t                   f_namesize;  /* [const] Size of `f_name' in characters. */
	size_t                   f_namehash;  /* [const] Hash of `f_name..f_namesize'. */
	/*ref*/struct TPPString *f_text;      /* [1..1] Reference to a chunk of text containing the `f_begin', `f_end' and `f_pos' pointers.
	                                       * NOTE: For regular text-files, this block always ends after a non-escaped linefeed ("[LF]\0"; never "\\[LF]\0").
	                                       * NOTE: If the original input-file doesn't terminate with this pattern, it may be missing. */
	char                    *f_begin;     /* [const][1..1] Raw, unformatted text start. */
	char                    *f_end;       /* [const][1..1] End of the text associated with this file (NOTE: Always dereferences to a `\0'-character). */
	char                    *f_pos;       /* [1..1] Current position between `f_begin..f_end'. */
	union {
		struct TPPTextFile   f_textfile;  /* [if(f_kind == TPPFILE_KIND_TEXT)] Text-specific data. */
		struct TPPMacroFile  f_macro;     /* [if(f_kind == TPPFILE_KIND_MACRO)] Macro-specific data. */
	} TPP_UNNAMED_UNION_DEF(f_specific);
};

TPPFUN struct TPPFile TPPFile_Empty;
#define TPPFile_Incref(self)       (void)(++(self)->f_refcnt)
#define TPPFile_Decref(self)       (void)(TPP_assert((self)->f_refcnt), --(self)->f_refcnt || (TPPFile_Destroy(self), 0))
#define TPPFile_DecrefNoKill(self) (void)(TPP_assert((self)->f_refcnt >= 2), --(self)->f_refcnt)
TPPFUN void TPPCALL TPPFile_Destroy(struct TPPFile *__restrict self);

/* Create a new explicit text file by inherited the given `inherited_text'.
 * @return: NULL: Not enough available memory. (TPP_CONFIG_SET_API_ERROR) */
TPPFUN /*ref*/struct TPPFile *TPPCALL
TPPFile_NewExplicitInherited(/*ref*/struct TPPString *__restrict inherited_text);

/* Query file/line information a the given text_pointer.
 * HINT: You can simply pass `self->f_pos' for
 *       information in the file's current source location.
 * NOTE: The caller is responsible for only passing a value
 *       for `text_pointer', that is conforming to:
 *       `self->f_begin <= text_pointer <= self->f_end'
 *       (Yes: `self->f_end' is still valid, although
 *       technically already out-of-bounds, but an exception
 *       is made to allow for safe calls to this function, even
 *       when `text_pointer' was retrieved from an EOF token) */
TPPFUN void TPPCALL
TPPFile_LCAt(struct TPPFile const *__restrict self,
             struct TPPLCInfo *__restrict info,
             char const *__restrict text_pointer);


/* Returns the zero-based line index of a given text pointer.
 * NOTE: The returned line index is always absolute to
 *       the original text file and continues to be valid
 *       even when the given file is a macro defined within. */
TPP_LOCAL TPP(line_t) TPPCALL
TPPFile_LineAt(struct TPPFile const *__restrict self,
               char const *__restrict text_pointer) {
	struct TPPLCInfo info;
	TPPFile_LCAt(self, &info, text_pointer);
	return info.lc_line;
}

/* Similar to `TPPFile_LineAt', but instead returns the column number. */
TPP_LOCAL TPP(col_t) TPPCALL
TPPFile_ColumnAt(struct TPPFile const *__restrict self,
                 char const *__restrict text_pointer) {
	struct TPPLCInfo info;
	TPPFile_LCAt(self, &info, text_pointer);
	return info.lc_col;
}

/* Returns the human-readable filename of a given file.
 * NOTE: For macro files, the returned filename continues
 *       to refer to the file that the macro was defined
 *       within.
 * NOTE: Returns NULL if no name is associated with the
 *       given file, such as for predefined macros. */
TPPFUN char const *TPPCALL
TPPFile_Filename(struct TPPFile const *__restrict self,
                 size_t *opt_filename_length);

/* Same as `TPPFile_Filename()', however return the original
 * file name if a #line directive was used to override it. */
TPPFUN char const *TPPCALL
TPPFile_RealFilename(struct TPPFile const *__restrict self,
                     size_t *opt_filename_length);

/* If the given file is a macro-file, ensure that it
 * owns a copy of its own name. In other words,
 * replace the file's name with a copy of itself when
 * the `TPP_MACROFILE_FLAG_OWNSNAME' flag isn't set.
 * @return: 1: Either the given file isn't a macro-file, the filename
 *             had already been copied, or the filename was copied
 *             successfully.
 * @return: 0: Not enough available memory (TPP_CONFIG_SET_API_ERROR) */
TPPFUN int TPPCALL
TPPFile_Copyname(struct TPPFile *__restrict self);

/* Copy the given file for use as #include-stack entry.
 * WARNING: The caller is responsible for only passing text files. */
TPPFUN /*ref*/struct TPPFile *TPPCALL
TPPFile_CopyForInclude(struct TPPFile *__restrict self);


/* Opens a file.
 * NOTE: The given filename is what will appear as text when expanding __FILE__
 * @return: NULL: Failed to open the given file (`errno' was set to ENOENT)
 * @return: NULL: Not enough available memory (TPP_CONFIG_SET_API_ERROR) */
TPPFUN /*ref*/struct TPPFile *TPPCALL TPPFile_Open(char const *__restrict filename);

/* Similar to `TPPFile_Open', but allows the caller to specify a stream,
 * allowing them to use this function for opening things like STD handles.
 * @return: NULL: Not enough available memory. (TPP_CONFIG_SET_API_ERROR) */
TPPFUN /*ref*/struct TPPFile *TPPCALL TPPFile_OpenStream(TPP(stream_t) stream, char const *__restrict name);

/* Parse a #define-style preprocessor command, expecting the
 * current lexer's token to point at the name of the macro.
 * NOTE: This function will also register the macro in the keyword list.
 * NOTE: When attempting to (re-)define a locked keyword, either the
 *       previous macro definition, or `&TPPFile_Empty' is returned.
 * WARNING: This function expects the `TPPLEXER_FLAG_WANTLF' flag to be set.
 * WARNING: This function does _not_ return a reference.
 * @return: NULL: A lexer error has been set. */
TPPFUN struct TPPFile *TPPCALL TPPFile_NewDefine(void);

/* Advances the given file to its next chunk.
 * NOTE: When `flags' contains `TPPFILE_NEXTCHUNK_FLAG_EXTEND', instead of dropping
 *       already-read data from the existing chunk, new data will be appended to that
 *       chunk, meaning that the resulting stream contains both old and new data,
 *       allowing for higher-level data lookahead while still remaining
 *       as unbuffered as possible.
 * @return:  0: The file's EOF was already reached, or the
 *             `TPPFILE_NEXTCHUNK_FLAG_NOBLCK' flag was passed
 *              and no data is available for reading right now.
 * @return:  1: Successfully read input.
 * #ifdef TPP_CONFIG_SET_API_ERROR
 * @return: -1: Not enough available memory (TPP_CONFIG_SET_API_ERROR)
 * #ifdef TPP_USERSTREAM_FREAD
 * @return: -1: The user-defined read callback returned 0 and set TPPLEXER_FLAG_ERROR-flag.
 * #endif
 * #else
 * @return:  0: Not enough available memory
 * #endif
 */
TPPFUN int TPPCALL TPPFile_NextChunk(struct TPPFile *__restrict self, unsigned int flags);
#define TPPFILE_NEXTCHUNK_FLAG_NONE   0x00000000 /* No special behavior modification. */
#define TPPFILE_NEXTCHUNK_FLAG_EXTEND 0x00020000 /* Extend the current file chunk. */
#define TPPFILE_NEXTCHUNK_FLAG_BINARY 0x00000002 /* Read data in binary mode (don't convert to UTF-8 without BOM).
                                                  * NOTE: This flag is implied if the lexer has the `TPPLEXER_FLAG_NO_ENCODING' flag set. */
#ifdef TPP_CONFIG_NONBLOCKING_IO
#define TPPFILE_NEXTCHUNK_FLAG_NOBLCK 0x00000040 /* If the stream has been marked as `TPP_TEXTFILE_FLAG_NONBLOCK',
                                                  * do not block when reading more file memory. */
#endif /* TPP_CONFIG_NONBLOCKING_IO */


#ifndef TPP_UNESCAPE_ENDIAN
#define TPP_UNESCAPE_ENDIAN  TPP_BYTEORDER
#endif /* !TPP_UNESCAPE_ENDIAN */
#ifndef TPP_UNESCAPE_MAXCHAR
/* Max value for `charsize' passed to `TPP_Unescape' (Must be one of 1,2,4 or 8) */
#define TPP_UNESCAPE_MAXCHAR 1
#endif /* !TPP_UNESCAPE_MAXCHAR */

/* Escape/Unescape a given block of data.
 * NOTE: `TPP_Unescape/TPP_Escape' will return the surrounding  */
#if TPP_UNESCAPE_MAXCHAR == 1
TPPFUN char *TPPCALL TPP_Unescape_(char *__restrict buf, char const *__restrict data, size_t size);
TPPFUN size_t TPPCALL TPP_SizeofUnescape_(char const *__restrict data, size_t size);
#define TPP_Unescape(buf,data,size,charsize)   TPP_Unescape_(buf,data,size)
#define TPP_SizeofUnescape(data,size,charsize) TPP_SizeofUnescape_(data,size)
#else /* TPP_UNESCAPE_MAXCHAR == 1 */
TPPFUN char *TPPCALL TPP_Unescape(char *__restrict buf, char const *__restrict data, size_t size, size_t charsize);
TPPFUN size_t TPPCALL TPP_SizeofUnescape(char const *__restrict data, size_t size, size_t charsize);
#endif /* TPP_UNESCAPE_MAXCHAR != 1 */
#ifdef TPP_CONFIG_RAW_STRING_LITERALS
TPPFUN char *TPPCALL TPP_UnescapeRaw(char *__restrict buf, char const *__restrict data, size_t size);
TPPFUN size_t TPPCALL TPP_SizeofUnescapeRaw(char const *__restrict data, size_t size);
#endif /* TPP_CONFIG_RAW_STRING_LITERALS */

TPPFUN char *TPPCALL TPP_Escape(char *__restrict buf, char const *__restrict data, size_t size);
TPPFUN char *TPPCALL TPP_Itos(char *__restrict buf, TPP(tint_t) i);
TPPFUN char *TPPCALL TPP_Ftos(char *__restrict buf, TPP(tfloat_t) f);
TPPFUN size_t TPPCALL TPP_SizeofEscape(char const *__restrict data, size_t size);
TPPFUN size_t TPPCALL TPP_SizeofItos(TPP(tint_t) i);
TPPFUN size_t TPPCALL TPP_SizeofFtos(TPP(tfloat_t) f);
TPPFUN TPP(hash_t) TPPCALL TPP_Hashof(void const *__restrict data, size_t size);

/* Implement TPP's hashing algorithm for constant strings, using only the preprocessor!
 * -> THIS! Is the power that TPP can wield: Full functional programming */
#if defined(__TPP_VERSION__) && (__SIZEOF_POINTER__ == 4 || __SIZEOF_POINTER__ == 8)
#define TPP_PRIVATE_PP_CAT2(a,b) a##b
#define TPP_PRIVATE_PP_CAT(a,b) TPP_PRIVATE_PP_CAT2(a,b)
#define TPP_PRIVATE_HASHOF_0(result,str) result
#pragma warning(disable: 108) /* Index out-of-bounds in `__TPP_EVAL' */

/* Using some sick-a$$ TPP extensions, we can actually
 * calculate keyword hashes within the preprocessor! */
#pragma extension(push,"-fmacro-recursion")
#if __SIZEOF_POINTER__ == 4
#define TPP_PRIVATE_HASHOF_1(result,str) TPP_PRIVATE_HASHOF2(__TPP_EVAL((result*263+str[0])&0xfffffffful),__TPP_EVAL(str[1:]))
#elif __SIZEOF_POINTER__ == 8
#define TPP_PRIVATE_HASHOF_1(result,str) TPP_PRIVATE_HASHOF2(__TPP_EVAL((result*263+str[0])&0xffffffffffffffffull),__TPP_EVAL(str[1:]))
#endif
#define TPP_PRIVATE_HASHOF2(result,str) TPP_PRIVATE_PP_CAT(TPP_PRIVATE_HASHOF_,__TPP_EVAL(!!str))(result,str)
#pragma extension(pop)
#if __SIZEOF_POINTER__ == 4
#define TPP_HASHOF(str)         TPP_PRIVATE_PP_CAT(TPP_PRIVATE_HASHOF2(1,str),ul)
#elif __SIZEOF_POINTER__ == 8
#define TPP_HASHOF(str)         TPP_PRIVATE_PP_CAT(TPP_PRIVATE_HASHOF2(1,str),ull)
#endif
#endif /* __TPP_VERSION__ && (__SIZEOF_POINTER__ == 4 || __SIZEOF_POINTER__ == 8) */


enum {
	/* Special tokens. */
	TPP(TOK_EOF)     = '\0', /* END-OF-FILE (will always be ZERO) */
	TPP(TOK_CHAR)    = '\'', /* 'f'. */
	TPP(TOK_STRING)  = '\"', /* "foobar". (also includes `r"foobar"' when `TPP_CONFIG_RAW_STRING_LITERALS' is enabled) */
	TPP(TOK_INT)     = '0',  /* 42 */
	TPP(TOK_FLOAT)   = 'f',  /* 42.0 */
	TPP(TOK_LF)      = '\n',
	TPP(TOK_SPACE)   = ' ',
	TPP(TOK_COMMENT) = 'c',              /* like this one! */
	TPP(TOK_ERR)     = (TPP(tok_t)) - 1, /* An error occurred (will always be negative). */

	/* Single-character tokens (always equal to that character's ordinal). */
	TPP(TOK_ADD)       = '+',
	TPP(TOK_AND)       = '&',
	TPP(TOK_ASSIGN)    = '=',
	TPP(TOK_AT)        = '@',
	TPP(TOK_BACKSLASH) = '\\',
	TPP(TOK_COLON)     = ':',
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
	TPP(TOK_SHL) = TPP(TOK_TWOCHAR_BEGIN), /* "<<". */
	TPP(TOK_SHR),           /* ">>". */
	TPP(TOK_EQUAL),         /* "==". */
	TPP(TOK_NOT_EQUAL),     /* "!=". */
	TPP(TOK_GREATER_EQUAL), /* ">=". */
	TPP(TOK_LOWER_EQUAL),   /* "<=". */
	TPP(TOK_DOTS),          /* "...". */
	TPP(TOK_ADD_EQUAL),     /* "+=". */
	TPP(TOK_SUB_EQUAL),     /* "-=". */
	TPP(TOK_MUL_EQUAL),     /* "*=". */
	TPP(TOK_DIV_EQUAL),     /* "/=". */
	TPP(TOK_MOD_EQUAL),     /* "%=". */
	TPP(TOK_SHL_EQUAL),     /* "<<=". */
	TPP(TOK_SHR_EQUAL),     /* ">>=". */
	TPP(TOK_AND_EQUAL),     /* "&=". */
	TPP(TOK_OR_EQUAL),      /* "|=". */
	TPP(TOK_XOR_EQUAL),     /* "^=". */
	TPP(TOK_POW_EQUAL),     /* "**=". */
	TPP(TOK_AT_EQUAL),      /* "@=". */
	TPP(TOK_GLUE),          /* "##". */
	TPP(TOK_LAND),          /* "&&". */
	TPP(TOK_LOR),           /* "||". */
	TPP(TOK_LXOR),          /* "^^". */
	TPP(TOK_INC),           /* "++". */
	TPP(TOK_DEC),           /* "--". */
	TPP(TOK_POW),           /* "**". */
	TPP(TOK_TILDE_TILDE),   /* "~~". */
	TPP(TOK_ARROW),         /* "->". */
	TPP(TOK_COLON_EQUAL),   /* ":=". */
	TPP(TOK_NAMESPACE),     /* "::". */
	TPP(TOK_ARROW_STAR),    /* "->*". */
	TPP(TOK_DOT_STAR),      /* ".*". */
	TPP(TOK_DOTDOT),        /* "..". */
	TPP(TOK_LOGT),          /* "<>". */
	TPP(TOK_LANGLE3),       /* "<<<". */
	TPP(TOK_RANGLE3),       /* ">>>". */
	TPP(TOK_LANGLE3_EQUAL), /* "<<<=". */
	TPP(TOK_RANGLE3_EQUAL), /* ">>>=". */
	TPP(TOK_EQUAL3),        /* "===". */
	TPP(TOK_NOT_EQUAL3),    /* "!==". */
	TPP(TOK_QMARK_QMARK),   /* "??". */
	TPP(TOK_KEYWORD_BEGIN), /* KEEP THIS THE LAST TOKEN! */

	TPP(TOK_TWOCHAR_END) = TPP(TOK_KEYWORD_BEGIN),

	/* Name aliases */
	TPP(TOK_POS)           = TPP(TOK_ADD),
	TPP(TOK_NEG)           = TPP(TOK_SUB),
	TPP(TOK_LOWER)         = TPP(TOK_LANGLE),
	TPP(TOK_GREATER)       = TPP(TOK_RANGLE),
	TPP(TOK_COLON_COLON)   = TPP(TOK_NAMESPACE),
	TPP(TOK_LOWER_GREATER) = TPP(TOK_LOGT),
	TPP(TOK_LANGLE_RANGLE) = TPP(TOK_LOGT),
	TPP(TOK_LANGLE1)       = TPP(TOK_LANGLE),
	TPP(TOK_LANGLE2)       = TPP(TOK_SHL),
	TPP(TOK_LANGLE_EQUAL)  = TPP(TOK_LOWER_EQUAL),
	TPP(TOK_LANGLE1_EQUAL) = TPP(TOK_LOWER_EQUAL),
	TPP(TOK_LANGLE2_EQUAL) = TPP(TOK_SHL_EQUAL),
	TPP(TOK_RANGLE1)       = TPP(TOK_RANGLE),
	TPP(TOK_RANGLE2)       = TPP(TOK_SHR),
	TPP(TOK_RANGLE_EQUAL)  = TPP(TOK_GREATER_EQUAL),
	TPP(TOK_RANGLE1_EQUAL) = TPP(TOK_GREATER_EQUAL),
	TPP(TOK_RANGLE2_EQUAL) = TPP(TOK_SHR_EQUAL),

/* Deprecated typos */
	TPP(TOK_COLLON)        = TPP(TOK_COLON),
	TPP(TOK_COLLON_EQUAL)  = TPP(TOK_COLON_EQUAL),
	TPP(TOK_COLLON_COLLON) = TPP(TOK_COLON_COLON),
};

/* Check if token ID is OK (neither an error, nor EOF) */
#define TPP_ISOK(id)          ((id) > 0)

/* Check if a token ID is a keyword (when true, the token's `t_kwd' field is up-to-date). */
#define TPP_ISKEYWORD(id)     ((id) >= TPP(TOK_KEYWORD_BEGIN))
#define TPP_ISUSERKEYWORD(id) ((id) >= TPP(_KWD_BACK))

/* Check if a given token ID is a builtin macro currently
 * defined (which may depend on active extensions). */
TPPFUN int TPPCALL TPP_ISBUILTINMACRO(TPP(tok_t) id);

enum {
	TPP(_KWD_FRONT) = TPP(TOK_KEYWORD_BEGIN)-1,
#define KWD(name,str) TPP(name),
#include "tpp-defs.inl"
#undef KWD
	TPP(_KWD_BACK),
	TPP(_KWD_COUNT) = (TPP(_KWD_BACK)-TPP(_KWD_FRONT))-1,
};

typedef enum { /* Warning states. */
	TPP(WSTATE_DISABLED) = 0,
	TPP(WSTATE_FATAL)    = 1,
	TPP(WSTATE_WARN)     = 2,
	TPP(WSTATE_ERROR)    = 3, /* Error (limited to a max number of invocations). */
	TPP(WSTATE_SUPPRESS) = 4, /* Can be set multiple times for recursion.
	                           * NOTE: Internally, this uses the same code as `WSTATE_ERROR',
	                           *       but the differentiation is made within the associated
	                           *      `TPPWarningStateEx' structure. */
	TPP(WSTATE_DEFAULT)  = 5,
	TPP(WSTATE_UNKNOWN)  = 5, /* May not be used as state. - May be returned by `TPPLexer_GetWarning(s)' */
	TPP(WSTATE_DISABLE)  = TPP(WSTATE_DISABLED), /* Deprecated alias. */
} TPP(wstate_t);
#define TPP_WSTATE_ISENABLED(s) ((6 >> (s))&1) /* WSTATE_FATAL|WSTATE_WARN */

enum {
#define WGROUP(name, str, default) TPP(name),
#include "tpp-defs.inl"
#undef WGROUP
	TPP(WG_COUNT)
};

enum { /* Declare symbolic warning numbers and namespaces (or rather ID-spaces). */
#define WARNING(name, groups, default) TPP(name),
#define WARNING_NAMESPACE(name, start) TPP(name) = (start), TPP(_WNEXT_##name) = (start)-1,
#include "tpp-defs.inl"
#undef WARNING_NAMESPACE
#undef WARNING
};

enum { /* Figure out effective warning ID. */
#define WARNING(name, groups, default) TPP(_WID_##name),
#define WARNING_NAMESPACE(name, start) TPP(_WID_##name##_START), TPP(_WID_##name##_NEXT) = TPP(_WID_##name##_START) - 1,
#include "tpp-defs.inl"
#undef WARNING_NAMESPACE
#undef WARNING
	TPP(W_COUNT)
};


enum { /* Figure out effective warning ID. */
#define EXTENSION(name, str, default) TPP(name),
#include "tpp-defs.inl"
#undef EXTENSION
	TPP(EXT_COUNT)
};


/* Without the ident/sccs extension, disable the insert-comment callback. */
#if (defined(TPP_CONFIG_EXTENSION_IDENT_SCCS) && !TPP_CONFIG_EXTENSION_IDENT_SCCS)
#undef TPP_CONFIG_NO_CALLBACK_INS_COMMENT
#undef TPP_CONFIG_CALLBACK_INS_COMMENT
#undef TPP_CONFIG_DYN_CALLBACK_INS_COMMENT
#define TPP_CONFIG_NO_CALLBACK_INS_COMMENT 1
#endif


/* Figure out which callbacks should be dynamically linked at runtime. */
#undef TPP_CONFIG_DYN_CALLBACK_PARSE_PRAGMA
#undef TPP_CONFIG_DYN_CALLBACK_PARSE_PRAGMA_GCC
#undef TPP_CONFIG_DYN_CALLBACK_INS_COMMENT
#undef TPP_CONFIG_DYN_CALLBACK_NEW_TEXTFILE
#undef TPP_CONFIG_DYN_CALLBACK_UNKNOWN_FILE
#if (!defined(TPP_CONFIG_NO_CALLBACK_PARSE_PRAGMA) && \
     !defined(TPP_CONFIG_CALLBACK_PARSE_PRAGMA))
#define TPP_CONFIG_DYN_CALLBACK_PARSE_PRAGMA 1
#endif /* ... */
#if (!defined(TPP_CONFIG_NO_CALLBACK_PARSE_PRAGMA_GCC) && \
     !defined(TPP_CONFIG_CALLBACK_PARSE_PRAGMA_GCC))
#define TPP_CONFIG_DYN_CALLBACK_PARSE_PRAGMA_GCC 1
#endif /* ... */
#if (!defined(TPP_CONFIG_NO_CALLBACK_INS_COMMENT) && \
     !defined(TPP_CONFIG_CALLBACK_INS_COMMENT))
#define TPP_CONFIG_DYN_CALLBACK_INS_COMMENT 1
#endif /* ... */
#if (!defined(TPP_CONFIG_NO_CALLBACK_NEW_TEXTFILE) && \
     !defined(TPP_CONFIG_CALLBACK_NEW_TEXTFILE))
#define TPP_CONFIG_DYN_CALLBACK_NEW_TEXTFILE 1
#endif /* ... */
#if (!defined(TPP_CONFIG_NO_CALLBACK_UNKNOWN_FILE) && \
     !defined(TPP_CONFIG_CALLBACK_UNKNOWN_FILE))
#define TPP_CONFIG_DYN_CALLBACK_UNKNOWN_FILE 1
#endif /* ... */
#if (defined(TPP_CONFIG_DYN_CALLBACK_PARSE_PRAGMA) ||     \
     defined(TPP_CONFIG_DYN_CALLBACK_PARSE_PRAGMA_GCC) || \
     defined(TPP_CONFIG_DYN_CALLBACK_INS_COMMENT) ||      \
     defined(TPP_CONFIG_DYN_CALLBACK_NEW_TEXTFILE) ||     \
     defined(TPP_CONFIG_DYN_CALLBACK_UNKNOWN_FILE))
#define TPP_CONFIG_DYN_CALLBACKS 1
#endif /* ... */


#ifdef TPP_CONFIG_DYN_CALLBACKS
struct TPPCallbacks {
	/* Optional user-hooks for implementing special preprocessor behavior.
	 * NOTE: Any function pointer in here may be specified as NULL. */
#ifdef TPP_CONFIG_DYN_CALLBACK_PARSE_PRAGMA
	/* Handle an unknown pragma.
	 *  - The lexer currently points to the pragma's first token
	 *    and is configured not to continue yielding tokens once
	 *    the pragma's effective end is reached, as well as
	 *    to ignore comment, space and LF tokens:
	 *    >> #pragma foo bar   // [foo][bar][EOF]
	 *    >> _Pragma("baz(2)") // [baz][(][2][)][EOF]
	 *    >> __pragma(x*y)     // [x][*][y][EOF]
	 * @return: 0: Unknown/errorous pragma.
	 * @return: 1: Successfully parsed the given pragma. */
	int (TPPCALL *c_parse_pragma)(void);
#endif /* TPP_CONFIG_DYN_CALLBACK_PARSE_PRAGMA */

#ifdef TPP_CONFIG_DYN_CALLBACK_PARSE_PRAGMA_GCC
	/* Same as `c_parse_pragma', but invoked for unknown GCC-namespace pragmas
	 * >> #pragma GCC visibility(push)
	 *                ^^^^^^^^^^ Invoked on this token */
	int (TPPCALL *c_parse_pragma_gcc)(void);
#endif /* TPP_CONFIG_DYN_CALLBACK_PARSE_PRAGMA_GCC */

#ifdef TPP_CONFIG_DYN_CALLBACK_INS_COMMENT
	/* Insert the given text into the ".comment" section of the current object file.
	 * @return: 0: Error occurred (Set a lexer error if not already set)
	 * @return: 1: Successfully inserted the given text. */
	int (TPPCALL *c_ins_comment)(struct TPPString *__restrict comment);
#endif /* TPP_CONFIG_DYN_CALLBACK_INS_COMMENT */

#ifdef TPP_CONFIG_DYN_CALLBACK_NEW_TEXTFILE
	/* Event-callback invoked when a textfile is included the first time.
	 * >> Very useful for generating dependency trees.
	 * NOTE: This function will only ever be called once
	 *       for any given file within the same lexer.
	 * @return: 0: Error occurred (Set a lexer error if not already set)
	 * @return: 1: Continue parsing (same as not filling in this member). */
	int (TPPCALL *c_new_textfile)(struct TPPFile *__restrict file, int is_system_header);
#endif /* TPP_CONFIG_DYN_CALLBACK_NEW_TEXTFILE */

#if TPP_CONFIG_DYN_CALLBACK_UNKNOWN_FILE
	/* Called when a given filename could not be found, allowing this
	 * function to attempt more voodoo-magic in an attempt to locate it.
	 * @param: mode:                    Set of `TPPLEXER_OPENFILE_FLAG_*' that are being used to open the file.
	 * @return: NULL:                   Still failed to find the file (unless a lexer error was set, only emit a warning)
	 * @return: * :                     The file we now managed to successfully open.
	 * @return: TPP_UNKNOWN_FILE_RETRY: Instruct the file loader to try again (without invoking this function on that try)
	 * WARNING: This callback is responsible to caching the file in a keyword entry!
	 */
	struct TPPFile *(TPPCALL *c_unknown_file)(int mode, char *__restrict filename,
	                                          size_t filename_size,
	                                          struct TPPKeyword **pkeyword_entry);
#endif /* TPP_CONFIG_DYN_CALLBACK_UNKNOWN_FILE */
};
#endif /* TPP_CONFIG_DYN_CALLBACKS */

#ifndef TPP_CONFIG_NO_CALLBACK_UNKNOWN_FILE
/* Return value by `c_unknown_file' to indicate that the open should be re-attempted. */
#define TPP_UNKNOWN_FILE_RETRY ((struct TPPFile *)-1)
#endif /* !TPP_CONFIG_NO_CALLBACK_UNKNOWN_FILE */


struct TPPWarningStateEx {   /* Extended state for a 0b11-warning (aka. `WSTATE_SUPPRESS'). */
	int           wse_wid;      /* Warning/group ID. */
	unsigned int  wse_suppress; /* Amount of remaining times this warning should be suppressed.
	                             * NOTE: When ZERO(0), this slot is unused.
	                             * NOTE: When (unsigned int)-1, this the current state is `WSTATE_ERROR'. */
#ifdef __INTELLISENSE__
	wstate_t      wse_oldstate; /* Old warning state to return to after suppression ends.
	                             * NOTE: Never `WSTATE_SUPPRESS' */
#else /* __INTELLISENSE__ */
	TPP(wstate_t) wse_oldstate; /* Old warning state to return to after suppression ends.
	                             * NOTE: Never `WSTATE_SUPPRESS' */
#endif /* !__INTELLISENSE__ */
};
#define TPP_WARNING_BITS       2 /* One of WSTATE_*. */
#define TPP_WARNING_TOTAL      (TPP(WG_COUNT) + TPP(W_COUNT))
#define TPP_WARNING_BITSETSIZE (((TPP_WARNING_TOTAL * TPP_WARNING_BITS + 7)) / 8)
struct TPPWarningState {
	/* Bitset describing the current warning state.
	 * NOTE: Warning groups come before warning numbers. */
	uint8_t                   ws_state[TPP_WARNING_BITSETSIZE];
	uint8_t                   ws_padding[sizeof(void *) - (TPP_WARNING_BITSETSIZE % sizeof(void *))]; /* Force pointer-alignment. */
	size_t                    ws_extendeda; /* Allocated members for the `ws_extendedv' vector. */
	struct TPPWarningStateEx *ws_extendedv; /* [0..ws_extendedc|alloc(ws_extendeda)][owned] Extended warning state data (Sorted by `wse_num'). */
	struct TPPWarningState   *ws_prev;      /* [0..1][owned_if(!= &:w_basestate)] Previous warning state.
	                                         * NOTE: Always NULL if `self == &:w_basestate' */
};
struct TPPWarnings {
	struct TPPWarningState *w_curstate;  /* [1..1][owned_if(!= &w_basestate)] Current warning state. */
	struct TPPWarningState  w_basestate; /* Base (aka. first) warning state. */
};

/* Push/Pop the current warning state.
 * @return: 0: [TPPLexer_PushWarnings] Not enough available memory. (TPP_CONFIG_SET_API_ERROR)
 * @return: 0: [TPPLexer_PopWarnings] No older warning state was available to restore.
 * @return: 1: Successfully pushed/popped the warnings. */
TPPFUN int TPPCALL TPPLexer_PushWarnings(void);
TPPFUN int TPPCALL TPPLexer_PopWarnings(void);

/* Set the state of a given warning number.
 * NOTE: If the given state is `WSTATE_SUPPRESS', ONE(1)
 *       will be added to the suppress recursion counter.
 * @return: 0: Not enough available memory. (TPP_CONFIG_SET_API_ERROR)
 * @return: 1: Successfully set the given warning number.
 * @return: 2: The given warning number is unknown. */
TPPFUN int TPPCALL TPPLexer_SetWarning(int wnum, TPP(wstate_t) state);
TPPFUN int TPPCALL TPPLexer_SetWarningGroup(int wgrp, TPP(wstate_t) state);
TPPFUN TPP(wstate_t) TPPCALL TPPLexer_GetWarning(int wnum);
TPPFUN TPP(wstate_t) TPPCALL TPPLexer_GetWarningGroup(int wgrp);

/* Similar to `TPPLexer_SetWarning', but set the state of all warnings from a given group.
 * NOTES:
 *   - Groups work independent of warning ids, meaning you can even
 *     specify `WSTATE_SUPPRESS' as state, with the next warning
 *     part of that group occurring simply consuming that suppression.
 *   - If you disable an entire warning group, no warning apart of it will be emit.
 *   - If a warning is invoked, that is both part of an error and a warning/disabled
 *     group it will always tend to do as little damage as possible:
 *     >> suppress >= disabled >= warning >= error
 *     With that in mind, both the warning itself, as well as all of its groups
 *     must be configured as `WSTATE_FATAL' for the warning to actually result
 *     in an error.
 * @return: 0: Not enough available memory. (TPP_CONFIG_SET_API_ERROR)
 * @return: 1: Successfully set the given warning number.
 * @return: 2: The given group name is unknown. */
TPPFUN int TPPCALL TPPLexer_SetWarnings(char const *__restrict group, TPP(wstate_t) state);
TPPFUN TPP(wstate_t) TPPCALL TPPLexer_GetWarnings(char const *__restrict group);

/* Invoke a given warning number, returning one of `TPP_WARNINGMODE_*'.
 * NOTE: Unknown warnings will always result in `TPP_WARNINGMODE_WARN' being returned. */
TPPFUN int TPPCALL TPPLexer_InvokeWarning(int wnum);
#define TPP_WARNINGMODE_FATAL  0 /* Emit an error and call TPPLexer_SetErr(). */
#define TPP_WARNINGMODE_ERROR  1 /* Emit an error, but continue normally. */
#define TPP_WARNINGMODE_WARN   2 /* Emit a warning, but continue normally. */
#define TPP_WARNINGMODE_IGNORE 3 /* Do nothing and continue normally (NOTE: If the warning was just suppressed, its ). */


struct TPPIfdefStackSlot {
#define TPP_IFDEFMODE_FALSE 0 /* The block is disabled. */
#define TPP_IFDEFMODE_TRUE  1 /* FLAG: The block is enabled. */
#define TPP_IFDEFMODE_ELSE  2 /* FLAG: The block follows an #else. */
	int             iss_mode; /* Slot mode (Used to differentiate between #if, #elif and #else regions). */
	TPP(line_t)     iss_line; /* ZERO-based line in which this slot was last updated (Used in warning messages). */
	struct TPPFile *iss_file; /* [1..1] The file that owns this #ifdef slot
	                           * NOTE: This file _must_ be part of the #include stack!
	                           * WARNING: This is not a reference and relies on the file
	                           *          being kept alive through the #include stack.
	                           * HINT: Also used to pop all unclosed blocks when a file ends. */
};
struct TPPIfdefStack {
	size_t                    is_slotc; /* Amount of #ifdef slots in use. */
	size_t                    is_slota; /* Allocated amount of #ifdef slots. */
	struct TPPIfdefStackSlot *is_slotv; /* [0..is_slotc|alloc(is_slota)][owned] Vector of #ifdef slots. */
};
#define TPP_EXTENSIONS_BITSETSIZE (TPP(EXT_COUNT) ? (TPP(EXT_COUNT) + 7) / 8 : 1)
struct TPPExtState {
	struct TPPExtState *es_prev; /* [0..1][owned] Previous extension state. */
	uint8_t             es_bitset[TPP_EXTENSIONS_BITSETSIZE]; /* Bitset of enabled extensions. */
	uint8_t             es_padding[sizeof(void *) - (TPP_EXTENSIONS_BITSETSIZE % sizeof(void *))];
};

/* Check if a given extension `ext' is currently enabled.
 * @return: 0: The extension is disabled.
 * @return: !0: The extension is enabled. */
#define TPPLexer_HasExtension(ext) \
	(TPPLexer_Current->l_extensions.es_bitset[(ext) / 8] & (1 << ((ext) % 8)))

/* Set the state of a given extension `ext'. */
#define TPPLexer_EnableExtension(ext)  (void)(TPPLexer_Current->l_extensions.es_bitset[(ext) / 8] |= (1 << ((ext) % 8)))
#define TPPLexer_DisableExtension(ext) (void)(TPPLexer_Current->l_extensions.es_bitset[(ext) / 8] &= ~(1 << ((ext) % 8)))

struct TPPIncludeList {
	/* List of sanitized #include paths. */
	struct TPPIncludeList    *il_prev;  /* [0..1][owned] Pointer to another m-allocated list of system #include-paths.
	                                     *                This field is used to implement system #include-path push/pop. */
	size_t                    il_pathc; /* Amount of elements in the vector below. */
	/*ref*/struct TPPString **il_pathv; /* [1..1][0..il_pathc][owned] Vector of sanitized #include path. */
};

/* Push/Pop the current system #include-path list.
 * @return: 0: [TPPLexer_PushInclude] Not enough available memory. (TPP_CONFIG_SET_API_ERROR)
 * @return: 0: [TPPLexer_PopInclude] No older #include-path list was available to restore.
 * @return: 1: Successfully pushed/popped the system #include-path list. */
TPPFUN int TPPCALL TPPLexer_PushInclude(void);
TPPFUN int TPPCALL TPPLexer_PopInclude(void);

/* Add/delete the given path from the list of system #include paths.
 * WARNING: This function will modify the given path.
 * WARNING: Be careful with absolute vs. relative paths!
 *          TPP can not tell that they're the same and
 *          `#pragma once' might break as a consequence!
 *       >> As a solution, _always_ use either absolute
 *          or relative paths for the same file/path.
 *         (This also goes for #include directives)
 * @return: 0: [TPPLexer_AddIncludePath] Not enough available memory. (TPP_CONFIG_SET_API_ERROR)
 * @return: 1: [TPPLexer_AddIncludePath] The given path was successfully added.
 * @return: 2: [TPPLexer_AddIncludePath] The given path had already been added before.
 * @return: 0: [TPPLexer_DelIncludePath] The given path was not found.
 * @return: 1: [TPPLexer_DelIncludePath] The given path was successfully removed. */
TPPFUN int TPPCALL TPPLexer_AddIncludePath(char *__restrict path, size_t pathsize);
TPPFUN int TPPCALL TPPLexer_DelIncludePath(char *__restrict path, size_t pathsize);


#ifndef TPP_CONFIG_NO_ASSERTIONS
struct TPPAssertion {
	struct TPPAssertion *as_next; /* [0..1][owned] Next assertion. */
	struct TPPKeyword   *as_kwd;  /* [1..1][const] Keyword associated with this assertion. */
};
struct TPPAssertions {
	/* s.a.: `https://gcc.gnu.org/onlinedocs/cpp/Obsolete-Features.html' */
	size_t                as_assc; /* Amount of defined assertions. */
	size_t                as_assa; /* Allocated amount of assertions. */
	struct TPPAssertion **as_assv; /* [0..1][owned][0..as_alloc][owned] Hash-map of existing assertions. */
};
#endif /* !TPP_CONFIG_NO_ASSERTIONS */

struct TPPRareKeyword {
	/* Keyword-specific data that is only rarely used. */
	/*ref*/struct TPPFile    *kr_file;     /* [0..1] Set if this keyword is actually the name of a file, when that file was already included.
	                                        *        Used to track recursive file-inclusion, as well as quickly dismiss guarded files and
	                                        *        speed up determining the correct filename for `include_next'.
	                                        *  NOTE: Sadly, this cannot simply be made into a union with `k_macro', as a filename could
	                                        *        potentially be equal to a keyword (e.g.: `#include "header"' vs. `#define header 42') */
	/*ref*/struct TPPFile    *kr_oldmacro; /* [0..1][linked_list(->f_hashnext...)] Linked list of old (aka. pushed) version of this macro. */
	/*ref*/struct TPPFile    *kr_defmacro; /* [0..1] Default macro definition (backup of the original, builtin macro when re-defined by the
	                                        *        user). This macro file is restored as the active macro when lexer macros are reset and
	                                        *        the `TPP_KEYWORDFLAG_BUILTINMACRO' keyword flag is set below. */
#define TPP_KEYWORDFLAG_NONE                   0x00000000 /* No special flags (default) */
#define TPP_KEYWORDFLAG_BUILTINMACRO           0x20000000 /* An explicitly defined builtin macro-definition, that can't be #undef'ed */
#define TPP_KEYWORDFLAG_NO_UNDERSCORES         0x40000000 /* When looking up keyword flags, don't allow this keyword to alias another with additional underscores at the front and back:
                                                           * >> __has_feature(__tpp_dollar_is_alpha__) // If `tpp_dollar_is_alpha' doesn't have this flag set, it can alias `__tpp_dollar_is_alpha__' */
#define TPP_KEYWORDFLAG_IMPORTED               0x80000000 /* Set for for files after they've been #import-ed. */
#if !defined(TPP_CONFIG_LOCKED_KEYWORDS) || TPP_CONFIG_LOCKED_KEYWORDS
#define TPP_KEYWORDFLAG_LOCKED                 0x00000200 /* Any attempts at defining or deleting a macro for this keyword using #define or #undef are denied. */
#endif /* TPP_CONFIG_LOCKED_KEYWORDS */
	/* NOTE: These flags share their values with those
	 *       from the old TPP for backwards compatibility. */
#define TPP_KEYWORDFLAG_HAS_ATTRIBUTE          0x00000001 /* `__has_attribute()' */
#define TPP_KEYWORDFLAG_HAS_BUILTIN            0x00000002 /* `__has_builtin()' */
#define TPP_KEYWORDFLAG_HAS_CPP_ATTRIBUTE      0x00000004 /* `__has_cpp_attribute()' */
#define TPP_KEYWORDFLAG_HAS_DECLSPEC_ATTRIBUTE 0x00000008 /* `__has_declspec_attribute()' */
#define TPP_KEYWORDFLAG_HAS_EXTENSION          0x00000010 /* `__has_extension()' */
#define TPP_KEYWORDFLAG_HAS_FEATURE            0x00000020 /* `__has_feature()' */
#define TPP_KEYWORDFLAG_IS_DEPRECATED          0x00000040 /* Warn when the keyword appears as the result of lexical processing. */
#define TPP_KEYWORDFLAG_IS_POISONED            0x00000080 /* Extension for `TPP_KEYWORDFLAG_IS_DEPRECATED':
                                                           * Don't emit a warning if the keyword is used inside of a macro.
                                                           * -> Only warn if it is used from a text file. */
#define TPP_KEYWORDFLAG_HAS_TPP_BUILTIN        0x00000100 /* The keyword is a __builtin-function available for use in preprocessor expressions. */
#define TPP_KEYWORDFLAG_USERMASK               0x0000007f /* Set of flags modifiable through `#pragma tpp_set_keyword_flags()'. */
	uint32_t                  kr_flags;    /* A set of `TPP_KEYWORDFLAG_*'. */
	TPP(tint_t)               kr_counter;  /* Counter value used by `__TPP_COUNTER()' */
#ifndef TPP_CONFIG_NO_ASSERTIONS
	struct TPPAssertions      kr_asserts;  /* Assertions (aka. #assert/#unassert associated with this keyword) */
#endif /* !TPP_CONFIG_NO_ASSERTIONS */
	void                     *kr_user;     /* User-defined meaning; initialized to NULL. */
};

struct TPPKeyword {
	       struct TPPKeyword *k_next;     /* [0..1][owned] Pointer to another keyword entry with the same hash. */
	/*ref*/struct TPPFile    *k_macro;    /* [0..1] Macro currently associated with this keyword. */
	struct TPPRareKeyword    *k_rare;     /* [0..1][owned] Rare keyword data. */
#ifdef __INTELLISENSE__
	    tok_t                 k_id;       /* [const] Unique token ID associated with this keyword. */
#else /* __INTELLISENSE__ */
	TPP(tok_t)                k_id;       /* [const] Unique token ID associated with this keyword. */
#endif /* !__INTELLISENSE__ */
#if __SIZEOF_POINTER__ > __SIZEOF_INT__
	uint8_t                   k_pad[sizeof(void *) - sizeof(int)];
#endif /* __SIZEOF_POINTER__ > __SIZEOF_INT__ */
	size_t                    k_size;     /* [const] Size of the keyword (in characters). */
	TPP(hash_t)               k_hash;     /* [const] The hash-value of the keyword. */
	char                      k_name[TPP_SYMARRAY_SIZE]; /* [const][k_size] name of this keyword (HINT: doesn't contain unescaped linefeeds). */
/*	char                      k_zero;     /* [const][== 0] Ensure ZERO-termination of the keyword name. */
};
#define TPPKeyword_ISDEFINED(self) ((self)->k_macro != NULL || TPP_ISBUILTINMACRO((self)->k_id))
#define TPPKeyword_MAKERARE(self)                                  \
	((self)->k_rare || ((self)->k_rare = (struct TPPRareKeyword *) \
	                    calloc(1, sizeof(struct TPPRareKeyword))) != NULL)
#ifdef TPP_HASHOF
#define TPPKeyword_EQUALS(self, constant_string)                       \
	((self)->k_hash == TPP_HASHOF(constant_string) &&                  \
	 (self)->k_size == (sizeof(constant_string) / sizeof(char)) - 1 && \
	 memcmp((self)->k_name, constant_string, sizeof(constant_string) - sizeof(char)) == 0)
#else /* TPP_HASHOF */
#define TPPKeyword_EQUALS(self, constant_string)                       \
	((self)->k_size == (sizeof(constant_string) / sizeof(char)) - 1 && \
	 memcmp((self)->k_name, constant_string, sizeof(constant_string) - sizeof(char)) == 0)
#endif /* !TPP_HASHOF */


/* Returns the effective keyword flags of `self'.
 * @return: A set of `TPP_KEYWORDFLAG_*' */
TPPFUN uint32_t TPPCALL TPPKeyword_GetFlags(struct TPPKeyword const *__restrict self,
                                            int check_without_underscores);


struct TPPKeywordMap {
	size_t              km_entryc;  /* Amount of keyword entries stored. */
	size_t              km_bucketc; /* Used amount of buckets. */
	struct TPPKeyword **km_bucketv; /* [0..1][owned][0..km_bucketc][owned]
	                                 * Resizable keyword hash-map vector. */
};
/* When this evaluates to true, TPP attempts to rehash the keyword map to `km_entryc' entries. */
#define TPPKeywordMap_SHOULDHASH(self) \
	((self)->km_entryc >= (self)->km_bucketc * 2)

struct TPPToken {
	TPP(tok_t)              t_id;    /* The symbol/keyword ID of this token. */
	unsigned long           t_num;   /* The token number (incremented every time a new token is yielded). */
	/*ref*/struct TPPFile  *t_file;  /* [1..1] File associated with this token. */
	char                   *t_begin; /* [1..1][<= t_end] Token text start pointer. */
	char                   *t_end;   /* [1..1][>= t_begin] Token text end pointer. */
	struct TPPKeyword      *t_kwd;   /* [0..1] Set when `t_id' is a keyword (WARNING: Not always updated during yield; check `TPP_ISKEYWORD(t_id)' before using). */
};

/* Returns the top-level source locations (in-macro & everything)
 * NOTE: These are _not_ what you're probably looking for.
 *       You probably expect these to act like __FILE__ and __LINE__,
 *       but instead they will show the true source locations where the
 *       current token originates from (e.g.: from a macro definition.)
 *    >> To get information about the source file you must walk the
 *       current token's t_file->f_prev->... chain until you reach
 *       a text file. Then, taking that file, use it and its f_pos
 *       pointers to figure out what you actually want to know. */
#define TPPLexer_TRUE_FILE(plength) TPPFile_Filename(TPPLexer_Current->l_token.t_file, plength)
#define TPPLexer_TRUE_LC(info)      TPPFile_LCAt(TPPLexer_Current->l_token.t_file, info, TPPLexer_Current->l_token.t_begin)
#define TPPLexer_TRUE_LINE()        TPPFile_LineAt(TPPLexer_Current->l_token.t_file, TPPLexer_Current->l_token.t_begin)
#define TPPLexer_TRUE_COLUMN()      TPPFile_ColumnAt(TPPLexer_Current->l_token.t_file, TPPLexer_Current->l_token.t_begin)

/* Returns the top-most text file associated with the current lexer.
 * NOTE: These functions never returns NULL. */
TPPFUN struct TPPFile *TPPCALL TPPLexer_Textfile(void);
TPPFUN struct TPPFile *TPPCALL TPPLexer_Basefile(void);

#define TPPLexer_FILE(plength)     TPPFile_Filename(TPPLexer_Textfile(), plength)
#define TPPLexer_BASEFILE(plength) TPPFile_Filename(TPPLexer_Basefile(), plength)
TPP_LOCAL void TPPCALL TPPLexer_LC(struct TPPLCInfo *__restrict info) { struct TPPFile *f = TPPLexer_Textfile(); TPPFile_LCAt(f, info, f->f_pos); }
TPP_LOCAL TPP(line_t) TPPCALL TPPLexer_LINE(void) { struct TPPFile *f = TPPLexer_Textfile(); return TPPFile_LineAt(f, f->f_pos); }
TPP_LOCAL TPP(col_t) TPPCALL TPPLexer_COLUMN(void) { struct TPPFile *f = TPPLexer_Textfile(); return TPPFile_ColumnAt(f, f->f_pos); }


/* Saved lexer position (can be restore to rewind the lexer)
 * When wanting to rewind the lexer, flags must be set as follows (+: set; -: clear)
 *  [+] TPPLEXER_FLAG_NO_DIRECTIVES     (Disallow directives since rewinding them isn't possible
 *                                      If a macro were to be deleted or defined, we'd not be
 *                                      able to undo that)
 *  [+] TPPLEXER_FLAG_EXTENDFILE        (Don't discard already-read data)
 *  [-] TPPLEXER_FLAG_WERROR            (You probably don't want errors)
 *  [+] TPPLEXER_FLAG_NO_WARNINGS       (You probably don't want warnings enabled...)
 *  [+] TPPLEXER_FLAG_WILLRESTORE       (Prevent some internal events from firing)
 * WARNING:
 *  - __TPP_RANDOM will yield different results after rewinding!
 *  - __TPP_COUNTER and __COUNTER__ will not be reset during rewinding!
 */
struct TPPLexerFilePosition {
	/*ref*/struct TPPFile *tlfp_file; /* [1..1] The file to restore. */
	ptrdiff_t              tlfp_pos;  /* File position to restore (relative to `tlfp_file->f_begin'). */
};
struct TPPLexerPosition {
	TPP(tok_t)                   tlp_tok_id;    /* The symbol/keyword ID of this token. */
	unsigned long                tlp_tok_num;   /* The token number (incremented every time a new token is yielded). */
	ptrdiff_t                    tlp_tok_begin; /* [<= tlp_tok_end] Token text start pointer (relative to `tlp_filev[tlp_filec-1].tlfp_file->f_begin'). */
	ptrdiff_t                    tlp_tok_end;   /* [>= tlp_tok_begin] Token text end pointer. */
	struct TPPKeyword           *tlp_tok_kwd;   /* [0..1] Set when `t_id' is a keyword (WARNING: Not always updated during yield; check `TPP_ISKEYWORD(t_id)' before using). */
	size_t                       tlp_filec;     /* # of files to restore from the #include-stack. */
	struct TPPLexerFilePosition *tlp_filev;     /* [0..tlp_filec] Vector of files to restore. */
	uint32_t                     tlp_flags;     /* Old lexer flags. */
};

/* Save/restore the lexer position (during save: lexer flags are altered as documented above)
 * @return: 1 : Success
 * @return: 0 : Error */
TPPFUN int TPPCALL TPPLexer_SavePosition(struct TPPLexerPosition *__restrict self);
TPPFUN void TPPCALL TPPLexer_LoadPosition(struct TPPLexerPosition *__restrict self);



/* Lexer state flags. */
#define TPPLEXER_FLAG_NONE                   0x00000000
#define TPPLEXER_FLAG_WANTCOMMENTS           0x00000001 /* Emit COMMENT tokens. */
#define TPPLEXER_FLAG_WANTSPACE              0x00000002 /* Emit SPACE tokens. */
#define TPPLEXER_FLAG_WANTLF                 0x00000004 /* Emit LF tokens. */
#define TPPLEXER_FLAG_NO_SEEK_ON_EOB         0x00000008 /* Don't seek the next chunk when the current one ends (instead, signal EOF). */
#define TPPLEXER_FLAG_NO_POP_ON_EOF          0x00000010 /* Don't pop the top file when an EOF occurs. */
#define TPPLEXER_FLAG_KEEP_MACRO_WHITESPACE  0x00000020 /* Keep whitespace tokens around the front and back of macro texts. */
#ifdef TPP_CONFIG_NONBLOCKING_IO
#define TPPLEXER_FLAG_NONBLOCKING            0x00000040 /* Enable non-blocking I/O in files that support that flag.
                                                         * When enabled, the lexer will produce EOF tokens in text files
                                                         * with the `TPP_TEXTFILE_FLAG_NONBLOCK' flag set, if the current
                                                         * text location is desirable for such behavior (i.e. no trailing
                                                         * unescaped linefeeds, or unfinished comments or strings), if
                                                         * reading data from the source stream would block.
                                                         * For convenience, you may use `TPPLexer_Yield*NB()' to set this
                                                         * flag for a single call. */
#endif /* TPP_CONFIG_NONBLOCKING_IO */
#define TPPLEXER_FLAG_TERMINATE_STRING_LF    0x00000080 /* Terminate character/string sequences when a linefeed is detected (also emit a warning in that case). */
#define TPPLEXER_FLAG_NO_DIRECTIVES          0x00000100 /* Disable evaluation of preprocessor directives. */
#define TPPLEXER_FLAG_NO_MACROS              0x00000200 /* Disable expansion of macros (user defined only; builtin must be disabled explicitly with `TPPLEXER_FLAG_NO_BUILTIN_MACROS'). */
#define TPPLEXER_FLAG_NO_BUILTIN_MACROS      0x00000400 /* When set, don't expand _any_ builtin macros (such as __FILE__ and __LINE__). */
#define TPPLEXER_FLAG_ASM_COMMENTS           0x00000800 /* Suppress warnings for unknown/invalid preprocessor directives, instead either emitting them as `TOK_COMMENT' or ignoring them based on `TPPLEXER_FLAG_WANTCOMMENTS'. */
#define TPPLEXER_FLAG_DIRECTIVE_NOOWN_LF     0x00001000 /* Linefeeds terminating preprocessor directives are not part of those directives and are instead re-emit (Meaningless without `TPPLEXER_FLAG_WANTLF').
                                                         * WARNING: Using this flag is not recommended, as a freshly defined macro will modify
                                                         *          text from the file and set the first character of that linefeed to `\0'. */
#define TPPLEXER_FLAG_COMMENT_NOOWN_LF       0x00002000 /* Linefeeds terminating a `// foo'-style comment are not owned by that comment, but are re-emit (Meaningless without `TPPLEXER_FLAG_WANTLF'). */
#define TPPLEXER_FLAG_MESSAGE_LOCATION       0x00004000 /* Print the file+line location in messages from `#pragma message'. */
#define TPPLEXER_FLAG_MESSAGE_NOLINEFEED     0x00008000 /* Don't print a linefeed following the user-provided message in `#pragma message'. */
#define TPPLEXER_FLAG_INCLUDESTRING          0x00010000 /* Parse strings as #include strings (without \-escape sequences). (WARNING: system-style (<...>) strings must be handled manually by the caller) */
#define TPPLEXER_FLAG_EXTENDFILE             0x00020000 /* Set the `TPPFILE_NEXTCHUNK_FLAG_EXTEND' flag when loading more file data. */
#define TPPLEXER_FLAG_NO_LEGACY_GUARDS       0x00040000 /* Don't recognize legacy #include-guards
                                                         * WARNING: Not setting this option may lead to whitespace and comments at the
                                                         *          start and end of a guarded file to not be emit on a second pass.
                                                         *       >> Enable this option when your compiler is sensitive to whitespace
                                                         *          in situations such as these. */
#define TPPLEXER_FLAG_WERROR                 0x00080000 /* All warnings are turned into errors (NOTE: less powerful than `TPPLEXER_FLAG_WSYSTEMHEADERS'). */
#define TPPLEXER_FLAG_WSYSTEMHEADERS         0x00100000 /* Still emit warnings in system headers (alongside errors). */
#define TPPLEXER_FLAG_NO_DEPRECATED          0x00200000 /* Don't warn about deprecated or poisoned keywords. */
#define TPPLEXER_FLAG_MSVC_MESSAGEFORMAT     0x00400000 /* Use msvc's file+line format `%s(%d,%d) : ' instead of GCC's `%s:%d:%d: '. */
#define TPPLEXER_FLAG_NO_WARNINGS            0x00800000 /* Don't emit warnings. */
#define TPPLEXER_FLAG_NO_ENCODING            0x01000000 /* Don't try to detect file encodings (Everything is UTF-8 without BOM; aka. raw text). */
#define TPPLEXER_FLAG_REEMIT_UNKNOWN_PRAGMA  0x02000000 /* Re-emit unknown pragmas. */
#define TPPLEXER_FLAG_CHAR_UNSIGNED          0x04000000 /* When set, character-constants are unsigned. */
#define TPPLEXER_FLAG_EOF_ON_PAREN           0x08000000 /* When set, recursively track `(`...`)' pairs and yield EOF when `l_eof_paren' reaches ZERO(0). */
#define TPPLEXER_FLAG_WILLRESTORE            0x10000000 /* A preceding lexer position will be restored (don't fire internal events that could pose problems with this) */
/*                                           0x20000000 /* ... */
#define TPPLEXER_FLAG_RANDOM_INITIALIZED     0x40000000 /* Set when rand() has been initialized. */
#define TPPLEXER_FLAG_ERROR                  0x80000000 /* When set, the lexer is in an error-state in which calls to yield() will return TOK_ERR. */
#define TPPLEXER_FLAG_MERGEMASK              0xe0000000 /* A mask of flags that are merged (or'd together) during popf(). */
#define TPPLEXER_FLAG_DEFAULT                0x00000000 /* Default set of flags (suitable for use with most token-based compilers). */
/* A mask of flags that are preserved when modified by #pragma directives.
 * WARNING: `TPPLEXER_FLAG_MERGEMASK' must not be part of this mask.
 * WARNING: `TPPLEXER_FLAG_NO_MACROS|TPPLEXER_FLAG_NO_DIRECTIVES|TPPLEXER_FLAG_NO_BUILTIN_MACROS'
 *           must not be part of this mask, as these flags may
 *           contain custom values while pragmas are executed. */
#define TPPLEXER_FLAG_PRAGMA_KEEPMASK                                          \
	(TPPLEXER_FLAG_KEEP_MACRO_WHITESPACE | TPPLEXER_FLAG_TERMINATE_STRING_LF | \
	 TPPLEXER_FLAG_ASM_COMMENTS | TPPLEXER_FLAG_MESSAGE_LOCATION |             \
	 TPPLEXER_FLAG_MESSAGE_NOLINEFEED | TPPLEXER_FLAG_EXTENDFILE |             \
	 TPPLEXER_FLAG_NO_LEGACY_GUARDS | TPPLEXER_FLAG_WERROR |                   \
	 TPPLEXER_FLAG_WSYSTEMHEADERS | TPPLEXER_FLAG_NO_DEPRECATED |              \
	 TPPLEXER_FLAG_MSVC_MESSAGEFORMAT | TPPLEXER_FLAG_NO_WARNINGS |            \
	 TPPLEXER_FLAG_NO_ENCODING | TPPLEXER_FLAG_REEMIT_UNKNOWN_PRAGMA |         \
	 TPPLEXER_FLAG_CHAR_UNSIGNED | TPPLEXER_FLAG_WILLRESTORE)



/* Recognized extension token flags. */
#define TPPLEXER_TOKEN_NONE                  0x00000000
#define TPPLEXER_TOKEN_TILDETILDE            0x00000001 /* Enable recognition of `~~' tokens. */
#define TPPLEXER_TOKEN_ROOFROOF              0x00000002 /* Enable recognition of `^^' tokens. */
#define TPPLEXER_TOKEN_COLONCOLON            0x00000004 /* Enable recognition of `::' tokens. */
#define TPPLEXER_TOKEN_COLONASSIGN           0x00000008 /* Enable recognition of `:=' tokens. */
#define TPPLEXER_TOKEN_STARSTAR              0x00000010 /* Enable recognition of `**' and `**=' tokens. */
#define TPPLEXER_TOKEN_ARROW                 0x00000020 /* Enable recognition of `->' tokens. */
#define TPPLEXER_TOKEN_ARROWSTAR             0x00000040 /* Enable recognition of `->*' tokens. */
#define TPPLEXER_TOKEN_DOTSTAR               0x00000080 /* Enable recognition of `.*' tokens. */
#define TPPLEXER_TOKEN_DOTDOT                0x00000100 /* Enable recognition of `..' tokens. */
#define TPPLEXER_TOKEN_ATEQUAL               0x00000200 /* Enable recognition of `@=' tokens. */
#define TPPLEXER_TOKEN_C_COMMENT             0x00000400 /* Enable recognition of `/[]* comment *[]/' tokens. */
#define TPPLEXER_TOKEN_CPP_COMMENT           0x00000800 /* Enable recognition of `// comment' tokens. */
#define TPPLEXER_TOKEN_ANGLE3                0x00001000 /* Enable recognition of `<<<' and `>>>' tokens. */
#define TPPLEXER_TOKEN_ANGLE3_EQUAL          0x00002000 /* Enable recognition of `<<<=' and `>>>=' tokens. */
#define TPPLEXER_TOKEN_LOGT                  0x00004000 /* Enable recognition of `<>' tokens. */
#define TPPLEXER_TOKEN_EQUALBINOP            0x00008000 /* Enable recognition of `=+', `=-', `=*', `=/', `=%', `=&', `=|', `=^', `=<<', `=>>', `=>>>', `=<<<', `=@' and `=**' tokens (NOTE: These are all aliasing the regular inplace versions).
                                                         * NOTE: Special token such as `=@' or `=<<<' are only available when other token extensions are enabled as well! */
#define TPPLEXER_TOKEN_EQUAL3                0x00010000 /* Enable recognition of `===' and `!==' tokens. */
#define TPPLEXER_TOKEN_QMARK_QMARK           0x00020000 /* Enable recognition of `??' tokens. */
#define TPPLEXER_TOKEN_DOLLAR                0x80000000 /* Recognize `$' as its own token (Supersedes `EXT_DOLLAR_IS_ALPHA'). */
#define TPPLEXER_TOKEN_DEFAULT               0x0fffffff /* Default set of extension tokens (enable all). */

/* Deprecated typos */
#define TPPLEXER_TOKEN_COLLONCOLLON TPPLEXER_TOKEN_COLONCOLON
#define TPPLEXER_TOKEN_COLLONASSIGN TPPLEXER_TOKEN_COLONASSIGN


/* Predefined set of extension tokens for some languages.
 * WARNING: Most of these languages will also need additional tweaks to other flags. */
#define TPPLEXER_TOKEN_LANG_C                          \
	(TPPLEXER_TOKEN_ARROW | TPPLEXER_TOKEN_C_COMMENT | \
	 TPPLEXER_TOKEN_CPP_COMMENT)
#define TPPLEXER_TOKEN_LANG_ASM                    \
	(TPPLEXER_TOKEN_DOLLAR | TPPLEXER_TOKEN_LOGT | \
	 TPPLEXER_TOKEN_C_COMMENT | TPPLEXER_TOKEN_CPP_COMMENT)
#define TPPLEXER_TOKEN_LANG_CPP                          \
	(TPPLEXER_TOKEN_COLONCOLON | TPPLEXER_TOKEN_ARROW |  \
	 TPPLEXER_TOKEN_ARROWSTAR | TPPLEXER_TOKEN_DOTSTAR | \
	 TPPLEXER_TOKEN_C_COMMENT | TPPLEXER_TOKEN_CPP_COMMENT)
#define TPPLEXER_TOKEN_LANG_JAVA \
	(TPPLEXER_TOKEN_C_COMMENT | TPPLEXER_TOKEN_CPP_COMMENT)
#define TPPLEXER_TOKEN_LANG_DEEMON                            \
	(TPPLEXER_TOKEN_COLONCOLON | TPPLEXER_TOKEN_COLONASSIGN | \
	 TPPLEXER_TOKEN_STARSTAR | TPPLEXER_TOKEN_ARROW |         \
	 TPPLEXER_TOKEN_C_COMMENT | TPPLEXER_TOKEN_CPP_COMMENT |  \
	 TPPLEXER_TOKEN_EQUAL3 | TPPLEXER_TOKEN_QMARK_QMARK)


struct TPPLexer {
	struct TPPToken       l_token;      /* The current token. */
	struct TPPFile       *l_eob_file;   /* [0..1] When non-NULL prevent seek_on_eob when this file is atop the stack.
	                                     * >> NOTE: This does the same as `TPPLEXER_FLAG_NO_SEEK_ON_EOB', but only for a specific file.
	                                     * >> Using this, you can restrict the lexer to a sub-space of a file, allowing
	                                     *    you to safely parse data until the current chunk of a given file ends. */
	struct TPPFile       *l_eof_file;   /* [0..1] Similar to `l_eob_file', but used for end-of-file instead. */
	uint32_t              l_flags;      /* A set of `TPPLEXER_FLAG_*' */
	uint32_t              l_extokens;   /* A set of `TPPLEXER_TOKEN_*' */
	struct TPPExtState    l_extensions; /* Enabled preprocessor features/extensions. */
	struct TPPKeywordMap  l_keywords;   /* Hash-map used to map keyword strings to their ids. */
	struct TPPIncludeList l_syspaths;   /* List of paths searched when looking for system #include files. */
	size_t                l_limit_mrec; /* Limit for how often a macro may recursively expand into itself. */
	size_t                l_limit_incl; /* Limit for how often the same text file may exist on the #include stack. */
	size_t                l_eof_paren;  /* Recursion counter used by the `TPPLEXER_FLAG_EOF_ON_PAREN' flag. */
	size_t                l_warncount;  /* Amount of warnings that were invoked (including those that were dismissed). */
	size_t                l_errorcount; /* Amount of errors that were invoked when compilation still continued. */
	size_t                l_maxerrors;  /* Max amount of errors (`l_errorcount') that should be ignored before they become fatal.
	                                     * NOTE: Defaults to `TPPLEXER_DEFAULT_LIMIT_ECNT'. */
	size_t                l_tabsize;    /* Width of `\t' tab characters (used for __COLUMN__ and in error messages).
	                                     * NOTE: Defaults to `TPPLEXER_DEFAULT_TABSIZE' */
	struct TPPIfdefStack  l_ifdef;      /* #ifdef stack. */
	struct TPPWarnings    l_warnings;   /* Current user-configured warnings state. */
#ifdef TPP_CONFIG_DYN_CALLBACKS
	struct TPPCallbacks   l_callbacks;  /* User-defined lexer callbacks. */
#endif /* TPP_CONFIG_DYN_CALLBACKS */
	TPP(tok_t)            l_noerror;    /* Old token ID before `TPPLEXER_FLAG_ERROR' was set. */
	TPP(tint_t)           l_counter;    /* Value returned the next time `__COUNTER__' is expanded (Initialized to ZERO(0)). */
};

#ifndef TPPLEXER_DEFAULT_LIMIT_ECNT
#define TPPLEXER_DEFAULT_LIMIT_ECNT 16  /* Default value of `l_errorcount' */
#endif /* !TPPLEXER_DEFAULT_LIMIT_ECNT */
#ifndef TPPLEXER_DEFAULT_LIMIT_MREC
#define TPPLEXER_DEFAULT_LIMIT_MREC 512 /* Even when generated text differs from previous version, don't allow more self-recursion per macro than this. */
#endif /* !TPPLEXER_DEFAULT_LIMIT_MREC */
#ifndef TPPLEXER_DEFAULT_LIMIT_INCL
#define TPPLEXER_DEFAULT_LIMIT_INCL 64  /* User attempts to #include a file more often that file will fail with an error message. */
#endif /* !TPPLEXER_DEFAULT_LIMIT_INCL */
#ifndef TPPLEXER_DEFAULT_TABSIZE
#if (defined(_WIN16) || defined(WIN16) || \
     defined(_WIN32) || defined(WIN32) || \
     defined(_WIN64) || defined(WIN64) || \
     defined(__WIN32__) || defined(__TOS_WIN__))
#define TPPLEXER_DEFAULT_TABSIZE    4   /* Default tab size (used for `__COLUMN__' and in error messages). */
#else /* Windows... */
#define TPPLEXER_DEFAULT_TABSIZE    8   /* Default tab size (used for `__COLUMN__' and in error messages). */
#endif /* Unix... */
#endif /* !TPPLEXER_DEFAULT_TABSIZE */

#if TPP_CONFIG_ONELEXER
#define TPPLexer_Current  (&TPPLexer_Global)
TPPFUN struct TPPLexer TPPLexer_Global;
#else /* TPP_CONFIG_ONELEXER */
/* [1..1] The currently selected lexer
 * >> When NULL, only certain parts of TPP can work without problems. */
TPPFUN struct TPPLexer *TPPLexer_Current;
#endif /* !TPP_CONFIG_ONELEXER */

/* Initialize/Finalize the given TPP Lexer object.
 * NOTE: These functions can (obviously) be called when
 *      `TPPLexer_Current' is NULL, or not initialized.
 * @return: 1: Successfully initialized the given lexer.
 * @return: 0: Not enough available memory to setup builtin keywords. (TPP_CONFIG_SET_API_ERROR) */
TPPFUN int  TPPCALL TPPLexer_Init(struct TPPLexer *__restrict self);
TPPFUN void TPPCALL TPPLexer_Quit(struct TPPLexer *__restrict self);

/* Clear the current ifdef-stack and warn about each entry.
 * @return: 1: Everything was ok, or no critical warning happened.
 * @return: 0: A critical warning happened. */
TPPFUN int TPPCALL TPPLexer_ClearIfdefStack(void);

/* Reset certain parts of the lexer.
 * NOTE: This function can be called when `TPPLexer_Current' is NULL, or not initialized.
 * @param: flags: Set of `TPPLEXER_RESET_*' */
TPPFUN void TPPCALL TPPLexer_Reset(struct TPPLexer *__restrict self, uint32_t flags);
#define TPPLEXER_RESET_NONE       0x00000000
#define TPPLEXER_RESET_INCLUDE    0x00000001 /* Reset the #include/#ifdef-stack and set the current token to EOF.
                                              * NOTE: Also resets the `l_eob_file' and `l_eof_file' special
                                              *       file pointers, as well as setting `l_noerror' to EOF
                                              *       and `l_warncount' and `l_errorcount' to ZERO(0). */
#define TPPLEXER_RESET_ESTATE     0x00000002 /* Reset the current extensions state to mirror the default. */
#define TPPLEXER_RESET_ESTACK     0x00000004 /* Clear all previously pushed extension states. */
#define TPPLEXER_RESET_WSTATE     0x00000008 /* Reset the current warning state to mirror the default. */
#define TPPLEXER_RESET_WSTACK     0x00000010 /* Clear all previously pushed warning states. */
#define TPPLEXER_RESET_SYSPATHS   0x00000020 /* Clears all system #include-paths. */
#define TPPLEXER_RESET_MACRO      0x00000040 /* Reset user-defined macros.
                                              * The original definitions of runtime builtin macros are restored,
                                              * unless the `TPPLEXER_RESET_NORESTOREMACROS' flag is set. */
#define TPPLEXER_RESET_ASSERT     0x00000080 /* Reset user-defined assertions. */
#define TPPLEXER_RESET_KWDFLAGS   0x00000100 /* Reset user-defined keyword flags. */
#define TPPLEXER_RESET_COUNTER    0x00000200 /* Reset __COUNTER__ and __TPP_COUNTER for all keywords. */
#define TPPLEXER_RESET_FONCE      0x00000400 /* Clear all `#pragma once' descriptors. */
#define TPPLEXER_RESET_KEYWORDS   0x00000800 /* Clear all keywords, but keep all predefined.
                                              * NOTE: When set, this flag implies `TPPLEXER_RESET_MACRO',
                                              *       `TPPLEXER_RESET_ASSERT', `TPPLEXER_RESET_KWDFLAGS',
                                              *       `TPPLEXER_RESET_COUNTER' and `TPPLEXER_RESET_FONCE'.
                                              * NOTE: It also implies `TPPLEXER_RESET_NORESTOREMACROS' */
#define TPPLEXER_RESET_NORESTOREMACROS 0x00001000 /* When used with `TPPLEXER_RESET_MACRO': Don't restore builtin macro definitions. */

#define TPPLEXER_RESET_EXTENSIONS (TPPLEXER_RESET_ESTATE|TPPLEXER_RESET_ESTACK)
#define TPPLEXER_RESET_WARNINGS   (TPPLEXER_RESET_WSTATE|TPPLEXER_RESET_WSTACK)

/* Push/Pop the current extension state.
 * @return: 0: [TPPLexer_PushExtensions] Not enough available memory. (TPP_CONFIG_SET_API_ERROR)
 * @return: 0: [TPPLexer_PopExtensions] No older extension state was available to restore.
 * @return: 1: Successfully pushed/popped active extensions. */
TPPFUN int TPPCALL TPPLexer_PushExtensions(void);
TPPFUN int TPPCALL TPPLexer_PopExtensions(void);

/* Set the state of a given extension `name'.
 * Extension names attempt to follow gcc names of the same extension.
 * The name of an extension can be found above.
 * @return: 0: Unknown extension.
 * @return: 1: Successfully configured the given extension. */
TPPFUN int TPPCALL TPPLexer_SetExtension(char const *__restrict name, int enable);

/* Returns the state of a given extension.
 * @return: -1: Unknown extension.
 * @return:  0: Disabled extension.
 * @return:  1: Enabled extension. */
TPPFUN int TPPCALL TPPLexer_GetExtension(char const *__restrict name);

/* Searches the cache and opens a new file if not found.
 * WARNING: If the caller intends to push the file onto the #include-stack,
 *          additional steps must be taken when the file was already
 *          located on the stack (in which case another stream must be opened,
 *          and a file that is not cached must be pushed onto the #include-stack).
 * WARNING: This function may modify the given `filename..filename_size+1' area of memory.
 * @param: pkeyword_entry: When non-NULL, the keyword entry associated with the filename is stored here.
 * @return: * :   A pointer to the already-chached file (WARNING: This is not a reference)
 * @return: NULL: File not found. */
TPPFUN struct TPPFile *TPPCALL
TPPLexer_OpenFile(int mode, char *__restrict filename, size_t filename_size,
                  struct TPPKeyword **pkeyword_entry);
#define TPPLEXER_OPENFILE_MODE_NORMAL     0x00 /* Normal open (simply pass the given filename to TPPFile_Open, but still sanitize and cache the filename) */
#define TPPLEXER_OPENFILE_MODE_RELATIVE   0x01 /* #include "foo.h" (Search for the file relative to the path of every text file on the #include-stack in reverse. - If this fails, search in system folders). */
#define TPPLEXER_OPENFILE_MODE_SYSTEM     0x02 /* #include <stdlib.h> (Search through system folders usually specified with `-I' on the commandline). */
#define TPPLEXER_OPENFILE_FLAG_NEXT       0x04 /* FLAG: Only open a file not already part of the #include-stack
                                                * WARNING: May not be used for `TPPLEXER_OPENFILE_MODE_NORMAL'! */
#define TPPLEXER_OPENFILE_FLAG_NOCASEWARN 0x08 /* FLAG: Don't warn about filename casing on windows. */
#ifndef TPP_CONFIG_NO_CALLBACK_UNKNOWN_FILE
#define TPPLEXER_OPENFILE_FLAG_NOCALLBACK 0x10 /* FLAG: Don't invoke the unknown-file callback when set. */
#endif /* !TPP_CONFIG_NO_CALLBACK_UNKNOWN_FILE */
#define TPPLEXER_OPENFILE_FLAG_CONSTNAME  0x20 /* FLAG: The given `filename' may not be modified, but is guarantied to be '\0'-terminated. */

/* Push a given file into the #include-stack of the current lexer.
 * NOTE: These functions never fail and return void.
 * HINT: Call `TPPLexer_PushFileInherited' if you want the lexer to inherit the file.
 * WARNING: The file argument may be evaluated more than once! */
#define TPPLexer_PushFileInherited(f)                      \
	(void)((f)->f_prev = TPPLexer_Current->l_token.t_file, \
	       TPPLexer_Current->l_token.t_file = (f))
#define TPPLexer_PushFile(f) \
	(TPPFile_Incref(f), TPPLexer_PushFileInherited(f))

/* Returns the currently active #include-file. */
#define TPPLexer_GetFile() TPPLexer_Current->l_token.t_file

/* Pop the current file off of the #include-stack.
 * HINT: This function is save to call, even when the current
 *       file is `TPPFile_Empty' (aka. no files are loaded)
 * WARNING: The caller is responsible never to call this
 *          function when `TPPLexer_GetFile()' has been
 *          configured as either the EOB or EOF lexer-file.
 * NOTE: This function is usually called in a context like:
 *    >> while (TPPLexer_GetFile() != my_file) TPPLexer_PopFile(); */
TPPFUN void TPPCALL TPPLexer_PopFile(void);

/* Lookup or create a keyword entry for the given name.
 * HINT: TPP also caches files inside the keyword hashmap.
 * @return: NULL: [create_missing]  Not enough available memory. (TPP_CONFIG_SET_API_ERROR)
 * @return: NULL: [!create_missing] No keyword with the given name.
 * @return: * :    The keyword entry associated with the given name. */
TPPFUN struct TPPKeyword *TPPCALL
TPPLexer_LookupKeyword(char const *__restrict name,
                       size_t namelen, int create_missing);
TPPFUN struct TPPKeyword *TPPCALL
TPPLexer_LookupEscapedKeyword(char const *__restrict name,
                              size_t namelen, int create_missing);

/* Looks up a keyword, given its ID
 * WARNING: This function is _extremely_ slow and should only
 *          be used if there is absolutely no other choice. */
TPPFUN struct TPPKeyword *TPPCALL TPPLexer_LookupKeywordID(TPP(tok_t) id);

/* Define a regular, keyword-style macro `name' as `value'.
 * @param: flags: A set of `TPPLEXER_DEFINE_FLAG_*'
 * @return: 0: Not enough available memory. (TPP_CONFIG_SET_API_ERROR)
 * @return: 1: Successfully defined the given macro.
 * @return: 2: A macro named `name' was already defined, and was overwritten. */
TPPFUN int TPPCALL TPPLexer_Define(char const *__restrict name, size_t name_size,
                                   char const *__restrict value, size_t value_size,
                                   uint32_t flags);
#define TPPLEXER_DEFINE_FLAG_NONE    0x00000000
#define TPPLEXER_DEFINE_FLAG_BUILTIN TPP_KEYWORDFLAG_BUILTINMACRO /* Define the macro as builtin, meaning the definition
                                                                   * set by `value' will be restored when `TPPLexer_Reset()'
                                                                   * is called with `TPPLEXER_RESET_MACRO'. */

/* Undefine the macro associated with a given name.
 * @return: 0: No macro was associated with the given name.
 * @return: 1: Successfully undefined a macro. */
TPPFUN int TPPCALL TPPLexer_Undef(char const *__restrict name, size_t name_size);

#ifndef TPP_CONFIG_NO_ASSERTIONS
/* Add/Delete a given assertion for a given predicate.
 * @param: answer: [TPPLexer_DelAssert] When NULL, clear all assertions.
 * @return: 0: [TPPLexer_AddAssert] Not enough available memory. (TPP_CONFIG_SET_API_ERROR)
 * @return: 0: [TPPLexer_DelAssert] Unknown/no answer(s)
 * @return: 1: Successfully added/deleted any assertion(s) */
TPPFUN int TPPCALL TPPLexer_AddAssert(char const *__restrict predicate, size_t predicate_size,
                                      char const *__restrict answer, size_t answer_size);
TPPFUN int TPPCALL TPPLexer_DelAssert(char const *__restrict predicate, size_t predicate_size,
                                      char const *answer, size_t answer_size);
#endif /* !TPP_CONFIG_NO_ASSERTIONS */

/* Similar to `TPPLexer_Yield' and used to implement it, but
 * doesn't expand macros or execute preprocessor directives. */
TPPFUN TPP(tok_t) TPPCALL TPPLexer_YieldRaw(void);

/* Similar to `TPPLexer_Yield' and used to
 * implement it, but doesn't expand macros. */
TPPFUN TPP(tok_t) TPPCALL TPPLexer_YieldPP(void);

/* Advance the selected lexer by one token and return the id of the new one.
 * HINT: Returns ZERO(0) if EOF was reached. */
TPPFUN TPP(tok_t) TPPCALL TPPLexer_Yield(void);

/* Return non-ZERO if the current token is the first of the current input line.
 * Return ZERO otherwise. */
TPPFUN int TPPCALL TPPLexer_AtStartOfLine(void);

#ifdef TPP_CONFIG_NONBLOCKING_IO
/* Yield the next token while trying not
 * to block in a non-block enabled file. */
TPP_LOCAL TPP(tok_t) TPPCALL TPPLexer_YieldRawNB(void) {
	TPP(tok_t)
	result;
	uint32_t old_flags = TPPLexer_Current->l_flags;
	TPPLexer_Current->l_flags |= TPPLEXER_FLAG_NONBLOCKING;
	result = TPPLexer_YieldRaw();
	TPPLexer_Current->l_flags &= TPPLEXER_FLAG_MERGEMASK;
	TPPLexer_Current->l_flags |= old_flags & ~TPPLEXER_FLAG_MERGEMASK;
	return result;
}

TPP_LOCAL TPP(tok_t) TPPCALL TPPLexer_YieldPPNB(void) {
	TPP(tok_t)
	result;
	uint32_t old_flags = TPPLexer_Current->l_flags;
	TPPLexer_Current->l_flags |= TPPLEXER_FLAG_NONBLOCKING;
	result = TPPLexer_YieldPP();
	TPPLexer_Current->l_flags &= TPPLEXER_FLAG_MERGEMASK;
	TPPLexer_Current->l_flags |= old_flags & ~TPPLEXER_FLAG_MERGEMASK;
	return result;
}

TPP_LOCAL TPP(tok_t) TPPCALL TPPLexer_YieldNB(void) {
	TPP(tok_t)
	result;
	uint32_t old_flags = TPPLexer_Current->l_flags;
	TPPLexer_Current->l_flags |= TPPLEXER_FLAG_NONBLOCKING;
	result = TPPLexer_Yield();
	TPPLexer_Current->l_flags &= TPPLEXER_FLAG_MERGEMASK;
	TPPLexer_Current->l_flags |= old_flags & ~TPPLEXER_FLAG_MERGEMASK;
	return result;
}
#endif /* TPP_CONFIG_NONBLOCKING_IO */


#ifndef TPP_CONFIG_CALLBACK_WARNING
/* Emit a given warning.
 * @return: 0: The warning was critical (TPPLexer_SetErr() was called and you should try to abort)
 * @return: 1: The warning was ignored, suppressed or simply non-fatal. */
TPPFUN int TPPVCALL TPPLexer_Warn(int wnum, ...); /* TODO: __attribute__((cold)) */
#endif /* !TPP_CONFIG_CALLBACK_WARNING */

#undef TPPLexer_SetErr
#undef TPPLexer_UnsetErr

#define TPPLexer_SetErr_inline()                                         \
	((TPPLexer_Current->l_flags & TPPLEXER_FLAG_ERROR)                   \
	 ? 0                                                                 \
	 : (TPPLexer_Current->l_flags |= TPPLEXER_FLAG_ERROR,                \
	    TPPLexer_Current->l_noerror    = TPPLexer_Current->l_token.t_id, \
	    TPPLexer_Current->l_token.t_id = TPP(TOK_ERR), 1))
#define TPPLexer_UnsetErr_inline()                                       \
	((TPPLexer_Current->l_flags & TPPLEXER_FLAG_ERROR)                   \
	 ? (TPPLexer_Current->l_flags &= ~TPPLEXER_FLAG_ERROR,               \
	    TPPLexer_Current->l_token.t_id = TPPLexer_Current->l_noerror, 1) \
	 : 0)


/* Set the lexer into an error-state in which
 * calls to to any yield function return TOK_ERR.
 * >> Called when an unrecoverable error occurrs.
 * HINT: To recover after such an event, `TPPLexer_UnsetErr()' should be called.
 * @return: 0: [TPPLexer_SetErr]   A lexer error was already set.
 *             [TPPLexer_UnsetErr] No lexer error was set.
 * @return: 1: [TPPLexer_SetErr]   Successfully set a lexer error.
 *             [TPPLexer_UnsetErr] Successfully cleared a lexer error. */
TPPFUN int TPPCALL TPPLexer_SetErr(void);
TPPFUN int TPPCALL TPPLexer_UnsetErr(void);

#ifdef TPP_CONFIG_INLINE_SETERR
#define TPPLexer_SetErr    TPPLexer_SetErr_inline
#define TPPLexer_UnsetErr  TPPLexer_UnsetErr_inline
#endif /* TPP_CONFIG_INLINE_SETERR */

/* Called after a given macro was referenced and
 * the associated parenthesis was located.
 * Expected to be called when the current token is the macro's name,
 * this function will parse the macro's argument list remainder of the macro's
 * argument list (including the terminating parenthesis), before 
 * pushing a new file describing the expanded macro onto the include stack.
 * @return: 0: A hard error occurred (such as not enough memory; (TPP_CONFIG_SET_API_ERROR))
 * @return: 1: Successfully expanded the macro.
 * @return: 2: Missing argument list or illegal recursive expansion. */
TPPFUN int TPPCALL TPPLexer_ExpandFunctionMacro(struct TPPFile *__restrict macro);


struct TPPConst {
#define TPP_CONST_INTEGRAL 0
#define TPP_CONST_FLOAT    1
#define TPP_CONST_STRING   2
	unsigned int c_kind; /* Constant kind (One of `TPP_CONST_*'). */
	union {
		TPP(tint_t)              c_int;    /* [TPP_CONST_INTEGRAL] Integral. */
		TPP(tfloat_t)            c_float;  /* [TPP_CONST_FLOAT] Floating point. */
		/*ref*/struct TPPString *c_string; /* [TPP_CONST_STRING][1..1] String. */
	} c_data;
};
#define TPPConst_IsTrue(self)                         \
	((self)->c_kind == TPP_CONST_STRING               \
	 ? (TPPString_SIZE((self)->c_data.c_string) != 0) \
	 : (self)->c_kind == TPP_CONST_FLOAT              \
	   ? ((self)->c_data.c_float != 0.0L)             \
	   : ((self)->c_data.c_int != 0))
#define TPPConst_IsBool(self)                \
	((self)->c_kind == TPP_CONST_INTEGRAL && \
	 !((self)->c_data.c_int & ~(TPP(tint_t))1))
#define TPPConst_AsInt(self)                 \
	((self)->c_kind == TPP_CONST_INTEGRAL    \
	 ? (self)->c_data.c_int                  \
	 : (self)->c_kind == TPP_CONST_FLOAT     \
	   ? (TPP(tint_t))(self)->c_data.c_float \
	   : TPPString_SIZE((self)->c_data.c_string) != 0)
#define TPPConst_AsFloat(self)               \
	((self)->c_kind == TPP_CONST_FLOAT       \
	 ? (self)->c_data.c_float                \
	 : (self)->c_kind == TPP_CONST_INTEGRAL  \
	   ? (TPP(tfloat_t))(self)->c_data.c_int \
	   : (TPP(tfloat_t))(TPPString_SIZE((self)->c_data.c_string) != 0))
#define TPPConst_InitCopy(self, right)                 \
	do {                                               \
		*(self) = *(right);                            \
		if ((self)->c_kind == TPP_CONST_STRING)        \
			TPPString_Incref((self)->c_data.c_string); \
	} while (TPP_MACRO_FALSE)

#define TPPConst_ToBool(self)                                            \
	do {                                                                 \
		if ((self)->c_kind == TPP_CONST_STRING) {                        \
			int c_newval = TPPString_SIZE((self)->c_data.c_string) != 0; \
			TPPString_Decref((self)->c_data.c_string);                   \
			(self)->c_data.c_int = (TPP(tint_t))c_newval;                \
			(self)->c_kind       = TPP_CONST_INTEGRAL;                   \
		} else if ((self)->c_kind == TPP_CONST_FLOAT) {                  \
			(self)->c_data.c_int = (self)->c_data.c_float != 0.0L;       \
			(self)->c_kind       = TPP_CONST_INTEGRAL;                   \
		} else {                                                         \
			(self)->c_data.c_int = !!(self)->c_data.c_int;               \
		}                                                                \
	} while (TPP_MACRO_FALSE)
#define TPPConst_ToInt(self)                                             \
	do {                                                                 \
		if ((self)->c_kind == TPP_CONST_STRING) {                        \
			int c_newval = TPPString_SIZE((self)->c_data.c_string) != 0; \
			TPPString_Decref((self)->c_data.c_string);                   \
			(self)->c_data.c_int = (TPP(tint_t))c_newval;                \
			(self)->c_kind       = TPP_CONST_INTEGRAL;                   \
		} else if ((self)->c_kind == TPP_CONST_FLOAT) {                  \
			(self)->c_data.c_int = (TPP(tint_t))(self)->c_data.c_float;  \
			(self)->c_kind       = TPP_CONST_INTEGRAL;                   \
		}                                                                \
	} while (TPP_MACRO_FALSE)

#define TPPConst_ZERO(self)                           \
	(void)((self)->c_kind       = TPP_CONST_INTEGRAL, \
	       (self)->c_data.c_int = 0)
#define TPPConst_Quit(self)                      \
	(void)((self)->c_kind != TPP_CONST_STRING || \
	       (TPPString_Decref((self)->c_data.c_string), 1))

/* Convert a given preprocessor constant into a string:
 * >> The returned string can be used to create a file
 *    that represents the constant's value as loaded
 *    by the `__TPP_EVAL' extension.
 * NOTE: If `self' is a string, it will be escaped.
 * @return: NULL: Not enough available memory. */
TPPFUN /*ref*/struct TPPString *TPPCALL
TPPConst_ToString(struct TPPConst const *__restrict self);

/* Evaluate a constant expression as found after `#if' or in `__TPP_EVAL(...)'
 * NOTE: If `result' is NULL, the expression's is
 *       parsed, yet warnings will not be emit.
 * NOTE: Expects the current token to point to the first one part of the expression.
 *       Upon exit, that token will point to the first one past the expression.
 * NOTE: Evaluation is compatible with standard c rules, but
 *       `,' operators are not parsed at the highest level.
 * @return: 1: Successfully parsed an expression
 * @return: 0: An error occurred. */
TPPFUN int TPPCALL TPPLexer_Eval(struct TPPConst *result);

/* Parse the data block of a pragma.
 * NOTE: `TPPLexer_ParseBuiltinPragma' behaves similar to
 *       `TPPLexer_ParsePragma', but will not invoke a
 *       user-provided pragma handler in the even of an
 *       unknown one.
 * @return: 0: Unknown/errorous pragma.
 * @return: 1: Successfully parsed the given pragma. */
TPPFUN int TPPCALL TPPLexer_ParsePragma(void);
TPPFUN int TPPCALL TPPLexer_ParseBuiltinPragma(void);

/* Parse an evaluate a string from the current lexer.
 * NOTE: This functions expects the current token to be a string token
 *       and will continue parsing and concat-ing strings until the
 *       next non-string token.
 * @return: * :   A reference to the unescaped string that was parsed.
 * @return: NULL: A lexer error occurred (TPPLexer_SetErr() was set; (TPP_CONFIG_SET_API_ERROR)). */
#if TPP_UNESCAPE_MAXCHAR == 1
TPPFUN /*ref*/struct TPPString *TPPCALL TPPLexer_ParseString(void);
#else /* TPP_UNESCAPE_MAXCHAR == 1 */
#define TPPLexer_ParseString() TPPLexer_ParseStringEx(sizeof(char))
TPPFUN /*ref*/struct TPPString *TPPCALL TPPLexer_ParseStringEx(size_t sizeof_char);
#endif /* TPP_UNESCAPE_MAXCHAR != 1 */

/* Transform the current token (which must either be `TOK_INT' or `TOK_CHAR')
 * into an integral value, storing that value in `*pint' and returning
 * a set of `TPP_ATOI_*' flags, indicating typing and success.
 * NOTE: This function does _NOT_ yield the current token once finished.
 *       If intended, the caller is responsible for advancing it upon success.
 * @return: TPP_ATOI_ERR: Emiting a warning caused the lexer to error out (TPPLexer_SetErr() was set).
 * @return: * :           A set of `TPP_ATOI_*' (see below) */
TPPFUN int TPPCALL TPP_Atoi(TPP(tint_t) *__restrict pint);
#define TPP_ATOI_ERR           0x00 /* NOTE: Never used with any flags (indicates failure). */
#define TPP_ATOI_OK            0x01 /* Always set on success. */
#define TPP_ATOI_UNSIGNED      0x02 /* Unless set, the integral is signed. */
#define TPP_ATOI_TYPE_MASK     0xf0 /* Mask of the integral's typing (NOTE: The function already clamped the resulting value with this type's range). */
#define TPP_ATOI_TYPE_INT      0x00 /* `int' (default typing without suffix/for chars). */
#define TPP_ATOI_TYPE_LONG     0x10 /* `long'. */
#define TPP_ATOI_TYPE_LONGLONG 0x20 /* `long long'. */
#define TPP_ATOI_TYPE_INT8     0x30 /* `__int8' (msvc-extension). */
#define TPP_ATOI_TYPE_INT16    0x40 /* `__int16' (msvc-extension). */
#define TPP_ATOI_TYPE_INT32    0x50 /* `__int32' (msvc-extension). */
#define TPP_ATOI_TYPE_INT64    0x60 /* `__int64' (msvc-extension). */

/* Transform the current token (which must be `TOK_FLOAT') into a
 * floating point value, storing that value in `*pfloat' and returning
 * a set of `TPP_ATOF_*' flags, indicating typing and success.
 * NOTE: This function does _NOT_ yield the current token once finished.
 *       If intended, the caller is responsible for advancing it upon success.
 * @return: TPP_ATOF_ERR: Emiting a warning caused the lexer to error out (TPPLexer_SetErr() was set).
 * @return: * :           A set of `TPP_ATOF_*' (see below) */
TPPFUN int TPPCALL TPP_Atof(TPP(tfloat_t) *__restrict pfloat);
#define TPP_ATOF_ERR             0x00 /* NOTE: Never used with any flags (indicates failure). */
#define TPP_ATOF_OK              0x01 /* Always set on success. */
#define TPP_ATOF_TYPE_MASK       0xf0 /* Mask of the float's typing. */
#define TPP_ATOF_TYPE_DOUBLE     0x00 /* `double' (default typing without suffix). */
#define TPP_ATOF_TYPE_FLOAT      0x10 /* `float' (float-suffix `f') */
#define TPP_ATOF_TYPE_LONGDOUBLE 0x20 /* `long double' (long-double-suffix `L'). */

/* Prints the text contained within the current token, automatically
 * skipping escaped linefeeds and converting di/trigraphs.
 * NOTE: `TPP_PrintComment' behaves similar, but will
 *        instead handle any kind of comment token,
 *        printing the comment text within.
 * @return: >= 0: Sum of all return values from `printer'.
 * @return: <  0: The first negative value returned by `printer' */
TPPFUN ptrdiff_t TPPCALL TPP_PrintToken(TPP(printer_t) printer, void *closure);
TPPFUN ptrdiff_t TPPCALL TPP_PrintComment(TPP(printer_t) printer, void *closure);


/* Helper macros to initialize/finalize the global TPP context.
 * NOTE: These macros can (obviously) be called when
 *      `TPPLexer_Current' is NULL, or not initialized. */
#if TPP_CONFIG_ONELEXER
#define TPP_INITIALIZE() TPPLexer_Init(&TPPLexer_Global)
#define TPP_FINALIZE()   TPPLexer_Quit(&TPPLexer_Global)
#else /* TPP_CONFIG_ONELEXER */
#define TPP_INITIALIZE()                                                    \
	(TPPLexer_Current = (struct TPPLexer *)malloc(sizeof(struct TPPLexer)), \
	 TPPLexer_Current ? (TPPLexer_Init(TPPLexer_Current) ? 1 : (free(TPPLexer_Current), 0)) : 0)
#define TPP_FINALIZE() (TPPLexer_Quit(TPPLexer_Current), free(TPPLexer_Current))
#endif /* !TPP_CONFIG_ONELEXER */


#ifdef TPP_NAMESPACE_DEFINED
#undef TPP_NAMESPACE_DEFINED
#undef TPP
#endif /* TPP_NAMESPACE_DEFINED */


/* Fix unnamed union/struct members. */
#if !TPP_HAVE_UNNAMED_UNION
#define m_function     m_specific.m_function
#define m_expand       m_specific.m_expand
#define f_textfile     f_specific.f_textfile
#define f_macro        f_specific.f_macro
#endif /* !TPP_HAVE_UNNAMED_UNION */


#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* !GUARD_TPP_H */

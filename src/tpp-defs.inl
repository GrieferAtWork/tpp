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
#ifndef KWD
#define TPP_DEFS_DEFINES_KWD
#define KWD(name,str)
#endif
#ifndef WGROUP
#define TPP_DEFS_DEFINES_WGROUP
#define WGROUP(name,str)
#endif
#ifndef WARNING
#define TPP_DEFS_DEFINES_WARNING
#define WARNING(name,group,default)
#endif
#ifndef MACRO
#define TPP_DEFS_DEFINES_MACRO
/* Reference a keyword that would behave as a predefined
 * macro only defined when 'if' evaluates to true at runtime.
 * NOTE: Such a macro can still be re-defined by the user,
 *       but may later be #undef-ined again to re-enable
 *       its original meaning. */
#define MACRO(name,if)
#else
#ifndef HAS_EXTENSION
#define HAS_EXTENSION(x) (TPPLexer_Current->l_extensions & (x))
#endif
#endif
#ifndef BUILTIN_MACRO
#define TPP_DEFS_DEFINES_BUILTIN_MACRO
#define BUILTIN_MACRO(name,value)
#endif

#define DEF_K(name)         KWD(KWD_##name,#name)
#define DEF_M(name)         KWD(KWD_##name,#name) MACRO(KWD_##name,1)
#define DEF_M_IF(name,expr) KWD(KWD_##name,#name) MACRO(KWD_##name,expr)
DEF_K(if)
DEF_K(ifdef)
DEF_K(ifndef)
DEF_K(elif)
DEF_K(else)
DEF_K(endif)
DEF_K(define)
DEF_K(defined)
DEF_K(undef)
DEF_K(include)
DEF_K(include_next)
DEF_K(import)
DEF_K(line)
DEF_K(error)
DEF_K(warning)

/* Various names for #pragma-directives (TPP supports everything) */
DEF_K(pragma)
DEF_M(_Pragma)  /*< GCC defines _Pragma as a macro... So I'll just do that as well! */
DEF_M(__pragma) /*< I promised this would be defined as a macro... */

/* STD-C predefined macros. */
DEF_M(__FILE__)
DEF_M(__LINE__)
DEF_M(__TIME__)
DEF_M(__DATE__)
DEF_M_IF(__BASE_FILE__,    HAS_EXTENSION(TPPLEXER_EXTENSION_BASEFILE))
DEF_M_IF(__INCLUDE_LEVEL__,HAS_EXTENSION(TPPLEXER_EXTENSION_INCLUDE_LEVEL))
DEF_M_IF(__INCLUDE_DEPTH__,HAS_EXTENSION(TPPLEXER_EXTENSION_INCLUDE_LEVEL))
DEF_M_IF(__COUNTER__,      HAS_EXTENSION(TPPLEXER_EXTENSION_COUNTER))
DEF_M_IF(__TIMESTAMP__,    HAS_EXTENSION(TPPLEXER_EXTENSION_TIMESTAMP))

DEF_M_IF(__is_identifier,         HAS_EXTENSION(TPPLEXER_EXTENSION_CLANG_FEATURES))
DEF_M_IF(__is_builtin_identifier, HAS_EXTENSION(TPPLEXER_EXTENSION_CLANG_FEATURES))
DEF_M_IF(__is_deprecated,         HAS_EXTENSION(TPPLEXER_EXTENSION_CLANG_FEATURES))
DEF_M_IF(__has_attribute,         HAS_EXTENSION(TPPLEXER_EXTENSION_CLANG_FEATURES))
DEF_M_IF(__has_builtin,           HAS_EXTENSION(TPPLEXER_EXTENSION_CLANG_FEATURES))
DEF_M_IF(__has_cpp_attribute,     HAS_EXTENSION(TPPLEXER_EXTENSION_CLANG_FEATURES))
DEF_M_IF(__has_declspec_attribute,HAS_EXTENSION(TPPLEXER_EXTENSION_CLANG_FEATURES))
DEF_M_IF(__has_extension,         HAS_EXTENSION(TPPLEXER_EXTENSION_CLANG_FEATURES))
DEF_M_IF(__has_feature,           HAS_EXTENSION(TPPLEXER_EXTENSION_CLANG_FEATURES))
DEF_M_IF(__has_include,           HAS_EXTENSION(TPPLEXER_EXTENSION_HAS_INCLUDE))
DEF_M_IF(__has_include_next,      HAS_EXTENSION(TPPLEXER_EXTENSION_HAS_INCLUDE))

/* Helper keywords used to implement variadic macros & extensions.
 * HINT: '__VA_NARGS__' is something new I added when I began reviving TPP:
 *     >> #define _sum0()       0
 *     >> #define _sum1(a)      a
 *     >> #define _sum2(a,b)    a+b
 *     >> #define _sum3(a,b,c)  a+b+c
 *     >> #define sum(args...)  _sum##__VA_NARGS__(args)
 *     >>
 *     >> // Overloading macros by argument count was never this easy!
 *     >> sum()       // []
 *     >> sum( )      // [ ]
 *     >> sum(42)     // [42]
 *     >> sum(42,16)  // [42][+][16]
 */
KWD(KWD___VA_ARGS__, "__VA_ARGS__")
KWD(KWD___VA_COMMA__,"__VA_COMMA__")
KWD(KWD___VA_NARGS__,"__VA_NARGS__")

/* Builtin pragmas. */
DEF_K(once)
DEF_K(push_macro)
DEF_K(pop_macro)
DEF_K(region)
DEF_K(endregion)
DEF_K(message)
DEF_K(deprecated)
DEF_K(tpp_exec)
DEF_K(tpp_set_keyword_flags)


/* TPP extension macros. */
DEF_M_IF(__TPP_EVAL,     HAS_EXTENSION(TPPLEXER_EXTENSION_TPP_EVAL))
DEF_M_IF(__TPP_LOAD_FILE,HAS_EXTENSION(TPPLEXER_EXTENSION_TPP_LOAD_FILE))
DEF_M_IF(__TPP_COUNTER,  HAS_EXTENSION(TPPLEXER_EXTENSION_TPP_COUNTER))
DEF_M_IF(__TPP_RANDOM,   HAS_EXTENSION(TPPLEXER_EXTENSION_TPP_RANDOM))
/* TODO: __TPP_STR_DECOMPILE */
/* TODO: __TPP_STR_AT */
/* TODO: __TPP_STR_SUBSTR (NOTE: Not ~really~ needed anymore: '__TPP_EVAL(str[begin:end])') */
/* TODO: __TPP_STR_PACK */
/* TODO: __TPP_STR_SIZE (NOTE: Not ~really~ needed anymore: '__TPP_EVAL(#str)') */
DEF_M_IF(__TPP_UNIQUE,HAS_EXTENSION(TPPLEXER_EXTENSION_TPP_UNIQUE))

DEF_M_IF(__DATE_DAY__,  HAS_EXTENSION(TPPLEXER_EXTENSION_DATEUTILS))
DEF_M_IF(__DATE_WDAY__, HAS_EXTENSION(TPPLEXER_EXTENSION_DATEUTILS))
DEF_M_IF(__DATE_YDAY__, HAS_EXTENSION(TPPLEXER_EXTENSION_DATEUTILS))
DEF_M_IF(__DATE_MONTH__,HAS_EXTENSION(TPPLEXER_EXTENSION_DATEUTILS))
DEF_M_IF(__DATE_YEAR__, HAS_EXTENSION(TPPLEXER_EXTENSION_DATEUTILS))
DEF_M_IF(__TIME_SEC__,  HAS_EXTENSION(TPPLEXER_EXTENSION_TIMEUTILS))
DEF_M_IF(__TIME_MIN__,  HAS_EXTENSION(TPPLEXER_EXTENSION_TIMEUTILS))
DEF_M_IF(__TIME_HOUR__, HAS_EXTENSION(TPPLEXER_EXTENSION_TIMEUTILS))

#undef DEF_M_IF
#undef DEF_M
#undef DEF_K

#define PREDEFINED_MACRO(name,value) \
  KWD(KWD_##name,#name) BUILTIN_MACRO(KWD_##name,value)

#define TPP_PP_STR2(x) #x
#define TPP_PP_STR(x)  TPP_PP_STR2(x)

/* Predefined macros and their values.
 * NOTE: These behave like other predefined macros, allowing
 *       the user to redefine them, but returning when they
 *       #undef their versions again. */
PREDEFINED_MACRO(__TPP_VERSION__,TPP_PP_STR(TPP_PREPROCESSOR_VERSION))

#undef TPP_PP_STR
#undef TPP_PP_STR2



WGROUP(WG_COMMENTS,"comments")
WGROUP(WG_MACROS,  "macros")
WGROUP(WG_SYNTAX,  "syntax")
WGROUP(WG_STRING,  "string")
WGROUP(WG_VALUE,   "value")
WGROUP(WG_USER,    "user")
WGROUP(WG_ENVIRON, "environ")
WGROUP(WG_LIMIT,   "limit")

WARNING(W_STARSLASH_OUTSIDE_OF_COMMENT,    WG_COMMENTS,WSTATE_WARN)    /*< [char *]. */
WARNING(W_LINE_COMMENT_CONTINUED,          WG_COMMENTS,WSTATE_WARN)    /*< . */
WARNING(W_REDEFINING_MACRO,                WG_MACROS,  WSTATE_WARN)    /*< [struct TPPKeyword *]. */
WARNING(W_REDEFINING_BUILTIN_KEYWORD,      WG_MACROS,  WSTATE_WARN)    /*< [struct TPPKeyword *]. */
WARNING(W_SPECIAL_ARGUMENT_NAME,           WG_MACROS,  WSTATE_WARN)    /*< [struct TPPKeyword *]. */
WARNING(W_VA_KEYWORD_IN_REGULAR_MACRO,     WG_MACROS,  WSTATE_WARN)    /*< [struct TPPKeyword *]. */
WARNING(W_KEYWORD_MACRO_ALREADY_ONSTACK,   WG_MACROS,  WSTATE_DISABLE) /*< [struct TPPFile *]. */
WARNING(W_TOO_MANY_MACRO_ARGUMENTS,        WG_MACROS,  WSTATE_WARN)    /*< [struct TPPFile *]. */
WARNING(W_NOT_ENGOUH_MACRO_ARGUMENTS,      WG_MACROS,  WSTATE_WARN)    /*< [struct TPPFile *]. */
WARNING(W_CHARACTER_TOO_LONG,              WG_VALUE,   WSTATE_WARN)    /*< . */
WARNING(W_DIVIDE_BY_ZERO,                  WG_VALUE,   WSTATE_WARN)    /*< . */
WARNING(W_INTEX_OUT_OF_BOUNDS,             WG_VALUE,   WSTATE_DISABLE) /*< [struct TPPString *,ptrdiff_t]. */
WARNING(W_EXPECTED_MACRO_ARGUMENT_NAME,    WG_SYNTAX,  WSTATE_WARN)    /*< [tok_t]. */
WARNING(W_ARGUMENT_NAMED_ALREADY_TAKEN,    WG_MACROS,  WSTATE_WARN)    /*< [tok_t]. */
WARNING(W_EXPECTED_COMMA_OR_ARGEND,        WG_SYNTAX,  WSTATE_WARN)    /*< [tok_t]. */
WARNING(W_EXPECTED_ARGEND_AFTER_VARARGS,   WG_SYNTAX,  WSTATE_WARN)    /*< [tok_t]. */
WARNING(W_EXPECTED_KEYWORD_AFTER_DEFINE,   WG_SYNTAX,  WSTATE_WARN)    /*< . */
WARNING(W_EXPECTED_KEYWORD_AFTER_UNDEF,    WG_SYNTAX,  WSTATE_WARN)    /*< . */
WARNING(W_MACRO_NOT_DEFINED,               WG_SYNTAX,  WSTATE_DISABLE) /*< [struct TPPKeyword *]. */
WARNING(W_CANT_UNDEF_BUILTIN_MACRO,        WG_SYNTAX,  WSTATE_WARN)    /*< [struct TPPKeyword *]. */
WARNING(W_UNKNOWN_PREPROCESSOR_DIRECTIVE,  WG_SYNTAX,  WSTATE_WARN)    /*< . */
WARNING(W_INVALID_INTEGER_SUFFIX,          WG_SYNTAX,  WSTATE_WARN)    /*< [char const *,size_t]. */
WARNING(W_EXPECTED_COLLON_AFTER_QUESTION,  WG_SYNTAX,  WSTATE_WARN)    /*< . */
WARNING(W_STRING_TERMINATED_BY_LINEFEED,   WG_STRING,  WSTATE_WARN)    /*< . */
WARNING(W_UNKNOWN_TOKEN_IN_EXPR_IS_ZERO,   WG_SYNTAX,  WSTATE_WARN)    /*< . */
WARNING(W_EXPECTED_RPAREN_IN_EXPRESSION,   WG_SYNTAX,  WSTATE_WARN)    /*< . */
WARNING(W_EXPECTED_RBRACKET_IN_EXPRESSION, WG_SYNTAX,  WSTATE_WARN)    /*< . */
WARNING(W_EXPECTED_KEYWORD_AFTER_IFDEF,    WG_SYNTAX,  WSTATE_WARN)    /*< . */
WARNING(W_EXPECTED_KEYWORD_AFTER_DEFINED,  WG_SYNTAX,  WSTATE_WARN)    /*< . */
WARNING(W_EXPECTED_RPAREN_AFTER_DEFINED,   WG_SYNTAX,  WSTATE_WARN)    /*< . */
WARNING(W_EXPECTED_LPAREN,                 WG_SYNTAX,  WSTATE_WARN)    /*< . */
WARNING(W_EXPECTED_RPAREN,                 WG_SYNTAX,  WSTATE_WARN)    /*< . */
WARNING(W_EXPECTED_COMMA,                  WG_SYNTAX,  WSTATE_WARN)    /*< . */
WARNING(W_EXPECTED_STRING_AFTER_PRAGMA,    WG_SYNTAX,  WSTATE_WARN)    /*< [struct TPPConst *]. */
WARNING(W_EXPECTED_STRING_IN_EXPRESSION,   WG_SYNTAX,  WSTATE_WARN)    /*< [struct TPPConst *]. */
WARNING(W_EXPECTED_STRING_AFTER_LINE,      WG_SYNTAX,  WSTATE_WARN)    /*< [struct TPPConst *]. */
WARNING(W_EXPECTED_INCLUDE_STRING,         WG_SYNTAX,  WSTATE_WARN)    /*< [char const *,size_t]. */
WARNING(W_EXPECTED_STRING_AFTER_PUSHMACRO, WG_SYNTAX,  WSTATE_WARN)    /*< [struct TPPConst *]. */
WARNING(W_EXPECTED_STRING_AFTER_MESSAGE,   WG_SYNTAX,  WSTATE_WARN)    /*< [struct TPPConst *]. */
WARNING(W_EXPECTED_STRING_AFTER_DEPRECATED,WG_SYNTAX,  WSTATE_WARN)    /*< [struct TPPConst *]. */
WARNING(W_EXPECTED_STRING_AFTER_TPP_EXEC,  WG_SYNTAX,  WSTATE_WARN)    /*< [struct TPPConst *]. */
WARNING(W_EXPECTED_STRING_AFTER_TPP_SETF,  WG_SYNTAX,  WSTATE_WARN)    /*< [struct TPPConst *]. */
WARNING(W_FILE_NOT_FOUND,                  WG_ENVIRON, WSTATE_WARN)    /*< [char const *]. */
WARNING(W_ERROR,                           WG_USER,    WSTATE_ERROR)   /*< [char const *,size_t]. */
WARNING(W_WARNING,                         WG_USER,    WSTATE_WARN)    /*< [char const *,size_t]. */
WARNING(W_MACRO_RECURSION_LIMIT_EXCEEDED,  WG_LIMIT,   WSTATE_WARN)    /*< [struct TPPFile *]. */
WARNING(W_INCLUDE_RECURSION_LIMIT_EXCEEDED,WG_LIMIT,   WSTATE_WARN)    /*< [struct TPPFile *]. */
WARNING(W_IF_WITHOUT_ENDIF,                WG_SYNTAX,  WSTATE_WARN)    /*< [struct TPPIfdefStackSlot *]. */
WARNING(W_ELSE_WITHOUT_IF,                 WG_SYNTAX,  WSTATE_WARN)    /*< . */
WARNING(W_ELIF_WITHOUT_IF,                 WG_SYNTAX,  WSTATE_WARN)    /*< . */
WARNING(W_ELSE_AFTER_ELSE,                 WG_SYNTAX,  WSTATE_WARN)    /*< [struct TPPIfdefStackSlot *]. */
WARNING(W_ELIF_AFTER_ELSE,                 WG_SYNTAX,  WSTATE_WARN)    /*< [struct TPPIfdefStackSlot *]. */
WARNING(W_ENDIF_WITHOUT_IF,                WG_SYNTAX,  WSTATE_WARN)    /*< . */
WARNING(W_DEPRECATED_IDENTIFIER,           WG_USER,    WSTATE_WARN)    /*< [struct TPPKeyword *]. */

#ifdef TPP_DEFS_DEFINES_BUILTIN_MACRO
#undef TPP_DEFS_DEFINES_BUILTIN_MACRO
#undef BUILTIN_MACRO
#endif
#ifdef TPP_DEFS_DEFINES_MACRO
#undef TPP_DEFS_DEFINES_MACRO
#undef MACRO
#endif
#ifdef TPP_DEFS_DEFINES_WARNING
#undef TPP_DEFS_DEFINES_WARNING
#undef WARNING
#endif
#ifdef TPP_DEFS_DEFINES_WGROUP
#undef TPP_DEFS_DEFINES_WGROUP
#undef WGROUP
#endif
#ifdef TPP_DEFS_DEFINES_KWD
#undef TPP_DEFS_DEFINES_KWD
#undef KWD
#endif

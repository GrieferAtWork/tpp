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
#if (defined(KWD_FLAGS) || defined(MACRO)) && !defined(HAS_EXTENSION)
#define HAS_EXTENSION(x) (TPPLexer_Current->l_extensions & (x))
#endif

#ifndef KWD
#define TPP_DEFS_DEFINES_KWD
#define KWD(name,str)
#endif
#ifndef KWD_FLAGS
#define TPP_DEFS_DEFINES_KWD_FLAGS
#define KWD_FLAGS(kwd,flags)
#endif
#ifndef WGROUP
#define TPP_DEFS_DEFINES_WGROUP
#define WGROUP(name,str,default)
#endif
#ifndef WARNING
#define TPP_DEFS_DEFINES_WARNING
#define WARNING(name,groups,default)
#endif
#ifndef MACRO
#define TPP_DEFS_DEFINES_MACRO
/* Reference a keyword that would behave as a predefined
 * macro only defined when 'if' evaluates to true at runtime.
 * NOTE: Such a macro can still be re-defined by the user,
 *       but may later be #undef-ined again to re-enable
 *       its original meaning. */
#define MACRO(name,if)
#endif
#ifndef BUILTIN_MACRO
#define TPP_DEFS_DEFINES_BUILTIN_MACRO
#define BUILTIN_MACRO(name,value)
#endif

#define DEF_K(name)         KWD(KWD_##name,#name)
#define DEF_M(name)         KWD(KWD_##name,#name) MACRO(KWD_##name,1)
#define DEF_M_IF(name,expr) KWD(KWD_##name,#name) MACRO(KWD_##name,expr)

#define DEF_FEATURE_IF(name,if)   KWD(KWD_##name,#name) KWD_FLAGS(KWD_##name,(if) ? TPP_KEYWORDFLAG_HAS_FEATURE : 0)
#define DEF_EXTENSION_IF(name,if) KWD(KWD_##name,#name) KWD_FLAGS(KWD_##name,(if) ? TPP_KEYWORDFLAG_HAS_EXTENSION : 0)

#define PREDEFINED_KWDMACRO(name,str,value)       KWD(name,str) MACRO(name,1) BUILTIN_MACRO(name,value)
#define PREDEFINED_KWDMACRO_IF(name,str,if,value) KWD(name,str) MACRO(name,if) BUILTIN_MACRO(name,value)
#define PREDEFINED_MACRO(name,value)              PREDEFINED_KWDMACRO(KWD_##name,#name,value)
#define PREDEFINED_MACRO_IF(name,if,value)        PREDEFINED_KWDMACRO_IF(KWD_##name,#name,if,value)
#define TPP_PP_STR2(x) #x
#define TPP_PP_STR(x)  TPP_PP_STR2(x)

/* Keywords for known preprocessor directives. */
DEF_K(if)           /*< #if defined(FOO) && FOO == 10. */
DEF_K(ifdef)        /*< #ifdef FOOBAR. */
DEF_K(ifndef)       /*< #ifndef FOOBAR. */
DEF_K(elif)         /*< #elif defined(BAR) && BAR == 20. */
DEF_K(else)         /*< #else. */
DEF_K(endif)        /*< #endif. */
DEF_K(define)       /*< #define FOO 42. */
DEF_K(defined)      /*< #if defined(FOO). */
DEF_K(undef)        /*< #undef FOO. */
DEF_K(include)      /*< #include "header.h". */
DEF_K(include_next) /*< #include_next <stdlib.h>. */
DEF_K(import)       /*< #import "header.h". */
DEF_K(line)         /*< #line 42 "foo.h". */
DEF_K(error)        /*< #error C5A9. */
DEF_K(warning)      /*< #warning $H17. */
DEF_K(ident)        /*< #ident "text". */
DEF_K(sccs)         /*< #sccs "text". */
DEF_K(assert)       /*< #assert machine(i386). */
DEF_K(unassert)     /*< #assert unmachine. */

/* Various names for #pragma-directives (TPP supports everything) */
DEF_K(pragma)   /*< #pragma once. */
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
DEF_M_IF(__COLUMN__,       HAS_EXTENSION(TPPLEXER_EXTENSION_COLUMN))

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
DEF_K(extension)

/* Argument keywords for #pragma warning. */
DEF_K(push)
DEF_K(pop)
DEF_K(disable)
DEF_K(enable)
DEF_K(suppress)
DEF_K(default)

/* Explicit namespace for TPP pragma extensions.
 * Can be used with the following pragmas:
 * >> #pragma TPP warning(...)
 * >> #pragma TPP extension(...)
 * >> #pragma TPP tpp_exec(...)
 * >> #pragma TPP tpp_set_keyword_flags(...)
 * >> #pragma TPP include_path(...)
 */
DEF_K(TPP)

/* Additional keywords used for pragmas capable of
 * adding/deleting/pushing/popping system #include-paths:
 * >> #include <stdlib.h> // FILE NOT FOUND
 * >> #pragma TPP include_path(push,+ "/usr/include")
 * >> #include <stdlib.h>
 * >> #pragma TPP include_path(pop)
 * >> #include <stdlib.h> // FILE NOT FOUND
 */
DEF_K(include_path)

/* Additional keywords required to implement some GCC stuff. */
DEF_K(GCC)
DEF_K(diagnostic)
DEF_K(ignored)
DEF_K(system_header)


/* TPP extension macros. */
DEF_M_IF(__TPP_EVAL,         HAS_EXTENSION(TPPLEXER_EXTENSION_TPP_EVAL))
DEF_M_IF(__TPP_LOAD_FILE,    HAS_EXTENSION(TPPLEXER_EXTENSION_TPP_LOAD_FILE))
DEF_M_IF(__TPP_COUNTER,      HAS_EXTENSION(TPPLEXER_EXTENSION_TPP_COUNTER))
DEF_M_IF(__TPP_RANDOM,       HAS_EXTENSION(TPPLEXER_EXTENSION_TPP_RANDOM))
DEF_M_IF(__TPP_STR_DECOMPILE,HAS_EXTENSION(TPPLEXER_EXTENSION_TPP_STR_DECOMPILE))
DEF_M_IF(__TPP_STR_AT,       HAS_EXTENSION(TPPLEXER_EXTENSION_TPP_STR_SUBSTR))
DEF_M_IF(__TPP_STR_SUBSTR,   HAS_EXTENSION(TPPLEXER_EXTENSION_TPP_STR_SUBSTR))
DEF_M_IF(__TPP_STR_PACK,     HAS_EXTENSION(TPPLEXER_EXTENSION_TPP_STR_PACK))
DEF_M_IF(__TPP_STR_SIZE,     HAS_EXTENSION(TPPLEXER_EXTENSION_TPP_STR_SIZE))
DEF_M_IF(__TPP_UNIQUE,       HAS_EXTENSION(TPPLEXER_EXTENSION_TPP_UNIQUE))
DEF_M_IF(__TPP_COUNT_TOKENS, HAS_EXTENSION(TPPLEXER_EXTENSION_TPP_COUNT_TOKENS))

DEF_M_IF(__DATE_DAY__,  HAS_EXTENSION(TPPLEXER_EXTENSION_DATEUTILS))
DEF_M_IF(__DATE_WDAY__, HAS_EXTENSION(TPPLEXER_EXTENSION_DATEUTILS))
DEF_M_IF(__DATE_YDAY__, HAS_EXTENSION(TPPLEXER_EXTENSION_DATEUTILS))
DEF_M_IF(__DATE_MONTH__,HAS_EXTENSION(TPPLEXER_EXTENSION_DATEUTILS))
DEF_M_IF(__DATE_YEAR__, HAS_EXTENSION(TPPLEXER_EXTENSION_DATEUTILS))
DEF_M_IF(__TIME_SEC__,  HAS_EXTENSION(TPPLEXER_EXTENSION_TIMEUTILS))
DEF_M_IF(__TIME_MIN__,  HAS_EXTENSION(TPPLEXER_EXTENSION_TIMEUTILS))
DEF_M_IF(__TIME_HOUR__, HAS_EXTENSION(TPPLEXER_EXTENSION_TIMEUTILS))


DEF_EXTENSION_IF(tpp_dollar_is_alpha,             HAS_EXTENSION(TPPLEXER_EXTENSION_DOLLAR_IS_ALPHA))
DEF_EXTENSION_IF(tpp_va_args,                     HAS_EXTENSION(TPPLEXER_EXTENSION_VA_ARGS))
DEF_EXTENSION_IF(tpp_named_va_args,               HAS_EXTENSION(TPPLEXER_EXTENSION_GCC_VA_ARGS))
DEF_EXTENSION_IF(tpp_va_comma,                    HAS_EXTENSION(TPPLEXER_EXTENSION_VA_COMMA))
DEF_EXTENSION_IF(tpp_reemit_unknown_pragmas,      !(TPPLexer_Current->l_flags&TPPLEXER_FLAG_EAT_UNKNOWN_PRAGMA))
//DEF_EXTENSION_IF(tpp_msvc_integer_suffix,       HAS_EXTENSION(0))
DEF_EXTENSION_IF(tpp_charize_operator,            HAS_EXTENSION(TPPLEXER_EXTENSION_HASH_AT))
DEF_EXTENSION_IF(tpp_trigraphs,                   HAS_EXTENSION(TPPLEXER_EXTENSION_TRIGRAPHS))
DEF_EXTENSION_IF(tpp_digraphs,                    HAS_EXTENSION(TPPLEXER_EXTENSION_DIGRAPHS))
DEF_EXTENSION_IF(tpp_pragma_push_macro,           1)
DEF_EXTENSION_IF(tpp_pragma_pop_macro,            1)
DEF_EXTENSION_IF(tpp_pragma_region,               1)
DEF_EXTENSION_IF(tpp_pragma_endregion,            1)
DEF_EXTENSION_IF(tpp_pragma_warning,              1)
DEF_EXTENSION_IF(tpp_pragma_message,              1)
DEF_EXTENSION_IF(tpp_pragma_error,                1)
DEF_EXTENSION_IF(tpp_pragma_once,                 1)
DEF_EXTENSION_IF(tpp_pragma_tpp_exec,             1)
DEF_EXTENSION_IF(tpp_pragma_deprecated,           1)
DEF_EXTENSION_IF(tpp_pragma_tpp_set_keyword_flags,1)
DEF_EXTENSION_IF(tpp_directive_include_next,      HAS_EXTENSION(TPPLEXER_EXTENSION_INCLUDE_NEXT))
DEF_EXTENSION_IF(tpp_directive_import,            HAS_EXTENSION(TPPLEXER_EXTENSION_IMPORT))
DEF_EXTENSION_IF(tpp_directive_warning,           HAS_EXTENSION(TPPLEXER_EXTENSION_WARNING))
DEF_EXTENSION_IF(tpp_lxor,                        HAS_EXTENSION(TPPLEXER_EXTENSION_LXOR))
DEF_EXTENSION_IF(tpp_token_tilde_tilde,           TPPLexer_Current->l_extokens&TPPLEXER_TOKEN_TILDETILDE)
DEF_EXTENSION_IF(tpp_token_pow,                   TPPLexer_Current->l_extokens&TPPLEXER_TOKEN_STARSTAR)
DEF_EXTENSION_IF(tpp_token_lxor,                  TPPLexer_Current->l_extokens&TPPLEXER_TOKEN_ROOFROOF)
DEF_EXTENSION_IF(tpp_token_arrow,                 TPPLexer_Current->l_extokens&TPPLEXER_TOKEN_ARROW)
DEF_EXTENSION_IF(tpp_token_collon_assign,         TPPLexer_Current->l_extokens&TPPLEXER_TOKEN_COLLONASSIGN)
DEF_EXTENSION_IF(tpp_token_collon_collon,         TPPLexer_Current->l_extokens&TPPLEXER_TOKEN_COLLONCOLLON)
DEF_EXTENSION_IF(tpp_macro_calling_conventions,   HAS_EXTENSION(TPPLEXER_EXTENSION_ALTMAC))
DEF_EXTENSION_IF(tpp_strict_whitespace,           (TPPLexer_Current->l_flags&TPPLEXER_FLAG_KEEP_ARG_WHITESPACE))
DEF_EXTENSION_IF(tpp_strict_integer_overflow,     0) /* TODO: (Re-)add detection for this. */
DEF_EXTENSION_IF(tpp_support_ansi_characters,     0) /* TODO: (Re-)add support for this. */
DEF_EXTENSION_IF(tpp_emit_lf_after_directive,     (TPPLexer_Current->l_flags&TPPLEXER_FLAG_DIRECTIVE_NOOWN_LF))
DEF_EXTENSION_IF(tpp_if_cond_expression,          0) /* TODO: (Re-)add support for this. ('__TPP_EVAL(if (foo) 42 else 10)') */
DEF_EXTENSION_IF(tpp_debug,                       TPP_CONFIG_DEBUG)

/* Predefined macros and their values.
 * NOTE: These behave like other predefined macros, allowing
 *       the user to redefine them, but returning when they
 *       #undef their versions again. */
PREDEFINED_MACRO(__TPP_VERSION__,TPP_PP_STR(TPP_PREPROCESSOR_VERSION))

#if !TPP_CONFIG_MINMACRO
/* Pull in GCC-specific definitions. */
#include "tpp-gcc-defs.inl"
#endif /* !TPP_CONFIG_MINMACRO */


WGROUP(WG_COMMENT,             "comment",             WSTATE_ERROR)
WGROUP(WG_COMMENTS,            "comments",            WSTATE_ERROR)
WGROUP(WG_MACROS,              "macros",              WSTATE_ERROR)
WGROUP(WG_SYNTAX,              "syntax",              WSTATE_ERROR)
WGROUP(WG_VALUE,               "value",               WSTATE_ERROR)
WGROUP(WG_USER,                "user",                WSTATE_ERROR)
WGROUP(WG_ENVIRON,             "environ",             WSTATE_ERROR)
WGROUP(WG_LIMIT,               "limit",               WSTATE_ERROR)
WGROUP(WG_UNDEF,               "undef",               WSTATE_ERROR)
WGROUP(WG_TRIGRAPHS,           "trigraphs",           WSTATE_DISABLE)
WGROUP(WG_EXPANSION_TO_DEFINED,"expansion-to-defined",WSTATE_DISABLE)
WGROUP(WG_DIRECTIVE,           "directive",           WSTATE_ERROR)
WGROUP(WG_QUALITY,             "quality",             WSTATE_ERROR)

/* NOTE: These warnings are arranged to mirror those from the old TPP. */
/* 0*/WARNING(W_EXPECTED_KEYWORD_AFTER_DEFINE,   (WG_SYNTAX),  WSTATE_WARN)    /*< OLD(TPPWarn_ExpectedKeywordAfterDefine). */
/* 1*/WARNING(W_REDEFINING_BUILTIN_KEYWORD,      (WG_MACROS),  WSTATE_DISABLE) /*< [struct TPPKeyword *] OLD(TPPWarn_RedefiningBuiltinKeyword). */
/* 2*/WARNING(W_UNKNOWN_PREPROCESSOR_DIRECTIVE,  (WG_SYNTAX),  WSTATE_WARN)    /*< OLD(TPPWarn_UnknownPreprocessorDirective). */
/* 3*/WARNING(W_STARSLASH_OUTSIDE_OF_COMMENT,    (WG_COMMENT,WG_COMMENTS),WSTATE_WARN) /*< [char *] OLD(TPPWarn_StarSlashOutsideOfComment). */
/* 4*/WARNING(W_ERROR,                           (WG_USER),    WSTATE_ERROR)   /*< [char const *,size_t] OLD(TPPWarn_DirectiveError). */
/* 5*/WARNING(W_WARNING,                         (WG_USER),    WSTATE_WARN)    /*< [char const *,size_t] OLD(TPPWarn_DirectiveWarning). */
/* 6*/WARNING(W_EXPECTED_KWDLPAR_AFTER_DEFINED,  (WG_SYNTAX),  WSTATE_WARN)    /*< OLD(TPPWarn_ExpectedKeywordOrLParenAfterDefined). */
/* 7*/WARNING(W_EXPECTED_KEYWORD_AFTER_DEFINED,  (WG_SYNTAX),  WSTATE_WARN)    /*< OLD(TPPWarn_ExpectedKeywordAfterDefined). */
/* 8*/WARNING(W_EXPECTED_RPAREN_AFTER_DEFINED,   (WG_SYNTAX),  WSTATE_WARN)    /*< OLD(TPPWarn_ExpectedRParenAfterDefined). */
/* 9*/WARNING(W_EXPECTED_MACRO_ARGUMENT_NAME,    (WG_SYNTAX),  WSTATE_WARN)    /*< [tok_t] OLD(TPPWarn_ExpectedKeywordForMacroArgument). */
/*10*/WARNING(W_EXPECTED_ARGEND_AFTER_VARARGS,   (WG_SYNTAX),  WSTATE_WARN)    /*< [tok_t] OLD(TPPWarn_ExpectedRParenAfterVaArgs). */
/*11*/WARNING(W_EXPECTED_COMMA_OR_ARGEND,        (WG_SYNTAX),  WSTATE_WARN)    /*< [tok_t] OLD(TPPWarn_ExpectedCommaOrRParenForMacroFuncDecl). */
/*12*/WARNING(W_TOO_MANY_MACRO_ARGUMENTS,        (WG_MACROS),  WSTATE_WARN)    /*< [struct TPPFile *] OLD( TPPWarn_InvalidMacroArgCount). */
/*13*/WARNING(W_EOF_IN_MACRO_ARGUMENT_LIST,      (WG_SYNTAX),  WSTATE_WARN)    /*< OLD(TPPWarn_UnexpectedEOFInMacroArgList). */
/*14*/WARNING(W_EXPECTED_INCLUDE_STRING,         (WG_SYNTAX),  WSTATE_WARN)    /*< OLD(TPPWarn_ExpectedIncludeString). */
/*15*/WARNING(W_FILE_NOT_FOUND,                  (WG_ENVIRON), WSTATE_WARN)    /*< [char const *] OLD(TPPWarn_IncludeFileNotFound). */
/*16*/WARNING(W_UNUSED_00,                       (WG_VALUE),   WSTATE_DISABLE) /*< OLD(TPPWarn_SysIncludeFileNotFound). */
/*17*/WARNING(W_UNUSED_01,                       (WG_VALUE),   WSTATE_DISABLE) /*< OLD(TPPWarn_ExpectedLParenAfterTPPCounter). */
/*18*/WARNING(W_UNUSED_02,                       (WG_VALUE),   WSTATE_DISABLE) /*< OLD(TPPWarn_ExpectedKeywordAfterTPPCounter). */
/*19*/WARNING(W_UNUSED_03,                       (WG_VALUE),   WSTATE_DISABLE) /*< OLD(TPPWarn_ExpectedRParenAfterTPPCounter). */
/*20*/WARNING(W_UNUSED_04,                       (WG_VALUE),   WSTATE_DISABLE) /*< OLD(TPPWarn_ExpectedLParenAfterTPPRandom). */
/*21*/WARNING(W_UNUSED_05,                       (WG_VALUE),   WSTATE_DISABLE) /*< OLD(TPPWarn_ExpectedIntegerAfterTPPRandom1). */
/*22*/WARNING(W_UNUSED_06,                       (WG_VALUE),   WSTATE_DISABLE) /*< OLD(TPPWarn_ExpectedCommaAfterTPPRandom). */
/*23*/WARNING(W_UNUSED_07,                       (WG_VALUE),   WSTATE_DISABLE) /*< OLD(TPPWarn_ExpectedIntegerAfterTPPRandom2). */
/*24*/WARNING(W_UNUSED_08,                       (WG_VALUE),   WSTATE_DISABLE) /*< OLD(TPPWarn_ExpectedRParenAfterTPPRandom). */
/*25*/WARNING(W_REDEFINING_MACRO,                (WG_MACROS),  WSTATE_WARN)    /*< [struct TPPKeyword *] OLD(TPPWarn_MacroAlreadyDefined). */
/*26*/WARNING(W_EXPECTED_KEYWORD_AFTER_UNDEF,    (WG_SYNTAX),  WSTATE_WARN)    /*< OLD(TPPWarn_ExpectedKeywordAfterUndef). */
/*27*/WARNING(W_EXPECTED_KEYWORD_AFTER_IFDEF,    (WG_SYNTAX),  WSTATE_WARN)    /*< OLD(TPPWarn_ExpectedKeywordAfterIfdef). */
/*28*/WARNING(W_ELSE_WITHOUT_IF,                 (WG_SYNTAX),  WSTATE_WARN)    /*< OLD(TPPWarn_ElseWithoutIfdef). */
/*29*/WARNING(W_ELSE_AFTER_ELSE,                 (WG_SYNTAX),  WSTATE_WARN)    /*< [struct TPPIfdefStackSlot *] OLD(TPPWarn_ElseAfterElse). */
/*30*/WARNING(W_ELIF_WITHOUT_IF,                 (WG_SYNTAX),  WSTATE_WARN)    /*< OLD(TPPWarn_ElifWithoutIfdef). */
/*31*/WARNING(W_ELIF_AFTER_ELSE,                 (WG_SYNTAX),  WSTATE_WARN)    /*< [struct TPPIfdefStackSlot *] OLD(TPPWarn_ElifAfterElse). */
/*32*/WARNING(W_IF_WITHOUT_ENDIF,                (WG_SYNTAX),  WSTATE_WARN)    /*< [struct TPPIfdefStackSlot *] OLD(TPPWarn_IfdefWithoutEndif). */
/*33*/WARNING(W_ENDIF_WITHOUT_IF,                (WG_SYNTAX),  WSTATE_WARN)    /*< OLD(TPPWarn_EndifWithoutIfdef). */
/*34*/WARNING(W_UNUSED_09,                       (WG_VALUE),   WSTATE_DISABLE) /*< OLD(TPPWarn_ExpectedIntAfterLine). */
/*35*/WARNING(W_EXPECTED_STRING_AFTER_LINE,      (WG_VALUE),   WSTATE_WARN)    /*< [struct TPPConst *] OLD(TPPWarn_ExpectedStringAfterLine). */
/*36*/WARNING(W_MACRO_NOT_DEFINED,               (WG_VALUE),   WSTATE_DISABLE) /*< [struct TPPKeyword *] OLD(TPPWarn_MacroDoesntExist). */
/*37*/WARNING(W_CANT_UNDEF_BUILTIN_MACRO,        (WG_VALUE),   WSTATE_WARN)    /*< [struct TPPKeyword *] OLD(TPPWarn_CantUndefBuiltinMacro). */
/*38*/WARNING(W_UNUSED_0A,                       (WG_VALUE),   WSTATE_DISABLE) /*< OLD(TPPWarn_ExpectedLParenAfterHasInclude). */
/*39*/WARNING(W_UNUSED_0B,                       (WG_VALUE),   WSTATE_DISABLE) /*< OLD(TPPWarn_ExpectedRParenAfterHasInclude). */
/*40*/WARNING(W_EXPECTED_COLLON_AFTER_QUESTION,  (WG_SYNTAX),  WSTATE_WARN)    /*< OLD(TPPWarn_ExpectedCollonAfterQuestion). */
/*41*/WARNING(W_INVALID_INTEGER_SUFFIX,          (WG_SYNTAX),  WSTATE_WARN)    /*< [char const *,size_t] OLD(TPPWarn_ExpectedInteger). */
/*42*/WARNING(W_EXPECTED_RPAREN_IN_EXPRESSION,   (WG_SYNTAX),  WSTATE_WARN)    /*< OLD(TPPWarn_ExpectedRparenAfterLParen). */
/*43*/WARNING(W_UNKNOWN_TOKEN_IN_EXPR_IS_ZERO,   (WG_UNDEF,WG_SYNTAX),WSTATE_WARN) /*< OLD(TPPWarn_UnexpectedTokenInConstExpr). */
/*44*/WARNING(W_UNUSED_0C,                       (WG_VALUE),   WSTATE_DISABLE) /*< OLD(TPPWarn_ExpectedLParenAfterTPPEval). */
/*45*/WARNING(W_UNUSED_0D,                       (WG_VALUE),   WSTATE_DISABLE) /*< OLD(TPPWarn_ExpectedRParenAfterTPPEval). */
/*46*/WARNING(W_UNUSED_0E,                       (WG_VALUE),   WSTATE_DISABLE) /*< OLD(TPPWarn_ExpectedLParenAfterPragma). */
/*47*/WARNING(W_EXPECTED_STRING_AFTER_PRAGMA,    (WG_VALUE),   WSTATE_WARN)    /*< [struct TPPConst *] OLD(TPPWarn_ExpectedStringAfterPragma). */
/*48*/WARNING(W_UNUSED_0F,                       (WG_VALUE),   WSTATE_DISABLE) /*< OLD(TPPWarn_ExpectedRParenAfterPragma). */
/*49*/WARNING(W_UNUSED_10,                       (WG_VALUE),   WSTATE_DISABLE) /*< OLD(TPPWarn_UnexpectedToken). */
/*50*/WARNING(W_INVALID_WARNING,                 (WG_VALUE),   WSTATE_WARN)    /*< [struct TPPConst *] OLD(TPPWarn_InvalidWarning). */
/*51*/WARNING(W_CANT_POP_WARNINGS,               (WG_VALUE),   WSTATE_WARN)    /*< OLD(TPPWarn_CantPopWarnings). */
/*52*/WARNING(W_UNUSED_11,                       (WG_VALUE),   WSTATE_DISABLE) /*< OLD(TPPWarn_TPPLoadFileNotFound). */
/*53*/WARNING(W_EXPECTED_STRING_AFTER_PUSHMACRO, (WG_VALUE),   WSTATE_WARN)    /*< [struct TPPConst *] OLD(TPPWarn_ExpectedStringAfterPushMacro). */
/*54*/WARNING(W_UNUSED_12,                       (WG_VALUE),   WSTATE_DISABLE) /*< OLD(TPPWarn_CantPopMacro). */
/*55*/WARNING(W_UNUSED_13,                       (WG_VALUE),   WSTATE_DISABLE) /*< OLD(TPPWarn_ExpectedLParenAfterTPPStrDecompile). */
/*56*/WARNING(W_EXPECTED_STRING_AFTER_TPP_STRD,  (WG_VALUE),   WSTATE_WARN)    /*< [struct TPPConst *] OLD(TPPWarn_ExpectedStringAfterTPPStrDecompile). */
/*57*/WARNING(W_UNUSED_14,                       (WG_VALUE),   WSTATE_DISABLE) /*< OLD(TPPWarn_ExpectedRParenAfterTPPStrDecompile). */
/*58*/WARNING(W_EXPECTED_LPAREN,                 (WG_SYNTAX),  WSTATE_WARN)    /*< OLD(TPPWarn_ExpectedLParen). */
/*59*/WARNING(W_EXPECTED_RPAREN,                 (WG_SYNTAX),  WSTATE_WARN)    /*< OLD(TPPWarn_ExpectedRParen). */
/*60*/WARNING(W_DEPRECATED_IDENTIFIER,           (WG_USER),    WSTATE_WARN)    /*< [struct TPPKeyword *] OLD(TPPWarn_DeprecatedKeyword). */
/*61*/WARNING(W_NONPARTABLE_FILENAME_CASING,     (WG_ENVIRON), WSTATE_WARN)    /*< [char const *,char const *,size_t,char const *]. (path,wrong_begin,wrong_size,corrent_begin) OLD(TPPWarn_InvalidPathCasing). */
/*62*/WARNING(W_DIVIDE_BY_ZERO,                  (WG_VALUE),   WSTATE_WARN)    /*< OLD(TPPWarn_DivideByZero|TPPWarn_ModuloByZero). */
/*63*/WARNING(W_ARGUMENT_NAMED_ALREADY_TAKEN,    (WG_MACROS),  WSTATE_WARN)    /*< [tok_t] OLD(TPPWarn_ReusedMacroParameter). */
/*64*/WARNING(W_SPECIAL_ARGUMENT_NAME,           (WG_MACROS),  WSTATE_WARN)    /*< [struct TPPKeyword *] OLD(TPPWarn_VaArgsUsedAsMacroParameter). */
/*65*/WARNING(W_UNUSED_15,                       (WG_VALUE),   WSTATE_WARN)    /*< OLD(TPPWarn_VaCommaUsedAsMacroParameter). */
/*66*/WARNING(W_UNUSED_16,                       (WG_VALUE),   WSTATE_WARN)    /*< OLD(TPPWarn_Unexpected). */
/*67*/WARNING(W_UNUSED_17,                       (WG_VALUE),   WSTATE_WARN)    /*< OLD(TPPWarn_VaArgsMustBeLastParameter). */
/*68*/WARNING(W_UNUSED_18,                       (WG_VALUE),   WSTATE_WARN)    /*< OLD(TPPWarn_ExpectedBoolExpression). */
/*69*/WARNING(W_UNUSED_19,                       (WG_VALUE),   WSTATE_WARN)    /*< OLD(TPPWarn_ExpectedBoolExpressionNot). */
/*70*/WARNING(W_UNUSED_1A,                       (WG_VALUE),   WSTATE_WARN)    /*< OLD(TPPWarn_ExpectedBoolExpressionLhsOP). */
/*71*/WARNING(W_UNUSED_1B,                       (WG_VALUE),   WSTATE_WARN)    /*< OLD(TPPWarn_ExpectedBoolExpressionRhsOP). */
/*72*/WARNING(W_UNUSED_1C,                       (WG_VALUE),   WSTATE_WARN)    /*< OLD(TPPWarn_ExpectedKeyword). */

/* Warnings added by the new TPP. */
WARNING(W_SLASHSTAR_INSIDE_OF_COMMENT,     (WG_COMMENTS,WG_COMMENT),WSTATE_WARN) /*< [char *]. */
WARNING(W_LINE_COMMENT_CONTINUED,          (WG_COMMENTS,WG_COMMENT),WSTATE_WARN) /*< . */
WARNING(W_VA_KEYWORD_IN_REGULAR_MACRO,     (WG_MACROS),  WSTATE_WARN)    /*< [struct TPPKeyword *]. */
WARNING(W_KEYWORD_MACRO_ALREADY_ONSTACK,   (WG_MACROS),  WSTATE_DISABLE) /*< [struct TPPFile *]. */
WARNING(W_FUNCTION_MACRO_ALREADY_ONSTACK,  (WG_MACROS),  WSTATE_DISABLE) /*< [struct TPPFile *]. */
WARNING(W_NOT_ENGOUH_MACRO_ARGUMENTS,      (WG_MACROS),  WSTATE_WARN)    /*< [struct TPPFile *]. */
WARNING(W_CHARACTER_TOO_LONG,              (WG_VALUE),   WSTATE_WARN)    /*< . */
WARNING(W_MULTICHAR_NOT_ALLOWED,           (WG_VALUE),   WSTATE_WARN)    /*< [char const *,size_t]. */
WARNING(W_INTEX_OUT_OF_BOUNDS,             (WG_VALUE),   WSTATE_DISABLE) /*< [struct TPPString *,ptrdiff_t]. */
WARNING(W_STRING_TERMINATED_BY_LINEFEED,   (WG_SYNTAX),  WSTATE_WARN)    /*< . */
WARNING(W_STRING_TERMINATED_BY_EOF,        (WG_SYNTAX),  WSTATE_WARN)    /*< . */
WARNING(W_COMMENT_TERMINATED_BY_EOF,       (WG_SYNTAX),  WSTATE_WARN)    /*< . */
WARNING(W_ENCOUNTERED_TRIGRAPH,            (WG_TRIGRAPHS),WSTATE_WARN)   /*< [char (*)[3]]. */
WARNING(W_EXPECTED_RBRACKET_IN_EXPRESSION, (WG_SYNTAX),  WSTATE_WARN)    /*< . */
WARNING(W_EXPECTED_COLLON_AFTER_WARNING,   (WG_SYNTAX),  WSTATE_WARN)    /*< . */
WARNING(W_EXPECTED_COMMA,                  (WG_SYNTAX),  WSTATE_WARN)    /*< . */
WARNING(W_EXPECTED_STRING_IN_EXPRESSION,   (WG_VALUE),   WSTATE_WARN)    /*< [struct TPPConst *]. */
WARNING(W_EXPECTED_STRING_AFTER_MESSAGE,   (WG_VALUE),   WSTATE_WARN)    /*< [struct TPPConst *]. */
WARNING(W_EXPECTED_STRING_AFTER_DEPRECATED,(WG_VALUE),   WSTATE_WARN)    /*< [struct TPPConst *]. */
WARNING(W_EXPECTED_STRING_AFTER_TPP_EXEC,  (WG_VALUE),   WSTATE_WARN)    /*< [struct TPPConst *]. */
WARNING(W_EXPECTED_STRING_AFTER_TPP_SETF,  (WG_VALUE),   WSTATE_WARN)    /*< [struct TPPConst *]. */
WARNING(W_EXPECTED_STRING_AFTER_TPP_STRAT, (WG_VALUE),   WSTATE_WARN)    /*< [struct TPPConst *]. */
WARNING(W_EXPECTED_STRING_AFTER_TPP_CNTTOK,(WG_VALUE),   WSTATE_WARN)    /*< [struct TPPConst *]. */
WARNING(W_EXPECTED_STRING_AFTER_PRGERROR,  (WG_VALUE),   WSTATE_WARN)    /*< [struct TPPConst *]. */
WARNING(W_EXPECTED_STRING_AFTER_EXTENSION, (WG_VALUE),   WSTATE_WARN)    /*< [struct TPPConst *]. */
WARNING(W_EXPECTED_STRING_AFTER_TPP_INCPTH,(WG_VALUE),   WSTATE_WARN)    /*< [struct TPPConst *]. */
WARNING(W_MACRO_RECURSION_LIMIT_EXCEEDED,  (WG_LIMIT),   WSTATE_WARN)    /*< [struct TPPFile *]. */
WARNING(W_INCLUDE_RECURSION_LIMIT_EXCEEDED,(WG_LIMIT),   WSTATE_WARN)    /*< [struct TPPFile *]. */
WARNING(W_UNKNOWN_EXTENSION,               (WG_VALUE),   WSTATE_WARN)    /*< [char const *]. */
WARNING(W_DEFINED_IN_MACRO_BODY,           (WG_EXPANSION_TO_DEFINED),WSTATE_WARN)
WARNING(W_IDENT_SCCS_IGNORED,              (WG_DIRECTIVE),WSTATE_WARN)   /*< [struct TPPConst *]. */
WARNING(W_EXPECTED_STRING_AFTER_IDENT,     (WG_VALUE),    WSTATE_WARN)   /*< [struct TPPConst *]. */
WARNING(W_EXPECTED_KEYWORD_AFTER_ASSERT,   (WG_DIRECTIVE),WSTATE_WARN)   /*< . */
WARNING(W_EXPECTED_KEYWORD_AFTER_PREDICATE,(WG_DIRECTIVE),WSTATE_WARN)   /*< [struct TPPKeyword *]. */
WARNING(W_EXPECTED_KEYWORD_AFTER_EXPR_HASH,(WG_DIRECTIVE),WSTATE_WARN)   /*< . */
WARNING(W_EXPECTED_KEYWORD_AFTER_EXPR_PRED,(WG_DIRECTIVE),WSTATE_WARN)   /*< . */
WARNING(W_UNKNOWN_ASSERTION,               (WG_VALUE),   WSTATE_DISABLE) /*< [struct TPPKeyword *,struct TPPKeyword *]. */
WARNING(W_EXPECTED_STRING_AFTER_GCC_DIAG,  (WG_VALUE),   WSTATE_WARN)    /*< [struct TPPConst *]. */
WARNING(W_CANT_POP_EXTENSIONS,             (WG_VALUE),   WSTATE_WARN)    /*< . */
WARNING(W_CANT_POP_INCLUDE_PATH,           (WG_VALUE),   WSTATE_WARN)    /*< . */
WARNING(W_CONSIDER_PAREN_AROUND_LAND,      (WG_QUALITY), WSTATE_WARN)    /*< . */
WARNING(W_INTEGRAL_OVERFLOW,               (WG_VALUE),   WSTATE_WARN)    /*< [int_t,int_t]. */
WARNING(W_INTEGRAL_CLAMPED,                (WG_VALUE),   WSTATE_WARN)    /*< [int_t,int_t]. */
WARNING(W_UNKNOWN_INCLUDE_PATH,            (WG_VALUE),   WSTATE_WARN)    /*< [char const *,size_t]. */
WARNING(W_INCLUDE_PATH_ALREADY_EXISTS,     (WG_VALUE),   WSTATE_WARN)    /*< [char const *,size_t]. */

#undef TPP_PP_STR
#undef TPP_PP_STR2
#undef PREDEFINED_MACRO_IF
#undef PREDEFINED_MACRO
#undef PREDEFINED_KWDMACRO_IF
#undef PREDEFINED_KWDMACRO
#undef DEF_EXTENSION_IF
#undef DEF_FEATURE_IF
#undef DEF_M_IF
#undef DEF_M
#undef DEF_K

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
#ifdef TPP_DEFS_DEFINES_KWD_FLAGS
#undef TPP_DEFS_DEFINES_KWD_FLAGS
#undef KWD_FLAGS
#endif
#ifdef TPP_DEFS_DEFINES_KWD
#undef TPP_DEFS_DEFINES_KWD
#undef KWD
#endif

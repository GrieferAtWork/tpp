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

#define TPP_PRIVATE_PP_CAT2(a, b) a##b
#define TPP_PRIVATE_PP_CAT3(a, b, c) a##b##c
#define TPP_PP_CAT2(a, b) TPP_PRIVATE_PP_CAT2(a, b)
#define TPP_PP_CAT3(a, b, c) TPP_PRIVATE_PP_CAT3(a, b, c)

/* CPU-specific predefined macros. */
#if defined(__alpha__) || defined(__alpha) || defined(_M_ALPHA)
PREDEFINED_MACRO_IF(__alpha__, HAS(EXT_CPU_MACROS), "1")
#endif

#if defined(__amd64__) || defined(__amd64) || \
defined(__x86_64__) || defined(__x86_64) ||   \
defined(_M_X64) || defined(_M_AMD64)
PREDEFINED_MACRO_IF(__x86_64__, HAS(EXT_CPU_MACROS), "1")
#endif

#if defined(__TARGET_ARCH_ARM)
#define TPP_ARM_VERSION __TARGET_ARCH_ARM
#elif defined(_M_ARM)
#define TPP_ARM_VERSION _M_ARM
#elif defined(__ARM_ARCH_8__)
#define TPP_ARM_VERSION 8
#elif defined(__ARM_ARCH_7__) || defined(__ARM_ARCH_7A__) || \
defined(__ARM_ARCH_7R__) || defined(__ARM_ARCH_7M__) ||      \
defined(__ARM_ARCH_7S__)
#define TPP_ARM_VERSION 7
#elif defined(__ARM_ARCH_6__) || defined(__ARM_ARCH_6J__) || \
defined(__ARM_ARCH_6K__) || defined(__ARM_ARCH_6Z__) ||      \
defined(__ARM_ARCH_6ZK__) || defined(__ARM_ARCH_6T2__)
#define TPP_ARM_VERSION 6
#elif defined(__ARM_ARCH_5__) || defined(__ARM_ARCH_5E__) || \
defined(__ARM_ARCH_5T__) || defined(__ARM_ARCH_5TE__) ||     \
defined(__ARM_ARCH_5TEJ__)
#define TPP_ARM_VERSION 5
#elif defined(__ARM_ARCH_4T__) || defined(__TARGET_ARM_4T)
#define TPP_ARM_VERSION 4
#elif defined(__ARM_ARCH_3__) || defined(__ARM_ARCH_3M__)
#define TPP_ARM_VERSION 3
#elif defined(__ARM_ARCH_2__)
#define TPP_ARM_VERSION 2
#elif defined(__arm__) || defined(__arm) || defined(_ARM) || defined(__ARM_ARCH_1__)
#define TPP_ARM_VERSION 1
#endif
#ifdef TPP_ARM_VERSION
PREDEFINED_MACRO_IF(__arm__, HAS(EXT_CPU_MACROS), TPP_PP_STR(TPP_ARM_VERSION))
#if TPP_ARM_VERSION == 8
PREDEFINED_MACRO_IF(__ARM_ARCH_8__, HAS(EXT_CPU_MACROS), "1")
#elif TPP_ARM_VERSION == 7
PREDEFINED_MACRO_IF(__ARM_ARCH_7__, HAS(EXT_CPU_MACROS), "1")
#elif TPP_ARM_VERSION == 6
#ifdef __ARM_ARCH_6T2__
PREDEFINED_MACRO_IF(__ARM_ARCH_6T2__, HAS(EXT_CPU_MACROS), "1")
#else
PREDEFINED_MACRO_IF(__ARM_ARCH_6__, HAS(EXT_CPU_MACROS), "1")
#endif
#elif TPP_ARM_VERSION == 5
#if defined(__ARM_ARCH_5T__) || defined(__ARM_ARCH_5TE__) || defined(__ARM_ARCH_5TEJ__)
PREDEFINED_MACRO_IF(__ARM_ARCH_5T__, HAS(EXT_CPU_MACROS), "1")
#else
PREDEFINED_MACRO_IF(__ARM_ARCH_5__, HAS(EXT_CPU_MACROS), "1")
#endif
#elif TPP_ARM_VERSION == 4
PREDEFINED_MACRO_IF(__ARM_ARCH_4T__, HAS(EXT_CPU_MACROS), "1")
#elif TPP_ARM_VERSION == 3
PREDEFINED_MACRO_IF(__ARM_ARCH_3__, HAS(EXT_CPU_MACROS), "1")
#elif TPP_ARM_VERSION == 2
PREDEFINED_MACRO_IF(__ARM_ARCH_2__, HAS(EXT_CPU_MACROS), "1")
#else
PREDEFINED_MACRO_IF(__ARM_ARCH_1__, HAS(EXT_CPU_MACROS), "1")
#endif
#if defined(__TARGET_ARCH_THUMB)
PREDEFINED_MACRO_IF(__thumb__, HAS(EXT_CPU_MACROS), TPP_PP_STR(__TARGET_ARCH_THUMB))
#elif defined(_M_ARMT)
PREDEFINED_MACRO_IF(__thumb__, HAS(EXT_CPU_MACROS), TPP_PP_STR(_M_ARM))
#elif defined(__thumb__)
PREDEFINED_MACRO_IF(__thumb__, HAS(EXT_CPU_MACROS), TPP_PP_STR(TPP_ARM_VERSION))
#endif
#undef TPP_ARM_VERSION
#endif

#ifdef __aarch64__
PREDEFINED_MACRO_IF(__aarch64__, HAS(EXT_CPU_MACROS), "1")
#endif /* __aarch64__ */

#if defined(__bfin) || defined(__BFIN__)
PREDEFINED_MACRO_IF(__bfin, HAS(EXT_CPU_MACROS), "1")
#endif /* __bfin || __BFIN__ */

#ifdef __C67__
PREDEFINED_MACRO_IF(__C67__, HAS(EXT_CPU_MACROS), "1")
#endif /* __C67__ */

#ifdef __convex__
PREDEFINED_MACRO_IF(__convex__, HAS(EXT_CPU_MACROS), "1")
#ifdef __convex_c1__
PREDEFINED_MACRO_IF(__convex_c1__, HAS(EXT_CPU_MACROS), "1")
#endif /* __convex_c1__ */
#ifdef __convex_c2__
PREDEFINED_MACRO_IF(__convex_c2__, HAS(EXT_CPU_MACROS), "1")
#endif /* __convex_c2__ */
#ifdef __convex_c32__
PREDEFINED_MACRO_IF(__convex_c32__, HAS(EXT_CPU_MACROS), "1")
#endif /* __convex_c32__ */
#ifdef __convex_c34__
PREDEFINED_MACRO_IF(__convex_c34__, HAS(EXT_CPU_MACROS), "1")
#endif /* __convex_c34__ */
#ifdef __convex_c38__
PREDEFINED_MACRO_IF(__convex_c38__, HAS(EXT_CPU_MACROS), "1")
#endif /* __convex_c38__ */
#endif /* __convex__ */

#ifdef __epiphany__
PREDEFINED_MACRO_IF(__epiphany__, HAS(EXT_CPU_MACROS), "1")
#endif /* __epiphany__ */

#if defined(__hppa__) || defined(__HPPA__) || defined(__hppa)
PREDEFINED_MACRO_IF(__hppa__, HAS(EXT_CPU_MACROS), "1")
#endif /* __hppa__ || __HPPA__ || __hppa */

#if defined(__I86__)
#define TPP_I386_VERSION (__I86__ * 100)
#elif defined(_M_IX86)
#define TPP_I386_VERSION _M_IX86
#elif defined(__i686__) || defined(__i686) || defined(i686)
#define TPP_I386_VERSION 600
#elif defined(__i586__) || defined(__i586) || defined(i586)
#define TPP_I386_VERSION 500
#elif defined(__i486__) || defined(__i486) || defined(i486)
#define TPP_I386_VERSION 400
#elif defined(__i386__) || defined(__i386) || defined(i386) || \
      defined(__X86__) || defined(_X86_) ||                    \
      defined(__THW_INTEL__) || defined(__INTEL__)
#define TPP_I386_VERSION 300
#endif
#ifdef TPP_I386_VERSION
#if TPP_I386_VERSION >= 600
PREDEFINED_MACRO_IF(__i686__, HAS(EXT_CPU_MACROS), "1")
#endif
#if TPP_I386_VERSION >= 500
PREDEFINED_MACRO_IF(__i586__, HAS(EXT_CPU_MACROS), "1")
#endif
#if TPP_I386_VERSION >= 400
PREDEFINED_MACRO_IF(__i486__, HAS(EXT_CPU_MACROS), "1")
#endif
#if TPP_I386_VERSION >= 300
PREDEFINED_MACRO_IF(__i386__, HAS(EXT_CPU_MACROS), "1")
#endif
#undef TPP_I386_VERSION
#endif /* TPP_I386_VERSION */

#if defined(__ia64__) || defined(_IA64) || defined(__IA64__) || \
    defined(__ia64) || defined(_M_IA64) || defined(__itanium__)
PREDEFINED_MACRO_IF(__ia64__, HAS(EXT_CPU_MACROS), "1")
#endif /* __ia64__ || _IA64 || __IA64__ || __ia64 || _M_IA64 || __itanium__ */

#if defined(__mc68060__) || defined(__mc68060) || defined(mc68060)
#define TPP_M64K_VERSION 68060
#elif defined(__mc68040__) || defined(__mc68040) || defined(mc68040)
#define TPP_M64K_VERSION 68040
#elif defined(__mc68030__) || defined(__mc68030) || defined(mc68030)
#define TPP_M64K_VERSION 68030
#elif defined(__mc68020__) || defined(__mc68020) || defined(mc68020)
#define TPP_M64K_VERSION 68020
#elif defined(__mc68010__) || defined(__mc68010) || defined(mc68010)
#define TPP_M64K_VERSION 68010
#elif defined(__mc68000__) || defined(__mc68000) || defined(mc68000) || \
      defined(__MC68000__) || defined(M68000) || defined(__MC68K__)
#define TPP_M64K_VERSION 68000
#endif
#ifdef TPP_M64K_VERSION
PREDEFINED_MACRO_IF(__m68k__, HAS(EXT_CPU_MACROS), TPP_PP_STR(TPP_M64K_VERSION))
PREDEFINED_KWD_MACRO_IF(TPP_PP_CAT3(KWD___mc, TPP_M64K_VERSION, __),
                        "__mc" TPP_PP_STR(TPP_M64K_VERSION) "__",
                        HAS(EXT_CPU_MACROS), "1")
#undef TPP_M64K_VERSION
#endif /* TPP_M64K_VERSION */

#if defined(__mips)
#define TPP_MIPS_VERSION __mips
#elif defined(__MIPS_ISA4__)
#define TPP_MIPS_VERSION 4
#elif defined(__MIPS_ISA3__)
#define TPP_MIPS_VERSION 3
#elif defined(__MIPS_ISA2__)
#define TPP_MIPS_VERSION 2
#elif defined(_MIPS_ISA)
#if defined(_MIPS_ISA_MIPS4) && _MIPS_ISA == _MIPS_ISA_MIPS4
#define TPP_MIPS_VERSION 4
#elif defined(_MIPS_ISA_MIPS3) && _MIPS_ISA == _MIPS_ISA_MIPS3
#define TPP_MIPS_VERSION 3
#elif defined(_MIPS_ISA_MIPS2) && _MIPS_ISA == _MIPS_ISA_MIPS2
#define TPP_MIPS_VERSION 2
#else
#define TPP_MIPS_VERSION 1
#endif
#elif defined(__mips__)
#define TPP_MIPS_VERSION __mips__
#elif defined(__MIPS__)
#define TPP_MIPS_VERSION 1
#endif

#ifdef TPP_MIPS_VERSION
PREDEFINED_MACRO_IF(__mips__, HAS(EXT_CPU_MACROS), TPP_PP_STR(TPP_MIPS_VERSION))
PREDEFINED_MACRO_IF(__mips, HAS(EXT_CPU_MACROS), TPP_PP_STR(TPP_MIPS_VERSION))
#undef TPP_MIPS_VERSION
#endif /* TPP_MIPS_VERSION */

#ifdef _M_PPC
#define TPP_POWERPC_VERSION _M_PPC
#elif defined(__ppc604__)
#define TPP_POWERPC_VERSION 604
#elif defined(__ppc603__)
#define TPP_POWERPC_VERSION 603
#elif defined(__ppc601__)
#define TPP_POWERPC_VERSION 601
#elif defined(__powerpc) || defined(__powerpc__) || defined(__powerpc64__) ||      \
      defined(__POWERPC__) || defined(__ppc__) || defined(__ppc64__) ||            \
      defined(__PPC__) || defined(__PPC64__) || defined(_ARCH_PPC) ||              \
      defined(_ARCH_PPC64) || defined(__PPCGECKO__) || defined(__PPCBROADWAY__) || \
      defined(_XENON) || defined(__ppc)
#if defined(_ARCH_620)
#define TPP_POWERPC_VERSION 620
#elif defined(_ARCH_604)
#define TPP_POWERPC_VERSION 604
#elif defined(_ARCH_603)
#define TPP_POWERPC_VERSION 603
#elif defined(_ARCH_601)
#define TPP_POWERPC_VERSION 601
#elif defined(_ARCH_450)
#define TPP_POWERPC_VERSION 450
#else
#define TPP_POWERPC_VERSION 440
#endif
#endif

#ifdef TPP_POWERPC_VERSION
PREDEFINED_MACRO_IF(__powerpc__, HAS(EXT_CPU_MACROS),
                    TPP_PP_STR(TPP_POWERPC_VERSION))
PREDEFINED_KWDMACRO_IF(TPP_PP_CAT3(KWD___ppc, TPP_POWERPC_VERSION, __),
                       "__ppc" TPP_PP_STR(TPP_POWERPC_VERSION) "__",
                       HAS(EXT_CPU_MACROS), "1")
#undef TPP_POWERPC_VERSION
#endif /* TPP_POWERPC_VERSION */

#ifdef pyr
PREDEFINED_MACRO_IF(pyr, HAS(EXT_CPU_MACROS), TPP_PP_STR(pyr))
#endif /* pyr */


#if defined(__sparc_v9__) || defined(__sparcv9)
#define TPP_SPARC_VERSION 9
#elif defined(__sparc_v8__) || defined(__sparcv8)
#define TPP_SPARC_VERSION 8
#elif defined(__sparc__) || defined(__sparc)
#define TPP_SPARC_VERSION 1
#endif

#ifdef TPP_SPARC_VERSION
PREDEFINED_MACRO_IF(__sparc__, HAS(EXT_CPU_MACROS), TPP_PP_STR(TPP_SPARC_VERSION))
#if TPP_SPARC_VERSION == 9
PREDEFINED_MACRO_IF(__sparc_v9__, HAS(EXT_CPU_MACROS), "1")
#elif TPP_SPARC_VERSION == 8
PREDEFINED_MACRO_IF(__sparc_v8__, HAS(EXT_CPU_MACROS), "1")
#endif
#undef TPP_SPARC_VERSION
#endif /* TPP_SPARC_VERSION */

#if defined(__SH5__) || defined(__sh5__)
#define TPP_SUPERH_VERSION 5
#elif defined(__SH4__) || defined(__sh4__)
#define TPP_SUPERH_VERSION 4
#elif defined(__SH3__) || defined(__sh3__)
#define TPP_SUPERH_VERSION 3
#elif defined(__SH2__) || defined(__sh2__)
#define TPP_SUPERH_VERSION 2
#elif defined(__SH1__) || defined(__sh1__) || defined(__sh__)
#define TPP_SUPERH_VERSION 1
#endif

#ifdef TPP_SUPERH_VERSION
PREDEFINED_MACRO_IF(__sh__, HAS(EXT_CPU_MACROS), TPP_PP_STR(TPP_SUPERH_VERSION))
PREDEFINED_KWDMACRO_IF(TPP_PP_CAT3(KWD___sh, TPP_SUPERH_VERSION, __),
                       "__sh" TPP_PP_STR(TPP_SUPERH_VERSION) "__",
                       HAS(EXT_CPU_MACROS), "1")
#undef TPP_SUPERH_VERSION
#endif /* TPP_SUPERH_VERSION */

#if defined(__s390x__) || defined(__zarch__) || defined(__SYSC_ZARCH__)
PREDEFINED_MACRO_IF(__s390x__, HAS(EXT_CPU_MACROS), "1")
#endif /* __s390x__ || __zarch__ || __SYSC_ZARCH__ */
#if defined(__370__) || defined(__THW_370__) || defined(__s390__)
PREDEFINED_MACRO_IF(__370__, HAS(EXT_CPU_MACROS), "1")
#endif /* __370__ || __THW_370__ || __s390__ */

/* System-specific predefined macros. */
#ifdef __APPLE__
PREDEFINED_MACRO_IF(__APPLE__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__APPLE__))
#endif /* __APPLE__ */
#ifdef __MACH__
PREDEFINED_MACRO_IF(__MACH__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__MACH__))
#endif /* __MACH__ */
#ifdef __ANDROID__
PREDEFINED_MACRO_IF(__ANDROID__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__ANDROID__))
#elif defined(__ANDROID)
PREDEFINED_MACRO_IF(__ANDROID__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__ANDROID))
#elif defined(__android__)
PREDEFINED_MACRO_IF(__ANDROID__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__android__))
#elif defined(__android)
PREDEFINED_MACRO_IF(__ANDROID__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__android))
#endif
#ifdef __amigaos__
PREDEFINED_MACRO_IF(__amigaos__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__amigaos__))
#elif defined(AMIGA)
PREDEFINED_MACRO_IF(__amigaos__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(AMIGA))
#endif
#if defined(__bg__) || defined(__bgq__) || defined(__THW_BLUEGENE__) || defined(__TOS_BGQ__)
PREDEFINED_MACRO_IF(__bg__, HAS(EXT_SYSTEM_MACROS), "1")
#endif /* __bg__ || __bgq__ || __THW_BLUEGENE__ || __TOS_BGQ__ */
#ifdef __bgq__
PREDEFINED_MACRO_IF(__bgq__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__bgq__))
#elif defined(__TOS_BGQ__)
PREDEFINED_MACRO_IF(__bgq__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__TOS_BGQ__))
#endif
#ifdef __FreeBSD__
PREDEFINED_MACRO_IF(__FreeBSD__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__FreeBSD__))
#endif /* __FreeBSD__ */
#ifdef __NetBSD__
PREDEFINED_MACRO_IF(__NetBSD__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__NetBSD__))
#endif /* __NetBSD__ */
#ifdef __OpenBSD__
PREDEFINED_MACRO_IF(__OpenBSD__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__OpenBSD__))
#endif /* __OpenBSD__ */
#ifdef __bsdi__
PREDEFINED_MACRO_IF(__bsdi__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__bsdi__))
#endif /* __bsdi__ */
#ifdef __CYGWIN__
#define TPP_PLATFORM_NOT_WINDOWS
PREDEFINED_MACRO_IF(__CYGWIN__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__CYGWIN__))
#elif defined(__MINGW32__)
#define TPP_PLATFORM_NOT_WINDOWS
PREDEFINED_MACRO_IF(__MINGW32__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__MINGW32__))
PREDEFINED_MACRO_IF(__CYGWIN__, HAS(EXT_SYSTEM_MACROS), "1") /* Prefer cygwin! */
#endif
#ifdef DGUX
PREDEFINED_MACRO_IF(__dgux__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(DGUX))
#elif defined(__DGUX__)
PREDEFINED_MACRO_IF(__dgux__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__DGUX__))
#elif defined(__dgux__)
PREDEFINED_MACRO_IF(__dgux__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__dgux__))
#endif
#ifdef __DragonFly__
PREDEFINED_MACRO_IF(__DragonFly__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__DragonFly__))
#endif /* __DragonFly__ */
#ifdef __ECOS
PREDEFINED_MACRO_IF(__ECOS, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__ECOS))
#endif /* __ECOS */
#ifdef __EMX__
PREDEFINED_MACRO_IF(__EMX__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__EMX__))
#endif /* __EMX__ */
#ifdef __hiuxmpp
PREDEFINED_MACRO_IF(__hiuxmpp, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__hiuxmpp))
#endif /* __hiuxmpp */
#ifdef _hpux
PREDEFINED_MACRO_IF(__hpux, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(_hpux))
#elif defined(hpux)
PREDEFINED_MACRO_IF(__hpux, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(hpux))
#elif defined(__hpux)
PREDEFINED_MACRO_IF(__hpux, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__hpux))
#endif
#ifdef sgi
PREDEFINED_MACRO_IF(__sgi, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(sgi))
#elif defined(__sgi)
PREDEFINED_MACRO_IF(__sgi, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__sgi))
#endif
#if defined(__linux__) || defined(__linux) || defined(linux)
PREDEFINED_MACRO_IF(__linux__, HAS(EXT_SYSTEM_MACROS), "1")
#endif /* __linux__ || __linux || linux */
#ifdef __Lynx__
PREDEFINED_MACRO_IF(__Lynx__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__Lynx__))
#endif /* __Lynx__ */
#ifdef __OS9000
PREDEFINED_MACRO_IF(__OS9000, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__OS9000))
#elif defined(_OSK)
PREDEFINED_MACRO_IF(__OS9000, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(_OSK))
#endif
#ifdef __minix
PREDEFINED_MACRO_IF(__minix, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__minix))
#endif /* __minix */
#ifdef __MORPHOS__
PREDEFINED_MACRO_IF(__MORPHOS__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__MORPHOS__))
#endif /* __MORPHOS__ */
#ifdef __mpeix
PREDEFINED_MACRO_IF(__mpeix, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__mpeix))
#elif defined(mpeix)
PREDEFINED_MACRO_IF(__mpeix, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(mpeix))
#endif
#ifdef __MSDOS__
PREDEFINED_MACRO_IF(__MSDOS__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__MSDOS__))
#elif defined(MSDOS)
PREDEFINED_MACRO_IF(__MSDOS__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(MSDOS))
#elif defined(_MSDOS)
PREDEFINED_MACRO_IF(__MSDOS__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(_MSDOS))
#elif defined(__DOS__)
PREDEFINED_MACRO_IF(__MSDOS__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__DOS__))
#endif
#ifdef __TANDEM
PREDEFINED_MACRO_IF(__TANDEM, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__TANDEM))
#endif /* __TANDEM */
#ifdef __MACOS__
PREDEFINED_MACRO_IF(__MACOS__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__MACOS__))
#endif /* __MACOS__ */
#ifdef __MACOSX__
PREDEFINED_MACRO_IF(__MACOSX__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__MACOSX__))
#endif /* __MACOSX__ */
#ifdef __nucleus__
PREDEFINED_MACRO_IF(__nucleus__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__nucleus__))
#endif /* __nucleus__ */
#ifdef OS2
PREDEFINED_MACRO_IF(__OS2__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(OS2))
#elif defined(_OS2)
PREDEFINED_MACRO_IF(__OS2__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(_OS2))
#elif defined(__OS2__)
PREDEFINED_MACRO_IF(__OS2__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__OS2__))
#elif defined(__TOS_OS2__)
PREDEFINED_MACRO_IF(__OS2__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__TOS_OS2__))
#endif
#ifdef __palmos__
PREDEFINED_MACRO_IF(__palmos__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__palmos__))
#endif /* __palmos__ */
#ifdef EPLAN9
PREDEFINED_MACRO_IF(EPLAN9, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(EPLAN9))
#endif /* EPLAN9 */
#ifdef __QNX__
PREDEFINED_MACRO_IF(__QNX__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__QNX__))
#endif /* __QNX__ */
#ifdef __QNXNTO__
PREDEFINED_MACRO_IF(__QNXNTO__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__QNXNTO__))
#endif /* __QNXNTO__ */
#ifdef sinux
PREDEFINED_MACRO_IF(sinux, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(sinux))
#endif /* sinux */
#ifdef sun
PREDEFINED_MACRO_IF(__sun, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(sun))
#elif defined(__sun)
PREDEFINED_MACRO_IF(__sun, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__sun))
#endif
#ifdef __VOS__
PREDEFINED_MACRO_IF(__VOS__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__VOS__))
#endif /* __VOS__ */
#if defined(__sysv__) || defined(__SVR4) || \
    defined(__svr4__) || defined(_SYSTYPE_SVR4)
PREDEFINED_MACRO_IF(__sysv__, HAS(EXT_SYSTEM_MACROS), "1")
PREDEFINED_MACRO_IF(__svr4__, HAS(EXT_SYSTEM_MACROS), "1")
#endif
#ifdef __SYLLABLE__
PREDEFINED_MACRO_IF(__SYLLABLE__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__SYLLABLE__))
#endif /* __SYLLABLE__ */
#ifdef __SYMBIAN32__
PREDEFINED_MACRO_IF(__SYMBIAN32__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__SYMBIAN32__))
#endif /* __SYMBIAN32__ */
#ifdef __osf__
PREDEFINED_MACRO_IF(__osf__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__osf__))
#elif defined(__osf)
PREDEFINED_MACRO_IF(__osf__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__osf))
#endif
#ifdef __ultrix__
PREDEFINED_MACRO_IF(__ultrix__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__ultrix__))
#elif defined(__ultrix)
PREDEFINED_MACRO_IF(__ultrix__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__ultrix))
#elif defined(ultrix)
PREDEFINED_MACRO_IF(__ultrix__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(ultrix))
#elif (defined(__unix__) || defined(__unix) || defined(unix)) && \
(defined(__vax__) || defined(__vax) || defined(vax))
PREDEFINED_MACRO_IF(__ultrix__, HAS(EXT_SYSTEM_MACROS), "1")
#endif
#ifdef _UNICOS
PREDEFINED_MACRO_IF(_UNICOS, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(_UNICOS))
#endif /* _UNICOS */
#ifdef __crayx1
PREDEFINED_MACRO_IF(__crayx1, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__crayx1))
#elif defined(_CRAY)
PREDEFINED_MACRO_IF(__crayx1, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(_CRAY))
#endif
#if defined(__unix__)
PREDEFINED_MACRO_IF(__unix__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__unix__))
#elif defined(__unix)
PREDEFINED_MACRO_IF(__unix__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__unix))
#elif defined(unix)
PREDEFINED_MACRO_IF(__unix__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(unix))
#elif defined(__ANDROID__) || defined(__ANDROID) ||               \
      defined(__android__) || defined(__android) ||               \
      defined(__linux__) || defined(__linux) || defined(linux) || \
      defined(__MACOS__) || defined(__MACOSX__) || defined(__POSIX__)
PREDEFINED_MACRO_IF(__unix__, HAS(EXT_SYSTEM_MACROS), "1")
#endif
#ifdef __VMS
PREDEFINED_MACRO_IF(__VMS, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__VMS))
#elif defined(VMS)
PREDEFINED_MACRO_IF(__VMS, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(VMS))
#endif
#ifdef __VMS_VER
PREDEFINED_MACRO_IF(__VMS_VER, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__VMS_VER))
#endif /* __VMS_VER */
#ifdef __vxworks
PREDEFINED_MACRO_IF(__vxworks, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__vxworks))
#elif defined(__VXWORKS__)
PREDEFINED_MACRO_IF(__vxworks, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__VXWORKS__))
#endif
#ifndef TPP_PLATFORM_NOT_WINDOWS
#ifdef __WINDOWS__
#define TPP_PLATFORM_WINDOWS
PREDEFINED_MACRO_IF(__WINDOWS__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__WINDOWS__))
#elif defined(_WIN16) || defined(WIN16) || \
      defined(_WIN32) || defined(WIN32) || \
      defined(_WIN64) || defined(WIN64) || \
      defined(__WIN32__) || defined(__TOS_WIN__)
#define TPP_PLATFORM_WINDOWS
PREDEFINED_MACRO_IF(__WINDOWS__, HAS(EXT_SYSTEM_MACROS), "1")
#elif defined(_WIN32_WCE) || defined(WIN32_WCE)
PREDEFINED_MACRO_IF(__WINDOWS__, HAS(EXT_SYSTEM_MACROS), "1")
#endif
#ifdef _WIN32
PREDEFINED_MACRO_IF(_WIN32, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(_WIN32))
#elif defined(WIN32)
PREDEFINED_MACRO_IF(_WIN32, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(WIN32))
#elif defined(__WIN32__)
PREDEFINED_MACRO_IF(_WIN32, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__WIN32__))
#elif defined(TPP_PLATFORM_WINDOWS) && __SIZEOF_POINTER__ >= 4
PREDEFINED_MACRO_IF(_WIN32, HAS(EXT_SYSTEM_MACROS), "1")
#endif
#ifdef _WIN64
PREDEFINED_MACRO_IF(_WIN64, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(_WIN64))
#elif defined(WIN64)
PREDEFINED_MACRO_IF(_WIN64, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(WIN64))
#elif defined(TPP_PLATFORM_WINDOWS) && __SIZEOF_POINTER__ == 8
PREDEFINED_MACRO_IF(_WIN64, HAS(EXT_SYSTEM_MACROS), "1")
#endif
#ifdef _WIN16
PREDEFINED_MACRO_IF(_WIN16, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(_WIN16))
#elif defined(WIN16)
PREDEFINED_MACRO_IF(_WIN16, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(WIN16))
#elif defined(TPP_PLATFORM_WINDOWS) && __SIZEOF_POINTER__ == 2
PREDEFINED_MACRO_IF(_WIN16, HAS(EXT_SYSTEM_MACROS), "1")
#endif
#ifdef _WIN32_WCE
PREDEFINED_MACRO_IF(_WIN32_WCE, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(_WIN32_WCE))
#elif defined(WIN32_WCE)
PREDEFINED_MACRO_IF(_WIN32_WCE, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(WIN32_WCE))
#endif
#ifdef TPP_PLATFORM_WINDOWS
#undef TPP_PLATFORM_WINDOWS
#endif /* TPP_PLATFORM_WINDOWS */
#endif /* !TPP_PLATFORM_NOT_WINDOWS */
#ifdef __MVS__
PREDEFINED_MACRO_IF(__MVS__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__MVS__))
#ifdef __HOS_MVS__
PREDEFINED_MACRO_IF(__HOS_MVS__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__HOS_MVS__))
#else
PREDEFINED_MACRO_IF(__HOS_MVS__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__MVS__))
#endif
#elif defined(__HOS_MVS__)
PREDEFINED_MACRO_IF(__MVS__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__HOS_MVS__))
PREDEFINED_MACRO_IF(__HOS_MVS__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__HOS_MVS__))
#endif
#ifdef __TOS_MVS__
PREDEFINED_MACRO_IF(__TOS_MVS__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__TOS_MVS__))
#endif /* __TOS_MVS__ */
#ifdef __KOS__ /* ~smirks~ */
PREDEFINED_MACRO_IF(__KOS__, HAS(EXT_SYSTEM_MACROS), TPP_PP_STR(__KOS__))
#endif /* __KOS__ */


/* Utility predefined macros. */
#ifndef TPP_UTILITY_MACROS_DEFINED
#define TPP_UTILITY_MACROS_DEFINED
#ifndef TPP_MSCV_OR_GCC
#ifdef _MSC_VER
#define TPP_MSCV_OR_GCC(msvc, gcc) msvc
#else /* _MSC_VER */
#define TPP_MSCV_OR_GCC(msvc, gcc) gcc
#endif /* !_MSC_VER */
#endif /* !TPP_MSCV_OR_GCC */
#ifndef __INT8_TYPE__
#define __INT8_TYPE__ TPP_MSCV_OR_GCC(__int8, signed char)
#endif /* !__INT8_TYPE__ */
#ifndef __UINT8_TYPE__
#define __UINT8_TYPE__ unsigned TPP_MSCV_OR_GCC(__int8, char)
#endif /* !__UINT8_TYPE__ */
#ifndef __INT16_TYPE__
#define __INT16_TYPE__ TPP_MSCV_OR_GCC(__int16, short)
#endif /* !__INT16_TYPE__ */
#ifndef __UINT16_TYPE__
#define __UINT16_TYPE__ unsigned TPP_MSCV_OR_GCC(__int16, short)
#endif /* !__UINT16_TYPE__ */
#ifndef __INT32_TYPE__
#define __INT32_TYPE__ TPP_MSCV_OR_GCC(__int32, int)
#endif /* !__INT32_TYPE__ */
#ifndef __UINT32_TYPE__
#define __UINT32_TYPE__ unsigned TPP_MSCV_OR_GCC(__int32, int)
#endif /* !__UINT32_TYPE__ */
#ifndef __INT64_TYPE__
#define __INT64_TYPE__ TPP_MSCV_OR_GCC(__int64, long long)
#endif /* !__INT64_TYPE__ */
#ifndef __UINT64_TYPE__
#define __UINT64_TYPE__ unsigned TPP_MSCV_OR_GCC(__int64, long long)
#endif /* !__UINT64_TYPE__ */
#define TPP_MUL8_1 8
#define TPP_MUL8_2 16
#define TPP_MUL8_4 32
#define TPP_MUL8_8 64
#define TPP_MUL8_16 128
#define TPP_MUL8(x) TPP_PRIVATE_PP_CAT2(TPP_MUL8_, x)
#define TPP_INTTYPE_1 __INT8_TYPE__
#define TPP_INTTYPE_2 __INT16_TYPE__
#define TPP_INTTYPE_4 __INT32_TYPE__
#define TPP_INTTYPE_8 __INT64_TYPE__
#define TPP_UINTTYPE_1 __UINT8_TYPE__
#define TPP_UINTTYPE_2 __UINT16_TYPE__
#define TPP_UINTTYPE_4 __UINT32_TYPE__
#define TPP_UINTTYPE_8 __UINT64_TYPE__
#define TPP_INTTYPE(n) TPP_PRIVATE_PP_CAT2(TPP_INTTYPE_, n)
#define TPP_UINTTYPE(n) TPP_PRIVATE_PP_CAT2(TPP_UINTTYPE_, n)
#ifndef __SIZEOF_INT__
#define __SIZEOF_INT__ 4
#endif /* !__SIZEOF_INT__ */
#ifndef __SIZEOF_LONG__
#if defined(_WIN16) || defined(WIN16) || \
    defined(_WIN32) || defined(WIN32) || \
    defined(_WIN64) || defined(WIN64)
#define __SIZEOF_LONG__ 4
#else
#define __SIZEOF_LONG__ __SIZEOF_POINTER__
#endif
#endif
#ifndef __SIZEOF_LONG_LONG__
#define __SIZEOF_LONG_LONG__ 8
#endif /* __SIZEOF_LONG_LONG__ */
#ifndef __SIZEOF_SHORT__
#define __SIZEOF_SHORT__ 2
#endif /* __SIZEOF_SHORT__ */
#ifndef __SIZEOF_FLOAT__
#define __SIZEOF_FLOAT__ 4
#endif /* __SIZEOF_FLOAT__ */
#ifndef __SIZEOF_DOUBLE__
#define __SIZEOF_DOUBLE__ 8
#endif /* __SIZEOF_DOUBLE__ */
#ifndef __SIZEOF_LONG_DOUBLE__
#ifdef _MSC_VER
#define __SIZEOF_LONG_DOUBLE__ 8
#elif defined(__C67__) || defined(__i386__) || \
defined(__i386) || defined(i386)
#define __SIZEOF_LONG_DOUBLE__ 12
#elif defined(__X86_64__)
#define __SIZEOF_LONG_DOUBLE__ 16
#else
#define __SIZEOF_LONG_DOUBLE__ 8
#endif
#endif /* !__SIZEOF_LONG_DOUBLE__ */
#ifndef __SIZEOF_SIZE_T__
#define __SIZEOF_SIZE_T__ __SIZEOF_POINTER__
#endif /* !__SIZEOF_SIZE_T__ */
#ifndef __SIZEOF_WCHAR_T__
#if defined(_WIN16) || defined(WIN16) || \
    defined(_WIN32) || defined(WIN32) || \
    defined(_WIN64) || defined(WIN64)
#define __SIZEOF_WCHAR_T__ 2
#else
#define __SIZEOF_WCHAR_T__ 4
#endif
#endif /* !__SIZEOF_WCHAR_T__ */
#ifndef __SIZEOF_WINT_T__
#define __SIZEOF_WINT_T__ __SIZEOF_INT__
#endif /* !__SIZEOF_WINT_T__ */
#ifndef __SIZEOF_PTRDIFF_T__
#define __SIZEOF_PTRDIFF_T__ __SIZEOF_POINTER__
#endif /* !__SIZEOF_PTRDIFF_T__ */
#ifndef __SCHAR_WIDTH__
#define __SCHAR_WIDTH__ 8
#endif /* !__SCHAR_WIDTH__ */
#ifndef __SHRT_WIDTH__
#define __SHRT_WIDTH__ TPP_MUL8(__SIZEOF_SHORT__)
#endif /* !__SHRT_WIDTH__ */
#ifndef __INT_WIDTH__
#define __INT_WIDTH__ TPP_MUL8(__SIZEOF_INT__)
#endif /* !__INT_WIDTH__ */
#ifndef __LONG_WIDTH__
#define __LONG_WIDTH__ TPP_MUL8(__SIZEOF_LONG__)
#endif /* !__LONG_WIDTH__ */
#ifndef __LONG_LONG_WIDTH__
#define __LONG_LONG_WIDTH__ TPP_MUL8(__SIZEOF_LONG_LONG__)
#endif /* !__LONG_LONG_WIDTH__ */
#ifndef __PTRDIFF_WIDTH__
#define __PTRDIFF_WIDTH__ TPP_MUL8(__SIZEOF_PTRDIFF_T__)
#endif /* !__PTRDIFF_WIDTH__ */
#ifndef __SIG_ATOMIC_WIDTH__
#define __SIG_ATOMIC_WIDTH__ TPP_MUL8(__SIZEOF_INT__)
#endif /* !__SIG_ATOMIC_WIDTH__ */
#ifndef __SIZE_WIDTH__
#define __SIZE_WIDTH__ TPP_MUL8(__SIZEOF_SIZE_T__)
#endif /* !__SIZE_WIDTH__ */
#ifndef __WCHAR_WIDTH__
#define __WCHAR_WIDTH__ TPP_MUL8(__SIZEOF_WCHAR_T__)
#endif /* !__WCHAR_WIDTH__ */
#ifndef __WINT_WIDTH__
#define __WINT_WIDTH__ TPP_MUL8(__SIZEOF_WINT_T__)
#endif /* !__WINT_WIDTH__ */
#ifndef __INT_LEAST8_WIDTH__
#define __INT_LEAST8_WIDTH__ 8
#endif /* !__INT_LEAST8_WIDTH__ */
#ifndef __INT_LEAST16_WIDTH__
#define __INT_LEAST16_WIDTH__ 16
#endif /* !__INT_LEAST16_WIDTH__ */
#ifndef __INT_LEAST32_WIDTH__
#define __INT_LEAST32_WIDTH__ 32
#endif /* !__INT_LEAST32_WIDTH__ */
#ifndef __INT_LEAST64_WIDTH__
#define __INT_LEAST64_WIDTH__ 64
#endif /* !__INT_LEAST64_WIDTH__ */
#ifndef __INT_FAST8_WIDTH__
#define __INT_FAST8_WIDTH__ 8
#endif /* !__INT_FAST8_WIDTH__ */
#ifndef __INT_FAST16_WIDTH__
#define __INT_FAST16_WIDTH__ 16
#endif /* !__INT_FAST16_WIDTH__ */
#ifndef __INT_FAST32_WIDTH__
#define __INT_FAST32_WIDTH__ 32
#endif /* !__INT_FAST32_WIDTH__ */
#ifndef __INT_FAST64_WIDTH__
#define __INT_FAST64_WIDTH__ 64
#endif /* !__INT_FAST64_WIDTH__ */
#ifndef __INTPTR_WIDTH__
#define __INTPTR_WIDTH__ TPP_MUL8(__SIZEOF_POINTER__)
#endif /* !__INTPTR_WIDTH__ */
#ifndef __INTMAX_WIDTH__
#define __INTMAX_WIDTH__ 64
#endif /* !__INTMAX_WIDTH__ */

#ifndef __SIZE_TYPE__
#define __SIZE_TYPE__ TPP_UINTTYPE(__SIZEOF_POINTER__)
#endif /* !__SIZE_TYPE__ */
#ifndef __PTRDIFF_TYPE__
#define __PTRDIFF_TYPE__ TPP_INTTYPE(__SIZEOF_POINTER__)
#endif /* !__PTRDIFF_TYPE__ */
#ifndef __WCHAR_TYPE__
#define __WCHAR_TYPE__ wchar_t
#endif /* !__WCHAR_TYPE__ */
#ifndef __WINT_TYPE__
#define __WINT_TYPE__ int
#endif /* !__WINT_TYPE__ */
#ifndef __INTMAX_TYPE__
#define __INTMAX_TYPE__ __INT64_TYPE__
#endif /* !__INTMAX_TYPE__ */
#ifndef __UINTMAX_TYPE__
#define __UINTMAX_TYPE__ __UINT64_TYPE__
#endif /* !__UINTMAX_TYPE__ */
#ifndef __SIG_ATOMIC_TYPE__
#define __SIG_ATOMIC_TYPE__ int
#endif /* !__SIG_ATOMIC_TYPE__ */
#ifndef __INT_LEAST8_TYPE__
#define __INT_LEAST8_TYPE__ __INT8_TYPE__
#endif /* !__INT_LEAST8_TYPE__ */
#ifndef __INT_LEAST16_TYPE__
#define __INT_LEAST16_TYPE__ __INT16_TYPE__
#endif /* !__INT_LEAST16_TYPE__ */
#ifndef __INT_LEAST32_TYPE__
#define __INT_LEAST32_TYPE__ __INT32_TYPE__
#endif /* !__INT_LEAST32_TYPE__ */
#ifndef __INT_LEAST64_TYPE__
#define __INT_LEAST64_TYPE__ __INT64_TYPE__
#endif /* !__INT_LEAST64_TYPE__ */
#ifndef __UINT_LEAST8_TYPE__
#define __UINT_LEAST8_TYPE__ __UINT8_TYPE__
#endif /* !__UINT_LEAST8_TYPE__ */
#ifndef __UINT_LEAST16_TYPE__
#define __UINT_LEAST16_TYPE__ __UINT16_TYPE__
#endif /* !__UINT_LEAST16_TYPE__ */
#ifndef __UINT_LEAST32_TYPE__
#define __UINT_LEAST32_TYPE__ __UINT32_TYPE__
#endif /* !__UINT_LEAST32_TYPE__ */
#ifndef __UINT_LEAST64_TYPE__
#define __UINT_LEAST64_TYPE__ __UINT64_TYPE__
#endif /* !__UINT_LEAST64_TYPE__ */
#ifndef __INT_FAST8_TYPE__
#define __INT_FAST8_TYPE__ __INT8_TYPE__
#endif /* !__INT_FAST8_TYPE__ */
#ifndef __INT_FAST16_TYPE__
#define __INT_FAST16_TYPE__ __INT16_TYPE__
#endif /* !__INT_FAST16_TYPE__ */
#ifndef __INT_FAST32_TYPE__
#define __INT_FAST32_TYPE__ __INT32_TYPE__
#endif /* !__INT_FAST32_TYPE__ */
#ifndef __INT_FAST64_TYPE__
#define __INT_FAST64_TYPE__ __INT64_TYPE__
#endif /* !__INT_FAST64_TYPE__ */
#ifndef __UINT_FAST8_TYPE__
#define __UINT_FAST8_TYPE__ __UINT8_TYPE__
#endif /* !__UINT_FAST8_TYPE__ */
#ifndef __UINT_FAST16_TYPE__
#define __UINT_FAST16_TYPE__ __UINT16_TYPE__
#endif /* !__UINT_FAST16_TYPE__ */
#ifndef __UINT_FAST32_TYPE__
#define __UINT_FAST32_TYPE__ __UINT32_TYPE__
#endif /* !__UINT_FAST32_TYPE__ */
#ifndef __UINT_FAST64_TYPE__
#define __UINT_FAST64_TYPE__ __UINT64_TYPE__
#endif /* !__UINT_FAST64_TYPE__ */
#ifndef __INTPTR_TYPE__
#define __INTPTR_TYPE__ __PTRDIFF_TYPE__
#endif /* !__INTPTR_TYPE__ */
#ifndef __UINTPTR_TYPE__
#define __UINTPTR_TYPE__ __SIZE_TYPE__
#endif /* !__UINTPTR_TYPE__ */
#endif /* !TPP_UTILITY_MACROS_DEFINED */

#if (defined(__LP64__) || defined(_LP64)) || \
    (__SIZEOF_INT__ == 4 && __SIZEOF_LONG__ == 8 && __SIZEOF_POINTER__ == 8)
PREDEFINED_MACRO_IF(__LP64__, HAS(EXT_SYSTEM_MACROS), "1")
#endif

PREDEFINED_MACRO_IF(__BYTE_ORDER__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(TPP_BYTEORDER))
#ifdef __FLOAT_WORD_ORDER__
PREDEFINED_MACRO_IF(__FLOAT_WORD_ORDER__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__FLOAT_WORD_ORDER__))
#else /* __FLOAT_WORD_ORDER__ */
PREDEFINED_MACRO_IF(__FLOAT_WORD_ORDER__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(TPP_BYTEORDER))
#endif /* !__FLOAT_WORD_ORDER__ */
PREDEFINED_MACRO_IF(__ORDER_LITTLE_ENDIAN__, HAS(EXT_UTILITY_MACROS), "1234")
PREDEFINED_MACRO_IF(__ORDER_BIG_ENDIAN__, HAS(EXT_UTILITY_MACROS), "4321")
PREDEFINED_MACRO_IF(__ORDER_PDP_ENDIAN__, HAS(EXT_UTILITY_MACROS), "3412")

PREDEFINED_MACRO_IF(__SIZEOF_INT__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__SIZEOF_INT__))
PREDEFINED_MACRO_IF(__SIZEOF_LONG__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__SIZEOF_LONG__))
PREDEFINED_MACRO_IF(__SIZEOF_LONG_LONG__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__SIZEOF_LONG_LONG__))
PREDEFINED_MACRO_IF(__SIZEOF_SHORT__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__SIZEOF_SHORT__))
PREDEFINED_MACRO_IF(__SIZEOF_POINTER__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__SIZEOF_POINTER__))
PREDEFINED_MACRO_IF(__SIZEOF_FLOAT__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__SIZEOF_FLOAT__))
PREDEFINED_MACRO_IF(__SIZEOF_DOUBLE__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__SIZEOF_DOUBLE__))
PREDEFINED_MACRO_IF(__SIZEOF_LONG_DOUBLE__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__SIZEOF_LONG_DOUBLE__))
PREDEFINED_MACRO_IF(__SIZEOF_SIZE_T__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__SIZEOF_SIZE_T__))
PREDEFINED_MACRO_IF(__SIZEOF_WCHAR_T__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__SIZEOF_WCHAR_T__))
PREDEFINED_MACRO_IF(__SIZEOF_WINT_T__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__SIZEOF_WINT_T__))
PREDEFINED_MACRO_IF(__SIZEOF_PTRDIFF_T__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__SIZEOF_PTRDIFF_T__))

PREDEFINED_MACRO_IF(__SCHAR_WIDTH__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__SCHAR_WIDTH__))
PREDEFINED_MACRO_IF(__SHRT_WIDTH__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__SHRT_WIDTH__))
PREDEFINED_MACRO_IF(__INT_WIDTH__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__INT_WIDTH__))
PREDEFINED_MACRO_IF(__LONG_WIDTH__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__LONG_WIDTH__))
PREDEFINED_MACRO_IF(__LONG_LONG_WIDTH__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__LONG_LONG_WIDTH__))
PREDEFINED_MACRO_IF(__PTRDIFF_WIDTH__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__PTRDIFF_WIDTH__))
PREDEFINED_MACRO_IF(__SIG_ATOMIC_WIDTH__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__SIG_ATOMIC_WIDTH__))
PREDEFINED_MACRO_IF(__SIZE_WIDTH__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__SIZE_WIDTH__))
PREDEFINED_MACRO_IF(__WCHAR_WIDTH__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__WCHAR_WIDTH__))
PREDEFINED_MACRO_IF(__WINT_WIDTH__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__WINT_WIDTH__))
PREDEFINED_MACRO_IF(__INT_LEAST8_WIDTH__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__INT_LEAST8_WIDTH__))
PREDEFINED_MACRO_IF(__INT_LEAST16_WIDTH__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__INT_LEAST16_WIDTH__))
PREDEFINED_MACRO_IF(__INT_LEAST32_WIDTH__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__INT_LEAST32_WIDTH__))
PREDEFINED_MACRO_IF(__INT_LEAST64_WIDTH__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__INT_LEAST64_WIDTH__))
PREDEFINED_MACRO_IF(__INT_FAST8_WIDTH__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__INT_FAST8_WIDTH__))
PREDEFINED_MACRO_IF(__INT_FAST16_WIDTH__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__INT_FAST16_WIDTH__))
PREDEFINED_MACRO_IF(__INT_FAST32_WIDTH__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__INT_FAST32_WIDTH__))
PREDEFINED_MACRO_IF(__INT_FAST64_WIDTH__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__INT_FAST64_WIDTH__))
PREDEFINED_MACRO_IF(__INTPTR_WIDTH__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__INTPTR_WIDTH__))
PREDEFINED_MACRO_IF(__INTMAX_WIDTH__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__INTMAX_WIDTH__))

PREDEFINED_MACRO_IF(__SIZE_TYPE__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__SIZE_TYPE__))
PREDEFINED_MACRO_IF(__PTRDIFF_TYPE__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__PTRDIFF_TYPE__))
PREDEFINED_MACRO_IF(__WCHAR_TYPE__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__WCHAR_TYPE__))
PREDEFINED_MACRO_IF(__WINT_TYPE__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__WINT_TYPE__))
PREDEFINED_MACRO_IF(__INTMAX_TYPE__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__INTMAX_TYPE__))
PREDEFINED_MACRO_IF(__UINTMAX_TYPE__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__UINTMAX_TYPE__))
PREDEFINED_MACRO_IF(__SIG_ATOMIC_TYPE__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__SIG_ATOMIC_TYPE__))
PREDEFINED_MACRO_IF(__INT8_TYPE__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__INT8_TYPE__))
PREDEFINED_MACRO_IF(__INT16_TYPE__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__INT16_TYPE__))
PREDEFINED_MACRO_IF(__INT32_TYPE__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__INT32_TYPE__))
PREDEFINED_MACRO_IF(__INT64_TYPE__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__INT64_TYPE__))
PREDEFINED_MACRO_IF(__UINT8_TYPE__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__UINT8_TYPE__))
PREDEFINED_MACRO_IF(__UINT16_TYPE__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__UINT16_TYPE__))
PREDEFINED_MACRO_IF(__UINT32_TYPE__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__UINT32_TYPE__))
PREDEFINED_MACRO_IF(__UINT64_TYPE__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__UINT64_TYPE__))
PREDEFINED_MACRO_IF(__INT_LEAST8_TYPE__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__INT_LEAST8_TYPE__))
PREDEFINED_MACRO_IF(__INT_LEAST16_TYPE__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__INT_LEAST16_TYPE__))
PREDEFINED_MACRO_IF(__INT_LEAST32_TYPE__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__INT_LEAST32_TYPE__))
PREDEFINED_MACRO_IF(__INT_LEAST64_TYPE__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__INT_LEAST64_TYPE__))
PREDEFINED_MACRO_IF(__UINT_LEAST8_TYPE__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__UINT_LEAST8_TYPE__))
PREDEFINED_MACRO_IF(__UINT_LEAST16_TYPE__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__UINT_LEAST16_TYPE__))
PREDEFINED_MACRO_IF(__UINT_LEAST32_TYPE__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__UINT_LEAST32_TYPE__))
PREDEFINED_MACRO_IF(__UINT_LEAST64_TYPE__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__UINT_LEAST64_TYPE__))
PREDEFINED_MACRO_IF(__INT_FAST8_TYPE__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__INT_FAST8_TYPE__))
PREDEFINED_MACRO_IF(__INT_FAST16_TYPE__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__INT_FAST16_TYPE__))
PREDEFINED_MACRO_IF(__INT_FAST32_TYPE__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__INT_FAST32_TYPE__))
PREDEFINED_MACRO_IF(__INT_FAST64_TYPE__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__INT_FAST64_TYPE__))
PREDEFINED_MACRO_IF(__UINT_FAST8_TYPE__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__UINT_FAST8_TYPE__))
PREDEFINED_MACRO_IF(__UINT_FAST16_TYPE__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__UINT_FAST16_TYPE__))
PREDEFINED_MACRO_IF(__UINT_FAST32_TYPE__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__UINT_FAST32_TYPE__))
PREDEFINED_MACRO_IF(__UINT_FAST64_TYPE__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__UINT_FAST64_TYPE__))
PREDEFINED_MACRO_IF(__INTPTR_TYPE__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__INTPTR_TYPE__))
PREDEFINED_MACRO_IF(__UINTPTR_TYPE__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__UINTPTR_TYPE__))

#ifdef __CHAR_BIT__
PREDEFINED_MACRO_IF(__CHAR_BIT__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__CHAR_BIT__))
#elif defined(CHAR_BIT)
PREDEFINED_MACRO_IF(__CHAR_BIT__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(CHAR_BIT))
#else
PREDEFINED_MACRO_IF(__CHAR_BIT__, HAS(EXT_UTILITY_MACROS), "8")
#endif

PREDEFINED_MACRO_IF(__SCHAR_MAX__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(SCHAR_MAX))
PREDEFINED_MACRO_IF(__WCHAR_MAX__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(WCHAR_MAX))
PREDEFINED_MACRO_IF(__SHRT_MAX__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(SHRT_MAX))
PREDEFINED_MACRO_IF(__INT_MAX__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(INT_MAX))
PREDEFINED_MACRO_IF(__LONG_MAX__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(LONG_MAX))
#ifdef __LONG_LONG_MAX__
PREDEFINED_MACRO_IF(__LONG_LONG_MAX__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(__LONG_LONG_MAX__))
#elif defined(LONG_LONG_MAX)
PREDEFINED_MACRO_IF(__LONG_LONG_MAX__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(LONG_LONG_MAX))
#else
PREDEFINED_MACRO_IF(__LONG_LONG_MAX__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(LLONG_MAX))
#endif
PREDEFINED_MACRO_IF(__WINT_MAX__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(WINT_MAX))
PREDEFINED_MACRO_IF(__SIZE_MAX__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(SIZE_MAX))
PREDEFINED_MACRO_IF(__PTRDIFF_MAX__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(PTRDIFF_MAX))
PREDEFINED_MACRO_IF(__INTMAX_MAX__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(INTMAX_MAX))
PREDEFINED_MACRO_IF(__UINTMAX_MAX__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(UINTMAX_MAX))
PREDEFINED_MACRO_IF(__SIG_ATOMIC_MAX__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(SIG_ATOMIC_MAX))
PREDEFINED_MACRO_IF(__INT8_MAX__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(INT8_MAX))
PREDEFINED_MACRO_IF(__INT16_MAX__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(INT16_MAX))
PREDEFINED_MACRO_IF(__INT32_MAX__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(INT32_MAX))
PREDEFINED_MACRO_IF(__INT64_MAX__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(INT64_MAX))
PREDEFINED_MACRO_IF(__UINT8_MAX__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(UINT8_MAX))
PREDEFINED_MACRO_IF(__UINT16_MAX__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(UINT16_MAX))
PREDEFINED_MACRO_IF(__UINT32_MAX__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(UINT32_MAX))
PREDEFINED_MACRO_IF(__UINT64_MAX__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(UINT64_MAX))
PREDEFINED_MACRO_IF(__INT_LEAST8_MAX__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(INT_LEAST8_MAX))
PREDEFINED_MACRO_IF(__INT_LEAST16_MAX__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(INT_LEAST16_MAX))
PREDEFINED_MACRO_IF(__INT_LEAST32_MAX__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(INT_LEAST32_MAX))
PREDEFINED_MACRO_IF(__INT_LEAST64_MAX__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(INT_LEAST64_MAX))
PREDEFINED_MACRO_IF(__UINT_LEAST8_MAX__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(UINT_LEAST8_MAX))
PREDEFINED_MACRO_IF(__UINT_LEAST16_MAX__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(UINT_LEAST16_MAX))
PREDEFINED_MACRO_IF(__UINT_LEAST32_MAX__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(UINT_LEAST32_MAX))
PREDEFINED_MACRO_IF(__UINT_LEAST64_MAX__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(UINT_LEAST64_MAX))
PREDEFINED_MACRO_IF(__INT_FAST8_MAX__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(INT_FAST8_MAX))
PREDEFINED_MACRO_IF(__INT_FAST16_MAX__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(INT_FAST16_MAX))
PREDEFINED_MACRO_IF(__INT_FAST32_MAX__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(INT_FAST32_MAX))
PREDEFINED_MACRO_IF(__INT_FAST64_MAX__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(INT_FAST64_MAX))
PREDEFINED_MACRO_IF(__UINT_FAST8_MAX__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(UINT_FAST8_MAX))
PREDEFINED_MACRO_IF(__UINT_FAST16_MAX__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(UINT_FAST16_MAX))
PREDEFINED_MACRO_IF(__UINT_FAST32_MAX__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(UINT_FAST32_MAX))
PREDEFINED_MACRO_IF(__UINT_FAST64_MAX__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(UINT_FAST64_MAX))
PREDEFINED_MACRO_IF(__INTPTR_MAX__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(INTPTR_MAX))
PREDEFINED_MACRO_IF(__UINTPTR_MAX__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(UINTPTR_MAX))
PREDEFINED_MACRO_IF(__WCHAR_MIN__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(WCHAR_MIN))
PREDEFINED_MACRO_IF(__WINT_MIN__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(WINT_MIN))
PREDEFINED_MACRO_IF(__SIG_ATOMIC_MIN__, HAS(EXT_UTILITY_MACROS), TPP_PP_STR(SIG_ATOMIC_MIN))

DEF_M_IF(__INT8_C, HAS(EXT_UTILITY_MACROS))
DEF_M_IF(__INT16_C, HAS(EXT_UTILITY_MACROS))
DEF_M_IF(__INT32_C, HAS(EXT_UTILITY_MACROS))
DEF_M_IF(__INT64_C, HAS(EXT_UTILITY_MACROS))
DEF_M_IF(__UINT8_C, HAS(EXT_UTILITY_MACROS))
DEF_M_IF(__UINT16_C, HAS(EXT_UTILITY_MACROS))
DEF_M_IF(__UINT32_C, HAS(EXT_UTILITY_MACROS))
DEF_M_IF(__UINT64_C, HAS(EXT_UTILITY_MACROS))
DEF_M_IF(__INTMAX_C, HAS(EXT_UTILITY_MACROS))
DEF_M_IF(__UINTMAX_C, HAS(EXT_UTILITY_MACROS))

PREDEFINED_MACRO_IF(__CHAR_UNSIGNED__,
                    HAS(EXT_UTILITY_MACROS) && (TPPLexer_Current->l_flags & TPPLEXER_FLAG_CHAR_UNSIGNED), "1")
PREDEFINED_MACRO_IF(__WCHAR_UNSIGNED__, HAS(EXT_UTILITY_MACROS), "1") /* xxx: flag? */

#undef TPP_PP_CAT3
#undef TPP_PP_CAT2
#undef TPP_PRIVATE_PP_CAT3
#undef TPP_PRIVATE_PP_CAT2

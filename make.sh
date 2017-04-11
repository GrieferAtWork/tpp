#!/bin/bash

CFLAGS=""

# I told you this is a ~tiny~ preprocessor.
# >> No dependencies other than libc & only 2 source files.
gcc $CFLAGS -o tpp src/frontend.c src/tpp.c

# NOTE: TPP Also recognizes a few compiler options.
#       All options begin with 'TPP_CONFIG_*' and must either
#       be predefined as '0' or '1' to override their behavior.
#       When not defined at all, they will default to the values
#       specified below.
#
#    -  TPP_CONFIG_DEBUG:     DEFAULT: 1
#                             Enable debug mode and internaly assertions.
#                             This option is enabled by default and helps
#                             detect internal problems with TPP.
#
#    -  TPP_CONFIG_ONELEXER:  DEFAULT: 1
#                             Configure TPP to only use one lexer globally.
#                             When disabled, a global pointer 'TPPLexer_Current'
#                             can be overwritten to set the currently used
#                             lexer, allowing you to set up your own synchronization
#                             when attempting to use multiple lexers between
#                             different threads.
#                             When disabled, only one lexer 'TPPLexer_Global'
#                             is made available and used, and 'TPPLexer_Current' is
#                             defined as a macro simply referring to 'TPPLexer_Global',
#                             as well as lacking the ability of being overwritable.
#                             In both cases, the used TPP lexer must be initialized
#                             before being used first, as well as be finalized after
#                             you're doing, which can easily be achieved using
#                             'TPP_INITIALIZE()' and 'TPP_FINALIZE()', which
#                             will always perform the necessary steps to setup
#                             and initialize the/a-new global lexer.
#
#    -  TPP_CONFIG_EXPORT:    DEFAULT: 0
#                             May be used to have TPP export its public functions
#                             from a shared library, thus allowing you to create
#                             and link it as a .dll or .so library.
#
#    -  TPP_CONFIG_HOOKS:     DEFAULT: 0
#                             Confure TPP to call extern function hooks for special
#                             functionality that require a higher-level implementation.
#                             Among other things, these hooks can be used to deal
#                             with compiler-specific pragmas, as well as more
#                             outlandish functionality such as "#ident" directives.
#                             For a list of required hooks, see 'tpp.c',
#                             section >> /* HOOK fallbacks & documentation. */ <<
#                             Not intended for use in a stand-alone preprocessor.

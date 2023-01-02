/* Copyright (c) 2017-2023 Griefer@Work                                       *
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
 *    Portions Copyright (c) 2017-2023 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#include "include/test.h"

/* TPP Allows for use of strings in #if directives (as well as `__TPP_EVAL') */
TEST_EXPANDS(__TPP_EVAL('F'), "70")
TEST_EXPANDS(__TPP_EVAL("FOO"[0]), "70")
TEST_EXPANDS(__TPP_EVAL("FOO"[0:]), "\"FOO\"")
TEST_EXPANDS(__TPP_EVAL("FOO"[1:]), "\"OO\"")
TEST_EXPANDS(__TPP_EVAL("FOO"[0:1]), "\"F\"")
TEST_EXPANDS(__TPP_EVAL("FOO"[0:2]), "\"FO\"")
TEST_EXPANDS(__TPP_EVAL("FOO"[0:-1]), "\"FO\"")
TEST_EXPANDS(__TPP_EVAL("FOO"[:-1]), "\"FO\"")
TEST_EXPANDS(__TPP_EVAL("FOO"[1:-1]), "\"O\"")
TEST_EXPANDS(__TPP_EVAL("FOO" == "BAR"), "0")
TEST_EXPANDS(__TPP_EVAL("FOO" != "BAR"), "1")
TEST_EXPANDS(__TPP_EVAL("FOO" == "FOO"), "1")
TEST_EXPANDS(__TPP_EVAL("FOO" == "foo"), "0")

/* TPP Also allows for use of GCC-style __builtin_* functions
 * in #if directives. (and therefor also in `__TPP_EVAL') */
TEST_EXPANDS(__TPP_EVAL(__builtin_strcmp("FOO", "foo") < 0), "1")
TEST_EXPANDS(__TPP_EVAL(__builtin_strcmp("FOO", "foo") > 0), "0")
TEST_EXPANDS(__TPP_EVAL(__builtin_strcmp("foo", "FOO") < 0), "0")
TEST_EXPANDS(__TPP_EVAL(__builtin_strcmp("foo", "FOO") > 0), "1")
TEST_EXPANDS(__TPP_EVAL(__builtin_strcasecmp("FOO", "foo")), "0")

TEST_EXPANDS(__TPP_EVAL(__builtin_ffs(0x123)), "1")
TEST_EXPANDS(__TPP_EVAL(__builtin_ffs(0x100)), "9")

/* Multi-char character literals. */
TEST_EXPANDS(__TPP_EVAL('a'), "97")
TEST_EXPANDS(__TPP_EVAL('ab'), "25185")
TEST_EXPANDS(__TPP_EVAL('abc'), "6513249")


#define CAT2(a, b) a##b
#define CAT(a, b) CAT2(a, b)
#define ISLESS_0 more than
#define ISLESS_1 less than
#define SELECT(n) CAT(ISLESS_, __TPP_EVAL(n < 10))
TEST_EXPANDS(SELECT(7), "less than")
TEST_EXPANDS(SELECT(10), "more than")

TEST_EXPANDS(__TPP_STR_PACK(0x48, 0x65, 0x6c, 0x6c, 0x6f), "\"Hello\"")

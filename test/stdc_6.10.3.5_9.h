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

// ISO/IEC 9899:201x - 6.10.3.5 - 9

#define debug(...)      fprintf(stderr, __VA_ARGS__)
#define debug2(...)     fprintf(stderr, ##__VA_ARGS__)
#define showlist(...)   puts(#__VA_ARGS__)
#define report(test, ...) ((test)?puts(#test):\
            printf(__VA_ARGS__))
TEST_EXPANDS(debug();, "fprintf(stderr, );")
TEST_EXPANDS(debug2();, "fprintf(stderr);")
TEST_EXPANDS(debug("Flag");, "fprintf(stderr, \"Flag\");")
TEST_EXPANDS(debug2("Flag");, "fprintf(stderr,\"Flag\");")
TEST_EXPANDS(debug("X = %d\n", x);, "fprintf(stderr, \"X = %d\\n\", x);")
TEST_EXPANDS(showlist(The first, second, and third items.);, "puts(\"The first, second, and third items.\");")
TEST_EXPANDS(report(x>y, "x is %d but y is %d", x, y);, "((x>y)?puts(\"x>y\"):            printf(\"x is %d but y is %d\", x, y));")


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

/* ISO/IEC 9899:201x - 6.10.3.5 - 6 */


#define str(s)      # s
#define xstr(s)     str(s)
#define debug(s, t) printf("x" # s "= %d, x" # t "= %s", \
x##s,x##t)
#define INCFILE(n)  vers ## n
#define glue(a, b)  a ## b
#define xglue(a, b) glue(a, b)
#define HIGHLOW     "hello"
#define LOW         LOW ", world"
TEST_EXPANDS(debug(1, 2);, "printf(\"x\" \"1\" \"= %d, x\" \"2\" \"= %s\", \\\nx1,x2);")
TEST_EXPANDS(fputs(str(strncmp("abc\0d", "abc", '\4') // this goes away
== 0) str(: @\n), s);,
	"fputs(\"strncmp(\\\"abc\\\\0d\\\", \\\"abc\\\", "
	"\\\'\\\\4\\\') // this goes away\\n== 0\" \": @\\\\n\", s);")

#pragma warning(push)
#pragma warning(disable:15) /* File not found */
TEST_EXPANDS(xstr(INCFILE(2).h), "\"vers2.h\"")
#include xstr(INCFILE(2).h)
#pragma warning(pop)

TEST_EXPANDS(glue(HIGH, LOW);, "\"hello\";")
TEST_EXPANDS(xglue(HIGH, LOW), "\"hello\" \", world\"")



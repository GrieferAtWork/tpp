/* Copyright (c) 2018-2021 Griefer@Work                                       *
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
#include "include/test.h"

// ISO/IEC 9899:201x - 6.10.3.5 - 5

#define x      3
#define f(a)   f(x * (a))
#undef x
#define x      2
#define g      f
#define z      z[0]
#define h      g(~
#define m(a)   a(w)
#define w      0,1
#define t(a)   a
#define p()    int
#define q(x)   x
#define r(x,y) x ## y
#define str(x) # x

/* z gets expanded multiple times (see "pp_fixme.h") */
TEST_EXPANDS(f(y+1) + f(f(z)) % t(t(g)(0) + t)(1);,
	"f(2 * (y+1)) + f(2 * (f(2 * (z[0][0][0])))) % f(2 * (2 * (0))) + t(1);")

/* EOF in macro argument list (see "pp_unsupported.h") */ 
//TEST_EXPANDS(g(x+(3,4)-w) | h 5) & m, "f(2 * (2+(3,4)-0,1)) | f(2 * (~)) 5")

TEST_EXPANDS((f)^m(m);, "(f)^m(0,1);")

TEST_EXPANDS((p() i[q()] = { q(1), r(2,3), r(4,), r(,5), r(,) };),
	"(int i[] = { 1, 23, 4, 5,  };)")
TEST_EXPANDS((char c[2][6] = { str(hello), str() };),
	"(char c[2][6] = { \"hello\", \"\" };)")


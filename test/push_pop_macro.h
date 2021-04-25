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

// #pragma push_macro

TEST_EXPANDS(int *a = new int();, "int *a = new int();")
#define new __debug_new
TEST_EXPANDS(int *b = new int();, "int *b = __debug_new int();")
#pragma push_macro("new")
#undef new
#define new __alt_default_new
TEST_EXPANDS(int *c = new int();, "int *c = __alt_default_new int();")
#pragma pop_macro("new")
TEST_EXPANDS(int *d = new int();, "int *d = __debug_new int();")
TEST_EXPANDS(int *e = new int();, "int *e = __debug_new int();")
#undef new
TEST_EXPANDS(int *f = new int();, "int *f = new int();")




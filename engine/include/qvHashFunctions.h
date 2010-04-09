/**************************************************************************************************

//This code is part of QuanticVortex for latest information, see http://www.quanticvortex.org
//
//Copyright (c) 2009-2010 QuanticMinds Software Ltda.
//
//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this software and associated documentation files (the "Software"), to deal
//in the Software without restriction, including without limitation the rights
//to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions:
//
//The above copyright notice and this permission notice shall be included in
//all copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//THE SOFTWARE.

**************************************************************************************************/


#ifndef __HASH_FUNCTIONS_H_
#define __HASH_FUNCTIONS_H_

#include "qvCompileConfig.h"
#include "qvTypes.h"

namespace qv
{    
    //-----------------------------------------------------------------------------
    // MurmurHash2, by Austin Appleby  from http://sites.google.com/site/murmurhash/

    // Note - This code makes a few assumptions about how your machine behaves -

    // 1. We can read a 4-byte value from any address without crashing
    // 2. sizeof(int) == 4

    // And it has a few limitations -

    // 1. It will not work incrementally.
    // 2. It will not produce the same results on little-endian and big-endian
    //    machines.

    // All code is released to the public domain. For business purposes, Murmurhash is
    // under the MIT license.
    _QUANTICVORTEX_API_ u32 QUANTICVORTEX_CALLCONV createMurmurHash2 ( const void * key, u32 len, u32 seed = 0);
}

#endif


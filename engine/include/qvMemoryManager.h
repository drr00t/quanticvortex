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


#ifndef _MEMORY_MANAGER_H_
#define _MEMORY_MANAGER_H_

#include "qvPrerequisites.h"

#include <limits>
#include <new>

#ifdef max
	#undef max
#endif

#ifdef min
	#undef min
#endif


namespace qv
{
    class MemoryManager
    {
    public:
        template <class T>
        static T* allocate(size_t size, const c8* filename, s32 line, const c8* function)
        {
            T* ptr = static_cast<T*>(operator new (size));
            return ptr;
        }

        static void deallocate(void* pointer)
        {
            operator delete (pointer);
        }

        static size_t getMaxAllocationSize()
        {
            return std::numeric_limits<size_t>::max();
        }
    };
}

#endif


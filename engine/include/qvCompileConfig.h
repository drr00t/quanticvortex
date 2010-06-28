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


#ifndef __COMPILE_CONFIG_H_
#define __COMPILE_CONFIG_H_

#include "qvConfigProfile.h"

//! QuanticVortex SDK Version
#define QUANTICVORTEX_VERSION_MAJOR 0
#define QUANTICVORTEX_VERSION_MINOR 2
#define QUANTICVORTEX_VERSION_REVISION 0

#define QUANTICVORTEX_PLATAFORM_WINDOWS 1

// This flag will be defined only in Mercurial, the official release code will have
// it undefined
//#define QUANTICVORTEX_VERSION_MERCURIAL
#define QUANTICVORTEX_SDK_VERSION "0.2"

//! WIN32 for Windows32
//! WIN64 for Windows64
// The windows platform 
#if defined(_WIN32) || defined(_WIN64) || defined(WIN32) || defined(WIN64)
#	define QUANTICVORTEX_PLATAFORM QUANTICVORTEX_PLATAFORM_WINDOWS
//#	define _QUANTICVORTEX_API_
#endif

//#ifdef _QUANTICVORTEX_API_

// To build as a static library, you must define _QUANTICVORTEX_STATIC_LIB_

#	ifndef _QUANTICVORTEX_STATIC_LIB_
#		ifdef _QUANTICVORTEX_EXPORTS
#			define _QUANTICVORTEX_API_ __declspec(dllexport)
#		else
#			define _QUANTICVORTEX_API_ __declspec(dllimport)
#		endif // _QUANTICVORTEX_EXPORTS
#	else
#		define _QUANTICVORTEX_API_
#endif // _QUANTICVORTEX_STATIC_LIB_

// Declare the calling convention.
#if defined(_STDCALL_SUPPORTED)
#		define QUANTICVORTEX_CALLCONV __stdcall
#	else
#		define QUANTICVORTEX_CALLCONV __cdecl
#	endif // STDCALL_SUPPORTED

//#else // _QUANTICVORTEX_API_

//// Force symbol export in shared libraries built with gcc.
//#	if (__GNUC__ >= 4) && !defined(_QUANTICVORTEX_STATIC_LIB_) && defined(_QUANTICVORTEX_EXPORTS)
//#		define _QUANTICVORTEX_API_ __attribute__ ((visibility("default")))
//#	else
//#		define _QUANTICVORTEX_API_
//#	endif
//#	define QUANTICVORTEX_CALLCONV

//#endif // _QUANTICVORTEX_API_

#endif


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

#ifndef _QV_ADDIN_IRRLICHT_CONFIG_H_
#define _QV_ADDIN_IRRLICHT_CONFIG_H_


//! WIN32 for Windows32
//! WIN64 for Windows64
// The windows platform
#if defined(_WIN32) || defined(_WIN64) || defined(WIN32) || defined(WIN64)

#include <windows.h> 

//#	define QUANTICVORTEX_ADDIN_PLATAFORM QUANTICVORTEX_PLATAFORM_WINDOWS
////#	define _QUANTICVORTEX_API_
#endif

// To build as a static library, you must define _QUANTICVORTEX_STATIC_LIB_

#ifndef _QUANTICVORTEX_STATIC_LIB_
#	ifdef _QUANTICVORTEX_ADDIN_IRRLICHT_EXPORTS
#		define _QUANTICVORTEX_ADDIN_IRRLICHT_API_ __declspec(dllexport)
#	else
#		define _QUANTICVORTEX_ADDIN_IRRLICHT_API_ __declspec(dllimport)
#	endif // _QUANTICVORTEX_EXPORTS
#else
#	define _QUANTICVORTEX_ADDIN_IRRLICHT_API_
#endif // _QUANTICVORTEX_STATIC_LIB_

// Declare the calling convention.
#if defined(_STDCALL_SUPPORTED)
#	define QUANTICVORTEX_ADDIN_IRRLICHT_CALLCONV __stdcall
#else
#	define QUANTICVORTEX_ADDIN_IRRLICHT_CALLCONV __cdecl
#endif // STDCALL_SUPPORTED

//#else // _QUANTICVORTEX_API_

// Force symbol export in shared libraries built with gcc.
#	if (__GNUC__ >= 4) && !defined(_QUANTICVORTEX_STATIC_LIB_) && defined(_QUANTICVORTEX_ADDIN_IRRLICHT_EXPORTS)
#		 undef _QUANTICVORTEX_ADDIN_IRRLICHT_API_
#		define _QUANTICVORTEX_ADDIN_IRRLICHT_API_ __attribute__ ((visibility("default")))
#	else
#		 undef _QUANTICVORTEX_ADDIN_IRRLICHT_API_
#		define _QUANTICVORTEX_ADDIN_IRRLICHT_API_
#	endif
#	undef QUANTICVORTEX_ADDIN_IRRLICHT_CALLCONV
#	define QUANTICVORTEX_ADDIN_IRRLICHT_CALLCONV

#endif
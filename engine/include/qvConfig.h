/**************************************************************************************************

//This code is part of QuanticVortex for latest information, see http://www.quanticvortex.org
//
//Copyright (c) 2009 QuanticMinds Software Ltda.
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

#ifndef _QUANTICVORTEX_CONFIG_H_
#define _QUANTICVORTEX_CONFIG_H_

#include "qvConfigProfile.h"

//! WIN32 for Windows32 
//! WIN64 for Windows64
#if defined(_WIN32) || defined(_WIN64) || defined(WIN32) || defined(WIN64)
#	define		QUANTICVORTEX_PLATAFORM  PLATAFORM_WINDOWS
#	include <windows.h>
#	undef NOMINMAX
#	define NOMINMAX
#endif

#if QUANTICVORTEX_PLATAFORM == PLATAFORM_WINDOWS // WINDOWS PLATAFORM
#	ifndef _QUANTICVORTEX_STATIC_LIB_

#		ifdef _QUANTICVORTEX_EXPORTS
#			define _QUANTICVORTEX_API __declspec(dllexport)
#		else
#			define _QUANTICVORTEX_API __declspec(dllimport)
#		endif // _QUANTICVORTEX_EXPORTS
#	else
#		define _QUANTICVORTEX_API
#	endif // _QUANTICVORTEX_STATIC_LIB_
#endif // WINDOWS PLATAFORM

// Declare the calling convention.
#if defined(_STDCALL_SUPPORTED)
#	define QUANTICVORTEX_CALLCONV __stdcall
#else
#	define QUANTICVORTEX_CALLCONV __cdecl
#endif // STDCALL_SUPPORTED


#define QUANTICVORTEX_PHYSICS PHYSICS_BULLET
#define QUANTICVORTEX_RENDER  RENDER_IRRLICHT

#endif

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


#ifndef __QV_PREREQUISITES_H_
#define __QV_PREREQUISITES_H_


#ifdef _MSC_VER

#   pragma warning (disable : 4275) // non dll-interface class used as base
//                                     // for dll-interface class
//
#   pragma warning (disable : 4661) // no suitable definition provided for
//                                     // explicit template instantiation request
//
#   pragma warning (disable : 4221) // private dependency

#	pragma warning (disable : 4251) //needs to have dll-interface to be used by clients

#   pragma warning( disable : 4244 ) // possible loss of data in converversion - small number of places

#endif

#include "irrlicht.h"
//#include "IReferenceCounted.h"
//#include "irrArray.h"
//#include "irrList.h"
//#include "irrMap.h"
//#include "irrMath.h"
//#include "irrString.h"
//#include "irrTypes.h"

using namespace irr;
using namespace irr::core;


#include "qvSuperFastHash.h"

namespace qv
{
    const f32 GF_GAME_LOGIC_FRAMERATE(16.666667f);
    const f32 GF_GAME_ANIMATION_FRAMERATE(16.666667f); // 1/30
    const f32 GF_GAME_RENDER_FRAMERATE(16.666667f); //    1/60
    const f32 GF_GAME_PHYSICS_FRAMERATE(16.666667f); //   1/60
    //const f32 GamePhysicsFramerate(16.666667f);
}

//----------------------------------------------

// POCO headers
#include "Poco/AutoPtr.h"
#include "Poco/SharedPtr.h"
#include "Poco/Path.h"
#include "Poco/File.h"
#include "Poco/Glob.h"
#include "Poco/Types.h"
#include "Poco/Void.h"
#include "Poco/Any.h"


namespace gv
{
    using Poco::SharedPtr;
    using Poco::AutoPtr;
    using Poco::Path;
    using Poco::Int8;
    using Poco::UInt8;
    using Poco::Int16;
    using Poco::UInt16;
    using Poco::Int32;
    using Poco::UInt32;
    using Poco::Int64;
    using Poco::UInt64;
    using Poco::IntPtr;
    using Poco::UIntPtr;
    using Poco::Void;
    using Poco::Any;
    using Poco::AnyCast;
}



//Memory manager configuration
#include "qvMemoryManager.h"

#ifdef _DEBUG
	#define QV_NEW(T) qv::MemoryManager::allocate<T>(sizeof(T), __FILE__, __LINE__, __FUNCTION__)
	#define QV_DELETE(pointer) qv::MemoryManager::deallocate(pointer)
#else
	#define QV_NEW(T) qv::MemoryManager::allocate<T>(sizeof(T))
	#define QV_DELETE(pointer) qv::MemoryManager::deallocate(pointer)
#endif

#endif


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


#ifndef __QV_PREREQUISITES_H_
#define __QV_PREREQUISITES_H_

//int definitions from C99
#include "inttypes.h"

#ifdef _MSC_VER

#   pragma warning (disable : 4275) // non dll-interface class used as base
//                                     // for dll-interface class
// 
#   pragma warning (disable : 4661) // no suitable definition provided for
//                                     // explicit template instantiation request
//
#   pragma warning (disable : 4221) // private dependency

#	pragma warning (disable : 4251) //needs to have dll-interface to be used by clients 


#endif

#include "irrlicht.h"
//#include "os.h"

using namespace irr;
using namespace irr::core;

#pragma warning( disable : 4244 ) // possible loss of data in converversion - small number of places

//#include <list>
//#include <map>

namespace qv
{
    const f32 GF_GAME_LOGIC_FRAMERATE(16.666667f);
    const f32 GF_GAME_ANIMATION_FRAMERATE(16.666667f);
    const f32 GF_GAME_RENDER_FRAMERATE(16.666667f);
    const f32 GF_GAME_PHYSICS_FRAMERATE(16.666667f);
    //const f32 GamePhysicsFramerate(16.666667f);
}

//----------------------------------------------

//#include "POCO/"

#endif


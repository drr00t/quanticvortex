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


#ifndef __GAME_STATE_CHANGE_EVENT_ARGS_H_
#define __GAME_STATE_CHANGE_EVENT_ARGS_H_

#include <vector>

#include "qvEventArgs.h"
#include "qvTypes.h"

namespace qv
{
namespace events
{
class _QUANTICVORTEX_API_ GameStateChangeEventArgs: public qv::events::EventArgs
{
public:

    GameStateChangeEventArgs( const qv::S_STATE& newGame );
    /// create a event argument with type

    virtual ~GameStateChangeEventArgs();
    /// destroy game view tick

//    u32 getElapsedTimeMs() const;
    /// elapsed time since last game logic tick in miliseconds
    
//    void setElapsedTimeMs( u32 elapsedTimeMs);
    /// setup new elapsed time since last game logic tick in miliseconds    
//private:

//    u32 mEventArgsHashType; // event arguments type
//    u32 mElapsedTimeMs; // event arguments type
};


//inlines 
//inline u32 GameTickEventArgs::getElapsedTimeMs() const 
//{ 
//    return mElapsedTimeMs; 
//}
//
//inline void GameTickEventArgs::setElapsedTimeMs( u32 elapsedTimeMs)
//{
//    mElapsedTimeMs = elapsedTimeMs;
//}
}
}

#endif


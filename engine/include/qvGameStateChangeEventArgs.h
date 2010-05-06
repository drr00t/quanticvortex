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
#include "qvStateTypes.h"

namespace qv
{
namespace events
{
class _QUANTICVORTEX_API_ GameStateChangeEventArgs: public qv::events::EventArgs
{
public:

    GameStateChangeEventArgs();
    /// create a event argument with type

    virtual ~GameStateChangeEventArgs();
    /// destroy game view tick

    u32 getNewGameState() const;
    /// new game state of game logic
    
    void setNewGameState( u32 newGameState);
    /// setup new game state of game logic
private:

    u32 mNewGameState; // new game state of game logic
};


//inlines 
// 
inline u32 GameStateChangeEventArgs::getNewGameState() const 
{ 
    return mNewGameState; 
}

inline void GameStateChangeEventArgs::setNewGameState( u32 newGameState)
{
    mNewGameState = newGameState;
}
}
}

#endif


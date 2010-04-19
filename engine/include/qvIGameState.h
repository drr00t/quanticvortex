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

#ifndef __I_GAME_STATE_H_
#define __I_GAME_STATE_H_

#include "qvIState.h"
#include "qvGameStateTypes.h"
#include "qvIEventCommand.h"
#include "qvIInputTranslator.h"

#include "Poco/SharedPtr.h"

namespace qv
{
    namespace gaming
    {
        
		// the game state will work on game logic views, like: add sceneview to a human view,
		// or add a gui view, or remove them when need, change content of a scene view
        // [GameState name]
        //      [scene files]
        //      [input translators]
        //      [event commands]
        // [GameState]
        class IGameState: public IState
        {

        public:

        };
        
        typedef Poco::SharedPtr<IGameState> IGameStateSharedPtr;
    }
}

#endif


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

#ifndef __GAME_STATE_MACHINE_H_
#define __GAME_STATE_MACHINE_H_

#include "qvPrerequisites.h"
#include "qvIStateMachine.h"


namespace qv
{
    namespace gaming
    {
        class IGameState;

		class GameStateMachine: public IStateMachine
        {
		protected:
            map<s32, IGameState*> mGameStateMap;
			S_STATE_TYPE mCurrentGameState;
            //IGameState* mPreviousGameState;
            //IGameState* mNextGameState;

        public:
			GameStateMachine();
			~GameStateMachine();

            virtual void addState(IState* state);
            virtual void changeState(const S_STATE_TYPE& newType);
			//virtual const IState* getCurrentState(){return mCurrentState;}
            virtual void removeState(IState* state);
			//virtual void setCurrentState(IState* state){ mCurrentState = state;}
	        virtual void update(u32 elapsedTimeMs);
        };
    }
}
#endif


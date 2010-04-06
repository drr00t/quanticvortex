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


#ifndef __I_GAME_LOGIC_H_
#define __I_GAME_LOGIC_H_

#include "qvSHashedString.h"
#include "qvIActor.h"
#include "qvIGameView.h"
#include "qvIProcess.h"
#include "qvIState.h"

#include "IReferenceCounted.h"

namespace qv
{

	namespace physics
	{
		class IPhysicsManager;
	}

    namespace gaming
    {

		class IGameLogic: public irr::IReferenceCounted
        {
            public:

			virtual bool initialize() const = 0;

			virtual bool finalize() const = 0;

            virtual IActorSharedPtr getActor( u32 actorHashId)=0;

			virtual void addActor( u32 actorHashId)=0;

			virtual void removeActor( u32 actorHashId) = 0;

			virtual const views::GameViewsArray& getGameViews() const = 0;

            virtual void addView(views::IGameView* gameView, u32 actorHashId = 0) = 0;

			virtual views::IGameView* addView(const c8* viewID, u32 gameViewHashType, u32 actorHashId = 0) = 0;

			virtual void removeView(views::IGameView* gameView) = 0;

			virtual bool loadGame(const irr::core::stringc& gameName) const = 0;

            virtual void update( u32 currentTimeMs, u32 elapsedTimeMs) = 0;

            virtual void changeState( u32 newStateHashId) = 0;

        };
    }
}
#endif


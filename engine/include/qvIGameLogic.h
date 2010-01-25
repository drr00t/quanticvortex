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
#include "qvIHumanView.h"
#include "qvIProcess.h"
#include "qvIState.h"


namespace qv
{
    namespace views
    {
		class IGameViewFactory;
    }

	namespace gaming
    {

		struct SActorArgs;

        typedef SHashedString GLT_GAME_LOGIC_TYPE;

		static const GLT_GAME_LOGIC_TYPE *GLT_GAME_LOGIC_DEFAULT = new GLT_GAME_LOGIC_TYPE("GLT_GAME_LOGIC_DEFAULT");


		class IGameLogic: public IReferenceCounted
        {
            public:

			virtual bool initialize()=0;

            virtual const GLT_GAME_LOGIC_TYPE* getType() const=0;

            virtual IActor* getActor(const AI_ACTOR_ID* actorID)=0;

			virtual void addActor( const AI_ACTOR_ID* actorID, const SActorArgs& args)=0;

			virtual void moveActor( const AI_ACTOR_ID* actorID, const matrix4& transformation)=0;
						
			virtual void removeActor(const AI_ACTOR_ID* actorID)=0;

			//TODO: implement this method
			//virtual void registerActorFactory(views::IActorFactory* factoryToAdd)=0;


			virtual const array<views::IGameView*>& getGameViews() const=0;

            virtual void addView(views::IGameView* gameView, const AI_ACTOR_ID* actorID = 0)=0;           
			 
			virtual views::IGameView* addView(const c8* viewID, const views::GVT_GAME_VIEW_TYPE* viewType, const AI_ACTOR_ID* actorID = 0)=0;

			virtual views::IHumanView* addHumanView(const c8* viewID, const AI_ACTOR_ID* actorID=0)=0;
            //virtual core::IRecorderView* addRecorderView(const c8* viewID, ActorID* actorID=0) = 0;
            //virtual core::IAIView* addAIView(const c8* viewID, ActorID* actorID=0) = 0;
            //virtual core::INetworkView* addNetworkView(const c8* viewID, ActorID* actorID=0) = 0;
            //virtual core::IPhysicsView* addPhysicsView(const c8* viewID, ActorID* actorID=0) = 0;




			virtual void removeView(views::IGameView* gameView)=0;

			virtual void registerGameViewFactory(views::IGameViewFactory* factoryToAdd)=0;

			virtual bool loadGame(const stringw& gameName)=0;

            virtual void update( u32 currentTimeMs, u32 elapsedTimeMs)=0;

            virtual void changeState( const S_STATE_TYPE* newState)=0;

        };
    }
}
#endif


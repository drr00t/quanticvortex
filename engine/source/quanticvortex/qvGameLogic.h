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


#ifndef __DEFAULT_GAME_LOGIC_H_
#define __DEFAULT_GAME_LOGIC_H_

//#include "qvIActor.h"
#include "qvIGameLogic.h"
//#include "qvIGameState.h"
//#include "qvIGameView.h"
//#include "qvIGameViewFactory.h"
#include "qvIProcessManager.h"

//#include "core/qvActor.h"
//#include "qvSActorParams.h"
//#include "qvSPlayerScore.h"

//#include "qvIEventListener.h"
//#include "qvIPhysicsManager.h"

//using namespace qv::events;
//using namespace qv::physics;
//using namespace qv::runtime;


namespace qv
{
    class IEngineManager;

	namespace views
	{
		IGameViewFactory;
	}

    namespace gaming
    {

		class GameLogic : public IGameLogic
        {

        protected:
            
            array<views::IGameViewFactory*> mGameViewFactories;

			const GLT_GAME_LOGIC_TYPE* mType;

            const S_STATE_TYPE* mState;

            map<u32, IActor*> mActors;
            
            array<views::IGameView*> mGameViews;
            
            IEngineManager* mEngineManager;

            //SPlayerScore mPlayerScore;
            //ActorID mHumanPlayerAttached;
	        //list<ActorID*> mAIPlayersAttached;

			//physics system
			//IPhysicsManager* mPhysicsManager;

   //         IProcessManager* mProcessManager;  game logic AI

			//IEventListener* mEventListener;

        public:
            GameLogic(IEngineManager* engineManager, const GLT_GAME_LOGIC_TYPE* type=GLT_GAME_LOGIC_DEFAULT);
            virtual ~GameLogic();

			virtual bool initialize();

			virtual bool finalize();

            virtual const GLT_GAME_LOGIC_TYPE* getType() const
            {
                return mType;
            }

            virtual IActor* getActor(const AI_ACTOR_ID* actorID)
			{
				map<u32,IActor*>::Node* actor = mActors.find(actorID->HashedText);
				IActor* actorFounded = 0;
				if(actor)
					actorFounded = actor->getValue();
				return actorFounded;
			}

			virtual void addActor( const AI_ACTOR_ID* actorID, const SActorArgs& args);


			virtual void moveActor( const AI_ACTOR_ID* actorID, const matrix4& transformation)
			{
				IActor* actor = getActor(actorID);

				if(actor)
					actor->setTransformation(transformation);
			}
            
			void removeActor(const AI_ACTOR_ID* actorID)
			{
				IActor* actor = getActor(actorID);

                if(actor)
                {
					actor->drop();
					mActors.delink(actorID->HashedText);
                }
			}


			virtual const array<views::IGameView*>& getGameViews() const
			{
				return mGameViews;
			}
			
            virtual void addView(views::IGameView* gameView, const AI_ACTOR_ID* actorID = 0);
            
			virtual views::IGameView* addView(const c8* viewID, const views::GVT_GAME_VIEW_TYPE* viewType, const AI_ACTOR_ID* actorID = 0);

            virtual views::IHumanView* addHumanView(const c8* viewID, const AI_ACTOR_ID* actorID = 0);
			
            virtual void removeView(views::IGameView* gameView);
			
			virtual void registerGameViewFactory(views::IGameViewFactory* factoryToAdd);


			virtual bool loadGame(const stringw& gameName);

            virtual void update( u32 currentTimeMs, u32 elapsedTimeMs);

            virtual void changeState( const S_STATE_TYPE* newState);


			//IPhysicsManager* getPhysicsManager(){return mPhysicsManager;}
			//IEventListener* getEventListener(){return mEventListener;}
            
			//void attachProcess(IProcess* process) 
			//{ 
			//	if(mProcessManager)mProcessManager->attach(process);
			//}

			//void detachProcess(IProcess* process){}
        };
    }
}
#endif


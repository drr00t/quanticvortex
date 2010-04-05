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

#include "irrArray.h"
#include "irrMap.h"


namespace qv
{
    class IEngineManager;

	namespace views
	{
		class IGameViewFactory;
	}

    namespace gaming
    {

		class GameLogic : public IGameLogic
        {

        protected:

            irr::core::array<views::IGameViewFactory*> mGameViewFactories;

            const S_STATE* mState;

            ActorsMap mActors;

            views::GameViewsArray mGameViews;

            IEngineManager* mEngineManager;

            //SPlayerScore mPlayerScore;
            //ActorID mHumanPlayerAttached;
	        //list<ActorID*> mAIPlayersAttached;

			//physics system
			physics::IPhysicsManager* mPhysicsManager;

   //         IProcessManager* mProcessManager;  game logic AI

			//IEventListener* mEventListener;// here need put all event that gamelogic will listen for

        public:
            GameLogic(IEngineManager* engineManager);
            virtual ~GameLogic();

			virtual bool initialize();

			virtual bool finalize();

            virtual IActorSharedPtr getActor( u32 actorHashId)
			{
//				ActorsMap::Node* actor = mActors.find(actorHashId);
				IActor* actorFounded = 0;
//				if(actor)
//					actorFounded = actor->getValue();
				return actorFounded;
			}

			virtual void addActor( u32 actorHashId);


//			virtual void moveActor( u32 actorHashId, const matrix4& transformation)
//			{
//				IActor* actor = getActor(actorID);
//
//				if(actor)
//					actor->setTransformation(transformation);
//			}

			void removeActor( u32 actorHashId)
			{
				IActor* actor = getActor(actorHashId);

                if(actor)
                {
//					actor->drop();
//					mActors.delink(actorID.Hash);
                }
			}


			virtual const views::GameViewsArray& getGameViews() const
			{
				return mGameViews;
			}

            virtual void addView(views::IGameView* gameView, u32 actorHashId = 0);

			virtual views::IGameView* addView(const c8* viewID, const views::GVT_GAME_VIEW_TYPE* viewType, u32 actorHashId = 0);

            virtual void removeView(views::IGameView* gameView);

			virtual void registerGameViewFactory(views::IGameViewFactory* factoryToAdd);


			virtual bool loadGame(const string& gameName);

            virtual void update( u32 currentTimeMs, u32 elapsedTimeMs);

            virtual void changeState( const S_STATE* newState);


			physics::IPhysicsManager* getPhysicsManager(){return mPhysicsManager;}

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


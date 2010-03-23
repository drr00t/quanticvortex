#include "qvActorManager.h"

namespace qv
{
	namespace gaming
	{
	    //-----------------------------------------------------------------------------------------
		ActorManager::ActorManager(void)
		{
		}

        //-----------------------------------------------------------------------------------------
		ActorManager::~ActorManager(void)
		{
		}
		//-----------------------------------------------------------------------------------------
        IActorSharedPtr ActorManager::addActor( const c8* actorName, u32 actorHashType)
        {
            IActorSharedPtr ptr;
            return ptr;
        }
        //-----------------------------------------------------------------------------------------
        IActorSharedPtr ActorManager::addCameraActor( u32 actorHashType)
        {
            IActorSharedPtr ptr;
            return ptr;
        }
        //-----------------------------------------------------------------------------------------
        IActorSharedPtr ActorManager::addPlayerActor( u32 actorHashType)
        {
            IActorSharedPtr ptr;
            return ptr;
        }
        //-----------------------------------------------------------------------------------------
        void ActorManager::findActorsByType( u32 actorHashType , ActorsSharedPtrArray& actors)
        {
            for(s32 i = 0; i < mActors.size(); ++i)
                if(mActors[i].getHashType() == actorHashType)
                    actors.push_back(mActors[i]);
        }
        //-----------------------------------------------------------------------------------------
        IActorSharedPtr ActorManager::findActor(u32 actorHashId)
        {
            IActorSharedPtr actorPtr;
            for(s32 i = 0; i < mActors.size(); ++i)
            {
                 if(mActors[i].getHashId() == actorHashId)
                 {
                     actorPtr = mActors[i];
                     break;
                 }
            }

            return actorPtr;
        }
        //-----------------------------------------------------------------------------------------
        void ActorManager::registerActorFactory(IActorFactory * factory)
        {
            mActorsFactories.push_back(IActorFactorySharedPtr(factory));
        }
        //-----------------------------------------------------------------------------------------
        void ActorManager::registerActorFactory(IActorFactorySharedPtr factory)
        {
            mActorsFactories.push_back(factory);
        }
        //-----------------------------------------------------------------------------------------
        void ActorManager::removeActor( u32 actorHashId)
        {
            u32 actorIdx;

            //populatin deletion list
            for(s32 i = 0; i < mActors.size(); ++i)
            {
                if(mActors[i].getHashId() == actorHashId)
                {
                    actorIdx = i ;
                    break;
                }
            }

            //effective deletion of actor
            if((actorIdx > 0) && ( actorIdx < mActors.size()))
                mActors.erase(actorIdx);

        }
        //-----------------------------------------------------------------------------------------
	}
}

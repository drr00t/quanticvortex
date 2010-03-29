
#ifndef __ACTORMANAGER_H_
#define __ACTORMANAGER_H_

#include "qvIActorManager.h"
//#include "qvActorArgs.h"
#include "qvActorFactory.h"

//using namespace irr::scene;

namespace qv
{
    namespace gaming
    {
        class ActorManager: IActorManager
        {
        public:
			ActorManager();

            virtual ~ActorManager();

            virtual IActorSharedPtr addActor( const c8* actorName, u32 actorHashType);

            virtual IActorSharedPtr addCameraActor( u32 actorHashType);

            virtual IActorSharedPtr addPlayerActor( u32 actorHashType);

            virtual void findActorsByType( u32 actorHashType , ActorsSharedPtrArray& actors);

            virtual IActorSharedPtr findActor(u32 actorHashId);

            virtual void registerActorFactory(IActorFactory * factory);

            virtual void registerActorFactory(IActorFactorySharedPtr factory);

            virtual void removeActor( u32 actorHashId);

        private:
            ActorsSharedPtrArray mActors;
            ActorFactorySharedPtrArray mActorsFactories;
        };
    }
}
#endif


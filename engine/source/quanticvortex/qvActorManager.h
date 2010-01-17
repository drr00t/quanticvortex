
#ifndef __ACTORMANAGER_H_
#define __ACTORMANAGER_H_

#include "qvIActor.h"
//#include "qvActorArgs.h"
#include "qvActorFactory.h"

//using namespace irr::scene;

namespace qv
{
    namespace gaming
    {
        class ActorManager
        {
		private:
			//map for mapping factories to actortors factories
			//s32, PlayerFactory* for example

        public: 
			ActorManager();
            virtual ~ActorManager();

			//query actor
			//remove actor
			//create actor with (args, empty just actor stub)
			//register actor factories by ID or type name
			//unregister actor factories by ID or type name
			//load actor from file (deserialization of actor sabed before)
			//query actor factory

        };
    }
}
#endif


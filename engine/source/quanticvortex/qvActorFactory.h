

#ifndef _ACTORFACTORY_H_
#define _ACTORFACTORY_H_

#include "qvPrerequisites.h"
#include "qvSHashedString.h"
#include "qvActor.h"

using namespace qv::gaming;
namespace qv
{
	namespace gaming
	{
		class ActorFactory
		{
		public:
			ActorFactory(void){}
			virtual ~ActorFactory(void){}

			virtual const ActorType& getActorType() const = 0;
			virtual Actor* create() = 0;
			virtual void destroy(Actor*) = 0;

		};
	}
}
#endif
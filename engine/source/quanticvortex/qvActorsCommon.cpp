#include "qvActorsCommon.h"

#include "qvActorManager.h"

namespace qv
{
    namespace gaming
    {
        extern "C" _QUANTICVORTEX_API_ IActorManager* QUANTICVORTEX_CALLCONV createActorManager()
        {
            return new ActorManager();
        }
    }
}


#ifndef _ACTORS_COMMON_H
#define _ACTORS_COMMON_H

#include "qvCompileConfig.h"

#include "qvIActorManager.h"



namespace qv
{
    namespace gaming
    {
        extern "C" _QUANTICVORTEX_API_ IActorManager* QUANTICVORTEX_CALLCONV createActorManager();
    }

}

#endif // _QVACTORS_COMMON_H

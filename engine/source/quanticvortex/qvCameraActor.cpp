
#include "qvCameraActor.h"
//#include "qvActorArgs.h"

namespace qv
{
    namespace gaming
    {
		//-----------------------------------------------------------------------------------------
		CameraActor::CameraActor()
        {
        }
		//-----------------------------------------------------------------------------------------
		CameraActor::CameraActor(const AI_ACTOR_ID* actorID, const AT_ACTOR_TYPE* actorType)
            : mID(actorID),mType(actorType)
        {
        }
        //-----------------------------------------------------------------------------------------
		CameraActor::CameraActor()
        {
        }
		//-----------------------------------------------------------------------------------------
        CameraActor::~CameraActor()
        {
        }
        //-----------------------------------------------------------------------------------------
        void CameraActor::update( u32 elapsedTimeMs)
        {
        }
        //-----------------------------------------------------------------------------------------
    }
}


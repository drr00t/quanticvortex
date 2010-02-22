
#ifndef __ACTOR_H_
#define __ACTOR_H_

#include "qvICameraActor.h"

using namespace irr::scene;


namespace qv
{
    namespace gaming
    {
        static const AT_ACTOR_TYPE AT_ACTOR("AT_ACTOR");

		class CameraActor: public ICameraActor
        {

        public: 
			
            CameraActor();
			//CameraActor( const SActorParams& params);
            CameraActor(const AI_ACTOR_ID* actorID, const AT_ACTOR_TYPE* actorType);
            virtual ~CameraActor();

			virtual u32 getId() const
			{
				return mID->HashedText;
			}
			
            virtual u32 getType() const
			{
				return mType->HashedText;
			}

			//virtual const matrix4& getTransformation() const =0;
			//
			//virtual f32 getAspectRatio () const =0;
			//
			//virtual f32 getFarValue () const =0;
			//
			//virtual f32 getFOV () const =0;
			//
			//virtual f32 getNearValue () const =0;
			//
			//virtual const core::vector3df& getTarget() const =0;
			//
			//virtual const core::vector3df& getUpVector () const =0;


			//virtual bool isPhysical() const = 0;

			//virtual bool isVisible () const = 0;

   //         virtual void setTransformation( const matrix4& transformation) = 0;
			//
			//virtual void setAspectRatio (f32 aspect)=0;

			//virtual void setFarValue (f32 zf)=0;

			//virtual void setFOV (f32 fovy)=0;

			//virtual void setNearValue (f32 zn)=0;

			//virtual void setTarget (const core::vector3df &pos)=0;

			//virtual void setUpVector (const core::vector3df &pos)=0;

            virtual void update( u32 elapsedTimeMs) = 0;

		protected:
            const AI_ACTOR_ID* mID;
            const AT_ACTOR_TYPE* mType;
			bool mPhysics;
            //SActorParams* mActorParams;
            matrix4 mTransformation;
        };
    }
}
#endif


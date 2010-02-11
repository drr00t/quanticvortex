
#ifndef __ACTOR_H_
#define __ACTOR_H_

#include "qvIActor.h"

using namespace irr::scene;


namespace qv
{
    namespace gaming
    {
		struct SActorParams;

        static const AT_ACTOR_TYPE AT_ACTOR("AT_ACTOR");

        class Actor: public IActor
        {
		//private:
		//	ActorArgs* mActorArgs;

		protected:
            AI_ACTOR_ID mActorID;
            AT_ACTOR_TYPE mActorType;
			bool mPhysics;
            SActorParams* mActorParams;
            matrix4 mTransformation;

        public: 
			
            Actor();
			Actor( const SActorParams& params);
            Actor(const AI_ACTOR_ID& actorID, const AT_ACTOR_TYPE& actorType = AT_ACTOR);
            virtual ~Actor();
			
            virtual SActorParams* getParams();
			virtual void setParams(SActorParams* params);

            virtual const AI_ACTOR_ID& getActorID() const 
            {
                return mActorID;
            } 

            virtual void setActorID(const AI_ACTOR_ID& actorID)
            {
                mActorID = actorID;
            } 

            virtual const AT_ACTOR_TYPE& getType() const 
            {
                return mActorType;
            }

            virtual void setType(const AT_ACTOR_TYPE& actorType)
            {
                mActorType = actorType;
            } 

			virtual bool isPhysical()
            {
                return mPhysics;
            }

            virtual const matrix4& getTransformation()
            {
                return mTransformation;
            }

            virtual void setTransformation(const matrix4& transformation)
            {
                mTransformation = transformation;
            }
			
 
            virtual void update( u32 elapsedTimeMs);
        };

/*        class _QUANTICVORTEX_API LightActor: public Actor
        {
		protected:
			//ActorID mActorID;
			//ActorType mActorType;
			//bool mPhysics;

        public: 
			LightActor();
			LightActor( const ActorArgs& args);
            LightActor(const c8* actorName, const c8* actorType);
            virtual ~LightActor();

			//ActorID& getActorId(){return mActorID;} 
			//ActorType& getType(){return mActorType;}
			//bool isPhysical(){return mPhysics;}
            virtual void update( u32 elapsedTimeMs);
        };

        class _QUANTICVORTEX_API MeshActor: public Actor
        {
		protected:
			stringc mMeshName;
			//ActorID mActorID;
			//ActorType mActorType;
			//bool mPhysics;

        public: 
			MeshActor();
			MeshActor( const ActorArgs& args);
            MeshActor(const c8* actorName, const c8* actorType);
            virtual ~MeshActor();

			virtual void update( u32 elapsedTimeMs);
        };
		*/
    }
}
#endif


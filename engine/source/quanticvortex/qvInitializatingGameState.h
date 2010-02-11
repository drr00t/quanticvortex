
#ifndef __INITIALIZATING_GAME_STATE_H_
#define __INITIALIZATING_GAME_STATE_H_

#include "qvIGameState.h"


namespace qv
{
    namespace views
    {
        class ISceneView;
    }

    namespace gaming
    {

        class InitializatingGameState: public IState
        {
        public: 
            InitializatingGameState();
            ~InitializatingGameState();

            virtual const S_STATE* getState()
            {
                return mState;
            }

            virtual void configure();

	        virtual void enter();

	        virtual void leave();

	        virtual void update( u32 currentTimeMs, u32 elapsedTimeMs);

        private:
            const S_STATE* mState; 

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


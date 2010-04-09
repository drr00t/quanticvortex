
#ifndef __WAINTING_PLAYER_GAME_STATE_H_
#define __WAINTING_PLAYER_GAME_STATE_H_

#include "qvIGameState.h"


namespace qv
{
    namespace views
    {
        class ISceneView;
    }

    namespace gaming
    {

        class WaintingPlayerGameState: public IState
        {
        public: 
            WaintingPlayerGameState();
            ~WaintingPlayerGameState();

            virtual u32 getState() { return mState.Hash; }

            virtual void configure();

	        virtual void enter();

	        virtual void leave();

	        virtual void update( u32 currentTimeMs, u32 elapsedTimeMs);

        private:
            S_STATE mState; 

        };
    }
}
#endif



#include "qvGameStateMachine.h"
#include "qvIGameState.h"

namespace qv
{
    namespace gaming
    {
		//-----------------------------------------------------------------------------------------
		GameStateMachine::GameStateMachine()
        {

        }
		//-----------------------------------------------------------------------------------------
        GameStateMachine::~GameStateMachine()
        {
        }
		//-----------------------------------------------------------------------------------------
		void GameStateMachine::addState(qv::IState *state, bool startUpState)
		{
//		    if(mStateMap.isEmpty())
//		    {
//		        mStateMap[state->getState()->Hash] = state;
//		    }
//		    else
//		    {
//		        StateMap::Node* node = mStateMap.find(state->getState()->Hash);
//
//                if(!node)
//                    mStateMap[state->getState()->Hash] = state;
//		    }

            if(startUpState)
                mCurrentState = state;

		}
		//-----------------------------------------------------------------------------------------
		void GameStateMachine::changeState(const qv::S_STATE* newState)
		{
            
            //leave old game state
//            StateMap::Node* nodeNewState = mStateMap.find(newState->Hash);

//            if(nodeNewState)
//            {
//                mCurrentState->leave();
//                mCurrentState = nodeNewState->getValue();
//                mCurrentState->configure();
//                mCurrentState->enter();
//            }

			//query for type in state list
			//execute leave from current state
			//execute enter from new current type state
		}
		//-----------------------------------------------------------------------------------------
		void GameStateMachine::removeState(qv::IState *state)
		{
            //mGameStateMap.remove(
		}
		//-----------------------------------------------------------------------------------------
	}
}


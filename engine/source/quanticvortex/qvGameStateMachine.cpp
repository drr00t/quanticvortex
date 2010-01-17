
#include "qvGameStateMachine.h"

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
		void GameStateMachine::addState(qv::gaming::IState *state)
		{
            map<s32, IGameState*>::Node* node = mGameStateMap.find(state->getType().ID);

            //if(!node)
            //    mGameStateMap[state->getType().ID] = state;
		}
		//-----------------------------------------------------------------------------------------
		void GameStateMachine::changeState(const qv::gaming::S_STATE_TYPE &newType)
		{
            //leave old game state
            map<s32, IGameState*>::Node* nodeOld = mGameStateMap.find(mCurrentGameState.ID);

            //if(nodeOld)
            //    nodeOld->getValue()->leave();

            //going to new one
            //map<s32, IGameState*>::Node* nodeNew = mGameStateMap.find(newType.ID);

            //if(nodeNew)
            //{
            //    mCurrentGameState = newType;
            //    nodeNew->getValue()->enter();

			//query for type in state list
			//execute leave from current state
			//execute enter from new current type state
		}
		//-----------------------------------------------------------------------------------------
		void GameStateMachine::removeState(qv::gaming::IState *state)
		{
            //mGameStateMap.remove(
		}
		//-----------------------------------------------------------------------------------------
		void GameStateMachine::update(irr::u32 elapsedTimeMs)
		{
			//mCurrentState->update(elapsedTimeMs);
		}
		//-----------------------------------------------------------------------------------------
	}
}


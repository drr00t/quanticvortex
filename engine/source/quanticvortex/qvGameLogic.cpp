/**************************************************************************************************

//This code is part of QuanticVortex for latest information, see http://www.quanticvortex.org
//
//Copyright (c) 2009-2010 QuanticMinds Software Ltda.
//
//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this software and associated documentation files (the "Software"), to deal
//in the Software without restriction, including without limitation the rights
//to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions:
//
//The above copyright notice and this permission notice shall be included in
//all copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//THE SOFTWARE.

**************************************************************************************************/


#include "qvGameLogic.h"

// parameters
#include "qvSActorParams.h"
#include "qvSGameParams.h"

// managers
#include "qvEventManager.h"
#include "qvPhysicsManager.h"

//event args
#include "qvGameTickEventArgs.h"

//game logic commands
#include "qvCreateGameViewCommand.h"

namespace qv
{
namespace gaming
{
//-----------------------------------------------------------------------------------------
GameLogic::GameLogic(qv::SGameParams& gameParams, qv::events::EventManager* eventManager)
        : mPhysicsManager(0), mEventManager(eventManager), mPaused(false)
{
    mPhysicsManager = new physics::PhysicsManager(eventManager);

    //TODO: GameLogic should be own of command that will do job of game logic data.
    // i have to think about this.
    mEventManager->addCommand(new qv::gaming::CreateGameViewCommand(this));
}
//-----------------------------------------------------------------------------------------
GameLogic::~GameLogic()
{
    qv::gaming::ActorsMap::ParentLastIterator itrActor = mActors.getParentLastIterator();

    while (!itrActor.atEnd())
        mActors.remove((*itrActor.getNode()).getKey());

    mActors.clear();
}
//-----------------------------------------------------------------------------------------------
bool GameLogic::initialize()
{

    mPhysicsManager->initialize();

    //mProcessManager = new ProcessManager();
    //mState = EGS_INITIALIZING;

    //m_random.Randomize();



    //m_bProxy = false;
    //m_RenderDiagnostics = false;
    //m_ExpectedPlayers = 0;
    //m_ExpectedRemotePlayers = 0;
    //m_ExpectedAI = 0;
    //m_pPathingGraph.reset(CreatePathingGraph());

    //m_pAiEventListener = EventListenerPtr (GCC_NEW AiEventListener ( ));
    //safeAddListener(m_pAiEventListener, EvtData_AiSteer::sk_EventType);
    return true;
}
//-----------------------------------------------------------------------------------------
bool GameLogic::finalize()
{
    return true;
}
//-----------------------------------------------------------------------------------------
void GameLogic::addActor( u32 actorHashId)
{
    Actor* actor(0);

    //ask to an actor factory if it possible create an actor with this args
    //if there is no other actor with this ID
    if (!mActors.find(actorHashId))
    {
        //if(args.getNodeType().equals_ignore_case("mesh"))
        //{
        //	actor = new MeshActor(args);
        //	mActors[actor->getActorID().getHashedName()] = actor;
        //}
        //else if(args.getNodeType().equals_ignore_case("light"))
        //{
        //	actor = new LightActor(args);
        //	mActors[actor->getActorID().getHashedName()] = actor;
        //}
    }
}
//-----------------------------------------------------------------------------------------
void GameLogic::update( u32 currentTimeMs, u32 elapsedTimeMs)
{
    //       switch(mState)
    //    {
    //     case EGS_INITIALIZING:
    //      // If we get to here we're ready to attach players
    //               changeState(EGS_LOADING);
    ////os::Printer::log("[GAMELOGIC]: changing game state to main menu");

    //      break;

    //     case EGS_LOADING:
    //changeState(EGS_MAINMENU);
    //      //if (mApplication->VLoadGame())
    //      //{
    //      // //changeState(BGS_SpawnAI);
    //      //}
    //      //else
    //      //{
    //      // assert(0 && _T("The game failed to load."));
    //       //mApplication->AbortGame();
    //      //}
    ////os::Printer::log("[GAMELOGIC]: changing game state to running");
    //      break;

    //     case EGS_MAINMENU:
    //changeState(EGS_RUNNING);// do nothing

    ////os::Printer::log("[GAMELOGIC]: changing game state to running");
    //
    //break;

    //     //case GameState::WaitingForPlayers:
    //     // // do nothing - the game class should handle this one.
    //     // break;

    //     //case BGS_SpawnAI:
    //     // if (this->m_ExpectedAI == 0)
    //     // {
    //     //  // the base game logic doesn't spawn AI - your child class will do that.
    //     //  // in the case no AI are coming, the base game logic will go ahead and move to
    //     //  // the next state.
    //     //  VChangeState(BGS_Running);
    //     // }
    //     // break;

    //     case EGS_RUNNING:

    ////game processes animations, etc...
    //               //mProcessManager->update(elapsedTimeMs);

    //      break;

    //     default:
    //               break;
    //      //assert(0 && _T("Unrecognized state."));
    //      // Not a bad idea to throw an exception here to
    //      // catch this in a release build...
    //    }
    //
    if (!mPaused)
    {
        if (mPhysicsManager)
        {
            mPhysicsManager->update(elapsedTimeMs);
        }
    }
}
//-----------------------------------------------------------------------------------------
bool GameLogic::loadGame(const irr::core::stringc& gameName)
{
    //if (gameName=="NewGame")
    //{
    // VBuildInitialScene();
    // safeTriggerEvent( EvtData_New_Game() );
    //}

    return true;
}

//-----------------------------------------------------------------------------------------
void GameLogic::changeState(const qv::S_STATE& newState)
{
//            mState = newState;
}
//-----------------------------------------------------------------------------------------
}
}

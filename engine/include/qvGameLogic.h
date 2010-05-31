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


#ifndef __GAME_LOGIC_H_
#define __GAME_LOGIC_H_

//engine headers
#include "qvActor.h"
#include "qvGameStateTypes.h"


namespace qv
{
struct SGameParams;

class CommandManager;


namespace physics
{
class PhysicsManager;
}

}

namespace qv
{
namespace gaming
{

class _QUANTICVORTEX_API_ GameLogic
{
public:
    GameLogic(qv::SGameParams& gameParams, qv::CommandManager* commandManager);
    /// create GameLogic core object to manage the game and set event manager
    /// and game parameters

    ~GameLogic();

    void addActor( u32 actorHashId);
    /// add new actor to the game


    Actor* getActor( u32 actorHashId)
    /// query a registred actor from game
    {
        ActorsMap::Node* actorNode = mActors.find(actorHashId);
        Actor* actor(0);
        if (actorNode)
            actor = actorNode->getValue();
        return actor;
    }

    void removeActor( u32 actorHashId)
    /// remove actor from the game, like when actor die or destroyed
    {
        Actor* actor = getActor(actorHashId);

        if (actor)
            mActors.delink(actorHashId);
    }

    bool loadGame(const irr::core::stringc& gameName);
    /// load game data, and raise event to inform all subsystems

    void update( u32 currentTimeMs, u32 elapsedTimeMs);
    /// update game data, and game tick

    void changeState( const qv::S_STATE& newState);
    /// change the state of game, like: from menu to running

    void setPause(bool pause);
    /// pause game logic update

    physics::PhysicsManager* getPhysicsManager();
    /// get physics subsystem access

    //void attachProcess(IProcess* process)
    //{
    //	if(mProcessManager)mProcessManager->attach(process);
    //}

    //void detachProcess(IProcess* process){}

private:

    GameLogic(const GameLogic&); // to avoid copy of game logic

    GameLogic& operator = (const GameLogic&); // to avoid copy of game logic

    bool initialize();
    /// initialize game logic data, like: physics susbsystem,
    /// raise initial game state event telling all other subsystem
    /// that game is ready to go

    bool finalize();
    /// finish game logic and all subsystems

    u32 mCurrentGameStateHashId;
    u32 mHumanPlayerAttached;
    bool mPaused;

    qv::gaming::ActorsMap mActors;

    physics::PhysicsManager* mPhysicsManager; // game physics
    qv::CommandManager* mCommandManager; // command manager
    // IProcessManager* mProcessManager;  //game logic AI

    //event args
    //qv::events::GameTickEventArgs* mGameTickEventArgs;
    //SPlayerScore mPlayerScore;
    //list<ActorID*> mAIPlayersAttached;

};


// inlines
inline qv::physics::PhysicsManager* GameLogic::getPhysicsManager()
{
    return mPhysicsManager;
}

inline void qv::gaming::GameLogic::setPause(bool pause)
{
    mPaused = pause;
}

}


}
#endif

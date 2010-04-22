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


#ifndef __DEFAULT_GAME_LOGIC_H_
#define __DEFAULT_GAME_LOGIC_H_

//system headers
#include <vector>

//engine headers
#include "qvAbstractGameView.h"
#include "qvActor.h"
#include "qvIGameState.h"
#include "qvIProcess.h"

//#include "qvIGameView.h"
//#include "qvIGameViewFactory.h"
#include "qvIProcessManager.h"

//external headers
#include "irrMap.h"

namespace qv
{
    class IEngineManager;

namespace views
{
    class IGameViewFactory;
}

namespace physics
{
    class IPhysicsManager;
}

}

namespace qv
{
namespace gaming
{

class _QUANTICVORTEX_API_ GameLogic
{
public:
    GameLogic(IEngineManager* engineManager);
    /// create GameLogic core object to manage the game

    ~GameLogic();

    bool initialize();
    /// initialize game logic data, like: physics susbsystem,
    /// raise initial game state event telling all other subsystem
    /// that game is ready to go

    bool finalize();
    /// finish game logic and all subsystems

    void addActor( u32 actorHashId);
    /// add new actor to the game

    Actor* getActor( u32 actorHashId)
    /// query a registred actor from game
    {
//				ActorsMap::Node* actor = mActors.find(actorHashId);
        Actor* actorFounded(0);
//				if(actor)
//					actorFounded = actor->getValue();
        return actorFounded;
    }

    void removeActor( u32 actorHashId)
    /// remove actor from the game, like when actor die or destroyed
    {
        Actor* actor = getActor(actorHashId);

        if(actor)
        {
//					actor->drop();
//					mActors.delink(actorID.Hash);
        }
    }

    bool loadGame(const irr::core::stringc& gameName);
    /// load game data, and raise event to inform all subsystems

    void update( u32 currentTimeMs, u32 elapsedTimeMs);
    /// update game data, and game tick

    void changeState( const S_STATE* newState);
    /// change the state of game, like: from menu to running

    const views::GameViewsArray& getGameViews() const;
    /// game views collections, all views must be registred on game
    /// logic to be used on game, ex: HumanView, NetworkView.

    views::AbstractGameView* addView(const c8* viewName, u32 viewHashType, u32 actorHashId = 0);
    /// create and add game view to game logic.

    void removeView(views::AbstractGameView* gameView);
    /// remove view from game logic views collection

    physics::IPhysicsManager* getPhysicsManager();
    /// get physics subsystem access

    events::IEventManager* getEventManager();
    /// get event manager access

    //IEventListener* getEventListener(){return mEventListener;}

    //void attachProcess(IProcess* process)
    //{
    //	if(mProcessManager)mProcessManager->attach(process);
    //}

    //void detachProcess(IProcess* process){}


private:

    GameLogic(const GameLogic&);
    GameLogic& operator = (const GameLogic&);


    u32 mCurrentGameStateHashId;
    u32 mHumanPlayerAttached;

    ActorsMap mActors;
    views::GameViewsArray   mGameViews;

    physics::IPhysicsManager* mPhysicsManager;
    events::IEventManager* mEventManager;
    // IProcessManager* mProcessManager;  //game logic AI

    //SPlayerScore mPlayerScore;
    //list<ActorID*> mAIPlayersAttached;

};


// inlines
inline physics::IPhysicsManager* GameLogic::getPhysicsManager()
{
    return mPhysicsManager;
}

inline events::IEventManager* GameLogic::getEventManager()
{
    return mEventManager;
}

inline const views::GameViewsArray& GameLogic::getGameViews() const
{
    return mGameViews;
}


}


}
#endif


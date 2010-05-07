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


#ifndef __GAME_H_
#define __GAME_H_

#include "qvCompileConfig.h"
#include "qvSGameParams.h"
#include "qvTypes.h"

// external classes
#include "LinearMath/btQuickprof.h"  // bullet timer

namespace qv
{
    class ICommand;
    
namespace events
{
    class EventManager;
}
namespace gaming
{
    class GameLogic;
}

}

// external classes declarations
namespace Poco
{
namespace Util
{
    class OptionProcessor;
}
}

namespace qv
{

class _QUANTICVORTEX_API_ Game
    /// engine core object, this work on lowest level and provide a 
    /// generic loop for global service like: EventManager, GameLogic
{

public:
    Game();
    virtual ~Game();

    s32 run( s32 argc, c8* argv[]);
    /// called by user to start main loop of the game.

    qv::gaming::GameLogic* getGameLogic();
    /// all game data, views, physics, actor storage here.

    qv::events::EventManager* getEventManager();
    /// all global events are processed here

    qv::SGameParams& getGameParameters();
    /// game global configuration options, menu interface can 
    /// change this values
    
    void setQuit(bool quit);
    /// quit from engine main loop if true
    

protected:

    virtual void loadConfiguration();
    /// load configuration from file, include saved game

    virtual void registerGameEvents();
    /// register event that will be used in all over the engine
    
    virtual void addCommand(qv::ICommand* command);
    /// register event commands

    qv::SGameParams mParams; // parameters for game
    Poco::Util::OptionProcessor* mOptions; // options from command
    
private:
    Game (const Game&);
    Game& operator = (const Game&);
    
    bool initialize();
    /// real method taht will start the engine, this it will 
    /// called inside constructor

    void finalize();
    /// this method is analog to the initialize, and will be called 
    /// in destructor to make a shutdown and cleanup before quit

    void update( u32 currentTimeMs, u32 elapsedTimeMs);
    /// will called every global engine tick and pass current 
    /// system time to GameLogic, EventManager

    void render( u32 currentTimeMs, u32 elapsedTimeMs);
    /// render content of views registred in GameLogic
    
    bool mQuit; /// quit of engine loop if is true
    btClock mClock; /// current system time provider
    qv::SGameParams mGameParams; /// engine, render paramaters
    qv::gaming::GameLogic* mGameLogic; /// game core object updated on engine loop
    qv::events::EventManager* mEventManager; /// global event manager
    
};

//inlines
inline qv::gaming::GameLogic* Game::getGameLogic()
{
    return mGameLogic;
}

inline qv::events::EventManager* Game::getEventManager()
{
    return mEventManager;
}

inline qv::SGameParams& Game::getGameParameters() 
{
    return mGameParams;
}

inline void Game::setQuit(bool quit) 
{ 
    mQuit = quit;
}

}

#endif


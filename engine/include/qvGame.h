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

#include <algorithm>

#include "qvCompileConfig.h"
#include "qvAbstractGameView.h"
#include "qvSGameParams.h"


#include "qvRAIIFactoryImp.h"

namespace qv
{

class CommandManager;

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

struct SortGameViewsLess
{
    bool operator()(qv::views::AbstractGameView* a, qv::views::AbstractGameView* b) const
    {
        return (a->getOrder() < b->getOrder());
    }
};

class _QUANTICVORTEX_API_ Game
            /// engine core object, this work on lowest level and provide a
            /// generic loop for global service like: EventManager, GameLogic
{

public:
    Game();
    virtual ~Game();

    s32 run(s32 argc, c8* argv[]);
    /// called by user to start main loop of the game.

    qv::gaming::GameLogic* getGameLogic();
    /// all game data, views, physics, actor storage here.

    qv::CommandManager* getCommandManager();
    /// all global events are processed here

    qv::SGameParams& getGameParameters();
    /// game global configuration options, menu interface can
    /// change this values

    void setQuit(bool quit);
    /// quit from engine main loop if true

    const qv::views::GameViewsArray& getGameViews() const;
    /// game views collections, all views must be registred on game
    /// logic to be used on game, ex: HumanView, NetworkView.

    template <class T> qv::views::AbstractGameView* addGameView( const qv::c8* gameViewName, qv::u8 viewOrder, const qv::views::GVT_GAME_VIEW_TYPE& gameViewType)
        /// create command for a command args type.
    {
        qv::views::AbstractGameView* gameView = mGameViewsFactory.keep(new T(gameViewName, viewOrder, gameViewType));

//        if(mGameViews.empty())
//        {
            mGameViews.push_back(gameView);
            std::sort(mGameViews.begin(), mGameViews.end(), SortGameViewsLess());
//        }
//        else
//        {
//            qv::views::GameViewsList itrViews = mGameViews.begin();
//            
//            for(;itrViews != mgameViews.end(); itrViews++)
//            {
//                if( (*itrViews)->getOrder() > gameView->getOrder())
//                {
//                    mGameViews.push_front(gameView);
//                    break;
//                }
//            }
//        }
        
        return gameView;
    }
    
    void removeGameView(qv::views::AbstractGameView* gameView)
    /// remvoe a game view from game views collection and delete from memory
    {
        for( qv::views::GameViewsArray::iterator itr = mGameViews.begin(); itr != mGameViews.end(); itr++)
        {
            if((*itr)->getId().Hash == gameView->getId().Hash)
            {
                mGameViews.erase(itr);
                mGameViewsFactory.dispose(gameView);
                break;
            }
        }
    }

protected:

    virtual void loadConfiguration();
    /// load configuration from file, include saved game

    void configFromCommandLine( s32 argc, c8* argv[]);
    /// override config file options with commandline options
    /// options passed by command line, will not be persisted
    /// to config file

    virtual void registerGameEvents();
    /// register event that will be used in all over the engine

//    virtual void addCommand(qv::ICommand* command);
    /// register event commands

    qv::SGameParams mParams; // parameters for game
//    Poco::Util::OptionProcessor* mOptions; // options from command

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
    qv::SGameParams mGameParams; /// engine, render paramaters
    qv::gaming::GameLogic* mGameLogic; /// game core object updated on engine loop
    qv::CommandManager* mCommandManager; /// global event manager
    qv::views::GameViewsArray  mGameViews;
    RaiiFactoryImp<qv::views::AbstractGameView> mGameViewsFactory;

};


//inlines
inline qv::gaming::GameLogic* Game::getGameLogic()
{
    return mGameLogic;
}

inline qv::CommandManager* Game::getCommandManager()
{
    return mCommandManager;
}

inline qv::SGameParams& Game::getGameParameters()
{
    return mGameParams;
}

inline const qv::views::GameViewsArray& Game::getGameViews() const
{
    return mGameViews;
}

inline void Game::setQuit(bool quit)
{
    mQuit = quit;
}

}

#endif

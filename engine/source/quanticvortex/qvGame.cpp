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


#include "qvGame.h"

#include <vector>
#include <algorithm>

#include "irrlicht.h"

// external classes
#include "LinearMath/btQuickprof.h"  // bullet timer

#include "qvGetopt.h"


// engine headers
#include "qvCommandManager.h"
#include "qvGameLogic.h"
#include "qvInputReceiver.h"

#include "qvHumanView.h"

// game command args
#include "qvLoadGameCommandArgs.h"
#include "qvConfigureContentCommandArgs.h"

//game command
#include "qvLoadGameCommand.h"

//game command types
#include "qvGameCommandTypes.h"


namespace qv
{

Game::Game()
        : mQuit(false)
{
    if (!initialize())
        mQuit = true;
}

Game::~Game()
{
    finalize();
}
//-----------------------------------------------------------------------------
bool Game::initialize()
{
    //pre allocate 5 slots for views
    mGameViews.reserve(5);

    loadConfiguration(); // load default configuration files, if present

    mCommandManager = new qv::CommandManager();
    mGameLogic = new qv::gaming::GameLogic(mGameParams, mCommandManager);

    addCommandType(qv::gaming::CT_GAME_LOAD);
//    mCommandManager->createCommand<qv::gaming::LoadGameCommand>("load_game", qv::gaming::CT_GAME_LOAD);

    irr::SIrrlichtCreationParameters parameters;

    parameters.Bits = mGameParams.Bits;
    parameters.DriverType = irr::video::EDT_OPENGL;
    parameters.Stencilbuffer = true;
    parameters.WindowSize = mGameParams.WindowSize;
    parameters.Fullscreen = mGameParams.Fullscreen;

    mDevice3d = irr::createDeviceEx(parameters);

    // maybe each one raise next state
    // initialize game logic - here game logic will get parâmeters configure internal things like: physics, sound, actor managment
    // loading resources - maybe preloading something musics and textures
    // menu - show menu to user choose options
    // waiting for players - check Players attached to game logic, if enogh, if not attach local player as humam view
    // running - start run


    return true;
}
//-----------------------------------------------------------------------------
void Game::finalize()
{
    if (mGameLogic)
        delete mGameLogic;

    mGameViews.clear();

    if (mCommandManager)
        delete mCommandManager;
}
//-----------------------------------------------------------------------------
qv::views::HumanView* Game::addHumanView(const qv::c8* gameViewName)
{
    qv::views::AbstractGameView* gameView = mGameViewsFactory.keep(new qv::views::HumanView(gameViewName, mCommandManager, mDevice3d ));

    mGameViews.push_back(gameView);

    if (mGameViews.size() > 1)
        std::sort(mGameViews.begin(), mGameViews.end(), SortGameViewsLess());

    return static_cast<qv::views::HumanView*>(gameView);
}
//-----------------------------------------------------------------------------
void Game::load( const qv::c8* gamePath, const qv::c8* gameFile)
{
    qv::CommandArgs* args = mCommandManager->createCommandArgs<qv::LoadGameCommandArgs>(qv::gaming::CT_GAME_LOAD);

    static_cast<qv::LoadGameCommandArgs*>(args)->setGameFile(gameFile);
    static_cast<qv::LoadGameCommandArgs*>(args)->setGamePath(gamePath);

    mCommandManager->executeCommand(args);
}
//-----------------------------------------------------------------------------
void Game::addCommandType(const qv::CT_COMMAND_TYPE& commandType)
{
    mCommandManager->registerCommandType(commandType);
}
//-----------------------------------------------------------------------------
void Game::loadConfiguration()
{
    //load strings
    //load language
    //load key-action mappings

    //configure game application
    mGameParams.Bits = 32;
    mGameParams.Fullscreen = false;
    mGameParams.LocalPlayers = 1;
    mGameParams.HostGame = true;
    mGameParams.Title = "Default Game Window";
    mGameParams.WindowSize = irr::core::dimension2di(1024, 768);

}
//-----------------------------------------------------------------------------
void Game::parseCommandLine( int argc, const char** argv)
{
    int c;

    while ((c = getopt( argc, argv, "s:a:")) != EOF)
    {
//        switch (c)
//        {
//        case 'i':
//            m_sceneFileName = optarg;
//            break;
//        case 'a':
//            sceneDirectory = optarg;
//            folderArchives.push_back(optarg);
//            break;
//        }
    }
}
//-----------------------------------------------------------------------------
void Game::update( u32 currentTimeMs, u32 elapsedTimeMs)
{
    mCommandManager->executeCommands();

    if (mGameLogic)
        mGameLogic->update(currentTimeMs, elapsedTimeMs);

    //update views after game logic update
    for (u32 i = 0; i < mGameViews.size(); i++)
        mGameViews.at(i)->update( elapsedTimeMs);
}
//-----------------------------------------------------------------------------
void Game::render( u32 currentTimeMs, u32 elapsedTimeMs)
{
    for (u32 i = 0; i < mGameViews.size(); i++)
        mGameViews.at(i)->render(currentTimeMs, elapsedTimeMs);
}
//-----------------------------------------------------------------------------
s32 Game::run(int argc, const char** argv)
{
    // - process commandline params, this shoud override file config value
    // just in SGameParams not in real config file
    parseCommandLine( argc, argv);

    mInputReceiver = new qv::input::InputReceiver();

    btClock clock;
    clock.reset();

    u32 lastTimeMs =  clock.getTimeMilliseconds();
    u32 curentTimeMs = lastTimeMs;

    while (!mQuit)
    {
        if ( mDevice3d->run())
        {
            curentTimeMs = clock.getTimeMilliseconds();
            u32 elapsedTimeMs = curentTimeMs - lastTimeMs;

            //game application update with current and
            //elapsed time from last application update
            update( curentTimeMs, elapsedTimeMs);

            mDevice3d->getVideoDriver()->beginScene(true, true); //call some beginRender from engine

            render( curentTimeMs, elapsedTimeMs);
            //game views rendering update with current and
            //elapsed time from last application tick

            mDevice3d->getVideoDriver()->endScene(); //call some endRender from engine

            lastTimeMs = curentTimeMs; //update last time
        }
    }

    return 0;
}

}

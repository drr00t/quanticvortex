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

// engine headers
#include "qvCommandManager.h"
#include "qvGameLogic.h"
#include "qvHumanView.h"

//external headers
#include "Poco/Util/Option.h"
#include "Poco/Util/OptionSet.h"
#include "Poco/Util/OptionProcessor.h"

// external classes
#include "LinearMath/btQuickprof.h"  // bullet timer


namespace qv
{

Game::Game()
        : mQuit(false)
{

    /*
    //    Poco::Util::OptionSet set;
    //    set.addOption(
    //    	Poco::Util::Option("bits", "bpp")
    //    	.description("bits per pixel of the color buffer. default: 16")
    //    	.required(false)
    //    	.repeatable(false)
    //        .argument("value"));
    //
    //    set.addOption(
    //    	Poco::Util::Option("windowsize", "ws")
    //    	.description("window size. default: 1024x768")
    //    	.required(false)
    //    	.repeatable(false)
    //        .argument("value"));
    //
    //    set.addOption(
    //    	Poco::Util::Option("vsync", "sync")
    //    	.description("vertical sync. default: false")
    //    	.required(false)
    //    	.repeatable(false)
    //        .argument("value"));
    //
    //    set.addOption(
    //    	Poco::Util::Option("scene", "s")
    //    	.description("can load a scene file directly.")
    //    	.required(false)
    //    	.repeatable(false)
    //        .argument("value"));
    //
    //    mOptions = new Poco::Util::OptionProcessor(set);
    */

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

    //registring engine events
    registerGameEvents();

    // registry my command here, like:
//        - QuitCommand
//        - ConfigurationLoaded
//        - ConfigurationChanged

    //raised engine initialized event
    // mEventManager->trigger(EngineInitializedEventArgs);

    // maybe each one raise next state
    // initialize game logic - here game logic will get parâmeters configure internal things like: physics, sound, actor managment
    // loading resources - maybe preloading something musics and textures
    // menu - show menu to user choose options
    // waiting for players - check Players attached to game logic, if enogh, if not attach local player as humam view
    // running - start run


    return true;
}
//-----------------------------------------------------------------------------
void Game::registerGameEvents()
{

}
//-----------------------------------------------------------------------------
//void Game::addCommand(qv::ICommand* command)
//{
//    mEventManager->addCommand(command);
//}
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
void Game::configFromCommandLine( s32 argc, c8* argv[])
{

}
//-----------------------------------------------------------------------------
void Game::finalize()
{
    //remove all views
    for (u32 i = 0; i < mGameViews.size(); ++i)
        delete mGameViews[i];

    mGameViews.clear();

    if (mGameLogic)
        delete mGameLogic;

    if (mCommandManager)
        delete mCommandManager;
}
//-----------------------------------------------------------------------------
void Game::update( u32 currentTimeMs, u32 elapsedTimeMs)
{
    mCommandManager->executeCommands();

    if (mGameLogic)
        mGameLogic->update(currentTimeMs, elapsedTimeMs);

    //update views after game logic update
    for (u32 i = 0; i < mGameViews.size(); i++)
        mGameViews[i]->update( elapsedTimeMs);
}
//-----------------------------------------------------------------------------
void Game::render( u32 currentTimeMs, u32 elapsedTimeMs)
{
    for (u32 i = 0; i < mGameViews.size(); i++)
        mGameViews[i]->render(currentTimeMs, elapsedTimeMs);
}
//-----------------------------------------------------------------------------
s32 Game::run(s32 argc, c8* argv[])
{
    // - process commandline params, this shoud override file config value
    // just in SGameParams not in real config file
    configFromCommandLine( argc, argv);

    // put game logic in initialization state, there several state pre-difined, how:
    //    - qv::events::EET_GAME_LOGIC_INITIALIZATING
    //    - qv::events::EET_GAME_LOGIC_MENU
    //    - qv::events::EET_GAME_LOGIC_LOADING
    //    - qv::events::EET_GAME_LOGIC_WAITING_PLAYER
    //    - qv::events::EET_GAME_LOGIC_RUNNING

    // In order to do framerate independent movement, we have to know
    // how long it was since the last frame
    btClock clock;
    clock.reset();
    u32 lastTimeMs =  clock.getTimeMilliseconds();
    u32 curentTimeMs = lastTimeMs;

    while (!mQuit)
    {

        // Work out a frame delta time.
        curentTimeMs = clock.getTimeMilliseconds();
        u32 elapsedTimeMs = curentTimeMs - lastTimeMs;

        //game application update with current and
        //elapsed time from last application update
        update( curentTimeMs, elapsedTimeMs);

        //game views rendering update with current and
        //elapsed time from last application tick
        render( curentTimeMs, elapsedTimeMs);

        //update last time
        lastTimeMs = curentTimeMs;
    }

    return 0;
}

/*
//change resolution in runtime

//bool resize = false, stop = false;
//int width = 640, height = 480, bpp = 16;
//
//class Receiver : public IEventReceiver
//{
//protected:
//   virtual bool OnEvent (const SEvent& event);
//};
//
//bool Receiver::OnEvent (const SEvent& event)
//{
//   if (event.EventType == EET_KEY_INPUT_EVENT)
//   {
//      if (event.KeyInput.Key == KEY_ESCAPE && event.KeyInput.PressedDown)
//      {
//         stop = true;
//         return true;
//      }
//      else if (event.KeyInput.Key == KEY_SPACE && event.KeyInput.PressedDown)
//      {
//         width = 800, height = 600, bpp = 32;
//         resize = true;
//         return true;
//      }
//   }
//
//   return false;
//}
//
//int main (void)
//{
//   Receiver* receiver = NULL;
//
//   while (!stop)
//   {
//      IrrlichtDevice* device = createDevice (EDT_OPENGL, dimension2d<s32>(width, height), bpp, false, false, false, NULL);
//
//      if (!device)
//         return 0;
//
//      IVideoDriver* driver = device->getVideoDriver();
//      ISceneManager* smgr = device->getSceneManager();
//
//      receiver = new Receiver;
//
//      device->setEventReceiver(receiver);
//
//      while (device->run() && !resize)
//      {
//         driver->beginScene(true, true, SColor(255,100,101,140));
//         smgr->drawAll();
//         driver->endScene();
//      }
//
//      resize = false;
//
//      if (receiver)
//      {
//         delete receiver;
//         receiver = NULL;
//      }
//
//      if (device)
//      {
//         device->closeDevice();
//         device->run(); // Very important to do this here!
//         device->drop();
//      }
//    }
*/
}

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

//managers
#include "qvEventManager.h"
#include "qvEngineManager.h"
#include "qvActorManager.h"

#include "qvGameLogic.h"

#include "irrlicht.h"
//Irrlicht input receiver implementation
#include "drivers/irrlicht/qvInputEventHandlerIrrlicht.h"


namespace qv
{
    //-----------------------------------------------------------------------------
    EngineManager::EngineManager()
    :mQuit(false),mHasPopup(false),_helpRequested(false)
    {
        if(!initialize())
            mQuit = true;
    }
    //-----------------------------------------------------------------------------
    EngineManager::~EngineManager()
    {
		finalize();
    }
    //-----------------------------------------------------------------------------
    void EngineManager::registerGameEvents()
    {
    	//if (!mEventManager )
    	//	return;

		//game application events...
        //mEventManager->registerEventType(ET_GRAPHICS_STARTED);
        //mEventManager->registerEventType(&ET_GRAPHICS_STOPPED);
        //
        //mEventManager->registerEventType(&ET_EVENT_SYSTEM_STARTED);
        //mEventManager->registerEventType(&ET_EVENT_SYSTEM_STOPPED);
        //
        //mEventManager->registerEventType(&ET_HUMAN_VIEW_ATTACHED);
        //mEventManager->registerEventType(&ET_HUMAN_VIEW_DETACHED);
        //
        //mEventManager->registerEventType(&ET_GAME_LOGIC_STARTED);
        //mEventManager->registerEventType(&ET_GAME_LOGIC_STOPPED);
        //mEventManager->registerEventType(&ET_GAME_LOGIC_TICK_UPDATE);
        //
		mEventManager->registerEventType(qv::events::ET_GAME_QUIT.Hash);
		mEventManager->registerEventType(qv::events::ET_GAME_SAVE.Hash);
		mEventManager->registerEventType(qv::events::ET_GAME_OPTIONS.Hash);
		mEventManager->registerEventType(qv::events::ET_GAME_LOAD.Hash);
        mEventManager->registerEventType(qv::events::ET_GAME_NEW.Hash);
        //
        //mEventManager->registerEventType(&ET_PHYSICS_STARTED);
        //mEventManager->registerEventType(&ET_PHYSICS_STOPPED);

        //mEventManager->registerEventType(&ET_ACTOR_CREATED);
        //mEventManager->registerEventType(&ET_ACTOR_DESTROYED);
        //mEventManager->registerEventType(&ET_ACTOR_MOVE);
        //mEventManager->registerEventType(&ET_ACTOR_COLLIDE);
        //
        //mEventManager->registerEventType(&ET_ACTOR_PLAYER_DIE);
        //mEventManager->registerEventType(&ET_ACTOR_PLAYER_JUMP);
        //mEventManager->registerEventType(&ET_ACTOR_PLAYER_MOVE);
        //mEventManager->registerEventType(&ET_ACTOR_PLAYER_NEW);
        //mEventManager->registerEventType(&ET_ACTOR_PLAYER_TURN);
        //mEventManager->registerEventType(&ET_ACTOR_PLAYER_COLLIDE);

    }
    //-----------------------------------------------------------------------------
    void EngineManager::loadConfiguration()
    {
        //load strings
        //load language
        //load key-action mappings
        
        //configure game application
        mGameParams.Bits = 32;
        mGameParams.Fullscreen = false;
        mGameParams.LocalPlayers = 1;
        mGameParams.HostGame = true;
        mGameParams.Title = "Default game Window";
        mGameParams.WindowSize = irr::core::dimension2di(1024,768);
        
    }
    //-----------------------------------------------------------------------------
	bool EngineManager::initialize()
    {
        mClock.reset();

        loadConfiguration(); // load default configuration files, if present

		irr::SIrrlichtCreationParameters parameters;

        parameters.Bits = mGameParams.Bits;
		parameters.DriverType = irr::video::EDT_OPENGL;
		parameters.Stencilbuffer = true;
        parameters.WindowSize = mGameParams.WindowSize;
        parameters.Fullscreen = mGameParams.Fullscreen;

        mDevice3d = irr::createDeviceEx(parameters);

		mEventManager = new events::EventManager();

        //registring engine events
		registerGameEvents();
        
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
	void EngineManager::finalize()
    {
        if(mGameLogic)
            delete mGameLogic;
        
        if(mEventManager)
            delete mEventManager;
            
        //render system
        mDevice3d->drop();
	}
	//-----------------------------------------------------------------------------
    void EngineManager::update( u32 currentTimeMs, u32 elapsedTimeMs)
    {
        if (mGameLogic)
	    {
            mEventManager->process(GC_GAME_FRAMERATE);

            mGameLogic->update(currentTimeMs, elapsedTimeMs);
	    }
    }
    //-----------------------------------------------------------------------------
    void EngineManager::render( u32 currentTimeMs, u32 elapsedTimeMs)
    {
//        const views::GameViewArray gameViews = mGameLogic->getGameViews();
//        for(u32 i = 0; i < gameViews.size(); ++i)
//            gameViews[i]->render(currentTimeMs, elapsedTimeMs);
    }
	//-----------------------------------------------------------------------------
    void EngineManager::beginRender(bool backBuffer, bool zBuffer)
    {
		mDevice3d->getVideoDriver()->beginScene(backBuffer, zBuffer);
    }
	//-----------------------------------------------------------------------------
    void EngineManager::endRender()
    {
		mDevice3d->getVideoDriver()->endScene();
    }
    //-----------------------------------------------------------------------------
    s32 EngineManager::run()
    {
        if (!_helpRequested)
        {
	        s32 lastFPS = -1;

			// In order to do framerate independent movement, we have to know
            // how long it was since the last frame
            u32 lastTimeMs =  mClock.getTimeMilliseconds();
            u32 curentTimeMs = lastTimeMs;
	        while(!mQuit)
            {
                // Work out a frame delta time.
                u32 curentTimeMs = mClock.getTimeMilliseconds();
                u32 elapsedTimeMs = (curentTimeMs - lastTimeMs); // Time in miliseconds

				lastTimeMs = curentTimeMs;

				if(elapsedTimeMs > 16)
					elapsedTimeMs = 16;

	            //if (mDevice3d->isWindowActive())
	            //{
					//game application update
					update( curentTimeMs, elapsedTimeMs);

                    //game application render
                    render( curentTimeMs, elapsedTimeMs);

					lastTimeMs = curentTimeMs;

					s32 fps = mDevice3d->getVideoDriver()->getFPS();

		            if (lastFPS != fps)
		            {
                        irr::core::stringw str = mGameParams.Title;
                        str.append(L" - QuanticVortex Engine [");
			            str.append(mDevice3d->getVideoDriver()->getName());
			            str.append("] FPS:");
			            str.append(fps);
			            str.append(" Triangles:");
						str.append(mDevice3d->getVideoDriver()->getPrimitiveCountDrawn());

                        mDevice3d->setWindowCaption(str.c_str());
                        
			            lastFPS = fps;
		            }
                //}
                //else
                //{
                    //mDevice3d->yield();
                //}
            }

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
//   }
        }

        return 0;
    }

}

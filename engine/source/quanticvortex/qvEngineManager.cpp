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
#include "qvEngineManager.h"
#include "qvEventManager.h"
//#include "qvInputReceiver.h"
#include "qvIrrEventHandler.h"

//factories
#include "qvGameLogicFactory.h"


namespace qv
{
    //-----------------------------------------------------------------------------
    EngineManager::EngineManager()
    {
#ifdef _DEBUG
		setDebugName("EngineManager");
#endif
		mGameParams.Bits = 16;
        mGameParams.Fullscreen = false;
        mGameParams.LocalPlayers = 1;
        mGameParams.Title = L"Default game Window";
        mGameParams.WindowSize = dimension2di(1024,768);
    }
    //-----------------------------------------------------------------------------
    EngineManager::EngineManager(const SGameParams& params):_helpRequested(false), 
        mDevice3d(0), mVideoDriver(0), mSceneManager(0), mInputReceiver(0), mQuit(false),
        mHasPopup(false), mEventManager(0), mFileSystem(0), mGameLogic(0),mWindowHandle(0)
        //mInputManager(0)
    {

#ifdef _DEBUG
		setDebugName("EngineManager");
#endif

		mGameParams = params;
    }
    //----------------------------------------------------------------------------- 	
    EngineManager::~EngineManager()
    {
        mGameLogic->drop();
        //mEventManager->drop();
        mDevice3d->drop();

        for(u32 i = 0; i < mGameLogicFactories.size(); ++i)
            mGameLogicFactories[i]->drop();

    }
    //-----------------------------------------------------------------------------
    void EngineManager::registerGameEvents()
    {
    	if (!mEventManager )
    		return;

		//game application events...
        mEventManager->registerEventType(ET_GRAPHICS_STARTED);
        mEventManager->registerEventType(ET_GRAPHICS_STOPPED);
        
        mEventManager->registerEventType(ET_EVENT_SYSTEM_STARTED);
        mEventManager->registerEventType(ET_EVENT_SYSTEM_STOPPED);
        
        mEventManager->registerEventType(ET_HUMAN_VIEW_ATTACHED);
        mEventManager->registerEventType(ET_HUMAN_VIEW_DETACHED);
        
        mEventManager->registerEventType(ET_GAME_LOGIC_STARTED);
        mEventManager->registerEventType(ET_GAME_LOGIC_STOPPED);
        mEventManager->registerEventType(ET_GAME_LOGIC_TICK_UPDATE);
        
        mEventManager->registerEventType(ET_GAME_LOAD);
        mEventManager->registerEventType(ET_GAME_NEW);
        
        mEventManager->registerEventType(ET_PHYSICS_STARTED);
        mEventManager->registerEventType(ET_PHYSICS_STOPPED);

        mEventManager->registerEventType(ET_ACTOR_CREATED);
        mEventManager->registerEventType(ET_ACTOR_DESTROYED);
        mEventManager->registerEventType(ET_ACTOR_MOVE);
        mEventManager->registerEventType(ET_ACTOR_COLLIDE);
        
        mEventManager->registerEventType(ET_ACTOR_PLAYER_DIE);
        mEventManager->registerEventType(ET_ACTOR_PLAYER_JUMP);
        mEventManager->registerEventType(ET_ACTOR_PLAYER_MOVE);
        mEventManager->registerEventType(ET_ACTOR_PLAYER_NEW);
        mEventManager->registerEventType(ET_ACTOR_PLAYER_TURN);
        mEventManager->registerEventType(ET_ACTOR_PLAYER_COLLIDE);

    }
    //-----------------------------------------------------------------------------
	void EngineManager::registerGameLogicFactory(gaming::IGameLogicFactory *factory)
    {
        factory->grab();
        mGameLogicFactories.push_back(factory);
    }
    //-----------------------------------------------------------------------------
	gaming::IGameLogic* EngineManager::addGameLogic(const gaming::GLT_GAME_LOGIC_TYPE& type)
    {
        for(u32 i = 0; i < mGameLogicFactories.size(); ++i)
		{
			if(mGameLogicFactories[i]->getCreateableGameLogicType(type))
			{
                mGameLogic = mGameLogicFactories[i]->addGameLogic(type);
				break;
			}
		}

        return mGameLogic;
    }
    //-----------------------------------------------------------------------------
    void EngineManager::loadConfiguration()
    {
        //load strings
        //load language
        //load key-action mappings
        //configure game application
    }
    //-----------------------------------------------------------------------------
	bool EngineManager::initialize()
    {
        loadConfiguration(); // load default configuration files, if present
		
		//mInputReceiver = new InputReceiver(this);

        SIrrlichtCreationParameters parameters;

        parameters.Bits = mGameParams.Bits;
		parameters.DriverType = EDT_OPENGL;
		parameters.Stencilbuffer = true;
        parameters.WindowSize = mGameParams.WindowSize;
        parameters.Fullscreen = mGameParams.Fullscreen;
		//parameters.EventReceiver = mInputReceiver;

        mDevice3d = createDeviceEx(parameters);
        
		gaming::IGameLogicFactory* factory = new gaming::GameLogicFactory(this);
        registerGameLogicFactory(factory);
        factory->drop();

        mEventManager = new EventManager();
		
		registerGameEvents();

        mVideoDriver = mDevice3d->getVideoDriver();

		mInputReceiver = new input::IrrEventHandler();
        mDevice3d->setEventReceiver(mInputReceiver);

        if(parameters.DriverType == EDT_OPENGL)
            mWindowHandle = (size_t)mVideoDriver->getExposedVideoData().OpenGLWin32.HWnd;

        else if(parameters.DriverType == EDT_DIRECT3D9)
            mWindowHandle = (size_t)mVideoDriver->getExposedVideoData().D3D9.HWnd;

        mSceneManager = mDevice3d->getSceneManager();
        
        mFileSystem = mDevice3d->getFileSystem();

        return true;
    }
	//-----------------------------------------------------------------------------
    void EngineManager::update( u32 currentTimeMs, u32 elapsedTimeMs)
    {
        if (mHasPopup)
		    return;

        if (mGameLogic)
	    {
            mEventManager->process(GF_GAME_LOGIC_FRAMERATE);

            mGameLogic->update(currentTimeMs, elapsedTimeMs);
	    }
    }
    //-----------------------------------------------------------------------------
    void EngineManager::render( u32 currentTimeMs, u32 elapsedTimeMs)
    {
        for(u32 i = 0; i < mGameLogic->getGameViews().size(); ++i)
            mGameLogic->getGameViews()[i]->render(currentTimeMs, elapsedTimeMs);
    }
    //-----------------------------------------------------------------------------
    s32 EngineManager::run()
    {
        if (!_helpRequested)
        {
            mDevice3d->getTimer()->getTime();

	        s32 lastFPS = -1;
            
			// In order to do framerate independent movement, we have to know
            // how long it was since the last frame
            u32 lastTimeMs = mDevice3d->getTimer()->getTime();

	        while(mDevice3d->run() && !mQuit)
            {
                // Work out a frame delta time.
                const u32 curentTimeMs = mDevice3d->getTimer()->getTime();
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

					s32 fps = mVideoDriver->getFPS();

		            if (lastFPS != fps)
		            {
                        stringw str = mGameParams.Title + L" - QuanticVortex Engine [";
			            str += mVideoDriver->getName();
			            str += "] FPS:";
			            str += fps;
			            str += " Triangles:";
						str += mVideoDriver->getPrimitiveCountDrawn();

                        mDevice3d->setWindowCaption(str.c_str());
			            lastFPS = fps;
		            }

					//if(elapsedTimeMs > 16)
					//{
					//	mDevice3d->sleep((elapsedTimeMs - 16));
					//}
					//else if(elapsedTimeMs > 16)
					//{
					//	mDevice3d->sleep((16 - elapsedTimeMs));
					//}

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

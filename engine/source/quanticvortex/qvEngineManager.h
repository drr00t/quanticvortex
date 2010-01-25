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


#ifndef __ENGINE_MANAGER_H_
#define __ENGINE_MANAGER_H_

#include "qvIEngineManager.h" 

//#include "IrrlichtDevice.h"
//#include "IVideoDriver.h"
//#include "ITimer.h"

namespace qv
{    
	
	class EngineManager : public IEngineManager
    {

    private:
        bool _helpRequested;
        bool mHasPopup;
		bool mQuit;

    protected:
		SGameParams mGameParams;

		array<gaming::IGameLogicFactory*> mGameLogicFactories;

        gaming::IGameLogic* mGameLogic;
		events::IEventManager* mEventManager;
		input::IInputReceiver* mInputReceiver;
        
		irr::IrrlichtDevice* mDevice3d;
		//irr::video::IVideoDriver* mVideoDriver;
		//irr::scene::ISceneManager* mSceneManager;
		//irr::io::IFileSystem* mFileSystem;
  //      size_t mWindowHandle;

        virtual void loadConfiguration();
 	            
        virtual void registerGameEvents();

        void update( u32 currentTimeMs, u32 elapsedTimeMs);

        void render( u32 currentTimeMs, u32 elapsedTimeMs); 


    public:

		EngineManager();
		EngineManager(const SGameParams& params );
        virtual ~EngineManager();
        
        virtual bool initialize();
		
		virtual void finalize();

 	    virtual s32 run();

		virtual void beginRender(bool backBuffer, bool zBuffer);

		virtual void endRender();

		virtual void registerGameLogicFactory(gaming::IGameLogicFactory* factory);
        
		virtual gaming::IGameLogic* addGameLogic(const gaming::GLT_GAME_LOGIC_TYPE* type);
		
		virtual gaming::IGameLogic* getGameLogic()
        {
            return mGameLogic;
        }
   
		virtual events::IEventManager* getEventManager()
        {
            return mEventManager;
        }

		virtual input::IInputReceiver* getInputReceiver()
        {
            return mInputReceiver;
        }

        virtual SGameParams& getGameParameters()
        {
            return mGameParams;
        }

		//virtual irr::IrrlichtDevice* getDevice()
  //      {
  //          return mDevice3d;
  //      }        

		//virtual irr::io::IFileSystem* getFileSystem()
  //      {
  //          return mFileSystem;
  //      }

		//virtual irr::gui::IGUIEnvironment* getGuiManager()
  //      {
  //          return mDevice3d->getGUIEnvironment();
  //      }

		//virtual irr::scene::ISceneManager* getSceneManager()
  //      {
  //          return mSceneManager;
  //      }

		//virtual irr::video::IVideoDriver* getVideoDriver()
  //      {
  //          return mVideoDriver;
  //      }

  //      virtual size_t getWindowHandle()
  //      {
  //          return mWindowHandle;
  //      }		

		virtual void setQuit(bool quit)
		{
			mQuit = quit;
		}
    };
}

#endif


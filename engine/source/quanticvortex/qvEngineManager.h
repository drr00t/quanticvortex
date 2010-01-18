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


#ifndef __ENGINEMANAGER_H_
#define __ENGINEMANAGER_H_

#include "qvIEngineManager.h" 

namespace qv
{    
	namespace input
	{ 
		class IInputReceiver;
	}

	class EngineManager : public IEngineManager
    {

    private:
        bool _helpRequested;
        bool mHasPopup;

    protected:
		SGameParams mGameParams;

		array<gaming::IGameLogicFactory*> mGameLogicFactories;

        gaming::IGameLogic* mGameLogic;
		gaming::IEventManager* mEventManager;
		input::IInputReceiver* mInputReceiver;
        
        IrrlichtDevice* mDevice3d;
        IVideoDriver* mVideoDriver;
        ISceneManager* mSceneManager;
        IFileSystem* mFileSystem;
        size_t mWindowHandle;
		//IrrEventHandler* mInputReceiver;

        virtual void loadConfiguration();
 	            
        virtual void registerGameEvents();

        void update( u32 currentTimeMs, u32 elapsedTimeMs);

        void render( u32 currentTimeMs, u32 elapsedTimeMs); 


    public:

		EngineManager();
		EngineManager(const SGameParams& params );
        virtual ~EngineManager();
        
		virtual bool initialize();

 	    virtual s32 run();
	       
        virtual void registerGameLogicFactory(gaming::IGameLogicFactory* factory);
        virtual gaming::IGameLogic* addGameLogic(const gaming::GLT_GAME_LOGIC_TYPE& type);

        virtual gaming::IEventManager* getEventManager()
        {
            return mEventManager;
        }

		virtual input::IInputReceiver* getInputReceiver()
        {
            return mInputReceiver;
        }


		virtual gaming::IGameLogic* getGameLogic()
        {
            return mGameLogic;
        }

        virtual SGameParams& getGameParameters()
        {
            return mGameParams;
        }

		//inline IInputManager* getInputManager(){return mInputManager;}

        virtual IrrlichtDevice* getDevice()
        {
            return mDevice3d;
        }        

        virtual IFileSystem* getFileSystem()
        {
            return mFileSystem;
        }

        virtual IGUIEnvironment* getGuiManager()
        {
            return mDevice3d->getGUIEnvironment();
        }

        virtual ISceneManager* getSceneManager()
        {
            return mSceneManager;
        }

        virtual IVideoDriver* getVideoDriver()
        {
            return mVideoDriver;
        }

        virtual size_t getWindowHandle()
        {
            return mWindowHandle;
        }		
    };
}

#endif


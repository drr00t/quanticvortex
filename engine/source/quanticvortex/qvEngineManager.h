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

#include "irrArray.h"

#include "IrrlichtDevice.h"


namespace qv
{

	class EngineManager : public IEngineManager
    {
    public:

		EngineManager();

		EngineManager(const SGameParams& params );

        virtual ~EngineManager();

        virtual bool initialize();

		virtual void finalize();

 	    virtual s32 run();

		virtual void beginRender(bool backBuffer, bool zBuffer);

		virtual void endRender();

        virtual void registerInputReceiverDriverFactory(input::IInputReceiverDriverFactory* factory);

		virtual gaming::IGameLogic* getGameLogic(){return mGameLogic;}

		virtual events::IEventManager* getEventManager(){return mEventManager;}

		virtual input::IInputReceiver* getInputReceiver() { return mInputReceiver;}

        virtual SGameParams& getGameParameters() { return mGameParams;}

		virtual void setQuit(bool quit) { mQuit = quit;}

    protected:
    
		SGameParams mGameParams;

		irr::core::array<input::IInputReceiverDriverFactory*> mInputReceiverDriverFactories;

        gaming::IGameLogic* mGameLogic;
        
		events::IEventManager* mEventManager;

		input::IInputReceiverSharedPtr mInputReceiver;

		irr::IrrlichtDevice* mDevice3d;

        virtual void loadConfiguration();

        virtual void registerGameEvents();

        void update( u32 currentTimeMs, u32 elapsedTimeMs);

        void render( u32 currentTimeMs, u32 elapsedTimeMs);
        
    private:
        bool _helpRequested;
        bool mHasPopup;
		bool mQuit;
		btClock mClock;
    };
}

#endif


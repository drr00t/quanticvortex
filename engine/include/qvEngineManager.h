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

#include "irrArray.h"

#include "IrrlichtDevice.h"

namespace qv
{

    struct SGameParams;

namespace events
{
    class EventManager;
}

namespace input
{
    class InputReceiver;
}

namespace gaming
{
    class GameLogic;
}

}

namespace qv
{

class EngineManager
{
public:

    EngineManager();

    virtual ~EngineManager();

    virtual s32 run();

    virtual gaming::GameLogic* getGameLogic();

    virtual events::EventManager* getEventManager();

    virtual SGameParams& getGameParameters();

protected:

    bool initialize();

    void finalize();

    void loadConfiguration();

    void registerGameEvents();

    void update( u32 currentTimeMs, u32 elapsedTimeMs);

    void render( u32 currentTimeMs, u32 elapsedTimeMs);

    SGameParams mGameParams;

    gaming::GameLogic* mGameLogic;

    events::IEventManager* mEventManager;

    input::IInputReceiverSharedPtr mInputReceiver;

    irr::IrrlichtDevice* mDevice3d;

private:
    bool _helpRequested;
    bool mHasPopup;
    bool mQuit;
    btClock mClock;
};

//inlines
gaming::GameLogic* EngineManager::getGameLogic()
{
    return mGameLogic;
}

events::EventManager* EngineManager::getEventManager()
{
    return mEventManager;
}

SGameParams& EngineManager::getGameParameters() 
{
    return mGameParams;
}

void EngineManager::setQuit(bool quit) 
{ 
    mQuit = quit;
}

}

#endif


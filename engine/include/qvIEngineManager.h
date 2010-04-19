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


#ifndef __I_ENGINE_MANAGER_H_
#define __I_ENGINE_MANAGER_H_

#include "qvIInputReceiverDriverFactory.h"
#include "qvSGameParams.h"

namespace qv
{

	struct SGameParams;

    namespace events
    {
		class IEventManager;
	}

	namespace input
	{
		class IInputReceiver;
	}

	namespace gaming
	{
		class IGameLogic;
	}

	class IEngineManager
    {

	public:

 	    virtual s32 run()=0;

		virtual void beginRender(bool backBuffer, bool zBuffer)=0;

		virtual void endRender()=0;

		virtual gaming::IGameLogic* getGameLogic()=0;

		virtual events::IEventManager* getEventManager()=0;

		virtual input::IInputReceiver* getInputReceiver()=0;

        virtual SGameParams& getGameParameters()=0;
    };
}

#endif


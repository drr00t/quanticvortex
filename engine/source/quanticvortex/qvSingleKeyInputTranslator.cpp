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

#include "qvSingleKeyInputTranslator.h"

#include "qvEventManager.h"
#include "qvInputReceiver.h"


namespace qv
{
	namespace input
	{
		//-----------------------------------------------------------------------------------------
		SingleKeyInputTranslator::SingleKeyInputTranslator(qv::events::EventManager* eventManager,
															irr::EKEY_CODE keyCode,
															qv::input::EKEY_STATE checkKeyState,
															bool realTime,
															qv::events::EventArgs* args,
															u32 inputTranslatorHashId)
															:mEventManager(eventManager),
															mKeyCode(keyCode),
															mCheckKeyState(checkKeyState),
															mRealTime(realTime), mArgs(args),
															mInputTranslatorHashType(qv::input::ITT_SINGLE_KEY),
                                                            mInputTranslatorHashId(inputTranslatorHashId)

		{

		}
		//-----------------------------------------------------------------------------------------
		SingleKeyInputTranslator::~SingleKeyInputTranslator()
		{
		}
		//-----------------------------------------------------------------------------------------
		bool SingleKeyInputTranslator::translate(qv::input::InputReceiver *context)
		{
			bool translated = false;

			switch(mCheckKeyState)
			{
			case EKS_PRESSED_OR_DOWN:

				if(context->keyPressed(mKeyCode) || context->keyDown(mKeyCode))
				{
					if(mRealTime)
						mEventManager->trigger(mArgs);
					else
						mEventManager->enqueueEvent(mArgs);

					translated = true;
				}

				break;

			case EKS_UP_OR_RELEASED:

				if(context->keyUp(mKeyCode) || context->keyReleased(mKeyCode))
				{
					if(mRealTime)
						mEventManager->trigger(mArgs);
					else
						mEventManager->enqueueEvent(mArgs);

					translated = true;
				}

				break;

			case EKS_PRESSED:

				if(context->keyPressed(mKeyCode))
				{
					if(mRealTime)
						mEventManager->trigger(mArgs);
					else
						mEventManager->enqueueEvent(mArgs);

					translated = true;
				}

				break;

			case EKS_RELEASED:

				if(context->keyReleased(mKeyCode))
				{
					if(mRealTime)
						mEventManager->trigger(mArgs);
					else
						mEventManager->enqueueEvent(mArgs);

					translated = true;
				}

				break;

			case EKS_DOWN:

				if(context->keyDown(mKeyCode))
				{
					if(mRealTime)
						mEventManager->trigger(mArgs);
					else
						mEventManager->enqueueEvent(mArgs);

					translated = true;
				}

				break;

			case EKS_UP:

				if(context->keyUp(mKeyCode))
				{
					if(mRealTime)
						mEventManager->trigger(mArgs);
					else
						mEventManager->enqueueEvent(mArgs);

					translated = true;
				}

				break;

			default:
				translated = false;
			}

			return translated;
		}
		//-----------------------------------------------------------------------------------------
	}
}

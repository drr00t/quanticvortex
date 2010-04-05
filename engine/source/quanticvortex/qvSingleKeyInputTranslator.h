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


#ifndef _SINGLE_KEY_INPUT_TRANSLATOR_H_
#define _SINGLE_KEY_INPUT_TRANSLATOR_H_

#include "qvISingleKeyInputTranslator.h"
#include "qvIEventArgs.h"


namespace qv
{
	namespace events
	{
		class IEventManager;
//		class IEventArgsSharedPtr;
	}

	namespace input
	{
		class IInputReceiver;

		class SingleKeyInputTranslator : public ISingleKeyInputTranslator
		{

		//private:
		//	const IT_INPUT_TRANSLATOR_ID* mID;
		//	const IT_INPUT_TRANSLATOR_TYPE* mType;
		//	bool mRealTime;
		//	events::IEventManager* mEventManager;

		//	EKEY_CODE mKeyCode;
		//	EKEY_STATE mCheckKeyState;
		//	events::IEventArgs* mArgs;

		public:

//			SingleKeyInputTranslator(events::IEventManager* eventManager,
//									EKEY_CODE keyCode,
//									EKEY_STATE checkKeyState,
//									bool realTime,
//									events::IEventArgsSharedPtr args,
//									const c8* inputTranslatorName);

			SingleKeyInputTranslator(events::IEventManager* eventManager,
									irr::EKEY_CODE keyCode,
									EKEY_STATE checkKeyState,
									bool realTime,
									events::IEventArgsSharedPtr args,
									u32 inputTranslatorHashtype,
									const c8* inputTranslatorName);

			virtual ~SingleKeyInputTranslator();

            virtual u32 getHashId() const { return mId->Hash; }

            virtual u32 getHashType() const { return mInputTranslatorHashType; }

			virtual bool translate(IInputReceiver *context);

        private:
            events::IEventManager* mEventManager;
			irr::EKEY_CODE mKeyCode;
			EKEY_STATE mCheckKeyState;
			bool mRealTime;
			events::IEventArgsSharedPtr mArgs;
			u32 mInputTranslatorHashType;
			const ITI_INPUT_TRANSLATOR_ID* mId;
		};
	}
}

#endif

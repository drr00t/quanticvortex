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


#ifndef _I_ANY_KEY_INPUT_TRANSLATOR_H_
#define _I_ANY_KEY_INPUT_TRANSLATOR_H_

#include "qvIInputTranslator.h"


namespace qv
{
//	namespace events
//	{
//		class IEventManager;
//		class IEventArgsSharedPtr;
//	}

	namespace input
	{
		class IInputReceiver;

		static const IT_INPUT_TRANSLATOR_TYPE ITT_ANY_KEY_TYPE("ITT_ANY_KEY_TYPE");

		class IAnyKeyInputTranslator : public IInputTranslator
		{
//        protected:
//			events::IEventArgs* mArgs;

//		public:

//			IAnyKeyInputTranslator(events::IEventManager* eventManager,
//									bool realTime,
//									events::IEventArgs* args,
//									const IT_INPUT_TRANSLATOR_ID* ID)
//									:IInputTranslator(eventManager, ID, ITT_ANY_KEY_TYPE, realTime),
//									mArgs(args)
//			{
//			}


		};
	}
}

#endif

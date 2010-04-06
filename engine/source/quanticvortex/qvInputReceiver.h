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


#ifndef _INPUTRECEIVER_H_
#define _INPUTRECEIVER_H_

#include "qvIInputReceiver.h"


namespace qv
{
    class IEngineManager;

	namespace input
	{
		class InputReceiver : public IInputReceiver
		{
        private:
            static const c8 C_KEY_GENERATIONS_COUNT = 4;

            u8 mCurrentGeneration;
            bool mKeyPressed[C_KEY_GENERATIONS_COUNT][irr::KEY_KEY_CODES_COUNT];

            IEngineManager* mEngineManager;

		public:

            InputReceiver(IEngineManager* engineManager);
			virtual ~InputReceiver();

            virtual bool OnEvent(const irr::SEvent& event);
            virtual void registerInputTranslator( IInputTranslator* translator);
            virtual void unregisterInputTranslator( u32 inputTranslatorHashId);
            virtual void unregisterInputTranslator( IInputTranslator* translator);
		};
	}
}

#endif

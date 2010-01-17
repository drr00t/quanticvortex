/**************************************************************************************************
//
//This code is part of QuanticVortex for latest information, see http://www.quanticvortex.org
//
//Copyright (c) 2009 QuanticMinds Software Ltda.
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
//
**************************************************************************************************/



#ifndef __I_INPUT_RECEIVER_H_
#define __I_INPUT_RECEIVER_H_

#include "qvPrerequisites.h"
#include "qvIInputTranslator.h"


namespace qv
{
	namespace input
	{
        class IInputReceiver :  public IEventReceiver,
                                public IReferenceCounted
		{
		public:

			virtual IInputTranslator* getInputTranslator( const IT_INPUT_TRANSLATOR_ID& translatorID) = 0;

            virtual void registerInputTranslator( IInputTranslator* translator) = 0;

            virtual void unregisterInputTranslator( const IT_INPUT_TRANSLATOR_ID& translatorID) = 0;

            virtual void unregisterInputTranslator( IInputTranslator* translator) = 0;

			virtual bool keyPressed(EKEY_CODE keycode)=0;

			virtual bool keyDown(EKEY_CODE keycode)=0;

			virtual bool keyUp(EKEY_CODE keycode)=0;

			virtual bool keyReleased(EKEY_CODE keycode)=0;
		};
	}
}

#endif

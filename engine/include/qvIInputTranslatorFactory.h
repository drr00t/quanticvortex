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


#ifndef __I_INPUT_TRANSLATOR_FACTORY_H_
#define __I_INPUT_TRANSLATOR_FACTORY_H_

#include "qvIInputTranslator.h"
#include "qvCommandArgs.h"


namespace qv
{
    namespace input
    {
		class IInputTranslatorFactory
		{
		public:

			virtual qv::input::IInputTranslator* addInputTranslator (const c8* inputTranslatorName,  u32 inputTranslatorHashType, qv::CommandArgs* args, bool realTime = false) = 0;

			virtual u32 getCreatableInputTranslatorCount() const = 0;

			virtual bool getCreateableInputTranslator( u32 inputTranslatorHashType) const = 0;
		};
    }
}
#endif


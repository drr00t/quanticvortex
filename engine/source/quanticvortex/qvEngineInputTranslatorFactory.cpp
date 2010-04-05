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


#include "qvEngineInputTranslatorFactory.h"

//translators
#include "qvAnyKeyInputTranslator.h"
#include "qvSingleKeyInputTranslator.h"


namespace qv
{
    namespace input
    {
        //-----------------------------------------------------------------------------------------
		EngineInputTranslatorFactory::EngineInputTranslatorFactory( IEventManager* eventManager,
																	IInputReceiver* inputReceiver)
																	:mEventManager(eventManager),
																	mInputReceiver(inputReceiver)
        {
			mSupportedEngineInputTranslatorTypes.push_back(ITT_ANY_KEY.Hash);
			mSupportedEngineInputTranslatorTypes.push_back(ITT_SINGLE_KEY.Hash);

			//quit translator
			//pause translator
			//menu translator
			//ok translator
        }
        //-----------------------------------------------------------------------------------------
        EngineInputTranslatorFactory::~EngineInputTranslatorFactory()
        {
        }
		//-----------------------------------------------------------------------------------------------
		IInputTranslatorSharedPtr EngineInputTranslatorFactory::addInputTranslator (const c8* inputTranslatorName,  u32 inputTranslatorHashType, events::IEventArgsSharedPtr args, bool realTime)
		{
			IInputTranslatorSharedPtr translator;
//			if(getCreateableInputTranslator(inputTranslatorHashType))
//			{
				//key and key state will be set after by user
				//if(ITT_SINGLE_KEY_TYPE->HashedText == type->HashedText)
				//	translator = new SingleKeyInputTranslator(mEventManager, realTime, args, ID);
//			}
			return translator;
		}
        //-----------------------------------------------------------------------------------------
		u32 EngineInputTranslatorFactory::getCreatableInputTranslatorCount() const
        {
            return mSupportedEngineInputTranslatorTypes.size();
        }
        //-----------------------------------------------------------------------------------------
		bool EngineInputTranslatorFactory::getCreateableInputTranslator( u32 inputTranslatorHashType) const
        {
	        for (u32 i=0; i<mSupportedEngineInputTranslatorTypes.size(); ++i)
				if (mSupportedEngineInputTranslatorTypes[i] == inputTranslatorHashType)
			        return true;

            return false;

        }
        //-----------------------------------------------------------------------------------------
    }
}

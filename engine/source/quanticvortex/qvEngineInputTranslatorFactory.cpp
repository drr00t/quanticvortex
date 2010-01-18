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
//#include "qvGameLogic.h"

 
namespace qv
{
    namespace input
    {
        //-----------------------------------------------------------------------------------------
		EngineInputTranslatorFactory::EngineInputTranslatorFactory()
        {
            //mSupportedEngineInputTranslatorTypes.push_back(GLT_GAME_LOGIC_DEFAULT.ID);
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
		IInputTranslator* EngineInputTranslatorFactory::addInputTranslator (const IT_INPUT_TRANSLATOR_ID& id, EKEY_CODE keyCode)
		{
			IInputTranslator* translator = 0;
			//if(getCreateableInputTranslator(id))
			//	translator = new GameLogic(mEngine);
			return translator;
		}
        //-----------------------------------------------------------------------------------------
		u32 EngineInputTranslatorFactory::getCreatableInputTranslatorCount() const
        {
            return mSupportedEngineInputTranslatorTypes.size();
        }
        //-----------------------------------------------------------------------------------------
		bool EngineInputTranslatorFactory::getCreateableInputTranslator(const IT_INPUT_TRANSLATOR_ID& id)
        {
	        for (u32 i=0; i<mSupportedEngineInputTranslatorTypes.size(); ++i)
                if (mSupportedEngineInputTranslatorTypes[i] == id.ID)
			        return true;

            return false;

        }
        //-----------------------------------------------------------------------------------------
    }
}
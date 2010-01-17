/**************************************************************************************************

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

**************************************************************************************************/



#ifndef _I_INPUT_TRANSLATOR_H_
#define _I_INPUT_TRANSLATOR_H_

#include "qvPrerequisites.h"
#include "qvIEventManager.h"
//#include "qvIrrEventHandler.h"
#include "qvSUniqueID.h"

using namespace qv::gaming;

namespace qv
{

	namespace input
	{
		class IInputReceiver;

        typedef UniqueID IT_INPUT_TRANSLATOR_ID;

		class IInputTranslator : public IReferenceCounted
		{
		protected:
			IT_INPUT_TRANSLATOR_ID mID;
			bool mIsActive;
			IInputTranslator* mNextTranslator;
			IEventManager* mEventManager;

		public:
			IInputTranslator(IEventManager* eventManager, const IT_INPUT_TRANSLATOR_ID& ID, bool active = true)
				:mIsActive(active), mID(ID),mNextTranslator(0), mEventManager(eventManager)
			{
			}

			virtual ~IInputTranslator (){}
			
			virtual const IT_INPUT_TRANSLATOR_ID& getID()
			{
				return mID;
			}

			virtual void setIsActive(bool active)
			{
				mIsActive = active;
			}
			
            virtual bool getIsActive()
			{
				return mIsActive;
			}
			
			virtual void setNextTranslator(IInputTranslator* nextTranslator)
			{
				mNextTranslator = nextTranslator;
			}

			virtual bool translate(IInputReceiver *inputState)
			{
				if(mNextTranslator)
					return mNextTranslator->translate(inputState);

				return false;
			}
		};
	}
}

#endif

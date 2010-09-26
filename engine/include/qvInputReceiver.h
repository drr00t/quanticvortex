/**************************************************************************************************
//
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
//
**************************************************************************************************/


#ifndef __INPUT_RECEIVER_H_
#define __INPUT_RECEIVER_H_

#include <vector>

#include "qvSingleKeyInputTranslator.h"
#include "qvAnyKeyInputTranslator.h"

#include "qvIInputTranslator.h"
#include "qvIInputTranslatorFactory.h"

namespace qv
{
namespace input
{


class _QUANTICVORTEX_API_ InputReceiver
	//base input receiver shoud be derived to each plataform, like: Irrlicht, OIS, etc
{

	public:

		InputReceiver()
		{
		}

		virtual ~InputReceiver(void)
		{
			std::vector<IInputTranslator*>::iterator itr = mInputTranslators.begin();

			for(; itr != mInputTranslators.end(); itr++)
				delete (*itr);

			mInputTranslators.clear();
		}

/*		class InputReceiverContext
		{
			public:
				InputReceiverContext()
				{

				}

				InputReceiverContext()
				{

				}

				//context
				bool keyPressed(irr::EKEY_CODE keycode)
				{
					return (mKeyState[keycode] == EKS_PRESSED);
				};

				bool keyDown(irr::EKEY_CODE keycode)
				{
					return (mKeyState[keycode] == EKS_DOWN || mKeyState[keycode] == EKS_PRESSED);
				};

				bool keyUp(irr::EKEY_CODE keycode)
				{
					return (mKeyState[keycode] == EKS_UP || mKeyState[keycode] == EKS_RELEASED);
				};

				bool keyReleased(irr::EKEY_CODE keycode)
				{
					return (mKeyState[keycode] == EKS_RELEASED);
				};
				
			key
		};*/

	protected:

		IInputTranslator* getInputTranslator( u32 inputTranslatorHashId)
		{
			IInputTranslator* inputTranslator = 0;

			for(u32 i = 0; i < mInputTranslators.size(); ++i)
			{
				if(mInputTranslators[i]->getHashId() == inputTranslatorHashId)
				{
					inputTranslator = mInputTranslators[i];
					break;
				}
			}

			return inputTranslator;
		}

		//translators
//			virtual IInputTranslatorSharedPtr addSingleKeyTranslator (const c8* inputTranslatorName, EKEY_CODE keyCode, EKEY_STATE checkState, events::IEventArgsSharedPtr args, bool realTime = false)
//			{
//				IInputTranslatorSharedPtr translator(new SingleKeyInputTranslator( mEventManager, keyCode, checkState, realTime, args, inputTranslatorName));
//				mInputTranslators.push_back(translator);
//
//				return translator;
//			}

//			virtual IInputTranslatorSharedPtr addSingleKeyTranslator (const c8* inputTranslatorName, EKEY_CODE keyCode, EKEY_STATE checkState, u32 inputTranslatorHashType, bool realTime = false)
//			{
//				IInputTranslatorSharedPtr translator(new SingleKeyInputTranslator( mEventManager, keyCode, checkState, realTime, inputTranslatorHashType, inputTranslatorName));
//				registerInputTranslator(translator);
//
//				return translator;
//			}

//			virtual IInputTranslatorSharedPtr addAnyKeyTranslator (const c8* inputTranslatorName, events::IEventArgsSharedPtr args, bool realTime = false)
//			{
//				IInputTranslatorSharedPtr translator(new AnyKeyInputTranslator( mEventManager, realTime, args,inputTranslatorName));
//				mInputTranslators.push_back(translator);
//
//				return translator;
//			}
//

		void registerInputTranslator( IInputTranslator* translator)
		{
//				IInputTranslatorSharedPtr inputTranslator = getInputTranslator(translator->getHashId());
//
//				if(!inputTranslator)
//					mInputTranslators.push_back(translator);
		}

		void unregisterInputTranslator( u32 inputTranslatorHashId)
		{

		}

		void unregisterInputTranslator( IInputTranslator* translator)
		{

		}

		void registerInputTranslatorFactory( IInputTranslatorFactory* factory)
		{
//        factory->grab();
//        mInputTranslatorsFactories.push_back(factory);
		}


	private:

		//i need see which collection will work bether here
		std::vector<IInputTranslator*> mInputTranslators;
		std::vector<IInputTranslatorFactory*> mInputTranslatorsFactories;
};

}

}

#endif

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


#ifndef __I_HUMAN_VIEW_H_
#define __I_HUMAN_VIEW_H_

//#include "qvEngineManager.h"
#include "qvIGameView.h"
#include "qvIElementView.h"
#include "qvICommand.h"
#include "qvIInputTranslator.h"

#include "IAudioManager.h"
//#include "runtime/qvProcessManager.h"


namespace qv
{
  //  namespace gaming
  //  {
  //      class IElementViewFactory;
		//class IElementView;
  //  }

    namespace views
    {
        class IElementViewFactory;

		class IHumanView: public IGameView
        {

        public:
            virtual IElementViewSharedPtr addElementView(const c8* name, u32 elementViewHashType)=0;

//            virtual u32 getHashId() const = 0;

   //         virtual void pushElement(IElementView* element)=0;

			//virtual void popElement(IElementView* element)=0;

            virtual void registerElementViewFactory(IElementViewFactory* factoryToAdd)=0;

//			void attachProcess(Process* process) = 0;

            //coomand that will registred on input manager to response to user input
            virtual const input::InputTranslatorList& listenInputTranslators() const = 0;

            virtual void initAudio() = 0;

            virtual cAudio::IAudioManager* getAudioManager() = 0;

        };
    }
}
#endif


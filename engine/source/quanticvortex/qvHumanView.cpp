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


#include "qvHumanView.h"

#include "qvDefaultElementViewFactory.h"
#include "qvIEventManager.h"
#include "qvIEngineManager.h"

namespace qv
{
    namespace views
    {
        //-----------------------------------------------------------------------------------------
        HumanView::HumanView( IEngineManager* engine, u32 viewHashType)
			: mViewHashType(viewHashType), mLastUpdateTime(0.0f), mEngine(engine),
			mCurrentTime(0.0f), mAccumulatorTime(0)
			/*mProcessManager(0),mInputController(0),*/
        {

            
            DefaultElementViewFactory* factory = new DefaultElementViewFactory(mEngine);
            registerElementViewFactory(factory);
            factory->drop();

            //mFont = mEngineManager->getGuiManager()->getBuiltInFont();
	        //IGUISkin* skin = mEngineManager->getGuiManager()->getSkin();
         //   skin->setFont(mFont);

	        //InitAudio();

	  //      mProcessManager = new ProcessManager();
			//mProcessManager->grab();

	        //m_pFont = NULL;         // Font for drawing text
	        //m_pTextSprite = NULL;   // Sprite for batching draw text calls
        }
        //-----------------------------------------------------------------------------------------
        HumanView::~HumanView()
        {
			//mProcessManager->drop();

//			for(u32 i = 0; i < mElementViews.size(); ++i)
//				mElementViews[i]->drop();

            mElementViews.clear();

         //   SAFE_RELEASE( m_pTextSprite );
	        //SAFE_RELEASE( m_pFont );

	        //SAFE_DELETE(m_pProcessManager);
        }
        //-----------------------------------------------------------------------------------------
        //virtual HRESULT onRestore()=0;
        //-----------------------------------------------------------------------------------------
        void HumanView::render( u32 currentTimeMs, u32 elapsedTimeMs)
        {
			//////// Lock FPS at around 60
			//////if((timeThisFrame - timePreviousFrame) <= 16)
			//////{
			//////  Timer->tick();
			//////  timeThisFrame = Timer->getTime();
			//////}
			//////timePreviousFrame = timeThisFrame;

            //get new system time, but FIXME: should be game time from GameLogic maybe
            mCurrentTime = currentTimeMs;

            if (mCurrentTime == mLastUpdateTime)
		        return;

			mAccumulatorTime += elapsedTimeMs;

            if(mAccumulatorTime >= 16 ) //qv::GF_GAME_RENDER_FRAMERATE)
            {
				mEngine->beginRender(true, true); //call some beginRender from engine

                for(u32 i = 0; i < mElementViews.size(); ++i)
                    if(mElementViews[i]->getVisible())
                        mElementViews[i]->render( mCurrentTime, elapsedTimeMs);

				//mEngineManager->getSceneManager()->drawAll();

				//mEngineManager->getGuiManager()->drawAll();

                mEngine->endRender(); //call some endRender from engine

                //register last render call time
                mLastUpdateTime = mCurrentTime;
				mAccumulatorTime = 0;
            }

        }
        //-----------------------------------------------------------------------------------------
//        void HumanView::lostDevice()
//        {
//
//        }
        //-----------------------------------------------------------------------------------------
        void HumanView::update( u32 elapsedTimeMs)
        {

			//mProcessManager->update(elapsedTimeMs);

	        //m_Console.Update(deltaMilliseconds);

//            for(u32 i = 0; i < mElementViews.size(); ++i)
//                mElementViews[i]->update( elapsedTimeMs);

            //fire game tick
   //         UpdateTickEventArgs tickEvent(elapsedTimeMs);
			//mEngineManager->getEventManager()->trigger(&tickEvent);
        }
        //-----------------------------------------------------------------------------------------
        IElementViewSharedPtr HumanView::addElementView(const c8* name, u32 elementViewHashType)
        {
            IElementViewSharedPtr elementView;
//            for(u32 i = 0; i < mElementViewFactories.size(); ++i)
//			{
////                if(mElementViewFactories[i]->getCreateableElementViewType(type))
////				{
////                    elementView.reset(mElementViewFactories[i]->addElementView(name,type));
////						mElementViews.push_back(elementView);
////					break;
////				}
//			}

			////sort element views array, to put 3D scene, behind gui view, etc...
			//if(mElementViews.size() > 1)
			//	mElementViews.sort();

            return elementView;
        }
  //      //-----------------------------------------------------------------------------------------
		//void HumanView::pushElement(IElementView* element)
  //      {
  //          //mElementViews.push_front(element);
  //      }
  //      //-----------------------------------------------------------------------------------------
		//void HumanView::popElement(IElementView* element)
  //      {
		//	list<IElementView*>::Iterator itr = mElementViews.begin();
		//	while(itr != mElementViews.end())
		//	{
		//		if((*itr)->getID() == element->getID())
		//		{
		//			mElementViews.erase (itr);
		//			break;
		//		}
		//		++itr;
		//	}
  //      }
        //-----------------------------------------------------------------------------------------
        void HumanView::registerElementViewFactory(IElementViewFactory *factoryToAdd)
        {
//            factoryToAdd->grab();
//            mElementViewFactories.push_back(factoryToAdd);
        }
        //-----------------------------------------------------------------------------------------
    }
}


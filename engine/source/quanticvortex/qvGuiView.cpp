
#include "qvGuiView.h"
//#include "qvIEngineManager.h"


namespace qv
{
    namespace views
    {
        //---------------------------------------------------------------------
        GuiView::GuiView(const c8* name, u32 elementViewHashType)
			: mElement(0), mGuiManager(0), mVisible(true), mID(name),
            mHashType(elementViewHashType)//, mOrder(5)
        {

//#ifdef _DEBUG
//			setDebugName("GuiView");
//#endif
//			mID  = ;
			//recti window(0,0,mGuiManager->getVideoDriver()->getScreenSize().Width,
			//				mGuiManager->getVideoDriver()->getScreenSize().Height);
			//mElement = mGuiManager->addWindow(window);
        }
        //---------------------------------------------------------------------
        GuiView::~GuiView()
        {
        }
        //---------------------------------------------------------------------
        void GuiView::render( u32 currentTimeMs, u32 elapsedTimeMs)
        {
            //mGuiManager->drawAll();
        }
        //---------------------------------------------------------------------
		void GuiView::update( u32 elapsedTimeMs)
        {

        }
		//-----------------------------------------------------------------------------------------------
    }
}


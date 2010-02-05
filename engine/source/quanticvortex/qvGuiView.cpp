
#include "qvGuiView.h"
#include "qvIEngineManager.h"


namespace qv
{
    namespace views
    {
        //---------------------------------------------------------------------
        GuiView::GuiView(const c8* name,IEngineManager* engine, const EVT_ELEMENT_VIEW_TYPE* type)
            : mElement(0), mGuiManager(0), mVisible(true)
        {

#ifdef _DEBUG
			setDebugName("GuiView");
#endif
			mID = new EVI_ELEMENT_VIEW_ID(name);
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


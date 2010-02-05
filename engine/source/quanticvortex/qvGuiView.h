
#ifndef __GUIVIEW_H_
#define __GUIVIEW_H_

#include "qvIGuiView.h"

using namespace irr::gui;


namespace qv
{
    class IEngineManager;

    namespace views
    {
        
        class GuiView: public IGuiView
        {
        protected:
            IGUIElement* mElement;
            IGUIEnvironment* mGuiManager;
			bool mVisible;
            const EVT_ELEMENT_VIEW_TYPE* mType;
            const EVI_ELEMENT_VIEW_ID* mID;

        public:
            GuiView(const c8* name, IEngineManager* engine, const EVT_ELEMENT_VIEW_TYPE* type = EVT_ELEMENT_VIEW_GUI);
            virtual ~GuiView();
			
            virtual const EVT_ELEMENT_VIEW_TYPE* getType()
            {
                return mType;
            }
            
            virtual const EVI_ELEMENT_VIEW_ID* getID()
            {
                return mID;
            }

            virtual bool getVisible()
            {
                return mVisible;
            }

			virtual void setVisible( bool visible)
            {
                mVisible = visible;
            }

	        virtual void render( u32 currentTimeMs, u32 elapsedTimeMs);
	        virtual void update( u32 elapsedTimeMs);
        };
    }
}
#endif


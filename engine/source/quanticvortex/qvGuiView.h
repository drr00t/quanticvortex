
#ifndef __GUIVIEW_H_
#define __GUIVIEW_H_

#include "qvIGuiView.h"

#include "IGUIElement.h"
#include "IGUIEnvironment.h"

namespace qv
{
 
    namespace views
    {

        class GuiView: public IGuiView
        {
        public:
            GuiView(const c8* name, u32 elementViewHashType);
            virtual ~GuiView();

            virtual u32 getHashId() const { return mID.Hash; }

            virtual u32 getHashType() const { return mHashType; }

	        virtual bool getVisible() const { return mVisible; }


			virtual void setVisible( bool visible)
			{
                mVisible = visible;
            }

	        virtual void render( u32 currentTimeMs, u32 elapsedTimeMs);
	        virtual void update( u32 elapsedTimeMs);
            
        protected:
            irr::gui::IGUIElement* mElement;
            irr::gui::IGUIEnvironment* mGuiManager;
			bool mVisible;
            u32 mHashType;
            EVI_ELEMENT_VIEW_ID mID;
        };
    }
}
#endif


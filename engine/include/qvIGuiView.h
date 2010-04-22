
#ifndef __IGUIVIEW_H_
#define __IGUIVIEW_H_

#include "qvIElementView.h"

namespace qv
{

namespace views
{

static const EVT_ELEMENT_VIEW_TYPE EVT_ELEMENT_VIEW_GUI = HASH_STRING("EVT_ELEMENT_VIEW_GUI");

class IGuiView: public IElementView
{

    //public:
    //         virtual const ElementViewID& getID()=0;
    //         virtual const ElementViewType& getType()=0;
    //      virtual bool getVisible()=0;
        //virtual void setVisible(bool visible)=0;
    //      virtual void render(u32 currentTimeMs, u32 elapsedTimeMs)=0;
    //      virtual void update( u32 elapsedTimeMs)=0;

};

}

}
#endif


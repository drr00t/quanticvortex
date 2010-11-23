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

#ifndef __ABSTRACT_ELEMENT_VIEW_H_
#define __ABSTRACT_ELEMENT_VIEW_H_

#include "qvElementViewTypes.h"

#include <list>

namespace qv
{

namespace views
{


class AbstractElementView
            /// base class for all view elements representation
            /// like a buttons, actors, all thing that will
            /// e affect by game time, shader effect, physics, etc.
{

public:

    AbstractElementView(const qv::views::EVI_ELEMENT_VIEW_ID& elementViewId, const qv::views::EVT_ELEMENT_VIEW_TYPE& elementViewType, qv::u8 elementViewOrder)
            : mElementViewId(elementViewId), mElementViewType(elementViewType), mElementViewOrder(elementViewOrder)
    {

    }

    virtual ~AbstractElementView()
    {

    }

    qv::u8 getOrder() const;
    /// order for all element of same level

    const qv::views::EVI_ELEMENT_VIEW_ID& getId() const;
    /// unique hash and name id of the element view

    const qv::views::EVT_ELEMENT_VIEW_TYPE& getType() const;

    bool visible() const;
    /// element should be displyed or not

    void visible(bool isVisible);

    virtual void render( qv::u32 currentTimeMs, qv::u32 elapsedTimeMs) = 0;

    virtual void update( qv::u32 elapsedTimeMs) = 0;

private:
    AbstractElementView(const AbstractElementView&);
    AbstractElementView& operator = (const AbstractElementView&);

    qv::views::EVI_ELEMENT_VIEW_ID mElementViewId;
    const qv::views::EVT_ELEMENT_VIEW_TYPE& mElementViewType;
    qv::u8 mElementViewOrder;
    bool mVisible;

};

struct SortElementViewsLess
/// utiliiy functor for ordering list data
{
    bool operator()(qv::views::AbstractElementView* a, qv::views::AbstractElementView* b) const
    {
        return (a->getOrder() < b->getOrder());
    }
};

typedef std::list<qv::views::AbstractElementView*> ElementViewsList;


//inlines
inline qv::u8 qv::views::AbstractElementView::getOrder() const
{
    return mElementViewOrder;
}

inline const qv::views::EVI_ELEMENT_VIEW_ID& qv::views::AbstractElementView::getId() const
{
    return mElementViewId;
}

inline const qv::views::EVT_ELEMENT_VIEW_TYPE& qv::views::AbstractElementView::getType() const
{
    return mElementViewType;
}

inline bool qv::views::AbstractElementView::visible() const
{
    return mVisible;
}

inline void qv::views::AbstractElementView::visible(bool isVisible)
{
    mVisible = isVisible;
}

}


}
#endif

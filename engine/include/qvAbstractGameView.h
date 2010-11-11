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


#ifndef __ABSTRACT_GAME_VIEW_H_
#define __ABSTRACT_GAME_VIEW_H_

// system headers
#include <vector>

// QuanticVortex headers
#include "qvGameViewTypes.h"


namespace qv
{
namespace views
{

class AbstractGameView
		/// abstract to views of game, all game views should derive from
		/// this class allow external events as user input, network events,
		/// structure allow make very nice things like: listen all events
		/// raised by game logic or even game we can recorde this events
		/// and use this to replay game. Engine implements views:
		///
		/// - HumanView:    most important view of our engine, this is
		///                 used by local player, getting user events
		///                 and translating in game events,
		/// - PhysicsView:  allow debug physics drawing collisions, body
		/// - RecorderView: record all events raised by game
		/// - NetworkView:  represent a remote player attached on game
{

public:

    AbstractGameView( const qv::views::GVI_GAME_VIEW_ID& gameViewId, qv::u8 viewOrder, const qv::views::GVT_GAME_VIEW_TYPE& viewType)
            : mViewOrder(viewOrder), mGameViewType(viewType), mGameViewId(gameViewId)
    {

    }

    virtual ~AbstractGameView()
    {

    }
    
    const qv::views::GVT_GAME_VIEW_TYPE& getType() const;
    /// event argument type
    
    const qv::views::GVI_GAME_VIEW_ID& getId() const;
    /// identification for view

    const qv::u8 getOrder() const;
    /// view order to update on game logic collection views

    virtual void render( qv::u32 currentTimeMs, qv::u32 elapsedTimeMs) = 0;
    /// render all content of this view

    virtual void update( qv::u32 elapsedTimeMs) = 0;
    /// update content this view, used when
    /// content dependent on time
    
//    bool operator < (const qv::views::AbstractGameView& other) const
//    {
//            return mViewOrder < other.getOrder();
//    }
    
private:

    AbstractGameView(const AbstractGameView&);
    AbstractGameView& operator = (const AbstractGameView&);

    u8 mViewOrder;      /// view order on view collection in GameLogic
    const qv::views::GVT_GAME_VIEW_TYPE& mGameViewType; //view type
    qv::views::GVI_GAME_VIEW_ID mGameViewId;

};

//inlines
inline const qv::views::GVT_GAME_VIEW_TYPE& qv::views::AbstractGameView::getType() const
{
    return mGameViewType;
}

inline const qv::views::GVI_GAME_VIEW_ID& qv::views::AbstractGameView::getId() const
{
    return mGameViewId;
}

inline const qv::u8 qv::views::AbstractGameView::getOrder() const
{
    return mViewOrder;
}

typedef std::vector<qv::views::AbstractGameView*> GameViewsArray;
/// game views array


}

}
#endif

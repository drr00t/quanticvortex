#ifndef __ABSTRACT_GAME_VIEW_TEST_H_
#define __ABSTRACT_GAME_VIEW_TEST_H_

#include "UnitTest++.h"
#include "qvAbstractGameView.h"

class TestGameView: public qv::views::AbstractGameView
{
public:
    TestGameView( const qv::c8* commandName, qv::u8 gameViewOrder, const qv::views::GVT_GAME_VIEW_TYPE& gameViewType)
            : qv::views::AbstractGameView(commandName, gameViewOrder, gameViewType), renderCall(0), updateCall(0)
    {

    }

    virtual void render( qv::u32 currentTimeMs, qv::u32 elapsedTimeMs)
    {
        renderCall++;
    }

    virtual void update( qv::u32 elapsedTimeMs)
    {
        updateCall++;
    }
    
    qv::u32 renderCall;  //updated when render method was called
    
    qv::u32 updateCall;  ///update when update method was called

};

// Commandargs test should stay here
SUITE(TestsAbstractGameView)
{
    //basic definition of CommandArgs
    TEST(TestAbstractGameViewRenderOrder)
    {
        static const qv::views::GVT_GAME_VIEW_TYPE GVT_FIRST("GVT_FIRST");
        static const qv::views::GVT_GAME_VIEW_TYPE GVT_SECOND("GVT_SECOND");
        static const qv::views::GVT_GAME_VIEW_TYPE GVT_THIRD("GVT_THIRD");

        qv::views::AbstractGameView* view1 = new TestGameView("test_game_view_01", 1, GVT_FIRST);
        qv::views::AbstractGameView* view2 = new TestGameView("test_game_view_02", 2, GVT_SECOND);
        qv::views::AbstractGameView* view3 = new TestGameView("test_game_view_03", 3, GVT_THIRD);
        
        

//        CHECK(command->getId() == CI_TEST_ID_01);
    }
}

#endif // __SHASHED_STRING_TEST_H_

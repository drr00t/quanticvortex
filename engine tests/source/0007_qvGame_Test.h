#ifndef __GAME_TEST_H_
#define __GAME_TEST_H_

#include "UnitTest++.h"

#include "qvGame.h"

class TestOrderGameView: public qv::views::AbstractGameView
{
public:
    TestOrderGameView( const qv::c8* commandName, qv::u8 gameViewOrder, const qv::views::GVT_GAME_VIEW_TYPE& gameViewType)
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

class TestGame: public qv::Game
{
public:
    TestGame()
    {
    }
};

SUITE(TestGame)
{
    TEST(TestOrderGameView)
    {
        static const qv::views::GVT_GAME_VIEW_TYPE GVT_FIRST("GVT_FIRST");
        static const qv::views::GVT_GAME_VIEW_TYPE GVT_SECOND("GVT_SECOND");
        static const qv::views::GVT_GAME_VIEW_TYPE GVT_THIRD("GVT_THIRD");
        
        TestGame game;
        
        game.addGameView<TestOrderGameView>("view_03", (qv::u8)3, GVT_THIRD);
        game.addGameView<TestOrderGameView>("view_01", (qv::u8)1, GVT_FIRST);
        game.addGameView<TestOrderGameView>("view_02", (qv::u8)2, GVT_SECOND);
        
        bool ordered = true;
        
        qv::views::GameViewsArray gameViews = game.getGameViews();
        
        qv::u8 ind = 1;
        
        for(qv::views::GameViewsArray::iterator itr = gameViews.begin(); itr != gameViews.end(); itr++)
        {
            if(ind != (*itr)->getOrder())
            {
                ordered = false;
                break;
            }
            
            ind++;
        }
        
        CHECK(ordered);
            
    }
}

#endif // __SHASHED_STRING_TEST_H_


#include "HelloWordGame.h"
#include "qvHumanView.h"

#include <iostream>

static const qv::views::GVT_GAME_VIEW_TYPE GVT_TEST("GVT_TEST");
static const qv::views::GVI_GAME_VIEW_ID GVI_TEST("GVI_TEST");

class TestGameView: public qv::views::HumanView
{
public:
	TestGameView(qv::Game* game)
		:qv::views::HumanView(GVI_TEST,game), mElapsedTimeMs(0)
	{}

    virtual void render( qv::u32 currentTimeMs, qv::u32 elapsedTimeMs)
	{
		std::cout << "Test Game View  - " << mElapsedTimeMs << "Current time" << currentTimeMs << std::endl;
	}

    virtual void update( qv::u32 elapsedTimeMs)
	{
		mElapsedTimeMs = elapsedTimeMs;
	}
	
private:
	qv::u32 mElapsedTimeMs;
};

int main(int argc, const char** argv)
{
//    MEM_ON();

	samples::HelloWordGame game;
	
//    MEM_OFF();
	return game.run(argc, argv);

}

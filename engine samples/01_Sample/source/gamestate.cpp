#include "gamestate.h"

namespace sdc
{
    TestGameState::TestGameState()
    :qv::gaming::GameState(sdc::S_TEST.Hash)
    {
    }
    
    TestGameState::~TestGameState()
    {
    }
}

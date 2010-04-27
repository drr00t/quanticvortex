
#include "qvGameState.h"


namespace sdc
{

    static const qv::S_STATE S_TEST = HASH_STRING("TEST");
/**
 * \class GameState
 * \author adriano.ribeiro
 * \date 04/14/10
 * \file gamestate.h
 * \brief
 */
class TestGameState: public qv::gaming::GameState
{
public:

    TestGameState();

    virtual ~TestGameState();
    
private:
//    qv::input::InputTranslatorList mInputTranslators;
//    qv::events::EventCommandHashTypesVector mEventCommandHashTypes;

};

    
}

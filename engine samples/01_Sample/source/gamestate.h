
#include "qvIGameState.h"

namespace sdc
{

/**
 * \class GameState
 * \author adriano.ribeiro
 * \date 04/14/10
 * \file gamestate.h
 * \brief
 */
class GameState: public qv::gaming::IGameState
{
public:

    GameState();

    virtual ~GameState();

    /**
     * \brief
     * \return
     */
    const qv::input::InputTranslatorList& getInputTranslators() const;

    /**
     * \brief
     * \return
     */
    const qv::events::EventCommandHashTypesVector& getEventCommandHashTypes() const;
    
private:
    qv::input::InputTranslatorList mInputTranslators;
    qv::events::EventCommandHashTypesVector mEventCommandHashTypes;

};

    const qv::events::EventCommandHashTypesVector& GameState::getEventCommandHashTypes() const
    {
    }

    const qv::input::InputTranslatorList& GameState::getInputTranslators() const
    {
    }
    
}

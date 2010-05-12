
#ifndef __SDC_CONTROLLER_INITIALIZATING_COMMAND_H_
#define __SDC_CONTROLLER_INITIALIZATING_COMMAND_H_

#include "qvICommand.h"
#include "qvTypes.h"

namespace qv
{
    class Game;
    class EngineManager;

namespace events
{
    class EventArgs;
    class EventManager;
}
}

namespace sdc
{
namespace controller
{

static const qv::CI_COMMAND_ID CI_INITIALIZATING = HASH_STRING("CI_INITIALIZATING");


class InitializatingCommand: public qv::ICommand
    /// initialization command to startup game application
{
public:
    InitializatingCommand( qv::EngineManager* engineManager);
    /// constructor
    
    virtual ~InitializatingCommand();
    
    virtual qv::u32 getHashId() const
    {
        return mCommandHashId;
    }
    
    virtual qv::u32 getHashType() const
    {
        return mCommandHashType;
    }
    
    virtual void executeCommand(const qv::events::EventArgs* args);

private:
    qv::u32 mCommandHashId;
    qv::u32 mCommandHashType;
    qv::EngineManager* mEngineManager;
};
}
}

#endif

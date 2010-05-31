
#ifndef __SDC_CONTROLLER_LOADING_COMMAND_H_
#define __SDC_CONTROLLER_LOADING_COMMAND_H_

//#include "qvICommand.h"
#include "qvTypes.h"

namespace qv
{
class Game;

namespace events
{
    class EventArgs;
}
}

namespace sdc
{
namespace controller
{
    
class LoadingCommand //: public qv::ICommand
{
public:
    LoadingCommand();
    virtual ~LoadingCommand();
    virtual qv::u32 getHashId() const { return 0;}

    virtual qv::u32 getHashType() const { return 0;}
    virtual void executeCommand(const qv::events::EventArgs* args);
};

}
}

#endif


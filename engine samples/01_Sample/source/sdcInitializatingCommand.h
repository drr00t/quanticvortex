
#ifndef __SDC_INITIALIZATING_COMMAND_H_
#define __SDC_INITIALIZATING_COMMAND_H_

#include "qvAbstractCommand.h"


namespace sdc
{
class SylfurDCGame;
}

namespace sdc
{
namespace commands
{

//static const qv::CI_COMMAND_ID CI_INITIALIZATING = HASH_STRING("CI_INITIALIZATING");


class InitializatingCommand: public qv::AbstractCommand
            /// initialization command to startup game application
{
public:
    InitializatingCommand( sdc::SylfurDCGame* gameApp);
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
    qv::Game* mGameApp;
};

}

}

#endif

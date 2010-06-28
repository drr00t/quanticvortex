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


#ifndef __COMMAND_ARGS_H_
#define __COMMAND_ARGS_H_

#include <vector>

#include "qvCommandTypes.h"

namespace qv
{
class CommandArgs
{
public:

    CommandArgs( const qv::CT_COMMAND_TYPE& commandType)
            : mCommandType(commandType)
            /// create a event argument with type
    {}


    virtual ~CommandArgs()
    {}

    const qv::CT_COMMAND_TYPE& getType() const;
    /// event argument type

private:

    CommandArgs(const CommandArgs&); // to avoid copy of command args
    CommandArgs& operator = (const CommandArgs&); // to avoid copy of command args

    const qv::CT_COMMAND_TYPE& mCommandType; // event arguments type
};

typedef std::vector<qv::CommandArgs*> CommandArgsArray;
/// array of CommandArgs

//inlines
inline const qv::CT_COMMAND_TYPE& qv::CommandArgs::getType() const
{
    return mCommandType;
}

}

#endif

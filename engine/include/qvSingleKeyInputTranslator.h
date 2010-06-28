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


#ifndef _SINGLE_KEY_INPUT_TRANSLATOR_H_
#define _SINGLE_KEY_INPUT_TRANSLATOR_H_

#include "qvIInputTranslator.h"
#include "qvCommandArgs.h"

namespace qv
{
    class CommandManager;


namespace input
{
    class InputReceiver;
}

}

namespace qv
{
namespace input
{

static const qv::input::ITT_INPUT_TRANSLATOR_TYPE ITT_SINGLE_KEY("SINGLE_KEY");

class _QUANTICVORTEX_API_ SingleKeyInputTranslator: public qv::input::IInputTranslator
{

public:

    SingleKeyInputTranslator(qv::CommandManager* commandManager,
                            irr::EKEY_CODE keyCode,
                            qv::input::EKEY_STATE checkKeyState,
                            bool realTime,
                            qv::CommandArgs* args,
                            u32 inputTranslatorHashId);

    virtual ~SingleKeyInputTranslator();

    virtual u32 getHashId() const { return mInputTranslatorHashId; }

    virtual u32 getHashType() const { return mInputTranslatorHashType; }

    virtual bool translate(qv::input::InputReceiver *context) const;

private:
    bool mRealTime;
    u32 mInputTranslatorHashType;
    u32 mInputTranslatorHashId;
    qv::CommandManager* mCommandManager;
    irr::EKEY_CODE mKeyCode;
    qv::input::EKEY_STATE mCheckKeyState;
    qv::CommandArgs* mArgs;
};

}

}

#endif

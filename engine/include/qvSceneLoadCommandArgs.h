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


#ifndef __SCENE_LOAD_COMMAND_ARGS_H_
#define __SCENE_LOAD_COMMAND_ARGS_H_

#include "qvCommandArgs.h"


namespace qv
{

namespace views
{

class SceneLoadCommandArgs: public qv::CommandArgs
{
public:

    SceneLoadCommandArgs( const qv::CT_COMMAND_TYPE& commandType)
    /// create a scene load command args with type
        : qv::CommandArgs(commandType)
    {

    }

    virtual ~SceneLoadCommandArgs()
    /// destroy scene load command
    {

    }

    const qv::c8* getSceneFile() const;
    /// scene file to load

private:
    irr::core::stringc mSceneFile;


};

//inlines
const qv::c8* SceneLoadCommandArgs::getSceneFile() const
{
    return mSceneFile.c_str();
}
}

}

#endif

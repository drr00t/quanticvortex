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


#ifndef __COMMAND_TYPES_H_
#define __COMMAND_TYPES_H_

#include <vector>

#include "qvSHashedString.h"


namespace qv
{

typedef SHashedString CI_COMMAND_ID;
/// this should be set by user when a command is created,
/// this value shoud be unique in command space

typedef SHashedString CT_COMMAND_TYPE;
/// define command family for this command

typedef std::vector<qv::CT_COMMAND_TYPE> CommandTypesArray;

static const CT_COMMAND_TYPE CT_CONTENT_CONFIGURE("CT_CONTENT_CONFIGURE");

namespace views
{
static const CT_COMMAND_TYPE CT_SCENE_LOAD("CT_SCENE_LOAD");    
}

}

#endif

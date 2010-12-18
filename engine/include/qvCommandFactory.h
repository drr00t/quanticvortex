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


#ifndef __COMMAND_FACTORY_H_
#define __COMMAND_FACTORY_H_

//system headers
#include <algorithm>
#include <tr1/unordered_map>

//engine headers
#include "qvAbstractCommand.h"



namespace qv
{

class Game;

class AbstractCommandFactory
	/// base class for all game views creation

{
public:
	virtual ~AbstractCommandFactory();
	virtual qv::AbstractCommand* create(qv::Game* game)=0;

protected:
	AbstractCommandFactory (const AbstractCommandFactory&);
	AbstractCommandFactory& operator = (const AbstractCommandFactory&);
};


template<class T> class CommandFactory: public qv::AbstractCommandFactory
	/// template class for command objects creation of type T

{
public:
	virtual qv::AbstractCommand* create(qv::Game* game)
	{
		return new T(game);
	}
};


typedef std::tr1::unordered_map<qv::u32, qv::AbstractCommandFactory*> CommandFactoriesMap;
/// hashmap of command args to command using types.


}
#endif

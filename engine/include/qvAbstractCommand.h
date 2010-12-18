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


#ifndef __ABSTRACT_COMMAND_H_
#define __ABSTRACT_COMMAND_H_

#include <algorithm>
#include <tr1/unordered_map>

#include "qvCommandArgs.h"


namespace qv
{

class AbstractCommand
	/// basic interface to execute a command inside the engine
{
public:
//	AbstractCommand(const qv::CI_COMMAND_ID& commandId, const qv::CT_COMMAND_TYPE& commandType)
	/// command constructor getting name and type of command args
	AbstractCommand( const qv::CT_COMMAND_TYPE& commandType)
		: mCommandType(commandType)
	{}

	virtual ~AbstractCommand() {}
	/// destructor

//	const qv::CI_COMMAND_ID& getId() const;
//	/// unique command id

	const qv::CT_COMMAND_TYPE& getType() const;
	/// command type family

	virtual void executeCommand(const qv::CommandArgs* args) = 0;
	/// body of command

private:

	AbstractCommand(const AbstractCommand&); // to avoid copy of command args
	AbstractCommand& operator = (const AbstractCommand&); // to avoid copy of command args

//	qv::CI_COMMAND_ID mCommandId;
	qv::CT_COMMAND_TYPE mCommandType;
};


//inlines
//inline const qv::CI_COMMAND_ID& qv::AbstractCommand::getId() const
//{
//	return mCommandId;
//}

inline const qv::CT_COMMAND_TYPE& qv::AbstractCommand::getType() const
{
	return mCommandType;
}

typedef std::vector<qv::AbstractCommand*> CommandArray;
/// commands vector for fast iteration.

typedef std::tr1::unordered_map<qv::u32, qv::AbstractCommand*> CommandsMap;
/// hashmap of command to command using types.

//typedef std::tr1::unordered_multimap<u32, qv::AbstractCommand*> CommandsMap;
///// hashmap of command args to command using types.
//
//typedef std::pair<CommandsMap::iterator, CommandsMap::iterator> CommandsMapRangeResult;
///// iterator for navegate throught hash_multmap result

}

#endif

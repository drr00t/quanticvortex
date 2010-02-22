// Copyright (C) 2007-2009 Matthias Specht
// For conditions of distribution and use, see copyright notice in license.txt

#include "CIrrIniIrr.h"

namespace irr
{
namespace io
{

IrrIni* createIniFile(const c8* file, IFileSystem* fileSystem, bool saveOnDestroy/* =false */)
{
	return new CIrrIniStub(fileSystem, file,saveOnDestroy);
}

IrrIni* createIniFile(io::IReadFile* file, IFileSystem* fileSystem, bool saveOnDestroy/* =false */)
{
	return new CIrrIniIrr(fileSystem, file,saveOnDestroy);
}

IrrIni* createIniFileEmpty(IFileSystem* fileSystem)
{
	return new CIrrIniStub(fileSystem,0,false);
}

}
}

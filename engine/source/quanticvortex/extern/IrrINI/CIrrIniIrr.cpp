// Copyright (C) 2007-2009 Matthias Specht
// For conditions of distribution and use, see copyright notice in license.txt

#include "CIrrIniIrr.h"

namespace irr
{
namespace io
{

CIrrIniIrr::CIrrIniIrr(IFileSystem* fileSystem, IReadFile* file, bool save)
: CIrrIniStub(fileSystem, 0,save)
{
   if(file)
   {
      s32 size = file->getSize();
      c8* buffer = new c8[size];
      file->read(buffer,size);
	  Content = buffer;
	  delete buffer;
   }
}

CIrrIniIrr::~CIrrIniIrr()
{

}

}
}

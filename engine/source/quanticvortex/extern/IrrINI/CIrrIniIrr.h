// Copyright (C) 2007-2009 Matthias Specht
// For conditions of distribution and use, see copyright notice in license.txt
#ifndef __C_IRR_INI_IRR_H_INCLUDED__
#define __C_IRR_INI_IRR_H_INCLUDED__

#include "CIrrIniStub.h"

namespace irr
{
namespace io
{

class CIrrIniIrr : public CIrrIniStub
{
   public:
      CIrrIniIrr(IFileSystem* fileSystem, IReadFile* file, bool saveOnDestroy=true);
      virtual ~CIrrIniIrr();
};

}
}

#endif // __C_IRR_INI_IRR_H_INCLUDED__

// Copyright (C) 2007-2009 Matthias Specht
// For conditions of distribution and use, see copyright notice in license.txt

#ifndef __C_IRR_INI_STUB_H_INCLUDED__
#define __C_IRR_INI_STUB_H_INCLUDED__

#include "IrrIni/IrrIni.h"

namespace irr
{
namespace io
{

class CIrrIniStub : public IrrIni
{
public:
	CIrrIniStub(IFileSystem* fileSystem, const c8* file, bool saveOnDestroy=true);
	virtual ~CIrrIniStub();

	virtual void setSaveOnDestroy(bool enabled);
	virtual void setSaveFileName(core::stringc fileName);
	virtual void setFileSystem(IFileSystem* fileSystem);

	virtual bool load();
	virtual bool save();

	virtual bool keyExists(const c8* section, const c8* key ) const;

	virtual const c8* getComment( const c8* section, const c8* key=0 ) const;
	virtual void setSectionComment( const c8* section, const c8* comment="" );
	virtual void setKeyComment( const c8* section, const c8* key, const c8* comment="" );

	virtual const c8* getValue(const c8* section, const c8* key) const;
	virtual s32 getValueI(const c8* section, const c8* key) const;
	virtual f32 getValueF(const c8* section, const c8* key) const;
	virtual bool getValueB(const c8* section, const c8* key) const;
	virtual EKEY_CODE getValueK(const c8* section, const c8* key) const;
	virtual video::E_DRIVER_TYPE getValueDrv(const c8* section, const c8* key) const;
	virtual u32 getValueU32(const c8* section, const c8* key) const;

	virtual void setValue(const c8* section, const c8* key, const c8* value);
	virtual void setValue(const c8* section, const c8* key, s32 value);
	virtual void setValue(const c8* section, const c8* key, f32 value);
	virtual void setValue(const c8* section, const c8* key, bool value);
	virtual void setValue(const c8* section, const c8* key, EKEY_CODE value);
	virtual void setValue(const c8* section, const c8* key, video::E_DRIVER_TYPE value);
	virtual void setValue(const c8* section, const c8* key, u32 value);

	virtual core::array<SSection*> getAllSections() const;
	virtual SSection* getSection(const c8* section) const;
	virtual void removeAll();
	virtual void addSection(const c8* name);

protected:
	core::array<SSection*> Sections;
	IFileSystem* FileSystem;
	core::stringc Content;
	core::stringc FullFileName;
	bool SaveOnDestroy;
	EKEY_CODE convertIrrKeyCode(core::stringc str) const;
	const char* convertIrrKeyCode(irr::EKEY_CODE value) const;
};

}
}

#endif // __C_IRR_INI_STUB_H_INCLUDED__


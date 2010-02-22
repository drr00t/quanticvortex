// Copyright (C) 2007-2009 Matthias Specht
// For conditions of distribution and use, see copyright notice in license.txt

#ifndef __IRR_INI_H_INCLUDED__
#define __IRR_INI_H_INCLUDED__

#include "irrlicht.h"
#include "SValue.h"

/*! \mainpage IrrINI documentation
* \section Introduction
* IrrIni is an easy to use class that allows you to read and write data from and into INI-files.
* It is completly platform independent and was designed to be integrated into the Irrlicht-Engine.
*
* \section Changes
* Release 4:
* <ul>
* <li> Added support for comments.</li>
* <li> Some speed improvements for reading and writing values.</li>
* <li> Removed SValue2D's constructor for core::position2d. Use core::vector2d instead.</li>
* <li> Removed SValue2D<T>::toPosition().</li>
* <li> Removed setValue( wchar_t* ) and getValueW().</li>
* </ul>
*
* Release 3:
* <ul>
* <li> Renamed IIniFileReader class to IrrIni.</li>
* <li> Renamed createIniFileReader(empty) to createIniFile(empty).</li>
* <li> Methods are now const correct.</li>
* <li> Added IrrIni::keyExists() to check if a key exists.</li>
* <li> Removed IrrIni::addKeyToSection(). Use setValue() to create new keys.</li>
* <li> Removed the 64 character limitation of section and key names. (Now using stringc instead of char*).</li>
* <li> IrrIni::getValue() now returns a const c8* instead of c8*.</li>
* <li> Added extra constructors to SValue structs allowing manual creation of these structs.</li>
* <li> Replaced SValue i/f with template classes.</li>
* <li> createIniFile(empty) now needs a pointer to the Irrlicht IFileSystem for writing the data. If you just need to read them you can pass 0.</li>
* <li> added IrrIni::setFileSystem() to set filesystem after creation.</li>
* <li> Fixed memory leak in IrrIni::load() if a key was found outside a section.</li>
* <li> Fixed data garbage in last key of a file if no new line was added to the end.</li>
* </ul>
*
* Release 2.1:
* <ul>
* <li>Fixed bug in IrrIni::addKeyToSection() setting the name but not the value of the key</li>
* <li>IrrIni::addKeyToSection() will now change the value of an existing key insted of adding a new one with an already used name</li>
* <li>Multidemensional values (e.g. dimension2d) are now seperated by a x instead of X</li>
* <li>added IrrIni::setValue() for unsigned 32bit integers</li>
* </ul>
*
* Release 2:
* <ul>
* <li>Added createIniFileReaderEmpty() function, which creates an empty object of the class. It stores its data in memory, but if you want to save it to disk it's no problem.</li>
* <li>Added IrrIni::getValueDrv() method. Returns the value as an E_DRIVER_TYPE value. </li>
* </ul>
*
* Release 1:
* <ul>
* <li>Initial release.</li>
* <li>Redesigned the code to fit better with Irrlicht's coding rules.</li>
* </ul>
*/

namespace irr
{
namespace io
{

//! interface for reading/writing INI files
class IrrIni : public IReferenceCounted
{
public:
	// forward declarations to make the code more readable
	struct SSection;
	struct SKey;

	//! Destructor
	virtual ~IrrIni() {}

	//! loads the data into the class
	virtual bool load() = 0;
	//! saves the data into a file
	virtual bool save() = 0;

	//! Sets if the data should be saved when the object is destroyed 
	virtual void setSaveOnDestroy(bool enabled) = 0;
	//! Sets a filename to save the data in
	virtual void setSaveFileName(core::stringc fileName) = 0;
	//! Sets a new pointer to the Irrlicht filesystem. This can be used if the object was created without one but now needs to be saved.
	virtual void setFileSystem(IFileSystem* fileSystem) = 0;

	//! Checks if the key exists in the section.
	virtual bool keyExists( const c8* section, const c8* key ) const = 0;

	//! Returns the comment associated with the section/key
	virtual const c8* getComment( const c8* section, const c8* key=0 ) const = 0;
	//! Sets the comment for the section
	virtual void setSectionComment( const c8* section, const c8* comment="" ) = 0;
	//! Sets the comment for the key
	virtual void setKeyComment( const c8* section, const c8* key, const c8* comment="" ) = 0;

	//! returns the value assigned to the section-key-pair as an ASCII-string.
	virtual const c8* getValue(const c8* section, const c8* key) const = 0;
	//! returns the value assigned to the section-key-pair as an integer.
	virtual s32 getValueI(const c8* section, const c8* key) const = 0;
	//! returns the value assigned to the section-key-pair as a floating point value.
	virtual f32 getValueF(const c8* section, const c8* key) const = 0;
	//! returns the value assigned to the section-key-pair as a boolean.
	virtual bool getValueB(const c8* section, const c8* key) const = 0;
	//! returns the value assigned to the section-key-pair as an Irrlicht key code.
	virtual EKEY_CODE getValueK(const c8* section, const c8* key) const = 0;
	//! returns the value as an E_DRIVER_TYPE value. The string should have the same
	//! identifiers as the values. For example a string 'edt_null' will be converted to video::EDT_NULL
	//! (which is also the default)
	virtual video::E_DRIVER_TYPE getValueDrv(const c8* section, const c8* key) const = 0;
	//! returns the value assigned to the section-key-pair as an unsigned 32bit integer
	virtual u32 getValueU32(const c8* section, const c8* key) const = 0;

	//! returns the value assigned to the section-key-pair as a 2 dimensional value.
	template<class T>
	SValue2D<T> getValue2D(const c8* section, const c8* key) const
	{
		return SValue2D<T>(getValue(section,key));
	}
	//! returns the value assigned to the section-key-pair as a 3 dimensional value.
	template <class T>
	SValue3D<T> getValue3D(const c8* section, const c8 *key) const
	{
		return SValue3D<T>(getValue(section,key));
	}
	//! returns the value assigned to the section-key-pair as a 4 dimensional value.
	template <class T>
	SValue4D<T> getValue4D(const c8* section, const c8* key) const
	{
		return SValue4D<T>(getValue(section,key));
	}

	//! Assigns a new ASCII-string value to the section-key-pair.
	virtual void setValue(const c8* section, const c8* key, const c8* value) = 0;
	//! Assigns a new integer value to the section-key-pair.
	virtual void setValue(const c8* section, const c8* key, s32 value) = 0;
	//! Assigns a new floating point value to the section-key-pair.
	virtual void setValue(const c8* section, const c8* key, f32 value) = 0;
	//! Assigns a new boolean value to the section-key-pair.
	virtual void setValue(const c8* section, const c8* key, bool value) = 0;
	//! Assigns a new Irrlicht key code value to the section-key-pair.
	virtual void setValue(const c8* section, const c8* key, EKEY_CODE value) = 0;
	//! Assigns a new Irrlicht driver type value to the section-key-pair.
	virtual void setValue(const c8* section, const c8* key, video::E_DRIVER_TYPE value) = 0;
	//! Assigns a new unsigned 32bit integer value to the section-key-pair
	virtual void setValue(const c8* section, const c8* key, u32 value) = 0;

	//! Assigns a new 2 dimensional value to the section-key-pair.
	template <class T>
	void setValue(const c8* section, const c8* key, SValue2D<T> value)
	{
		setValue(section,key,value.toString().c_str());
	}
	//! Assigns a new 3 dimensional value to the section-key-pair.
	template <class T>
	void setValue(const c8* section, const c8* key, SValue3D<T> value)
	{
		setValue(section,key,value.toString().c_str());
	}
	//! Assigns a new 4 dimensional value to the section-key-pair.
	template <class T>
	void setValue(const c8* section, const c8* key, SValue4D<T> value)
	{
		setValue(section,key,value.toString().c_str());
	}

	//! Returns all sections stored in the file
	virtual core::array<SSection*> getAllSections() const = 0;
	//! Returns the section with the name 'name' or 0 if no section with this name exist.
	virtual SSection* getSection(const c8* name) const = 0;
	//! Removes all sections and keys from the file
	virtual void removeAll() = 0;
	//! Adds a new section with the name 'name' to the file
	virtual void addSection(const c8* name) = 0;

	//! Structure for holding data about a key.
	struct SKey
	{
		//! Name of the key
		core::stringc Name;
		//! Value of the key
		core::stringc Value;
		//! Comment for this key
		core::stringc Comment;
	};

	//! Structure for holding data about a section.
	struct SSection
	{
		//! Name of the section
		core::stringc Name;
		//! Array of keys that belong to the section
		core::array<SKey*> Keys;
		//! Comment for this section
		core::stringc Comment;
	};
};

//! Creates an IrrIni object from a filename. You need to pass a valid pointer to the filesystem if you want to save the file to disk.
IrrIni* createIniFile(const c8* file, IFileSystem* fileSystem=0, bool saveOnDestroy=false);
//! Creates an IrrIni object from an already opend file. You need to pass a valid pointer to the filesystem if you want to save the file to disk.
IrrIni* createIniFile(IReadFile* file, IFileSystem* fileSystem=0, bool saveOnDestroy=false);
//! Creates an empty IrrIni object. If you pass 0 for a filesystem pointer you cannot save the file disk later.
IrrIni* createIniFileEmpty(IFileSystem* fileSystem=0);

} // end namespace io
} // end namespace irr

/*! \file IrrIni.h
\brief Main header file of IrrINI, the only file needed to include.
*/

#endif // __IRR_INI_H_INCLUDED__

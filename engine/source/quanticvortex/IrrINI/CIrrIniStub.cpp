// Copyright (C) 2007-2009 Matthias Specht
// For conditions of distribution and use, see copyright notice in license.txt
#include "CIrrIniStub.h"

namespace irr
{
namespace io
{

CIrrIniStub::CIrrIniStub(IFileSystem* fileSystem, const c8* file, bool save)
: FileSystem(fileSystem), Content(""), SaveOnDestroy(save)
{
	if(FileSystem)
		FileSystem->grab();

	if(file)
	{
		FullFileName = file;

		if(FileSystem)
		{
			IReadFile* readFile = fileSystem->createAndOpenFile(file);
			if(readFile)
			{
				s32 size = readFile->getSize();
				c8* buffer = new c8[size+2];
				readFile->read(buffer,size);
				buffer[size+1] = 0x0;
				Content = buffer;
				delete [] buffer;
			}
		}
		else
		{
			FILE* fp = fopen(FullFileName.c_str(), "rb");
			if(fp)
			{
				fseek(fp,0,SEEK_END);
				s32 size = ftell(fp);
				fseek(fp,0,SEEK_SET);

				c8* buffer = new c8[size+2];
				fread(buffer,sizeof(char),size,fp);
				buffer[size+1] = 0x0;
				Content = buffer;
				delete buffer;

				fclose(fp);
			}
		}
	}
}

CIrrIniStub::~CIrrIniStub()
{
	if(SaveOnDestroy)
		save();

	removeAll();

	if(FileSystem)
		FileSystem->drop();
}

bool CIrrIniStub::load()
{
	if(!Content.size())
		return false;

	bool inSection=false;

	SSection* currentSection=0;

	core::stringc buffer;
	core::stringc comment;
	s32 eol_pos = Content.findFirst('\n');
	s32 sol_pos = 0;

	while(eol_pos != -1)
	{
		buffer = Content.subString( sol_pos, eol_pos-sol_pos );

		if( Content.equalsn("##", 2) || Content.equalsn(";", 1) )
		{
			comment = buffer;
			comment.trim( ";# \t\n\r" );

			sol_pos = eol_pos+1;
			eol_pos = Content.findNext('\n', sol_pos);
			continue;
		}

		core::stringc str(buffer);
		if( buffer.findFirst('[') != -1 && buffer.findFirst(']') != -1)
		{
			if(inSection)
			{
				Sections.push_back(currentSection);
				currentSection=0;
			}

			inSection=true;
			s32 open=str.findFirst('[');
			s32 close=str.findLast(']');
			s32 len = close-open-1;
			core::stringc name = str.subString(open+1,len);
			name.trim();

			currentSection = new SSection;
			currentSection->Name = name;
			currentSection->Comment = comment;
			comment = "";
		}
		else if( buffer.findFirst('=') != -1)
		{
			core::stringc str(buffer);
			core::stringc key;
			core::stringc value;

			str.trim();
			s32 eq = str.findFirst('=');
			key = str.subString(0,eq);
			s32 len = str.size()-eq-2;
			value = str.subString(eq+1,len+1);

			key.trim();
			value.trim();

			SKey *k = new SKey;
			k->Name = key;
			k->Value = value;
			k->Comment = comment;
			comment = "";

			if(currentSection)
				currentSection->Keys.push_back(k);
			else
				delete k;
		}

		sol_pos = eol_pos+1;
		eol_pos = Content.findNext('\n', sol_pos);
	}

	if(currentSection)
	{
		buffer = Content.subString( sol_pos, Content.size()-sol_pos-1 );

		if( buffer.findFirst('=') != -1)
		{
			core::stringc str(buffer);
			core::stringc key;
			core::stringc value;

			str.trim();
			s32 eq = str.findFirst('=');
			key = str.subString(0,eq);
			s32 len = str.size()-eq-2;
			value = str.subString(eq+1,len+1);

			key.trim();
			value.trim();

			SKey *k = new SKey;
			k->Name = key;
			k->Value = value;

			currentSection->Keys.push_back(k);
		}

		Sections.push_back(currentSection);
	}
	currentSection=0;

	return true;
}

bool CIrrIniStub::save()
{
	if(!FullFileName.size() || !FileSystem)
		return false;

	core::stringc buffer;

	IWriteFile* fp = FileSystem->createAndWriteFile(FullFileName.c_str());
	if(!fp)
		return false;

	for(u32 i=0; i<Sections.size(); ++i)
	{
		if( Sections[i]->Comment.size() > 0 )
		{
			buffer += core::stringc("; ") + core::stringc(Sections[i]->Comment) + core::stringc("\r\n");
		}

		buffer += core::stringc("[") + core::stringc(Sections[i]->Name) + core::stringc("]\r\n");

		for(u32 j=0; j<Sections[i]->Keys.size(); ++j)
		{
			if( Sections[i]->Keys[j]->Comment.size() > 0 )
			{
				buffer += core::stringc("; ") + core::stringc(Sections[i]->Keys[j]->Comment) + core::stringc("\r\n");
			}

			buffer += core::stringc(Sections[i]->Keys[j]->Name.c_str()) + core::stringc("=") + core::stringc(Sections[i]->Keys[j]->Value) + core::stringc("\r\n");
		}

		buffer += "\r\n";
	}

	fp->write(buffer.c_str(), buffer.size());
	fp->drop();
	return true;
}

void CIrrIniStub::setSaveFileName(core::stringc fileName)
{
	FullFileName = fileName;
}

void CIrrIniStub::setSaveOnDestroy(bool enabled)
{
	SaveOnDestroy = enabled;
}

void CIrrIniStub::setFileSystem(IFileSystem* fileSystem)
{
	if(FileSystem)
		FileSystem->drop();

	FileSystem = fileSystem;

	if(FileSystem)
		FileSystem->grab();
}

bool CIrrIniStub::keyExists(const c8* section, const c8* key ) const
{
	for(u32 i=0; i<Sections.size(); ++i)
	{
		if( Sections[i]->Name.equals_ignore_case(section) )
		{
			for(u32 j=0; j<Sections[i]->Keys.size(); ++j)
			{
				if( Sections[i]->Keys[j]->Name.equals_ignore_case(key) )
					return true;
			}

			break;
		}
	}

	return false;
}

const c8* CIrrIniStub::getComment( const c8* section, const c8* key ) const
{
	if( !section )
		return 0;

	for( u32 i=0; i<Sections.size(); ++i )
	{
		if( Sections[i]->Name.equals_ignore_case( section ) )
		{
			if( !key )
			{
				return Sections[i]->Comment.c_str();
			}

			for( u32 j=0; j<Sections[i]->Keys.size(); ++j )
			{
				if( Sections[i]->Keys[j]->Name.equals_ignore_case( key ) )
				{
					return Sections[i]->Keys[j]->Comment.c_str();
				}
			}

			break;
		}
	}

	return 0;
}

void CIrrIniStub::setSectionComment( const c8* section, const c8* comment )
{
	if( !section )
		return;

	for( u32 i=0; i<Sections.size(); ++i )
	{
		if( Sections[i]->Name.equals_ignore_case( section ) )
		{
			Sections[i]->Comment = comment;
			return;
		}
	}
}

void CIrrIniStub::setKeyComment( const c8* section, const c8* key, const c8* comment )
{
	if( !section || !key )
		return;

	for( u32 i=0; i<Sections.size(); ++i )
	{
		if( Sections[i]->Name.equals_ignore_case( section ) )
		{
			for( u32 j=0; j<Sections[i]->Keys.size(); ++j )
			{
				if( Sections[i]->Keys[j]->Name.equals_ignore_case( key ) )
				{
					Sections[i]->Keys[j]->Comment = comment;
					return;
				}
			}

			break;
		}
	}
}

const c8* CIrrIniStub::getValue(const c8* section, const c8* key) const
{
	if( !section || !key )
		return 0;

	for(u32 i=0; i<Sections.size(); ++i)
	{
		if( Sections[i]->Name.equals_ignore_case(section) )
		{
			for(u32 j=0; j<Sections[i]->Keys.size(); ++j)
			{
				if( Sections[i]->Keys[j]->Name.equals_ignore_case(key) )
				{
					return Sections[i]->Keys[j]->Value.c_str();
				}
			}
		}
	}

	return 0;
}

s32 CIrrIniStub::getValueI(const c8* section, const c8* key) const
{
	const c8* buf = getValue(section,key);
	if(buf)
		return atoi(buf);
	return 0;
}

u32 CIrrIniStub::getValueU32(const c8* section, const c8* key) const
{
	const c8* buf = getValue(section,key);
	if(buf)
		return (u32)atoi(buf);
	return 0;
}

f32 CIrrIniStub::getValueF(const c8* section, const c8* key) const
{
	const c8* buf = getValue(section,key);
	if(buf)
		return (f32)atof(buf);
	return 0;
}

bool CIrrIniStub::getValueB(const c8* section, const c8* key) const
{
	const c8* buf = getValue(section,key);
	if(buf)
		return strcmp(buf,"true") == 0;
	return false;
}

EKEY_CODE CIrrIniStub::getValueK(const c8* section, const c8* key) const
{
	const c8* buf = getValue(section,key);

	if(buf)
		return convertIrrKeyCode(buf);

	return (EKEY_CODE)0x0;
}

void CIrrIniStub::setValue(const c8* section, const c8* key, const c8* value)
{
	if( !keyExists(section, key) )
	{
		SKey* k = new SKey;
		k->Name = key;
		k->Value = value;

		for(u32 i=0; i<Sections.size(); ++i)
		{
			if( Sections[i]->Name.equals_ignore_case(section) )
			{
				for(u32 j=0; j<Sections[i]->Keys.size(); ++j)
				{
					if( Sections[i]->Keys[j]->Name.equals_ignore_case(key) )
					{
						Sections[i]->Keys[j]->Value = value;
						break;
					}
				}

				Sections[i]->Keys.push_back(k);
				break;
			}
		}

		return;
	}

	for(u32 i=0; i<Sections.size(); ++i)
	{
		if( Sections[i]->Name.equals_ignore_case(section) )
		{
			for(u32 j=0; j<Sections[i]->Keys.size(); ++j)
			{
				if( Sections[i]->Keys[j]->Name.equals_ignore_case(key) )
				{
					Sections[i]->Keys[j]->Value = value;
					return;
				}
			}

			break;
		}
	}
}

void CIrrIniStub::setValue(const c8* section, const c8* key, s32 value)
{
	c8 buf[20];
	sprintf(buf,"%d",value);
	setValue(section,key,buf);
}

void CIrrIniStub::setValue(const c8* section, const c8* key, u32 value)
{
	setValue(section,key,(s32)value);
}

void CIrrIniStub::setValue(const c8* section, const c8* key, f32 value)
{
	c8 buf[20];
	sprintf(buf,"%.4f",value);
	setValue(section,key,buf);
}

void CIrrIniStub::setValue(const c8* section, const c8* key, bool value)
{
	c8 buf[6];
	if(value)
		strncpy(buf,"true",6);
	else
		strncpy(buf,"false",6);
	setValue(section,key,buf);
}

void CIrrIniStub::setValue(const c8* section, const c8* key, EKEY_CODE value)
{
	setValue(section,key,convertIrrKeyCode(value));
}

void CIrrIniStub::addSection(const c8* name)
{
	SSection* s = new SSection;
	s->Name = name;
	Sections.push_back(s);
}

CIrrIniStub::SSection* CIrrIniStub::getSection(const c8 *section) const
{
	for(u32 i=0; i<Sections.size(); ++i)
	{
		if( Sections[i]->Name.equals_ignore_case(section) )
			return Sections[i];
	}

	return 0;
}

void CIrrIniStub::removeAll()
{
	for(u32 i=0; i<Sections.size(); ++i)
	{
		for(u32 j=0; j<Sections[i]->Keys.size(); ++j)
			delete Sections[i]->Keys[j];

		Sections[i]->Keys.clear();
		delete Sections[i];
	}
	Sections.clear();
}

core::array<CIrrIniStub::SSection*> CIrrIniStub::getAllSections() const
{
	return Sections;
}

void CIrrIniStub::setValue(const c8* section, const c8* key, video::E_DRIVER_TYPE value)
{
	core::stringc str;


	switch(value)
	{
	case video::EDT_NULL:
		str = "EDT_NULL";
		break;

	case video::EDT_SOFTWARE:
		str = "EDT_SOFTWARE";
		break;

	case video::EDT_BURNINGSVIDEO:
		str = "EDT_BURNINGSVIDEO";
		break;

	case video::EDT_DIRECT3D8:
		str = "EDT_DIRECT3D8";
		break;

	case video::EDT_DIRECT3D9:
		str = "EDT_DIRECT3D9";
		break;

	case video::EDT_OPENGL:
		str = "EDT_OPENGL";
		break;
	}

	setValue(section,key,str.c_str());
}

video::E_DRIVER_TYPE CIrrIniStub::getValueDrv(const c8* section, const c8* key) const
{
	core::stringc str(getValue(section,key));

	if(str.equals_ignore_case("EDT_SOFTWARE"))
		return video::EDT_SOFTWARE;
	else if(str.equals_ignore_case("EDT_BURNINGSVIDEO"))
		return video::EDT_BURNINGSVIDEO;
	else if(str.equals_ignore_case("EDT_DIRECT3D8"))
		return video::EDT_DIRECT3D8;
	else if(str.equals_ignore_case("EDT_DIRECT3D9"))
		return video::EDT_DIRECT3D9;
	else if(str.equals_ignore_case("EDT_OPENGL"))
		return video::EDT_OPENGL;
	else
		return video::EDT_NULL;
}


EKEY_CODE CIrrIniStub::convertIrrKeyCode(core::stringc str) const
{
	if(str.equals_ignore_case("MOUSE_L"))
		return KEY_LBUTTON;
	else if(str.equals_ignore_case("MOUSE_R"))
		return KEY_RBUTTON;
	else if(str.equals_ignore_case("MOUSE_M"))
		return KEY_MBUTTON;
	else if(str.equals_ignore_case("XBUTTON_1"))
		return KEY_XBUTTON1;
	else if(str.equals_ignore_case("XBUTTON_2"))
		return KEY_XBUTTON2;
	else if(str.equals_ignore_case("BACK"))
		return KEY_BACK;
	else if(str.equals_ignore_case("TAB"))
		return KEY_TAB;
	else if(str.equals_ignore_case("RETURN"))
		return KEY_RETURN;
	else if(str.equals_ignore_case("CLEAR"))
		return KEY_CLEAR;
	else if(str.equals_ignore_case("SHIFT"))
		return KEY_SHIFT;
	else if(str.equals_ignore_case("CTRL"))
		return KEY_CONTROL;
	else if(str.equals_ignore_case("MENU"))
		return KEY_MENU;
	else if(str.equals_ignore_case("PAUSE"))
		return KEY_PAUSE;
	else if(str.equals_ignore_case("CAPITAL"))
		return KEY_CAPITAL;
	else if(str.equals_ignore_case("ESCAPE"))
		return KEY_ESCAPE;
	else if(str.equals_ignore_case("SPACE"))
		return KEY_SPACE;
	else if(str.equals_ignore_case("PRIOR"))
		return KEY_PRIOR;
	else if(str.equals_ignore_case("NEXT"))
		return KEY_NEXT;
	else if(str.equals_ignore_case("END"))
		return KEY_END;
	else if(str.equals_ignore_case("HOME"))
		return KEY_HOME;
	else if(str.equals_ignore_case("LEFT"))
		return KEY_LEFT;
	else if(str.equals_ignore_case("UP"))
		return KEY_UP;
	else if(str.equals_ignore_case("RIGHT"))
		return KEY_RIGHT;
	else if(str.equals_ignore_case("DOWN"))
		return KEY_DOWN;
	else if(str.equals_ignore_case("SELECT"))
		return KEY_SELECT;
	else if(str.equals_ignore_case("PRINT"))
		return KEY_PRINT;
	else if(str.equals_ignore_case("EXECUT"))
		return KEY_EXECUT;
	else if(str.equals_ignore_case("SNAPSHOT"))
		return KEY_SNAPSHOT;
	else if(str.equals_ignore_case("INSERT"))
		return KEY_INSERT;
	else if(str.equals_ignore_case("DELETE"))
		return KEY_DELETE;
	else if(str.equals_ignore_case("HELP"))
		return KEY_HELP;
	else if(str.equals_ignore_case("0"))
		return KEY_KEY_0;
	else if(str.equals_ignore_case("1"))
		return KEY_KEY_1;
	else if(str.equals_ignore_case("2"))
		return KEY_KEY_2;
	else if(str.equals_ignore_case("3"))
		return KEY_KEY_3;
	else if(str.equals_ignore_case("4"))
		return KEY_KEY_4;
	else if(str.equals_ignore_case("5"))
		return KEY_KEY_5;
	else if(str.equals_ignore_case("6"))
		return KEY_KEY_6;
	else if(str.equals_ignore_case("7"))
		return KEY_KEY_7;
	else if(str.equals_ignore_case("8"))
		return KEY_KEY_8;
	else if(str.equals_ignore_case("9"))
		return KEY_KEY_9;
	else if(str.equals_ignore_case("A"))
		return KEY_KEY_A;
	else if(str.equals_ignore_case("B"))
		return KEY_KEY_B;
	else if(str.equals_ignore_case("C"))
		return KEY_KEY_C;
	else if(str.equals_ignore_case("D"))
		return KEY_KEY_D;
	else if(str.equals_ignore_case("E"))
		return KEY_KEY_E;
	else if(str.equals_ignore_case("F"))
		return KEY_KEY_F;
	else if(str.equals_ignore_case("G"))
		return KEY_KEY_G;
	else if(str.equals_ignore_case("H"))
		return KEY_KEY_H;
	else if(str.equals_ignore_case("I"))
		return KEY_KEY_I;
	else if(str.equals_ignore_case("J"))
		return KEY_KEY_J;
	else if(str.equals_ignore_case("K"))
		return KEY_KEY_K;
	else if(str.equals_ignore_case("L"))
		return KEY_KEY_L;
	else if(str.equals_ignore_case("M"))
		return KEY_KEY_M;
	else if(str.equals_ignore_case("N"))
		return KEY_KEY_N;
	else if(str.equals_ignore_case("O"))
		return KEY_KEY_O;
	else if(str.equals_ignore_case("P"))
		return KEY_KEY_P;
	else if(str.equals_ignore_case("Q"))
		return KEY_KEY_Q;
	else if(str.equals_ignore_case("R"))
		return KEY_KEY_R;
	else if(str.equals_ignore_case("S"))
		return KEY_KEY_S;
	else if(str.equals_ignore_case("T"))
		return KEY_KEY_T;
	else if(str.equals_ignore_case("U"))
		return KEY_KEY_U;
	else if(str.equals_ignore_case("V"))
		return KEY_KEY_V;
	else if(str.equals_ignore_case("W"))
		return KEY_KEY_W;
	else if(str.equals_ignore_case("x"))
		return KEY_KEY_X;
	else if(str.equals_ignore_case("Y"))
		return KEY_KEY_Y;
	else if(str.equals_ignore_case("Z"))
		return KEY_KEY_Z;
	else if(str.equals_ignore_case("LWIN"))
		return KEY_LWIN;
	else if(str.equals_ignore_case("RWIN"))
		return KEY_RWIN;
	else if(str.equals_ignore_case("APPS"))
		return KEY_APPS;
	else if(str.equals_ignore_case("SLEEP"))
		return KEY_SLEEP;
	else if(str.equals_ignore_case("NUMPAD0"))
		return KEY_NUMPAD0;
	else if(str.equals_ignore_case("NUMPAD1"))
		return KEY_NUMPAD1;
	else if(str.equals_ignore_case("NUMPAD2"))
		return KEY_NUMPAD2;
	else if(str.equals_ignore_case("NUMPAD3"))
		return KEY_NUMPAD3;
	else if(str.equals_ignore_case("NUMPAD4"))
		return KEY_NUMPAD4;
	else if(str.equals_ignore_case("NUMPAD5"))
		return KEY_NUMPAD5;
	else if(str.equals_ignore_case("NUMPAD6"))
		return KEY_NUMPAD6;
	else if(str.equals_ignore_case("NUMPAD7"))
		return KEY_NUMPAD7;
	else if(str.equals_ignore_case("NUMPAD8"))
		return KEY_NUMPAD8;
	else if(str.equals_ignore_case("NUMPAD9"))
		return KEY_NUMPAD9;
	else if(str.equals_ignore_case("MULTIPLY"))
		return KEY_MULTIPLY;
	else if(str.equals_ignore_case("ADD"))
		return KEY_ADD;
	else if(str.equals_ignore_case("SEPARATOR"))
		return KEY_SEPARATOR;
	else if(str.equals_ignore_case("SUBTRACT"))
		return KEY_SUBTRACT;
	else if(str.equals_ignore_case("DECIMAL"))
		return KEY_DECIMAL;
	else if(str.equals_ignore_case("DIVIDE"))
		return KEY_DIVIDE;
	else if(str.equals_ignore_case("F1"))
		return KEY_F1;
	else if(str.equals_ignore_case("F2"))
		return KEY_F2;
	else if(str.equals_ignore_case("F3"))
		return KEY_F3;
	else if(str.equals_ignore_case("F4"))
		return KEY_F4;
	else if(str.equals_ignore_case("F5"))
		return KEY_F5;
	else if(str.equals_ignore_case("F6"))
		return KEY_F6;
	else if(str.equals_ignore_case("F7"))
		return KEY_F7;
	else if(str.equals_ignore_case("F8"))
		return KEY_F8;
	else if(str.equals_ignore_case("F9"))
		return KEY_F9;
	else if(str.equals_ignore_case("F10"))
		return KEY_F10;
	else if(str.equals_ignore_case("F11"))
		return KEY_F11;
	else if(str.equals_ignore_case("F12"))
		return KEY_F12;
	else if(str.equals_ignore_case("NUMLOCK"))
		return KEY_NUMLOCK;
	else if(str.equals_ignore_case("COMMA"))
		return KEY_COMMA;
	else if(str.equals_ignore_case("PLUS"))
		return KEY_PLUS;
	else if(str.equals_ignore_case("MINUS"))
		return KEY_MINUS;
	else if(str.equals_ignore_case("PERIOD"))
		return KEY_PERIOD;
	else if(str.equals_ignore_case("PLAY"))
		return KEY_PLAY;
	else if(str.equals_ignore_case("ZOOM"))
		return KEY_ZOOM;
	else
		return (EKEY_CODE)0x0;
}

const char* CIrrIniStub::convertIrrKeyCode(EKEY_CODE value) const
{
	switch(value)
	{
	case KEY_LBUTTON: return "MOUSE_L";
	case KEY_RBUTTON: return "MOUSE_R";
	case KEY_CANCEL: return "MOUSE_M";
	case KEY_MBUTTON: return "MOUSE_M";
	case KEY_XBUTTON1: return "XBUTTON_1";
	case KEY_XBUTTON2: return "XBUTTON_2";
	case KEY_BACK: return "BACK";
	case KEY_TAB: return "TAB";
	case KEY_CLEAR: return "CLEAR";
	case KEY_RETURN: return "RETURN";
	case KEY_SHIFT: return "SHIFT";
	case KEY_CONTROL: return "CTRL";
	case KEY_MENU: return "MENU";
	case KEY_PAUSE: return "PAUSE";
	case KEY_CAPITAL: return "CAPITAL";
	case KEY_ESCAPE: return "ESCAPE";
	case KEY_SPACE: return "SPACE";
	case KEY_PRIOR: return "PRIOR";
	case KEY_NEXT: return "NEXT";
	case KEY_END: return "END";
	case KEY_HOME: return "HOME";
	case KEY_LEFT: return "LEFT";
	case KEY_UP: return "UP";
	case KEY_RIGHT: return "RIGHT";
	case KEY_DOWN: return "DOWN";
	case KEY_SELECT: return "SELECT";
	case KEY_PRINT: return "PRINT";
	case KEY_EXECUT: return "EXECUT";
	case KEY_SNAPSHOT: return "SNAPSHOT";
	case KEY_INSERT: return "INSERT";
	case KEY_DELETE: return "DELETE";
	case KEY_HELP: return "HELP";
	case KEY_KEY_0: return "0";
	case KEY_KEY_1: return "1";
	case KEY_KEY_2: return "2";
	case KEY_KEY_3: return "3";
	case KEY_KEY_4: return "4";
	case KEY_KEY_5: return "5";
	case KEY_KEY_6: return "6";
	case KEY_KEY_7: return "7";
	case KEY_KEY_8: return "8";
	case KEY_KEY_9: return "9";
	case KEY_KEY_A: return "A";
	case KEY_KEY_B: return "B";
	case KEY_KEY_C: return "C";
	case KEY_KEY_D: return "D";
	case KEY_KEY_E: return "E";
	case KEY_KEY_F: return "F";
	case KEY_KEY_G: return "G";
	case KEY_KEY_H: return "H";
	case KEY_KEY_I: return "I";
	case KEY_KEY_J: return "J";
	case KEY_KEY_K: return "K";
	case KEY_KEY_L: return "L";
	case KEY_KEY_M: return "M";
	case KEY_KEY_N: return "N";
	case KEY_KEY_O: return "O";
	case KEY_KEY_P: return "P";
	case KEY_KEY_Q: return "Q";
	case KEY_KEY_R: return "R";
	case KEY_KEY_S: return "S";
	case KEY_KEY_T: return "T";
	case KEY_KEY_U: return "U";
	case KEY_KEY_V: return "V";
	case KEY_KEY_W: return "W";
	case KEY_KEY_X: return "x";
	case KEY_KEY_Y: return "Y";
	case KEY_KEY_Z: return "Z";
	case KEY_LWIN: return "LWIN";
	case KEY_RWIN: return "RWIN";
	case KEY_APPS: return "APPS";
	case KEY_SLEEP: return "SLEEP";
	case KEY_NUMPAD0: return "NUMPAD0";
	case KEY_NUMPAD1: return "NUMPAD1";
	case KEY_NUMPAD2: return "NUMPAD2";
	case KEY_NUMPAD3: return "NUMPAD3";
	case KEY_NUMPAD4: return "NUMPAD4";
	case KEY_NUMPAD5: return "NUMPAD5";
	case KEY_NUMPAD6: return "NUMPAD6";
	case KEY_NUMPAD7: return "NUMPAD7";
	case KEY_NUMPAD8: return "NUMPAD8";
	case KEY_NUMPAD9: return "NUMPAD9";
	case KEY_MULTIPLY: return "MULTIPLY";
	case KEY_ADD: return "ADD";
	case KEY_SEPARATOR: return "SEPARATOR";
	case KEY_SUBTRACT: return "SUBTRACT";
	case KEY_DECIMAL: return "DECIMAL";
	case KEY_DIVIDE: return "DIVIDE";
	case KEY_F1: return "F1";
	case KEY_F2: return "F2";
	case KEY_F3: return "F3";
	case KEY_F4: return "F4";
	case KEY_F5: return "F5";
	case KEY_F6: return "F6";
	case KEY_F7: return "F7";
	case KEY_F8: return "F8";
	case KEY_F9: return "F9";
	case KEY_F10: return "F10";
	case KEY_F11: return "F11";
	case KEY_F12: return "F12";
	case KEY_NUMLOCK: return "NUMLOCK";
	case KEY_COMMA: return "COMMA";
	case KEY_PLUS: return "PLUS";
	case KEY_MINUS: return "MINUS";
	case KEY_PERIOD: return "PERIOD";
	case KEY_PLAY: return "PLAY";
	case KEY_ZOOM: return "ZOOM";
	default: return "NONE";
	}
}

}
}

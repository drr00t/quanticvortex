.PHONY: clean All

All:
	@echo ----------Building project:[ QuanticVortex_Core - Windows x86 - DLL - Debug ]----------
	@cd "..\engine\builds\codelite" && "c:/mingw/bin/mingw32-make.EXE"  -j 2 -f "QuanticVortex_Core.mk"
	@echo ----------Building project:[ 01_Sample - Windows x86 - DLL - Debug ]----------
	@cd "01_Sample\builds\cl" && "c:/mingw/bin/mingw32-make.EXE"  -j 2 -f "01_Sample.mk"
clean:
	@echo ----------Cleaning project:[ QuanticVortex_Core - Windows x86 - DLL - Debug ]----------
	@cd "..\engine\builds\codelite" && "c:/mingw/bin/mingw32-make.EXE"  -j 2 -f "QuanticVortex_Core.mk"  clean
	@echo ----------Cleaning project:[ 01_Sample - Windows x86 - DLL - Debug ]----------
	@cd "01_Sample\builds\cl" && "c:/mingw/bin/mingw32-make.EXE"  -j 2 -f "01_Sample.mk" clean

.PHONY: clean All

All:
	@echo ----------Building project:[ QuanticVortex_Core - Windows x86 - DLL - Debug ]----------
	@cd "..\engine\builds\codelite" && "mingw32-make.exe"  -j 8 -f "QuanticVortex_Core.mk"
	@echo ----------Building project:[ 01_HelloWord - Windows x86 - DLL - Debug ]----------
	@cd "01_HelloWord\builds\cl" && "mingw32-make.exe"  -j 8 -f "01_HelloWord.mk"
clean:
	@echo ----------Cleaning project:[ QuanticVortex_Core - Windows x86 - DLL - Debug ]----------
	@cd "..\engine\builds\codelite" && "mingw32-make.exe"  -j 8 -f "QuanticVortex_Core.mk"  clean
	@echo ----------Cleaning project:[ 01_HelloWord - Windows x86 - DLL - Debug ]----------
	@cd "01_HelloWord\builds\cl" && "mingw32-make.exe"  -j 8 -f "01_HelloWord.mk" clean

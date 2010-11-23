.PHONY: clean All

All:
	@echo ----------Building project:[ QuanticVortex_Core - Windows x86 - DLL - Debug ]----------
	@cd "..\engine\builds\codelite" && "mingw32-make.exe"  -j 8 -f "QuanticVortex_Core.mk"
	@echo ----------Building project:[ QuanticVortexAddin_Irrlicht - Windows x86 - DLL - Debug ]----------
	@cd "..\addins\QuanticVortexAddin_Irrlicht\builds" && "mingw32-make.exe"  -j 8 -f "QuanticVortexAddin_Irrlicht.mk"
clean:
	@echo ----------Cleaning project:[ QuanticVortex_Core - Windows x86 - DLL - Debug ]----------
	@cd "..\engine\builds\codelite" && "mingw32-make.exe"  -j 8 -f "QuanticVortex_Core.mk"  clean
	@echo ----------Cleaning project:[ QuanticVortexAddin_Irrlicht - Windows x86 - DLL - Debug ]----------
	@cd "..\addins\QuanticVortexAddin_Irrlicht\builds" && "mingw32-make.exe"  -j 8 -f "QuanticVortexAddin_Irrlicht.mk" clean

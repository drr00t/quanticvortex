.PHONY: clean All

All:
	@echo ----------Building project:[ QuanticVortexAddin_Irrlicht - Windows x86 - DLL - Debug ]----------
	@cd "..\addins\QuanticVortexAddin_Irrlicht\builds" && "mingw32-make.exe"  -j 8 -f "QuanticVortexAddin_Irrlicht.mk"
clean:
	@echo ----------Cleaning project:[ QuanticVortexAddin_Irrlicht - Windows x86 - DLL - Debug ]----------
	@cd "..\addins\QuanticVortexAddin_Irrlicht\builds" && "mingw32-make.exe"  -j 8 -f "QuanticVortexAddin_Irrlicht.mk" clean

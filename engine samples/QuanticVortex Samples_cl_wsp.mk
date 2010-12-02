.PHONY: clean All

All:
	@echo ----------Building project:[ QuanticVortex_Core - Windows x86 - DLL - Debug ]----------
	@cd "..\engine\builds\codelite" && "mingw32-make.exe"  -j 8 -f "QuanticVortex_Core.mk"
clean:
	@echo ----------Cleaning project:[ QuanticVortex_Core - Windows x86 - DLL - Debug ]----------
	@cd "..\engine\builds\codelite" && "mingw32-make.exe"  -j 8 -f "QuanticVortex_Core.mk" clean

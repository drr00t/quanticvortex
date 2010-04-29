.PHONY: clean All

All:
	@echo ----------Building project:[ QuanticVortex_Core - Windows x86 - DLL - Debug ]----------
	@cd "..\engine\builds\codelite" && "C:\MinGW\bin\make.exe"  -j 2 -f "QuanticVortex_Core.mk"
clean:
	@echo ----------Cleaning project:[ QuanticVortex_Core - Windows x86 - DLL - Debug ]----------
	@cd "..\engine\builds\codelite" && "C:/MinGW/bin/make.exe"  -j 2 -f "QuanticVortex_Core.mk" clean

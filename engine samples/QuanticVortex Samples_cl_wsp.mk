.PHONY: clean All

All:
	@echo ----------Building project:[ QuanticVortex_Core - Windows x86 - DLL - Debug ]----------
	@cd "..\engine\builds\codelite" && "c:/mingw/bin/make.EXE"  -j 2 -f "QuanticVortex_Core.mk"
	@echo ----------Building project:[ QuanticVortex_Tests - Debug ]----------
	@cd "..\engine tests\builds\codelite" && "c:/mingw/bin/make.EXE"  -j 2 -f "QuanticVortex_Tests.mk"
clean:
	@echo ----------Cleaning project:[ QuanticVortex_Core - Windows x86 - DLL - Debug ]----------
	@cd "..\engine\builds\codelite" && "c:/mingw/bin/make.EXE"  -j 2 -f "QuanticVortex_Core.mk"  clean
	@echo ----------Cleaning project:[ QuanticVortex_Tests - Debug ]----------
	@cd "..\engine tests\builds\codelite" && "c:/mingw/bin/make.EXE"  -j 2 -f "QuanticVortex_Tests.mk" clean

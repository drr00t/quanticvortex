.PHONY: clean All

All:
	@echo ----------Building project:[ 01_Sample - Debug ]----------
	@cd "01_Sample\builds\cl" && "C:\MinGW\bin\make.exe"  -j 2 -f "01_Sample.mk"
clean:
	@echo ----------Cleaning project:[ 01_Sample - Debug ]----------
	@cd "01_Sample\builds\cl" && "C:/MinGW/bin/make.exe"  -j 2 -f "01_Sample.mk" clean

##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Windows_x86_-_DLL_-_Debug
ProjectName            :=01_Sample
ConfigurationName      :=Windows_x86_-_DLL_-_Debug
IntermediateDirectory  :=../../obj/debug
OutDir                 := $(IntermediateDirectory)
WorkspacePath          := "E:\Projetos\QuanticVortex\engine samples"
ProjectPath            := "E:\Projetos\QuanticVortex\engine samples\01_Sample\builds\cl"
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=adriano
Date                   :=07/18/10
CodeLitePath           :="C:\Program Files\CodeLite"
LinkerName             :=g++
ArchiveTool            :=ar rcus
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
CompilerName           :=g++
C_CompilerName         :=gcc
OutputFile             :=../../../bin/01_Sample_d.exe
Preprocessors          :=$(PreprocessorSwitch)WIN32 $(PreprocessorSwitch)_DEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
MakeDirCommand         :=makedir
CmpOptions             := -g -Wall -fno-rtti $(Preprocessors)
LinkOptions            :=  
IncludePath            :=  "$(IncludeSwitch)." "$(IncludeSwitch)../../include" "$(IncludeSwitch)../../../../engine/include" "$(IncludeSwitch)../../../../dependencies/include/irrlicht/include" "$(IncludeSwitch)../../../../dependencies/include/bullet" "$(IncludeSwitch)../../../../dependencies/include/poco" "$(IncludeSwitch)../../../../dependencies/include/cAudio/include" 
RcIncludePath          :=
Libs                   :=$(LibrarySwitch)QuanticVortex_d 
LibPath                := "$(LibraryPathSwitch)." "$(LibraryPathSwitch)../../../../engine/bin/win32-gcc" 


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects=$(IntermediateDirectory)/source_main$(ObjectSuffix) $(IntermediateDirectory)/source_sdcSylfurDCGame$(ObjectSuffix) 

##
## Main Build Targets 
##
all: $(OutputFile)

$(OutputFile): makeDirStep $(Objects)
	@$(MakeDirCommand) $(@D)
	$(LinkerName) $(OutputSwitch)$(OutputFile) $(Objects) $(LibPath) $(Libs) $(LinkOptions)
	@echo Executing Post Build commands ...
	copy ..\..\..\..\engine\bin\win32-gcc\QuanticVortex_d.dll ..\..\..\bin\QuanticVortex_d.dll
	copy ..\..\..\..\dependencies\bin\win32-gcc\cAudio_d.dll ..\..\..\bin\cAudio_d.dll
	copy ..\..\..\..\dependencies\bin\win32-gcc\Irrlicht_d.dll ..\..\..\bin\Irrlicht_d.dll
	copy ..\..\..\..\dependencies\bin\win32-gcc\OpenAL32.dll ..\..\..\bin\OpenAL32.dll
	copy ..\..\..\..\dependencies\bin\win32-gcc\wrap_oal.dll ..\..\..\bin\wrap_oal.dll
	copy ..\..\..\..\dependencies\bin\win32-gcc\cAp_EAXLegacyPreset.dll ..\..\..\bin\cAp_EAXLegacyPreset.dll
	@echo Done

makeDirStep:
	@$(MakeDirCommand) "../../obj/debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/source_main$(ObjectSuffix): ../../source/main.cpp $(IntermediateDirectory)/source_main$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticVortex/engine samples/01_Sample/source/main.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/source_main$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/source_main$(DependSuffix): ../../source/main.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/source_main$(ObjectSuffix) -MF$(IntermediateDirectory)/source_main$(DependSuffix) -MM "E:/Projetos/QuanticVortex/engine samples/01_Sample/source/main.cpp"

$(IntermediateDirectory)/source_main$(PreprocessSuffix): ../../source/main.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/source_main$(PreprocessSuffix) "E:/Projetos/QuanticVortex/engine samples/01_Sample/source/main.cpp"

$(IntermediateDirectory)/source_sdcSylfurDCGame$(ObjectSuffix): ../../source/sdcSylfurDCGame.cpp $(IntermediateDirectory)/source_sdcSylfurDCGame$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticVortex/engine samples/01_Sample/source/sdcSylfurDCGame.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/source_sdcSylfurDCGame$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/source_sdcSylfurDCGame$(DependSuffix): ../../source/sdcSylfurDCGame.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/source_sdcSylfurDCGame$(ObjectSuffix) -MF$(IntermediateDirectory)/source_sdcSylfurDCGame$(DependSuffix) -MM "E:/Projetos/QuanticVortex/engine samples/01_Sample/source/sdcSylfurDCGame.cpp"

$(IntermediateDirectory)/source_sdcSylfurDCGame$(PreprocessSuffix): ../../source/sdcSylfurDCGame.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/source_sdcSylfurDCGame$(PreprocessSuffix) "E:/Projetos/QuanticVortex/engine samples/01_Sample/source/sdcSylfurDCGame.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/source_main$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/source_main$(DependSuffix)
	$(RM) $(IntermediateDirectory)/source_main$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/source_sdcSylfurDCGame$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/source_sdcSylfurDCGame$(DependSuffix)
	$(RM) $(IntermediateDirectory)/source_sdcSylfurDCGame$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe



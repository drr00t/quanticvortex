##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Windows_x86_-_DLL_-_Debug
ProjectName            :=01_Sample
ConfigurationName      :=Windows_x86_-_DLL_-_Debug
IntermediateDirectory  :=../../obj/debug
OutDir                 := $(IntermediateDirectory)
WorkspacePath          := "E:\Projetos\QuanticMinds\Sylfur-D.C\QuanticVortex\engine samples"
ProjectPath            := "E:\Projetos\QuanticMinds\Sylfur-D.C\QuanticVortex\engine samples\01_Sample\builds\cl"
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=adriano
Date                   :=04/25/10
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
OutputFile             :=../../../bin/win32-gcc/01_Sample_d.exe
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
Objects=$(IntermediateDirectory)/source_main$(ObjectSuffix) $(IntermediateDirectory)/source_sdcSylfurDCGame$(ObjectSuffix) $(IntermediateDirectory)/source_sdcQuitCommand$(ObjectSuffix) $(IntermediateDirectory)/source_gamestate$(ObjectSuffix) 

##
## Main Build Targets 
##
all: $(OutputFile)

$(OutputFile): makeDirStep $(Objects)
	@$(MakeDirCommand) $(@D)
	$(LinkerName) $(OutputSwitch)$(OutputFile) $(Objects) $(LibPath) $(Libs) $(LinkOptions)
	@echo Executing Post Build commands ...
	copy ..\..\..\..\engine\bin\win32-gcc\QuanticVortex_d.dll ..\..\..\bin\win32-gcc\QuanticVortex_d.dll
	copy ..\..\..\..\dependencies\bin\win32-gcc\cAudio_d.dll ..\..\..\bin\win32-gcc\cAudio_d.dll
	copy ..\..\..\..\dependencies\bin\win32-gcc\Irrlicht_d.dll ..\..\..\bin\win32-gcc\Irrlicht_d.dll
	copy ..\..\..\..\dependencies\bin\win32-gcc\OpenAL32.dll ..\..\..\bin\win32-gcc\OpenAL32.dll
	copy ..\..\..\..\dependencies\bin\win32-gcc\wrap_oal.dll ..\..\..\bin\win32-gcc\wrap_oal.dll
	copy ..\..\..\..\dependencies\bin\win32-gcc\cAp_EAXLegacyPreset.dll ..\..\..\bin\win32-gcc\cAp_EAXLegacyPreset.dll
	@echo Done

makeDirStep:
	@$(MakeDirCommand) "../../obj/debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/source_main$(ObjectSuffix): ../../source/main.cpp $(IntermediateDirectory)/source_main$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine samples/01_Sample/source/main.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/source_main$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/source_main$(DependSuffix): ../../source/main.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/source_main$(ObjectSuffix) -MF$(IntermediateDirectory)/source_main$(DependSuffix) -MM "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine samples/01_Sample/source/main.cpp"

$(IntermediateDirectory)/source_main$(PreprocessSuffix): ../../source/main.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/source_main$(PreprocessSuffix) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine samples/01_Sample/source/main.cpp"

$(IntermediateDirectory)/source_sdcSylfurDCGame$(ObjectSuffix): ../../source/sdcSylfurDCGame.cpp $(IntermediateDirectory)/source_sdcSylfurDCGame$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine samples/01_Sample/source/sdcSylfurDCGame.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/source_sdcSylfurDCGame$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/source_sdcSylfurDCGame$(DependSuffix): ../../source/sdcSylfurDCGame.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/source_sdcSylfurDCGame$(ObjectSuffix) -MF$(IntermediateDirectory)/source_sdcSylfurDCGame$(DependSuffix) -MM "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine samples/01_Sample/source/sdcSylfurDCGame.cpp"

$(IntermediateDirectory)/source_sdcSylfurDCGame$(PreprocessSuffix): ../../source/sdcSylfurDCGame.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/source_sdcSylfurDCGame$(PreprocessSuffix) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine samples/01_Sample/source/sdcSylfurDCGame.cpp"

$(IntermediateDirectory)/source_sdcQuitCommand$(ObjectSuffix): ../../source/sdcQuitCommand.cpp $(IntermediateDirectory)/source_sdcQuitCommand$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine samples/01_Sample/source/sdcQuitCommand.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/source_sdcQuitCommand$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/source_sdcQuitCommand$(DependSuffix): ../../source/sdcQuitCommand.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/source_sdcQuitCommand$(ObjectSuffix) -MF$(IntermediateDirectory)/source_sdcQuitCommand$(DependSuffix) -MM "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine samples/01_Sample/source/sdcQuitCommand.cpp"

$(IntermediateDirectory)/source_sdcQuitCommand$(PreprocessSuffix): ../../source/sdcQuitCommand.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/source_sdcQuitCommand$(PreprocessSuffix) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine samples/01_Sample/source/sdcQuitCommand.cpp"

$(IntermediateDirectory)/source_gamestate$(ObjectSuffix): ../../source/gamestate.cpp $(IntermediateDirectory)/source_gamestate$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine samples/01_Sample/source/gamestate.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/source_gamestate$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/source_gamestate$(DependSuffix): ../../source/gamestate.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/source_gamestate$(ObjectSuffix) -MF$(IntermediateDirectory)/source_gamestate$(DependSuffix) -MM "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine samples/01_Sample/source/gamestate.cpp"

$(IntermediateDirectory)/source_gamestate$(PreprocessSuffix): ../../source/gamestate.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/source_gamestate$(PreprocessSuffix) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine samples/01_Sample/source/gamestate.cpp"


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
	$(RM) $(IntermediateDirectory)/source_sdcQuitCommand$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/source_sdcQuitCommand$(DependSuffix)
	$(RM) $(IntermediateDirectory)/source_sdcQuitCommand$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/source_gamestate$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/source_gamestate$(DependSuffix)
	$(RM) $(IntermediateDirectory)/source_gamestate$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe



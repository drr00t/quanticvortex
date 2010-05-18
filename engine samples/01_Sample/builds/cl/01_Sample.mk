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
Date                   :=05/17/10
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
Objects=$(IntermediateDirectory)/source_main$(ObjectSuffix) $(IntermediateDirectory)/source_sdcSylfurDCGame$(ObjectSuffix) $(IntermediateDirectory)/source_sdcQuitCommand$(ObjectSuffix) $(IntermediateDirectory)/source_sdcInitializatingCommand$(ObjectSuffix) $(IntermediateDirectory)/source_sdcMenuCommand$(ObjectSuffix) $(IntermediateDirectory)/source_sdcLoadingCommand$(ObjectSuffix) $(IntermediateDirectory)/source_sdcRunningCommand$(ObjectSuffix) 

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

$(IntermediateDirectory)/source_sdcQuitCommand$(ObjectSuffix): ../../source/sdcQuitCommand.cpp $(IntermediateDirectory)/source_sdcQuitCommand$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticVortex/engine samples/01_Sample/source/sdcQuitCommand.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/source_sdcQuitCommand$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/source_sdcQuitCommand$(DependSuffix): ../../source/sdcQuitCommand.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/source_sdcQuitCommand$(ObjectSuffix) -MF$(IntermediateDirectory)/source_sdcQuitCommand$(DependSuffix) -MM "E:/Projetos/QuanticVortex/engine samples/01_Sample/source/sdcQuitCommand.cpp"

$(IntermediateDirectory)/source_sdcQuitCommand$(PreprocessSuffix): ../../source/sdcQuitCommand.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/source_sdcQuitCommand$(PreprocessSuffix) "E:/Projetos/QuanticVortex/engine samples/01_Sample/source/sdcQuitCommand.cpp"

$(IntermediateDirectory)/source_sdcInitializatingCommand$(ObjectSuffix): ../../source/sdcInitializatingCommand.cpp $(IntermediateDirectory)/source_sdcInitializatingCommand$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticVortex/engine samples/01_Sample/source/sdcInitializatingCommand.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/source_sdcInitializatingCommand$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/source_sdcInitializatingCommand$(DependSuffix): ../../source/sdcInitializatingCommand.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/source_sdcInitializatingCommand$(ObjectSuffix) -MF$(IntermediateDirectory)/source_sdcInitializatingCommand$(DependSuffix) -MM "E:/Projetos/QuanticVortex/engine samples/01_Sample/source/sdcInitializatingCommand.cpp"

$(IntermediateDirectory)/source_sdcInitializatingCommand$(PreprocessSuffix): ../../source/sdcInitializatingCommand.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/source_sdcInitializatingCommand$(PreprocessSuffix) "E:/Projetos/QuanticVortex/engine samples/01_Sample/source/sdcInitializatingCommand.cpp"

$(IntermediateDirectory)/source_sdcMenuCommand$(ObjectSuffix): ../../source/sdcMenuCommand.cpp $(IntermediateDirectory)/source_sdcMenuCommand$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticVortex/engine samples/01_Sample/source/sdcMenuCommand.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/source_sdcMenuCommand$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/source_sdcMenuCommand$(DependSuffix): ../../source/sdcMenuCommand.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/source_sdcMenuCommand$(ObjectSuffix) -MF$(IntermediateDirectory)/source_sdcMenuCommand$(DependSuffix) -MM "E:/Projetos/QuanticVortex/engine samples/01_Sample/source/sdcMenuCommand.cpp"

$(IntermediateDirectory)/source_sdcMenuCommand$(PreprocessSuffix): ../../source/sdcMenuCommand.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/source_sdcMenuCommand$(PreprocessSuffix) "E:/Projetos/QuanticVortex/engine samples/01_Sample/source/sdcMenuCommand.cpp"

$(IntermediateDirectory)/source_sdcLoadingCommand$(ObjectSuffix): ../../source/sdcLoadingCommand.cpp $(IntermediateDirectory)/source_sdcLoadingCommand$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticVortex/engine samples/01_Sample/source/sdcLoadingCommand.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/source_sdcLoadingCommand$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/source_sdcLoadingCommand$(DependSuffix): ../../source/sdcLoadingCommand.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/source_sdcLoadingCommand$(ObjectSuffix) -MF$(IntermediateDirectory)/source_sdcLoadingCommand$(DependSuffix) -MM "E:/Projetos/QuanticVortex/engine samples/01_Sample/source/sdcLoadingCommand.cpp"

$(IntermediateDirectory)/source_sdcLoadingCommand$(PreprocessSuffix): ../../source/sdcLoadingCommand.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/source_sdcLoadingCommand$(PreprocessSuffix) "E:/Projetos/QuanticVortex/engine samples/01_Sample/source/sdcLoadingCommand.cpp"

$(IntermediateDirectory)/source_sdcRunningCommand$(ObjectSuffix): ../../source/sdcRunningCommand.cpp $(IntermediateDirectory)/source_sdcRunningCommand$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticVortex/engine samples/01_Sample/source/sdcRunningCommand.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/source_sdcRunningCommand$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/source_sdcRunningCommand$(DependSuffix): ../../source/sdcRunningCommand.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/source_sdcRunningCommand$(ObjectSuffix) -MF$(IntermediateDirectory)/source_sdcRunningCommand$(DependSuffix) -MM "E:/Projetos/QuanticVortex/engine samples/01_Sample/source/sdcRunningCommand.cpp"

$(IntermediateDirectory)/source_sdcRunningCommand$(PreprocessSuffix): ../../source/sdcRunningCommand.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/source_sdcRunningCommand$(PreprocessSuffix) "E:/Projetos/QuanticVortex/engine samples/01_Sample/source/sdcRunningCommand.cpp"


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
	$(RM) $(IntermediateDirectory)/source_sdcInitializatingCommand$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/source_sdcInitializatingCommand$(DependSuffix)
	$(RM) $(IntermediateDirectory)/source_sdcInitializatingCommand$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/source_sdcMenuCommand$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/source_sdcMenuCommand$(DependSuffix)
	$(RM) $(IntermediateDirectory)/source_sdcMenuCommand$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/source_sdcLoadingCommand$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/source_sdcLoadingCommand$(DependSuffix)
	$(RM) $(IntermediateDirectory)/source_sdcLoadingCommand$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/source_sdcRunningCommand$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/source_sdcRunningCommand$(DependSuffix)
	$(RM) $(IntermediateDirectory)/source_sdcRunningCommand$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe



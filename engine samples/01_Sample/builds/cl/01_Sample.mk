##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=01_Sample
ConfigurationName      :=Debug
IntermediateDirectory  :=../../obj/debug
OutDir                 := $(IntermediateDirectory)
WorkspacePath          := "E:\QuanticVortex\engine samples"
ProjectPath            := "E:\QuanticVortex\engine samples\01_Sample\builds\cl"
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=adriano.ribeiro
Date                   :=04/20/10
CodeLitePath           :="C:\Arquivos de programas\CodeLite"
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
OutputFile             :=../../../bin/debug/01_Sample_d.exe
Preprocessors          :=
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
UNIT_TEST_PP_SRC_DIR:=C:\Arquivos de programas\UnitTest++-1.3
CodeLiteDir:=C:\Arquivos de programas\CodeLite
Objects=$(IntermediateDirectory)/source_main$(ObjectSuffix) $(IntermediateDirectory)/source_sdcSylfurDCGame$(ObjectSuffix) $(IntermediateDirectory)/source_sdcQuitCommand$(ObjectSuffix) $(IntermediateDirectory)/source_gamestate$(ObjectSuffix) 

##
## Main Build Targets 
##
all: $(OutputFile)

$(OutputFile): makeDirStep $(Objects)
	@$(MakeDirCommand) $(@D)
	$(LinkerName) $(OutputSwitch)$(OutputFile) $(Objects) $(LibPath) $(Libs) $(LinkOptions)

makeDirStep:
	@$(MakeDirCommand) "../../obj/debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/source_main$(ObjectSuffix): ../../source/main.cpp $(IntermediateDirectory)/source_main$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/QuanticVortex/engine samples/01_Sample/source/main.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/source_main$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/source_main$(DependSuffix): ../../source/main.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/source_main$(ObjectSuffix) -MF$(IntermediateDirectory)/source_main$(DependSuffix) -MM "E:/QuanticVortex/engine samples/01_Sample/source/main.cpp"

$(IntermediateDirectory)/source_main$(PreprocessSuffix): ../../source/main.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/source_main$(PreprocessSuffix) "E:/QuanticVortex/engine samples/01_Sample/source/main.cpp"

$(IntermediateDirectory)/source_sdcSylfurDCGame$(ObjectSuffix): ../../source/sdcSylfurDCGame.cpp $(IntermediateDirectory)/source_sdcSylfurDCGame$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/QuanticVortex/engine samples/01_Sample/source/sdcSylfurDCGame.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/source_sdcSylfurDCGame$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/source_sdcSylfurDCGame$(DependSuffix): ../../source/sdcSylfurDCGame.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/source_sdcSylfurDCGame$(ObjectSuffix) -MF$(IntermediateDirectory)/source_sdcSylfurDCGame$(DependSuffix) -MM "E:/QuanticVortex/engine samples/01_Sample/source/sdcSylfurDCGame.cpp"

$(IntermediateDirectory)/source_sdcSylfurDCGame$(PreprocessSuffix): ../../source/sdcSylfurDCGame.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/source_sdcSylfurDCGame$(PreprocessSuffix) "E:/QuanticVortex/engine samples/01_Sample/source/sdcSylfurDCGame.cpp"

$(IntermediateDirectory)/source_sdcQuitCommand$(ObjectSuffix): ../../source/sdcQuitCommand.cpp $(IntermediateDirectory)/source_sdcQuitCommand$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/QuanticVortex/engine samples/01_Sample/source/sdcQuitCommand.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/source_sdcQuitCommand$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/source_sdcQuitCommand$(DependSuffix): ../../source/sdcQuitCommand.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/source_sdcQuitCommand$(ObjectSuffix) -MF$(IntermediateDirectory)/source_sdcQuitCommand$(DependSuffix) -MM "E:/QuanticVortex/engine samples/01_Sample/source/sdcQuitCommand.cpp"

$(IntermediateDirectory)/source_sdcQuitCommand$(PreprocessSuffix): ../../source/sdcQuitCommand.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/source_sdcQuitCommand$(PreprocessSuffix) "E:/QuanticVortex/engine samples/01_Sample/source/sdcQuitCommand.cpp"

$(IntermediateDirectory)/source_gamestate$(ObjectSuffix): ../../source/gamestate.cpp $(IntermediateDirectory)/source_gamestate$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/QuanticVortex/engine samples/01_Sample/source/gamestate.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/source_gamestate$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/source_gamestate$(DependSuffix): ../../source/gamestate.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/source_gamestate$(ObjectSuffix) -MF$(IntermediateDirectory)/source_gamestate$(DependSuffix) -MM "E:/QuanticVortex/engine samples/01_Sample/source/gamestate.cpp"

$(IntermediateDirectory)/source_gamestate$(PreprocessSuffix): ../../source/gamestate.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/source_gamestate$(PreprocessSuffix) "E:/QuanticVortex/engine samples/01_Sample/source/gamestate.cpp"


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



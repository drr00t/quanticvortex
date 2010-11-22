##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Windows_x86_-_DLL_-_Debug
ProjectName            :=QuanticVortex_Core
ConfigurationName      :=Windows_x86_-_DLL_-_Debug
IntermediateDirectory  :=../../obj/debug
OutDir                 := $(IntermediateDirectory)
WorkspacePath          := "E:\Projetos\QuanticVortex\engine samples"
ProjectPath            := "E:\Projetos\QuanticVortex\engine\builds\codelite"
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Adriano
Date                   :=11/21/10
CodeLitePath           :="C:\Program Files (x86)\CodeLite"
LinkerName             :=g++
ArchiveTool            :=ar rcus
SharedObjectLinkerName :=g++ -shared 
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
OutputFile             :=../../bin/win32-gcc/QuanticVortex_d.dll
Preprocessors          :=$(PreprocessorSwitch)WIN32 $(PreprocessorSwitch)_DEBUG $(PreprocessorSwitch)_QUANTICVORTEX_EXPORTS $(PreprocessorSwitch)_CRT_SECURE_NO_WARNINGS $(PreprocessorSwitch)__GNUWIN32__ 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
MakeDirCommand         :=makedir
CmpOptions             := -g -Wall  $(Preprocessors)
LinkOptions            :=  
IncludePath            :=  "$(IncludeSwitch)." "$(IncludeSwitch)../../../engine/include" "$(IncludeSwitch)../../../engine/source/quanticvortex" "$(IncludeSwitch)../../../engine/source/quanticvortex/physfs" "$(IncludeSwitch)../../../dependencies/include/irrlicht/include" "$(IncludeSwitch)../../../dependencies/include/cAudio/include" "$(IncludeSwitch)../../../dependencies/include/bullet" "$(IncludeSwitch)../../../dependencies/include/poco" "$(IncludeSwitch)../../../dependencies/include/tbb" 
RcIncludePath          :=
Libs                   :=$(LibrarySwitch)Irrlicht_d $(LibrarySwitch)cAudio_d $(LibrarySwitch)bulletdynamics_d $(LibrarySwitch)bulletcollision_d $(LibrarySwitch)bulletsoftbody_d $(LibrarySwitch)LinearMath_d $(LibrarySwitch)PocoFoundationmtd $(LibrarySwitch)PocoUtilmtd 
LibPath                := "$(LibraryPathSwitch)." "$(LibraryPathSwitch)../../../dependencies/libs/win32-gcc" "$(LibraryPathSwitch)../../../dependencies/bin/win32-gcc" 


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files (x86)\CodeLite
Objects=$(IntermediateDirectory)/quanticvortex_qvEngineInputTranslatorFactory$(ObjectSuffix) $(IntermediateDirectory)/quanticvortex_qvHashFunctions$(ObjectSuffix) $(IntermediateDirectory)/quanticvortex_qvSHashedString$(ObjectSuffix) $(IntermediateDirectory)/quanticvortex_qvCommandManager$(ObjectSuffix) $(IntermediateDirectory)/quanticvortex_qvGetopt$(ObjectSuffix) $(IntermediateDirectory)/quanticvortex_qvLoadGameCommand$(ObjectSuffix) $(IntermediateDirectory)/quanticvortex_qvIrrSceneLoader$(ObjectSuffix) $(IntermediateDirectory)/quanticvortex_qvGame$(ObjectSuffix) $(IntermediateDirectory)/quanticvortex_qvAddinManager$(ObjectSuffix) $(IntermediateDirectory)/quanticvortex_qvGameLogic$(ObjectSuffix) \
	$(IntermediateDirectory)/quanticvortex_qvHumanView$(ObjectSuffix) $(IntermediateDirectory)/quanticvortex_qvSceneElementView$(ObjectSuffix) $(IntermediateDirectory)/quanticvortex_qvPhysicsManager$(ObjectSuffix) $(IntermediateDirectory)/quanticvortex_qvAnyKeyInputTranslator$(ObjectSuffix) $(IntermediateDirectory)/quanticvortex_qvSingleKeyInputTranslator$(ObjectSuffix) $(IntermediateDirectory)/quanticvortex_qvFileSystem$(ObjectSuffix) 

##
## Main Build Targets 
##
all: $(OutputFile)

$(OutputFile): makeDirStep $(Objects)
	@$(MakeDirCommand) $(@D)
	$(SharedObjectLinkerName) $(OutputSwitch)$(OutputFile) $(Objects) $(LibPath) $(Libs) $(LinkOptions)

makeDirStep:
	@$(MakeDirCommand) "../../obj/debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/quanticvortex_qvEngineInputTranslatorFactory$(ObjectSuffix): ../../source/quanticvortex/qvEngineInputTranslatorFactory.cpp $(IntermediateDirectory)/quanticvortex_qvEngineInputTranslatorFactory$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvEngineInputTranslatorFactory.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/quanticvortex_qvEngineInputTranslatorFactory$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/quanticvortex_qvEngineInputTranslatorFactory$(DependSuffix): ../../source/quanticvortex/qvEngineInputTranslatorFactory.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/quanticvortex_qvEngineInputTranslatorFactory$(ObjectSuffix) -MF$(IntermediateDirectory)/quanticvortex_qvEngineInputTranslatorFactory$(DependSuffix) -MM "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvEngineInputTranslatorFactory.cpp"

$(IntermediateDirectory)/quanticvortex_qvEngineInputTranslatorFactory$(PreprocessSuffix): ../../source/quanticvortex/qvEngineInputTranslatorFactory.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/quanticvortex_qvEngineInputTranslatorFactory$(PreprocessSuffix) "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvEngineInputTranslatorFactory.cpp"

$(IntermediateDirectory)/quanticvortex_qvHashFunctions$(ObjectSuffix): ../../source/quanticvortex/qvHashFunctions.cpp $(IntermediateDirectory)/quanticvortex_qvHashFunctions$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvHashFunctions.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/quanticvortex_qvHashFunctions$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/quanticvortex_qvHashFunctions$(DependSuffix): ../../source/quanticvortex/qvHashFunctions.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/quanticvortex_qvHashFunctions$(ObjectSuffix) -MF$(IntermediateDirectory)/quanticvortex_qvHashFunctions$(DependSuffix) -MM "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvHashFunctions.cpp"

$(IntermediateDirectory)/quanticvortex_qvHashFunctions$(PreprocessSuffix): ../../source/quanticvortex/qvHashFunctions.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/quanticvortex_qvHashFunctions$(PreprocessSuffix) "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvHashFunctions.cpp"

$(IntermediateDirectory)/quanticvortex_qvSHashedString$(ObjectSuffix): ../../source/quanticvortex/qvSHashedString.cpp $(IntermediateDirectory)/quanticvortex_qvSHashedString$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvSHashedString.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/quanticvortex_qvSHashedString$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/quanticvortex_qvSHashedString$(DependSuffix): ../../source/quanticvortex/qvSHashedString.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/quanticvortex_qvSHashedString$(ObjectSuffix) -MF$(IntermediateDirectory)/quanticvortex_qvSHashedString$(DependSuffix) -MM "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvSHashedString.cpp"

$(IntermediateDirectory)/quanticvortex_qvSHashedString$(PreprocessSuffix): ../../source/quanticvortex/qvSHashedString.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/quanticvortex_qvSHashedString$(PreprocessSuffix) "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvSHashedString.cpp"

$(IntermediateDirectory)/quanticvortex_qvCommandManager$(ObjectSuffix): ../../source/quanticvortex/qvCommandManager.cpp $(IntermediateDirectory)/quanticvortex_qvCommandManager$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvCommandManager.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/quanticvortex_qvCommandManager$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/quanticvortex_qvCommandManager$(DependSuffix): ../../source/quanticvortex/qvCommandManager.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/quanticvortex_qvCommandManager$(ObjectSuffix) -MF$(IntermediateDirectory)/quanticvortex_qvCommandManager$(DependSuffix) -MM "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvCommandManager.cpp"

$(IntermediateDirectory)/quanticvortex_qvCommandManager$(PreprocessSuffix): ../../source/quanticvortex/qvCommandManager.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/quanticvortex_qvCommandManager$(PreprocessSuffix) "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvCommandManager.cpp"

$(IntermediateDirectory)/quanticvortex_qvGetopt$(ObjectSuffix): ../../source/quanticvortex/qvGetopt.cpp $(IntermediateDirectory)/quanticvortex_qvGetopt$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvGetopt.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/quanticvortex_qvGetopt$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/quanticvortex_qvGetopt$(DependSuffix): ../../source/quanticvortex/qvGetopt.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/quanticvortex_qvGetopt$(ObjectSuffix) -MF$(IntermediateDirectory)/quanticvortex_qvGetopt$(DependSuffix) -MM "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvGetopt.cpp"

$(IntermediateDirectory)/quanticvortex_qvGetopt$(PreprocessSuffix): ../../source/quanticvortex/qvGetopt.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/quanticvortex_qvGetopt$(PreprocessSuffix) "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvGetopt.cpp"

$(IntermediateDirectory)/quanticvortex_qvLoadGameCommand$(ObjectSuffix): ../../source/quanticvortex/qvLoadGameCommand.cpp $(IntermediateDirectory)/quanticvortex_qvLoadGameCommand$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvLoadGameCommand.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/quanticvortex_qvLoadGameCommand$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/quanticvortex_qvLoadGameCommand$(DependSuffix): ../../source/quanticvortex/qvLoadGameCommand.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/quanticvortex_qvLoadGameCommand$(ObjectSuffix) -MF$(IntermediateDirectory)/quanticvortex_qvLoadGameCommand$(DependSuffix) -MM "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvLoadGameCommand.cpp"

$(IntermediateDirectory)/quanticvortex_qvLoadGameCommand$(PreprocessSuffix): ../../source/quanticvortex/qvLoadGameCommand.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/quanticvortex_qvLoadGameCommand$(PreprocessSuffix) "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvLoadGameCommand.cpp"

$(IntermediateDirectory)/quanticvortex_qvIrrSceneLoader$(ObjectSuffix): ../../source/quanticvortex/qvIrrSceneLoader.cpp $(IntermediateDirectory)/quanticvortex_qvIrrSceneLoader$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvIrrSceneLoader.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/quanticvortex_qvIrrSceneLoader$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/quanticvortex_qvIrrSceneLoader$(DependSuffix): ../../source/quanticvortex/qvIrrSceneLoader.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/quanticvortex_qvIrrSceneLoader$(ObjectSuffix) -MF$(IntermediateDirectory)/quanticvortex_qvIrrSceneLoader$(DependSuffix) -MM "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvIrrSceneLoader.cpp"

$(IntermediateDirectory)/quanticvortex_qvIrrSceneLoader$(PreprocessSuffix): ../../source/quanticvortex/qvIrrSceneLoader.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/quanticvortex_qvIrrSceneLoader$(PreprocessSuffix) "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvIrrSceneLoader.cpp"

$(IntermediateDirectory)/quanticvortex_qvGame$(ObjectSuffix): ../../source/quanticvortex/qvGame.cpp $(IntermediateDirectory)/quanticvortex_qvGame$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvGame.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/quanticvortex_qvGame$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/quanticvortex_qvGame$(DependSuffix): ../../source/quanticvortex/qvGame.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/quanticvortex_qvGame$(ObjectSuffix) -MF$(IntermediateDirectory)/quanticvortex_qvGame$(DependSuffix) -MM "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvGame.cpp"

$(IntermediateDirectory)/quanticvortex_qvGame$(PreprocessSuffix): ../../source/quanticvortex/qvGame.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/quanticvortex_qvGame$(PreprocessSuffix) "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvGame.cpp"

$(IntermediateDirectory)/quanticvortex_qvAddinManager$(ObjectSuffix): ../../source/quanticvortex/qvAddinManager.cpp $(IntermediateDirectory)/quanticvortex_qvAddinManager$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvAddinManager.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/quanticvortex_qvAddinManager$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/quanticvortex_qvAddinManager$(DependSuffix): ../../source/quanticvortex/qvAddinManager.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/quanticvortex_qvAddinManager$(ObjectSuffix) -MF$(IntermediateDirectory)/quanticvortex_qvAddinManager$(DependSuffix) -MM "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvAddinManager.cpp"

$(IntermediateDirectory)/quanticvortex_qvAddinManager$(PreprocessSuffix): ../../source/quanticvortex/qvAddinManager.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/quanticvortex_qvAddinManager$(PreprocessSuffix) "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvAddinManager.cpp"

$(IntermediateDirectory)/quanticvortex_qvGameLogic$(ObjectSuffix): ../../source/quanticvortex/qvGameLogic.cpp $(IntermediateDirectory)/quanticvortex_qvGameLogic$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvGameLogic.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/quanticvortex_qvGameLogic$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/quanticvortex_qvGameLogic$(DependSuffix): ../../source/quanticvortex/qvGameLogic.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/quanticvortex_qvGameLogic$(ObjectSuffix) -MF$(IntermediateDirectory)/quanticvortex_qvGameLogic$(DependSuffix) -MM "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvGameLogic.cpp"

$(IntermediateDirectory)/quanticvortex_qvGameLogic$(PreprocessSuffix): ../../source/quanticvortex/qvGameLogic.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/quanticvortex_qvGameLogic$(PreprocessSuffix) "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvGameLogic.cpp"

$(IntermediateDirectory)/quanticvortex_qvHumanView$(ObjectSuffix): ../../source/quanticvortex/qvHumanView.cpp $(IntermediateDirectory)/quanticvortex_qvHumanView$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvHumanView.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/quanticvortex_qvHumanView$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/quanticvortex_qvHumanView$(DependSuffix): ../../source/quanticvortex/qvHumanView.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/quanticvortex_qvHumanView$(ObjectSuffix) -MF$(IntermediateDirectory)/quanticvortex_qvHumanView$(DependSuffix) -MM "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvHumanView.cpp"

$(IntermediateDirectory)/quanticvortex_qvHumanView$(PreprocessSuffix): ../../source/quanticvortex/qvHumanView.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/quanticvortex_qvHumanView$(PreprocessSuffix) "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvHumanView.cpp"

$(IntermediateDirectory)/quanticvortex_qvSceneElementView$(ObjectSuffix): ../../source/quanticvortex/qvSceneElementView.cpp $(IntermediateDirectory)/quanticvortex_qvSceneElementView$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvSceneElementView.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/quanticvortex_qvSceneElementView$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/quanticvortex_qvSceneElementView$(DependSuffix): ../../source/quanticvortex/qvSceneElementView.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/quanticvortex_qvSceneElementView$(ObjectSuffix) -MF$(IntermediateDirectory)/quanticvortex_qvSceneElementView$(DependSuffix) -MM "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvSceneElementView.cpp"

$(IntermediateDirectory)/quanticvortex_qvSceneElementView$(PreprocessSuffix): ../../source/quanticvortex/qvSceneElementView.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/quanticvortex_qvSceneElementView$(PreprocessSuffix) "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvSceneElementView.cpp"

$(IntermediateDirectory)/quanticvortex_qvPhysicsManager$(ObjectSuffix): ../../source/quanticvortex/qvPhysicsManager.cpp $(IntermediateDirectory)/quanticvortex_qvPhysicsManager$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvPhysicsManager.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/quanticvortex_qvPhysicsManager$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/quanticvortex_qvPhysicsManager$(DependSuffix): ../../source/quanticvortex/qvPhysicsManager.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/quanticvortex_qvPhysicsManager$(ObjectSuffix) -MF$(IntermediateDirectory)/quanticvortex_qvPhysicsManager$(DependSuffix) -MM "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvPhysicsManager.cpp"

$(IntermediateDirectory)/quanticvortex_qvPhysicsManager$(PreprocessSuffix): ../../source/quanticvortex/qvPhysicsManager.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/quanticvortex_qvPhysicsManager$(PreprocessSuffix) "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvPhysicsManager.cpp"

$(IntermediateDirectory)/quanticvortex_qvAnyKeyInputTranslator$(ObjectSuffix): ../../source/quanticvortex/qvAnyKeyInputTranslator.cpp $(IntermediateDirectory)/quanticvortex_qvAnyKeyInputTranslator$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvAnyKeyInputTranslator.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/quanticvortex_qvAnyKeyInputTranslator$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/quanticvortex_qvAnyKeyInputTranslator$(DependSuffix): ../../source/quanticvortex/qvAnyKeyInputTranslator.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/quanticvortex_qvAnyKeyInputTranslator$(ObjectSuffix) -MF$(IntermediateDirectory)/quanticvortex_qvAnyKeyInputTranslator$(DependSuffix) -MM "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvAnyKeyInputTranslator.cpp"

$(IntermediateDirectory)/quanticvortex_qvAnyKeyInputTranslator$(PreprocessSuffix): ../../source/quanticvortex/qvAnyKeyInputTranslator.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/quanticvortex_qvAnyKeyInputTranslator$(PreprocessSuffix) "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvAnyKeyInputTranslator.cpp"

$(IntermediateDirectory)/quanticvortex_qvSingleKeyInputTranslator$(ObjectSuffix): ../../source/quanticvortex/qvSingleKeyInputTranslator.cpp $(IntermediateDirectory)/quanticvortex_qvSingleKeyInputTranslator$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvSingleKeyInputTranslator.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/quanticvortex_qvSingleKeyInputTranslator$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/quanticvortex_qvSingleKeyInputTranslator$(DependSuffix): ../../source/quanticvortex/qvSingleKeyInputTranslator.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/quanticvortex_qvSingleKeyInputTranslator$(ObjectSuffix) -MF$(IntermediateDirectory)/quanticvortex_qvSingleKeyInputTranslator$(DependSuffix) -MM "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvSingleKeyInputTranslator.cpp"

$(IntermediateDirectory)/quanticvortex_qvSingleKeyInputTranslator$(PreprocessSuffix): ../../source/quanticvortex/qvSingleKeyInputTranslator.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/quanticvortex_qvSingleKeyInputTranslator$(PreprocessSuffix) "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvSingleKeyInputTranslator.cpp"

$(IntermediateDirectory)/quanticvortex_qvFileSystem$(ObjectSuffix): ../../source/quanticvortex/qvFileSystem.cpp $(IntermediateDirectory)/quanticvortex_qvFileSystem$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvFileSystem.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/quanticvortex_qvFileSystem$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/quanticvortex_qvFileSystem$(DependSuffix): ../../source/quanticvortex/qvFileSystem.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/quanticvortex_qvFileSystem$(ObjectSuffix) -MF$(IntermediateDirectory)/quanticvortex_qvFileSystem$(DependSuffix) -MM "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvFileSystem.cpp"

$(IntermediateDirectory)/quanticvortex_qvFileSystem$(PreprocessSuffix): ../../source/quanticvortex/qvFileSystem.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/quanticvortex_qvFileSystem$(PreprocessSuffix) "E:/Projetos/QuanticVortex/engine/source/quanticvortex/qvFileSystem.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/quanticvortex_qvEngineInputTranslatorFactory$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvEngineInputTranslatorFactory$(DependSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvEngineInputTranslatorFactory$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvHashFunctions$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvHashFunctions$(DependSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvHashFunctions$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvSHashedString$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvSHashedString$(DependSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvSHashedString$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvCommandManager$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvCommandManager$(DependSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvCommandManager$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvGetopt$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvGetopt$(DependSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvGetopt$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvLoadGameCommand$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvLoadGameCommand$(DependSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvLoadGameCommand$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvIrrSceneLoader$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvIrrSceneLoader$(DependSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvIrrSceneLoader$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvGame$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvGame$(DependSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvGame$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvAddinManager$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvAddinManager$(DependSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvAddinManager$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvGameLogic$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvGameLogic$(DependSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvGameLogic$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvHumanView$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvHumanView$(DependSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvHumanView$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvSceneElementView$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvSceneElementView$(DependSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvSceneElementView$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvPhysicsManager$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvPhysicsManager$(DependSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvPhysicsManager$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvAnyKeyInputTranslator$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvAnyKeyInputTranslator$(DependSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvAnyKeyInputTranslator$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvSingleKeyInputTranslator$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvSingleKeyInputTranslator$(DependSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvSingleKeyInputTranslator$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvFileSystem$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvFileSystem$(DependSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvFileSystem$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile)



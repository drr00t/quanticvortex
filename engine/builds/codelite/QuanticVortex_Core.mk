##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Windows_x86_-_DLL_-_Debug
ProjectName            :=QuanticVortex_Core
ConfigurationName      :=Windows_x86_-_DLL_-_Debug
IntermediateDirectory  :=../../obj/debug
OutDir                 := $(IntermediateDirectory)
WorkspacePath          := "E:\Projetos\QuanticMinds\Sylfur-D.C\QuanticVortex\engine samples"
ProjectPath            := "E:\Projetos\QuanticMinds\Sylfur-D.C\QuanticVortex\engine\builds\codelite"
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=adriano
Date                   :=04/27/10
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
OutputFile             :=../../bin/win32-gcc/QuanticVortex_d.dll
Preprocessors          :=$(PreprocessorSwitch)WIN32 $(PreprocessorSwitch)_DEBUG $(PreprocessorSwitch)_QUANTICVORTEX_EXPORTS $(PreprocessorSwitch)_CRT_SECURE_NO_WARNINGS $(PreprocessorSwitch)__GNUWIN32__ 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
MakeDirCommand         :=makedir
CmpOptions             := -g -fno-rtti $(Preprocessors)
LinkOptions            :=  
IncludePath            :=  "$(IncludeSwitch)." "$(IncludeSwitch)../../../engine/include" "$(IncludeSwitch)../../../engine/source/quanticvortex" "$(IncludeSwitch)../../../dependencies/include/irrlicht/include" "$(IncludeSwitch)../../../dependencies/include/cAudio/include" "$(IncludeSwitch)../../../dependencies/include/bullet" "$(IncludeSwitch)../../../dependencies/include/poco" 
RcIncludePath          :=
Libs                   :=$(LibrarySwitch)Irrlicht_d $(LibrarySwitch)cAudio_d $(LibrarySwitch)bulletdynamics_d $(LibrarySwitch)bulletcollision_d $(LibrarySwitch)bulletsoftbody_d $(LibrarySwitch)LinearMath_d $(LibrarySwitch)PocoFoundationmtd $(LibrarySwitch)PocoUtilmtd 
LibPath                := "$(LibraryPathSwitch)." "$(LibraryPathSwitch)../../../dependencies/libs/win32-gcc" "$(LibraryPathSwitch)../../../dependencies/bin/win32-gcc" 


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects=$(IntermediateDirectory)/quanticvortex_qvActorMotion$(ObjectSuffix) $(IntermediateDirectory)/quanticvortex_qvAnyKeyInputTranslator$(ObjectSuffix) $(IntermediateDirectory)/quanticvortex_qvDefaultElementViewFactory$(ObjectSuffix) $(IntermediateDirectory)/quanticvortex_qvEngineInputTranslatorFactory$(ObjectSuffix) $(IntermediateDirectory)/quanticvortex_qvEventArgs$(ObjectSuffix) $(IntermediateDirectory)/quanticvortex_qvEventManager$(ObjectSuffix) $(IntermediateDirectory)/quanticvortex_qvGameLogic$(ObjectSuffix) $(IntermediateDirectory)/quanticvortex_qvGameParameters$(ObjectSuffix) $(IntermediateDirectory)/quanticvortex_qvGameStateMachine$(ObjectSuffix) $(IntermediateDirectory)/quanticvortex_qvGuiView$(ObjectSuffix) \
	$(IntermediateDirectory)/quanticvortex_qvHashFunctions$(ObjectSuffix) $(IntermediateDirectory)/quanticvortex_qvHumanView$(ObjectSuffix) $(IntermediateDirectory)/quanticvortex_qvPhysicsManager$(ObjectSuffix) $(IntermediateDirectory)/quanticvortex_qvQuanticVortex$(ObjectSuffix) $(IntermediateDirectory)/quanticvortex_qvSingleKeyInputTranslator$(ObjectSuffix) $(IntermediateDirectory)/quanticvortex_qvSHashedString$(ObjectSuffix) $(IntermediateDirectory)/quanticvortex_qvGame$(ObjectSuffix) $(IntermediateDirectory)/quanticvortex_qvGameState$(ObjectSuffix) $(IntermediateDirectory)/quanticvortex_qvEventArgsFactory$(ObjectSuffix) $(IntermediateDirectory)/quanticvortex_qvGameTickEventArgs$(ObjectSuffix) \
	

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
$(IntermediateDirectory)/quanticvortex_qvActorMotion$(ObjectSuffix): ../../source/quanticvortex/qvActorMotion.cpp $(IntermediateDirectory)/quanticvortex_qvActorMotion$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvActorMotion.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/quanticvortex_qvActorMotion$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/quanticvortex_qvActorMotion$(DependSuffix): ../../source/quanticvortex/qvActorMotion.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/quanticvortex_qvActorMotion$(ObjectSuffix) -MF$(IntermediateDirectory)/quanticvortex_qvActorMotion$(DependSuffix) -MM "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvActorMotion.cpp"

$(IntermediateDirectory)/quanticvortex_qvActorMotion$(PreprocessSuffix): ../../source/quanticvortex/qvActorMotion.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/quanticvortex_qvActorMotion$(PreprocessSuffix) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvActorMotion.cpp"

$(IntermediateDirectory)/quanticvortex_qvAnyKeyInputTranslator$(ObjectSuffix): ../../source/quanticvortex/qvAnyKeyInputTranslator.cpp $(IntermediateDirectory)/quanticvortex_qvAnyKeyInputTranslator$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvAnyKeyInputTranslator.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/quanticvortex_qvAnyKeyInputTranslator$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/quanticvortex_qvAnyKeyInputTranslator$(DependSuffix): ../../source/quanticvortex/qvAnyKeyInputTranslator.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/quanticvortex_qvAnyKeyInputTranslator$(ObjectSuffix) -MF$(IntermediateDirectory)/quanticvortex_qvAnyKeyInputTranslator$(DependSuffix) -MM "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvAnyKeyInputTranslator.cpp"

$(IntermediateDirectory)/quanticvortex_qvAnyKeyInputTranslator$(PreprocessSuffix): ../../source/quanticvortex/qvAnyKeyInputTranslator.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/quanticvortex_qvAnyKeyInputTranslator$(PreprocessSuffix) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvAnyKeyInputTranslator.cpp"

$(IntermediateDirectory)/quanticvortex_qvDefaultElementViewFactory$(ObjectSuffix): ../../source/quanticvortex/qvDefaultElementViewFactory.cpp $(IntermediateDirectory)/quanticvortex_qvDefaultElementViewFactory$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvDefaultElementViewFactory.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/quanticvortex_qvDefaultElementViewFactory$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/quanticvortex_qvDefaultElementViewFactory$(DependSuffix): ../../source/quanticvortex/qvDefaultElementViewFactory.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/quanticvortex_qvDefaultElementViewFactory$(ObjectSuffix) -MF$(IntermediateDirectory)/quanticvortex_qvDefaultElementViewFactory$(DependSuffix) -MM "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvDefaultElementViewFactory.cpp"

$(IntermediateDirectory)/quanticvortex_qvDefaultElementViewFactory$(PreprocessSuffix): ../../source/quanticvortex/qvDefaultElementViewFactory.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/quanticvortex_qvDefaultElementViewFactory$(PreprocessSuffix) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvDefaultElementViewFactory.cpp"

$(IntermediateDirectory)/quanticvortex_qvEngineInputTranslatorFactory$(ObjectSuffix): ../../source/quanticvortex/qvEngineInputTranslatorFactory.cpp $(IntermediateDirectory)/quanticvortex_qvEngineInputTranslatorFactory$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvEngineInputTranslatorFactory.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/quanticvortex_qvEngineInputTranslatorFactory$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/quanticvortex_qvEngineInputTranslatorFactory$(DependSuffix): ../../source/quanticvortex/qvEngineInputTranslatorFactory.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/quanticvortex_qvEngineInputTranslatorFactory$(ObjectSuffix) -MF$(IntermediateDirectory)/quanticvortex_qvEngineInputTranslatorFactory$(DependSuffix) -MM "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvEngineInputTranslatorFactory.cpp"

$(IntermediateDirectory)/quanticvortex_qvEngineInputTranslatorFactory$(PreprocessSuffix): ../../source/quanticvortex/qvEngineInputTranslatorFactory.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/quanticvortex_qvEngineInputTranslatorFactory$(PreprocessSuffix) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvEngineInputTranslatorFactory.cpp"

$(IntermediateDirectory)/quanticvortex_qvEventArgs$(ObjectSuffix): ../../source/quanticvortex/qvEventArgs.cpp $(IntermediateDirectory)/quanticvortex_qvEventArgs$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvEventArgs.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/quanticvortex_qvEventArgs$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/quanticvortex_qvEventArgs$(DependSuffix): ../../source/quanticvortex/qvEventArgs.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/quanticvortex_qvEventArgs$(ObjectSuffix) -MF$(IntermediateDirectory)/quanticvortex_qvEventArgs$(DependSuffix) -MM "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvEventArgs.cpp"

$(IntermediateDirectory)/quanticvortex_qvEventArgs$(PreprocessSuffix): ../../source/quanticvortex/qvEventArgs.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/quanticvortex_qvEventArgs$(PreprocessSuffix) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvEventArgs.cpp"

$(IntermediateDirectory)/quanticvortex_qvEventManager$(ObjectSuffix): ../../source/quanticvortex/qvEventManager.cpp $(IntermediateDirectory)/quanticvortex_qvEventManager$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvEventManager.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/quanticvortex_qvEventManager$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/quanticvortex_qvEventManager$(DependSuffix): ../../source/quanticvortex/qvEventManager.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/quanticvortex_qvEventManager$(ObjectSuffix) -MF$(IntermediateDirectory)/quanticvortex_qvEventManager$(DependSuffix) -MM "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvEventManager.cpp"

$(IntermediateDirectory)/quanticvortex_qvEventManager$(PreprocessSuffix): ../../source/quanticvortex/qvEventManager.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/quanticvortex_qvEventManager$(PreprocessSuffix) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvEventManager.cpp"

$(IntermediateDirectory)/quanticvortex_qvGameLogic$(ObjectSuffix): ../../source/quanticvortex/qvGameLogic.cpp $(IntermediateDirectory)/quanticvortex_qvGameLogic$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvGameLogic.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/quanticvortex_qvGameLogic$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/quanticvortex_qvGameLogic$(DependSuffix): ../../source/quanticvortex/qvGameLogic.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/quanticvortex_qvGameLogic$(ObjectSuffix) -MF$(IntermediateDirectory)/quanticvortex_qvGameLogic$(DependSuffix) -MM "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvGameLogic.cpp"

$(IntermediateDirectory)/quanticvortex_qvGameLogic$(PreprocessSuffix): ../../source/quanticvortex/qvGameLogic.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/quanticvortex_qvGameLogic$(PreprocessSuffix) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvGameLogic.cpp"

$(IntermediateDirectory)/quanticvortex_qvGameParameters$(ObjectSuffix): ../../source/quanticvortex/qvGameParameters.cpp $(IntermediateDirectory)/quanticvortex_qvGameParameters$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvGameParameters.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/quanticvortex_qvGameParameters$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/quanticvortex_qvGameParameters$(DependSuffix): ../../source/quanticvortex/qvGameParameters.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/quanticvortex_qvGameParameters$(ObjectSuffix) -MF$(IntermediateDirectory)/quanticvortex_qvGameParameters$(DependSuffix) -MM "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvGameParameters.cpp"

$(IntermediateDirectory)/quanticvortex_qvGameParameters$(PreprocessSuffix): ../../source/quanticvortex/qvGameParameters.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/quanticvortex_qvGameParameters$(PreprocessSuffix) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvGameParameters.cpp"

$(IntermediateDirectory)/quanticvortex_qvGameStateMachine$(ObjectSuffix): ../../source/quanticvortex/qvGameStateMachine.cpp $(IntermediateDirectory)/quanticvortex_qvGameStateMachine$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvGameStateMachine.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/quanticvortex_qvGameStateMachine$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/quanticvortex_qvGameStateMachine$(DependSuffix): ../../source/quanticvortex/qvGameStateMachine.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/quanticvortex_qvGameStateMachine$(ObjectSuffix) -MF$(IntermediateDirectory)/quanticvortex_qvGameStateMachine$(DependSuffix) -MM "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvGameStateMachine.cpp"

$(IntermediateDirectory)/quanticvortex_qvGameStateMachine$(PreprocessSuffix): ../../source/quanticvortex/qvGameStateMachine.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/quanticvortex_qvGameStateMachine$(PreprocessSuffix) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvGameStateMachine.cpp"

$(IntermediateDirectory)/quanticvortex_qvGuiView$(ObjectSuffix): ../../source/quanticvortex/qvGuiView.cpp $(IntermediateDirectory)/quanticvortex_qvGuiView$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvGuiView.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/quanticvortex_qvGuiView$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/quanticvortex_qvGuiView$(DependSuffix): ../../source/quanticvortex/qvGuiView.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/quanticvortex_qvGuiView$(ObjectSuffix) -MF$(IntermediateDirectory)/quanticvortex_qvGuiView$(DependSuffix) -MM "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvGuiView.cpp"

$(IntermediateDirectory)/quanticvortex_qvGuiView$(PreprocessSuffix): ../../source/quanticvortex/qvGuiView.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/quanticvortex_qvGuiView$(PreprocessSuffix) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvGuiView.cpp"

$(IntermediateDirectory)/quanticvortex_qvHashFunctions$(ObjectSuffix): ../../source/quanticvortex/qvHashFunctions.cpp $(IntermediateDirectory)/quanticvortex_qvHashFunctions$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvHashFunctions.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/quanticvortex_qvHashFunctions$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/quanticvortex_qvHashFunctions$(DependSuffix): ../../source/quanticvortex/qvHashFunctions.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/quanticvortex_qvHashFunctions$(ObjectSuffix) -MF$(IntermediateDirectory)/quanticvortex_qvHashFunctions$(DependSuffix) -MM "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvHashFunctions.cpp"

$(IntermediateDirectory)/quanticvortex_qvHashFunctions$(PreprocessSuffix): ../../source/quanticvortex/qvHashFunctions.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/quanticvortex_qvHashFunctions$(PreprocessSuffix) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvHashFunctions.cpp"

$(IntermediateDirectory)/quanticvortex_qvHumanView$(ObjectSuffix): ../../source/quanticvortex/qvHumanView.cpp $(IntermediateDirectory)/quanticvortex_qvHumanView$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvHumanView.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/quanticvortex_qvHumanView$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/quanticvortex_qvHumanView$(DependSuffix): ../../source/quanticvortex/qvHumanView.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/quanticvortex_qvHumanView$(ObjectSuffix) -MF$(IntermediateDirectory)/quanticvortex_qvHumanView$(DependSuffix) -MM "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvHumanView.cpp"

$(IntermediateDirectory)/quanticvortex_qvHumanView$(PreprocessSuffix): ../../source/quanticvortex/qvHumanView.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/quanticvortex_qvHumanView$(PreprocessSuffix) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvHumanView.cpp"

$(IntermediateDirectory)/quanticvortex_qvPhysicsManager$(ObjectSuffix): ../../source/quanticvortex/qvPhysicsManager.cpp $(IntermediateDirectory)/quanticvortex_qvPhysicsManager$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvPhysicsManager.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/quanticvortex_qvPhysicsManager$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/quanticvortex_qvPhysicsManager$(DependSuffix): ../../source/quanticvortex/qvPhysicsManager.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/quanticvortex_qvPhysicsManager$(ObjectSuffix) -MF$(IntermediateDirectory)/quanticvortex_qvPhysicsManager$(DependSuffix) -MM "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvPhysicsManager.cpp"

$(IntermediateDirectory)/quanticvortex_qvPhysicsManager$(PreprocessSuffix): ../../source/quanticvortex/qvPhysicsManager.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/quanticvortex_qvPhysicsManager$(PreprocessSuffix) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvPhysicsManager.cpp"

$(IntermediateDirectory)/quanticvortex_qvQuanticVortex$(ObjectSuffix): ../../source/quanticvortex/qvQuanticVortex.cpp $(IntermediateDirectory)/quanticvortex_qvQuanticVortex$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvQuanticVortex.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/quanticvortex_qvQuanticVortex$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/quanticvortex_qvQuanticVortex$(DependSuffix): ../../source/quanticvortex/qvQuanticVortex.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/quanticvortex_qvQuanticVortex$(ObjectSuffix) -MF$(IntermediateDirectory)/quanticvortex_qvQuanticVortex$(DependSuffix) -MM "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvQuanticVortex.cpp"

$(IntermediateDirectory)/quanticvortex_qvQuanticVortex$(PreprocessSuffix): ../../source/quanticvortex/qvQuanticVortex.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/quanticvortex_qvQuanticVortex$(PreprocessSuffix) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvQuanticVortex.cpp"

$(IntermediateDirectory)/quanticvortex_qvSingleKeyInputTranslator$(ObjectSuffix): ../../source/quanticvortex/qvSingleKeyInputTranslator.cpp $(IntermediateDirectory)/quanticvortex_qvSingleKeyInputTranslator$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvSingleKeyInputTranslator.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/quanticvortex_qvSingleKeyInputTranslator$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/quanticvortex_qvSingleKeyInputTranslator$(DependSuffix): ../../source/quanticvortex/qvSingleKeyInputTranslator.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/quanticvortex_qvSingleKeyInputTranslator$(ObjectSuffix) -MF$(IntermediateDirectory)/quanticvortex_qvSingleKeyInputTranslator$(DependSuffix) -MM "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvSingleKeyInputTranslator.cpp"

$(IntermediateDirectory)/quanticvortex_qvSingleKeyInputTranslator$(PreprocessSuffix): ../../source/quanticvortex/qvSingleKeyInputTranslator.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/quanticvortex_qvSingleKeyInputTranslator$(PreprocessSuffix) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvSingleKeyInputTranslator.cpp"

$(IntermediateDirectory)/quanticvortex_qvSHashedString$(ObjectSuffix): ../../source/quanticvortex/qvSHashedString.cpp $(IntermediateDirectory)/quanticvortex_qvSHashedString$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvSHashedString.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/quanticvortex_qvSHashedString$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/quanticvortex_qvSHashedString$(DependSuffix): ../../source/quanticvortex/qvSHashedString.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/quanticvortex_qvSHashedString$(ObjectSuffix) -MF$(IntermediateDirectory)/quanticvortex_qvSHashedString$(DependSuffix) -MM "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvSHashedString.cpp"

$(IntermediateDirectory)/quanticvortex_qvSHashedString$(PreprocessSuffix): ../../source/quanticvortex/qvSHashedString.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/quanticvortex_qvSHashedString$(PreprocessSuffix) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvSHashedString.cpp"

$(IntermediateDirectory)/quanticvortex_qvGame$(ObjectSuffix): ../../source/quanticvortex/qvGame.cpp $(IntermediateDirectory)/quanticvortex_qvGame$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvGame.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/quanticvortex_qvGame$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/quanticvortex_qvGame$(DependSuffix): ../../source/quanticvortex/qvGame.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/quanticvortex_qvGame$(ObjectSuffix) -MF$(IntermediateDirectory)/quanticvortex_qvGame$(DependSuffix) -MM "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvGame.cpp"

$(IntermediateDirectory)/quanticvortex_qvGame$(PreprocessSuffix): ../../source/quanticvortex/qvGame.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/quanticvortex_qvGame$(PreprocessSuffix) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvGame.cpp"

$(IntermediateDirectory)/quanticvortex_qvGameState$(ObjectSuffix): ../../source/quanticvortex/qvGameState.cpp $(IntermediateDirectory)/quanticvortex_qvGameState$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvGameState.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/quanticvortex_qvGameState$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/quanticvortex_qvGameState$(DependSuffix): ../../source/quanticvortex/qvGameState.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/quanticvortex_qvGameState$(ObjectSuffix) -MF$(IntermediateDirectory)/quanticvortex_qvGameState$(DependSuffix) -MM "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvGameState.cpp"

$(IntermediateDirectory)/quanticvortex_qvGameState$(PreprocessSuffix): ../../source/quanticvortex/qvGameState.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/quanticvortex_qvGameState$(PreprocessSuffix) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvGameState.cpp"

$(IntermediateDirectory)/quanticvortex_qvEventArgsFactory$(ObjectSuffix): ../../source/quanticvortex/qvEventArgsFactory.cpp $(IntermediateDirectory)/quanticvortex_qvEventArgsFactory$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvEventArgsFactory.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/quanticvortex_qvEventArgsFactory$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/quanticvortex_qvEventArgsFactory$(DependSuffix): ../../source/quanticvortex/qvEventArgsFactory.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/quanticvortex_qvEventArgsFactory$(ObjectSuffix) -MF$(IntermediateDirectory)/quanticvortex_qvEventArgsFactory$(DependSuffix) -MM "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvEventArgsFactory.cpp"

$(IntermediateDirectory)/quanticvortex_qvEventArgsFactory$(PreprocessSuffix): ../../source/quanticvortex/qvEventArgsFactory.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/quanticvortex_qvEventArgsFactory$(PreprocessSuffix) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvEventArgsFactory.cpp"

$(IntermediateDirectory)/quanticvortex_qvGameTickEventArgs$(ObjectSuffix): ../../source/quanticvortex/qvGameTickEventArgs.cpp $(IntermediateDirectory)/quanticvortex_qvGameTickEventArgs$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvGameTickEventArgs.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/quanticvortex_qvGameTickEventArgs$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/quanticvortex_qvGameTickEventArgs$(DependSuffix): ../../source/quanticvortex/qvGameTickEventArgs.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/quanticvortex_qvGameTickEventArgs$(ObjectSuffix) -MF$(IntermediateDirectory)/quanticvortex_qvGameTickEventArgs$(DependSuffix) -MM "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvGameTickEventArgs.cpp"

$(IntermediateDirectory)/quanticvortex_qvGameTickEventArgs$(PreprocessSuffix): ../../source/quanticvortex/qvGameTickEventArgs.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/quanticvortex_qvGameTickEventArgs$(PreprocessSuffix) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvGameTickEventArgs.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/quanticvortex_qvActorMotion$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvActorMotion$(DependSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvActorMotion$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvAnyKeyInputTranslator$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvAnyKeyInputTranslator$(DependSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvAnyKeyInputTranslator$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvDefaultElementViewFactory$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvDefaultElementViewFactory$(DependSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvDefaultElementViewFactory$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvEngineInputTranslatorFactory$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvEngineInputTranslatorFactory$(DependSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvEngineInputTranslatorFactory$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvEventArgs$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvEventArgs$(DependSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvEventArgs$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvEventManager$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvEventManager$(DependSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvEventManager$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvGameLogic$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvGameLogic$(DependSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvGameLogic$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvGameParameters$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvGameParameters$(DependSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvGameParameters$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvGameStateMachine$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvGameStateMachine$(DependSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvGameStateMachine$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvGuiView$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvGuiView$(DependSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvGuiView$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvHashFunctions$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvHashFunctions$(DependSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvHashFunctions$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvHumanView$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvHumanView$(DependSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvHumanView$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvPhysicsManager$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvPhysicsManager$(DependSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvPhysicsManager$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvQuanticVortex$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvQuanticVortex$(DependSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvQuanticVortex$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvSingleKeyInputTranslator$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvSingleKeyInputTranslator$(DependSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvSingleKeyInputTranslator$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvSHashedString$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvSHashedString$(DependSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvSHashedString$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvGame$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvGame$(DependSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvGame$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvGameState$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvGameState$(DependSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvGameState$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvEventArgsFactory$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvEventArgsFactory$(DependSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvEventArgsFactory$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvGameTickEventArgs$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvGameTickEventArgs$(DependSuffix)
	$(RM) $(IntermediateDirectory)/quanticvortex_qvGameTickEventArgs$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile)



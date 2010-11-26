##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Windows_x86_-_DLL_-_Debug
ProjectName            :=QuanticVortexAddin_Irrlicht
ConfigurationName      :=Windows_x86_-_DLL_-_Debug
IntermediateDirectory  :=../obj/Debug
OutDir                 := $(IntermediateDirectory)
WorkspacePath          := "E:\Projetos\QuanticVortex\engine samples"
ProjectPath            := "E:\Projetos\QuanticVortex\addins\QuanticVortexAddin_Irrlicht\builds"
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Adriano
Date                   :=11/26/10
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
OutputFile             :=../../bin/$(ProjectName)_d.dll
Preprocessors          :=$(PreprocessorSwitch)WIN32 $(PreprocessorSwitch)_DEBUG $(PreprocessorSwitch)_QUANTICVORTEX_ADDIN_IRRLICHT_EXPORTS $(PreprocessorSwitch)_CRT_SECURE_NO_WARNINGS $(PreprocessorSwitch)__GNUWIN32__ 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
MakeDirCommand         :=makedir
CmpOptions             := -g $(Preprocessors)
LinkOptions            :=  
IncludePath            :=  "$(IncludeSwitch)." "$(IncludeSwitch)../source" "$(IncludeSwitch)../include" "$(IncludeSwitch)../../../engine/include" "$(IncludeSwitch)../../../dependencies/include/irrlicht/include" "$(IncludeSwitch)../../../dependencies/include/bullet" 
RcIncludePath          :=
Libs                   :=$(LibrarySwitch)QuanticVortex_d $(LibrarySwitch)Irrlicht_d $(LibrarySwitch)cAudio_d $(LibrarySwitch)bulletdynamics_d $(LibrarySwitch)bulletcollision_d $(LibrarySwitch)bulletsoftbody_d $(LibrarySwitch)LinearMath_d 
LibPath                := "$(LibraryPathSwitch)." "$(LibraryPathSwitch)../../../dependencies/libs/win32-gcc" "$(LibraryPathSwitch)../../../dependencies/bin/win32-gcc" "$(LibraryPathSwitch)../../../engine/bin/win32-gcc" 


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files (x86)\CodeLite
Objects=$(IntermediateDirectory)/source_qvAddinIrrlicht$(ObjectSuffix) $(IntermediateDirectory)/source_qvIrrlichtHumanView$(ObjectSuffix) $(IntermediateDirectory)/source_qvIrrlichtGuiElementView$(ObjectSuffix) $(IntermediateDirectory)/source_qvIrrlichtSceneElementView$(ObjectSuffix) $(IntermediateDirectory)/source_qvIrrlichtSceneLoader$(ObjectSuffix) 

##
## Main Build Targets 
##
all: $(OutputFile)

$(OutputFile): makeDirStep $(Objects)
	@$(MakeDirCommand) $(@D)
	$(SharedObjectLinkerName) $(OutputSwitch)$(OutputFile) $(Objects) $(LibPath) $(Libs) $(LinkOptions)

makeDirStep:
	@$(MakeDirCommand) "../obj/Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/source_qvAddinIrrlicht$(ObjectSuffix): ../source/qvAddinIrrlicht.cpp $(IntermediateDirectory)/source_qvAddinIrrlicht$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticVortex/addins/QuanticVortexAddin_Irrlicht/source/qvAddinIrrlicht.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/source_qvAddinIrrlicht$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/source_qvAddinIrrlicht$(DependSuffix): ../source/qvAddinIrrlicht.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/source_qvAddinIrrlicht$(ObjectSuffix) -MF$(IntermediateDirectory)/source_qvAddinIrrlicht$(DependSuffix) -MM "E:/Projetos/QuanticVortex/addins/QuanticVortexAddin_Irrlicht/source/qvAddinIrrlicht.cpp"

$(IntermediateDirectory)/source_qvAddinIrrlicht$(PreprocessSuffix): ../source/qvAddinIrrlicht.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/source_qvAddinIrrlicht$(PreprocessSuffix) "E:/Projetos/QuanticVortex/addins/QuanticVortexAddin_Irrlicht/source/qvAddinIrrlicht.cpp"

$(IntermediateDirectory)/source_qvIrrlichtHumanView$(ObjectSuffix): ../source/qvIrrlichtHumanView.cpp $(IntermediateDirectory)/source_qvIrrlichtHumanView$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticVortex/addins/QuanticVortexAddin_Irrlicht/source/qvIrrlichtHumanView.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/source_qvIrrlichtHumanView$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/source_qvIrrlichtHumanView$(DependSuffix): ../source/qvIrrlichtHumanView.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/source_qvIrrlichtHumanView$(ObjectSuffix) -MF$(IntermediateDirectory)/source_qvIrrlichtHumanView$(DependSuffix) -MM "E:/Projetos/QuanticVortex/addins/QuanticVortexAddin_Irrlicht/source/qvIrrlichtHumanView.cpp"

$(IntermediateDirectory)/source_qvIrrlichtHumanView$(PreprocessSuffix): ../source/qvIrrlichtHumanView.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/source_qvIrrlichtHumanView$(PreprocessSuffix) "E:/Projetos/QuanticVortex/addins/QuanticVortexAddin_Irrlicht/source/qvIrrlichtHumanView.cpp"

$(IntermediateDirectory)/source_qvIrrlichtGuiElementView$(ObjectSuffix): ../source/qvIrrlichtGuiElementView.cpp $(IntermediateDirectory)/source_qvIrrlichtGuiElementView$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticVortex/addins/QuanticVortexAddin_Irrlicht/source/qvIrrlichtGuiElementView.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/source_qvIrrlichtGuiElementView$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/source_qvIrrlichtGuiElementView$(DependSuffix): ../source/qvIrrlichtGuiElementView.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/source_qvIrrlichtGuiElementView$(ObjectSuffix) -MF$(IntermediateDirectory)/source_qvIrrlichtGuiElementView$(DependSuffix) -MM "E:/Projetos/QuanticVortex/addins/QuanticVortexAddin_Irrlicht/source/qvIrrlichtGuiElementView.cpp"

$(IntermediateDirectory)/source_qvIrrlichtGuiElementView$(PreprocessSuffix): ../source/qvIrrlichtGuiElementView.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/source_qvIrrlichtGuiElementView$(PreprocessSuffix) "E:/Projetos/QuanticVortex/addins/QuanticVortexAddin_Irrlicht/source/qvIrrlichtGuiElementView.cpp"

$(IntermediateDirectory)/source_qvIrrlichtSceneElementView$(ObjectSuffix): ../source/qvIrrlichtSceneElementView.cpp $(IntermediateDirectory)/source_qvIrrlichtSceneElementView$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticVortex/addins/QuanticVortexAddin_Irrlicht/source/qvIrrlichtSceneElementView.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/source_qvIrrlichtSceneElementView$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/source_qvIrrlichtSceneElementView$(DependSuffix): ../source/qvIrrlichtSceneElementView.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/source_qvIrrlichtSceneElementView$(ObjectSuffix) -MF$(IntermediateDirectory)/source_qvIrrlichtSceneElementView$(DependSuffix) -MM "E:/Projetos/QuanticVortex/addins/QuanticVortexAddin_Irrlicht/source/qvIrrlichtSceneElementView.cpp"

$(IntermediateDirectory)/source_qvIrrlichtSceneElementView$(PreprocessSuffix): ../source/qvIrrlichtSceneElementView.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/source_qvIrrlichtSceneElementView$(PreprocessSuffix) "E:/Projetos/QuanticVortex/addins/QuanticVortexAddin_Irrlicht/source/qvIrrlichtSceneElementView.cpp"

$(IntermediateDirectory)/source_qvIrrlichtSceneLoader$(ObjectSuffix): ../source/qvIrrlichtSceneLoader.cpp $(IntermediateDirectory)/source_qvIrrlichtSceneLoader$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticVortex/addins/QuanticVortexAddin_Irrlicht/source/qvIrrlichtSceneLoader.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/source_qvIrrlichtSceneLoader$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/source_qvIrrlichtSceneLoader$(DependSuffix): ../source/qvIrrlichtSceneLoader.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/source_qvIrrlichtSceneLoader$(ObjectSuffix) -MF$(IntermediateDirectory)/source_qvIrrlichtSceneLoader$(DependSuffix) -MM "E:/Projetos/QuanticVortex/addins/QuanticVortexAddin_Irrlicht/source/qvIrrlichtSceneLoader.cpp"

$(IntermediateDirectory)/source_qvIrrlichtSceneLoader$(PreprocessSuffix): ../source/qvIrrlichtSceneLoader.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/source_qvIrrlichtSceneLoader$(PreprocessSuffix) "E:/Projetos/QuanticVortex/addins/QuanticVortexAddin_Irrlicht/source/qvIrrlichtSceneLoader.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/source_qvAddinIrrlicht$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/source_qvAddinIrrlicht$(DependSuffix)
	$(RM) $(IntermediateDirectory)/source_qvAddinIrrlicht$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/source_qvIrrlichtHumanView$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/source_qvIrrlichtHumanView$(DependSuffix)
	$(RM) $(IntermediateDirectory)/source_qvIrrlichtHumanView$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/source_qvIrrlichtGuiElementView$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/source_qvIrrlichtGuiElementView$(DependSuffix)
	$(RM) $(IntermediateDirectory)/source_qvIrrlichtGuiElementView$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/source_qvIrrlichtSceneElementView$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/source_qvIrrlichtSceneElementView$(DependSuffix)
	$(RM) $(IntermediateDirectory)/source_qvIrrlichtSceneElementView$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/source_qvIrrlichtSceneLoader$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/source_qvIrrlichtSceneLoader$(DependSuffix)
	$(RM) $(IntermediateDirectory)/source_qvIrrlichtSceneLoader$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile)



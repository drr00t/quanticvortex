##
## Auto Generated makefile, please do not edit
##
INCLUDE:=C:\Program Files\Microsoft Visual Studio 8\VC\ATLMFC\INCLUDE;C:\Program Files\Microsoft Visual Studio 8\VC\INCLUDE;C:\Program Files\Microsoft Visual Studio 8\VC\PlatformSDK\include;C:\Program Files\Microsoft Visual Studio 8\SDK\v2.0\include;
LIB:=C:\Program Files\Microsoft Visual Studio 8\VC\ATLMFC\LIB;C:\Program Files\Microsoft Visual Studio 8\VC\LIB;C:\Program Files\Microsoft Visual Studio 8\VC\PlatformSDK\lib;C:\Program Files\Microsoft Visual Studio 8\SDK\v2.0\lib;
Path:=%PAT%;C:\Program Files\Microsoft Visual Studio 8\Common7\IDE;C:\Program Files\Microsoft Visual Studio 8\VC\BIN;C:\Program Files\Microsoft Visual Studio 8\Common7\Tools;C:\Program Files\Microsoft Visual Studio 8\Common7\Tools\bin;C:\Program Files\Microsoft Visual Studio 8\VC\PlatformSDK\bin;C:\Program Files\Microsoft Visual Studio 8\SDK\v2.0\bin;C:\Windows\Microsoft.NET\Framework\v2.0.50727;C:\Program Files\Microsoft Visual Studio 8\VC\VCPackages;C:\Perl\site\bin;C:\Perl\bin;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Program Files\TortoiseSVN\bin;C:\Program Files\TortoiseHg;C:\Program Files\GtkSharp\2.12\bin;C:\msys\1.0\bin;C:\Program Files\Cppcheck\;C:\Program Files\CMake 2.8\bin
UNIT_TEST_PP_SRC_DIR:=C:\Program Files\CodeLite\UnitTest++-1.3
ProjectName:=QuanticVortex Core

## DebugDLL
ConfigurationName      :=DebugDLL
IntermediateDirectory  :=../obj/debug
OutDir                 := $(IntermediateDirectory)
WorkspacePath          := "E:\Projetos\QuanticMinds\Sylfur-D.C\Sdcgame"
ProjectPath            := "E:\Projetos\QuanticMinds\Sylfur-D.C\QuanticVortex\engine\builds\codelite"
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=adriano
Date                   :=02/01/10
CodeLitePath           :="C:\Program Files\CodeLite"
LinkerName             :=link.exe  /nologo
ArchiveTool            :=lib.exe  /nologo
SharedObjectLinkerName :=link.exe /DLL  /nologo
ObjectSuffix           :=.obj
DependSuffix           :=
PreprocessSuffix       :=
DebugSwitch            :=/Zi 
IncludeSwitch          :=/I
LibrarySwitch          := 
OutputSwitch           :=/OUT:
LibraryPathSwitch      :=/LIBPATH:
PreprocessorSwitch     :=/D
SourceSwitch           :=
CompilerName           :=cl.exe /nologo /c
C_CompilerName         :=cl.exe /nologo /c
OutputFile             :=
Preprocessors          :=$(PreprocessorSwitch)WIN32 $(PreprocessorSwitch)_DEBUG $(PreprocessorSwitch)_QUANTICVORTEX_EXPORTS $(PreprocessorSwitch)_CRT_SECURE_NO_WARNINGS 
ObjectSwitch           :=/Fo
ArchiveOutputSwitch    :=/OUT:
PreprocessOnlySwitch   :=
CmpOptions             := -g $(Preprocessors)
LinkOptions            :=  -O0
IncludePath            := "$(IncludeSwitch)"C:/Program Files/Microsoft Visual Studio 8/VC/ATLMFC/INCLUDE" "$(IncludeSwitch)C:/Program Files/Microsoft Visual Studio 8/VC/INCLUDE" "$(IncludeSwitch)C:/Program Files/Microsoft Visual Studio 8/VC/PlatformSDK/include" "$(IncludeSwitch)C:/Program Files/Microsoft Visual Studio 8/SDK/v2.0/include"" "$(IncludeSwitch)."  "$(IncludeSwitch)." "$(IncludeSwitch)../../../engine/include" "$(IncludeSwitch)../../../engine/source/quanticvortex" "$(IncludeSwitch)../../../engine/source/quanticvortex/irrbmesh" "$(IncludeSwitch)../../../../dependencies/include/irrlicht/include" "$(IncludeSwitch)../../../../dependencies/include/bullet" "$(IncludeSwitch)../../../../dependencies/include/tbb" "$(IncludeSwitch)../../../../dependencies/include/POCO" 
RcIncludePath          :=
Libs                   :=
LibPath                :="$(LibraryPathSwitch)"C:/Program Files/Microsoft Visual Studio 8/VC/ATLMFC/LIB" "$(LibraryPathSwitch)C:/Program Files/Microsoft Visual Studio 8/VC/LIB" "$(LibraryPathSwitch)C:/Program Files/Microsoft Visual Studio 8/VC/PlatformSDK/lib" "$(LibraryPathSwitch)C:/Program Files/Microsoft Visual Studio 8/SDK/v2.0/lib" "$(LibraryPathSwitch)""  "$(LibraryPathSwitch)." "$(LibraryPathSwitch)." "$(LibraryPathSwitch)Debug" 


Objects=../../source/quanticvortex/$(IntermediateDirectory)/qvEngineManager$(ObjectSuffix) ../../source/quanticvortex/$(IntermediateDirectory)/qvQuanticVortex$(ObjectSuffix) ../../source/quanticvortex/extern/IrrINI/$(IntermediateDirectory)/CIrrIniIrr$(ObjectSuffix) ../../source/quanticvortex/extern/IrrINI/$(IntermediateDirectory)/CIrrIniStub$(ObjectSuffix) ../../source/quanticvortex/extern/IrrINI/$(IntermediateDirectory)/IrrINI$(ObjectSuffix) ../../source/quanticvortex/extern/getopt/$(IntermediateDirectory)/getopt$(ObjectSuffix) ../../source/quanticvortex/$(IntermediateDirectory)/qvDefaultElementViewFactory$(ObjectSuffix) ../../source/quanticvortex/$(IntermediateDirectory)/qvDefaultGameViewFactory$(ObjectSuffix) ../../source/quanticvortex/$(IntermediateDirectory)/qvHumanView$(ObjectSuffix) ../../source/quanticvortex/$(IntermediateDirectory)/qvSceneView$(ObjectSuffix) \
	../../source/quanticvortex/$(IntermediateDirectory)/qvGuiView$(ObjectSuffix) ../../source/quanticvortex/$(IntermediateDirectory)/qvPhysicsManager$(ObjectSuffix) ../../source/quanticvortex/$(IntermediateDirectory)/qvEngineInputTranslatorFactory$(ObjectSuffix) ../../source/quanticvortex/$(IntermediateDirectory)/qvInputReceiver$(ObjectSuffix) ../../source/quanticvortex/$(IntermediateDirectory)/qvActor$(ObjectSuffix) ../../source/quanticvortex/$(IntermediateDirectory)/qvActorFactory$(ObjectSuffix) ../../source/quanticvortex/$(IntermediateDirectory)/qvActorManager$(ObjectSuffix) ../../source/quanticvortex/$(IntermediateDirectory)/qvEventManager$(ObjectSuffix) ../../source/quanticvortex/$(IntermediateDirectory)/qvGameLogic$(ObjectSuffix) ../../source/quanticvortex/$(IntermediateDirectory)/qvGameLogicFactory$(ObjectSuffix) \
	../../source/quanticvortex/$(IntermediateDirectory)/qvGameStateMachine$(ObjectSuffix) 

##
## Main Build Targets 
##
all: $(OutputFile)

$(OutputFile): makeDirStep $(Objects)
	@makedir $(@D)
	$(LinkerName) $(OutputSwitch)$(OutputFile) $(Objects) $(LibPath) $(Libs) $(LinkOptions)

makeDirStep:
	@makedir "../obj/debug"

PreBuild:


##
## Objects
##
../../source/quanticvortex/$(IntermediateDirectory)/qvEngineManager$(ObjectSuffix): ../../source/quanticvortex/qvEngineManager.cpp 
	@makedir "../../source/quanticvortex/../obj/debug"
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvEngineManager.cpp" $(CmpOptions) $(ObjectSwitch)../../source/quanticvortex/$(IntermediateDirectory)/qvEngineManager$(ObjectSuffix) $(IncludePath)
../../source/quanticvortex/$(IntermediateDirectory)/qvQuanticVortex$(ObjectSuffix): ../../source/quanticvortex/qvQuanticVortex.cpp 
	@makedir "../../source/quanticvortex/../obj/debug"
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvQuanticVortex.cpp" $(CmpOptions) $(ObjectSwitch)../../source/quanticvortex/$(IntermediateDirectory)/qvQuanticVortex$(ObjectSuffix) $(IncludePath)
../../source/quanticvortex/extern/IrrINI/$(IntermediateDirectory)/CIrrIniIrr$(ObjectSuffix): ../../source/quanticvortex/extern/IrrINI/CIrrIniIrr.cpp 
	@makedir "../../source/quanticvortex/extern/IrrINI/../obj/debug"
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/extern/IrrINI/CIrrIniIrr.cpp" $(CmpOptions) $(ObjectSwitch)../../source/quanticvortex/extern/IrrINI/$(IntermediateDirectory)/CIrrIniIrr$(ObjectSuffix) $(IncludePath)
../../source/quanticvortex/extern/IrrINI/$(IntermediateDirectory)/CIrrIniStub$(ObjectSuffix): ../../source/quanticvortex/extern/IrrINI/CIrrIniStub.cpp 
	@makedir "../../source/quanticvortex/extern/IrrINI/../obj/debug"
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/extern/IrrINI/CIrrIniStub.cpp" $(CmpOptions) $(ObjectSwitch)../../source/quanticvortex/extern/IrrINI/$(IntermediateDirectory)/CIrrIniStub$(ObjectSuffix) $(IncludePath)
../../source/quanticvortex/extern/IrrINI/$(IntermediateDirectory)/IrrINI$(ObjectSuffix): ../../source/quanticvortex/extern/IrrINI/IrrINI.cpp 
	@makedir "../../source/quanticvortex/extern/IrrINI/../obj/debug"
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/extern/IrrINI/IrrINI.cpp" $(CmpOptions) $(ObjectSwitch)../../source/quanticvortex/extern/IrrINI/$(IntermediateDirectory)/IrrINI$(ObjectSuffix) $(IncludePath)
../../source/quanticvortex/extern/getopt/$(IntermediateDirectory)/getopt$(ObjectSuffix): ../../source/quanticvortex/extern/getopt/getopt.cpp 
	@makedir "../../source/quanticvortex/extern/getopt/../obj/debug"
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/extern/getopt/getopt.cpp" $(CmpOptions) $(ObjectSwitch)../../source/quanticvortex/extern/getopt/$(IntermediateDirectory)/getopt$(ObjectSuffix) $(IncludePath)
../../source/quanticvortex/$(IntermediateDirectory)/qvDefaultElementViewFactory$(ObjectSuffix): ../../source/quanticvortex/qvDefaultElementViewFactory.cpp 
	@makedir "../../source/quanticvortex/../obj/debug"
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvDefaultElementViewFactory.cpp" $(CmpOptions) $(ObjectSwitch)../../source/quanticvortex/$(IntermediateDirectory)/qvDefaultElementViewFactory$(ObjectSuffix) $(IncludePath)
../../source/quanticvortex/$(IntermediateDirectory)/qvDefaultGameViewFactory$(ObjectSuffix): ../../source/quanticvortex/qvDefaultGameViewFactory.cpp 
	@makedir "../../source/quanticvortex/../obj/debug"
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvDefaultGameViewFactory.cpp" $(CmpOptions) $(ObjectSwitch)../../source/quanticvortex/$(IntermediateDirectory)/qvDefaultGameViewFactory$(ObjectSuffix) $(IncludePath)
../../source/quanticvortex/$(IntermediateDirectory)/qvHumanView$(ObjectSuffix): ../../source/quanticvortex/qvHumanView.cpp 
	@makedir "../../source/quanticvortex/../obj/debug"
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvHumanView.cpp" $(CmpOptions) $(ObjectSwitch)../../source/quanticvortex/$(IntermediateDirectory)/qvHumanView$(ObjectSuffix) $(IncludePath)
../../source/quanticvortex/$(IntermediateDirectory)/qvSceneView$(ObjectSuffix): ../../source/quanticvortex/qvSceneView.cpp 
	@makedir "../../source/quanticvortex/../obj/debug"
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvSceneView.cpp" $(CmpOptions) $(ObjectSwitch)../../source/quanticvortex/$(IntermediateDirectory)/qvSceneView$(ObjectSuffix) $(IncludePath)
../../source/quanticvortex/$(IntermediateDirectory)/qvGuiView$(ObjectSuffix): ../../source/quanticvortex/qvGuiView.cpp 
	@makedir "../../source/quanticvortex/../obj/debug"
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvGuiView.cpp" $(CmpOptions) $(ObjectSwitch)../../source/quanticvortex/$(IntermediateDirectory)/qvGuiView$(ObjectSuffix) $(IncludePath)
../../source/quanticvortex/$(IntermediateDirectory)/qvPhysicsManager$(ObjectSuffix): ../../source/quanticvortex/qvPhysicsManager.cpp 
	@makedir "../../source/quanticvortex/../obj/debug"
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvPhysicsManager.cpp" $(CmpOptions) $(ObjectSwitch)../../source/quanticvortex/$(IntermediateDirectory)/qvPhysicsManager$(ObjectSuffix) $(IncludePath)
../../source/quanticvortex/$(IntermediateDirectory)/qvEngineInputTranslatorFactory$(ObjectSuffix): ../../source/quanticvortex/qvEngineInputTranslatorFactory.cpp 
	@makedir "../../source/quanticvortex/../obj/debug"
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvEngineInputTranslatorFactory.cpp" $(CmpOptions) $(ObjectSwitch)../../source/quanticvortex/$(IntermediateDirectory)/qvEngineInputTranslatorFactory$(ObjectSuffix) $(IncludePath)
../../source/quanticvortex/$(IntermediateDirectory)/qvInputReceiver$(ObjectSuffix): ../../source/quanticvortex/qvInputReceiver.cpp 
	@makedir "../../source/quanticvortex/../obj/debug"
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvInputReceiver.cpp" $(CmpOptions) $(ObjectSwitch)../../source/quanticvortex/$(IntermediateDirectory)/qvInputReceiver$(ObjectSuffix) $(IncludePath)
../../source/quanticvortex/$(IntermediateDirectory)/qvActor$(ObjectSuffix): ../../source/quanticvortex/qvActor.cpp 
	@makedir "../../source/quanticvortex/../obj/debug"
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvActor.cpp" $(CmpOptions) $(ObjectSwitch)../../source/quanticvortex/$(IntermediateDirectory)/qvActor$(ObjectSuffix) $(IncludePath)
../../source/quanticvortex/$(IntermediateDirectory)/qvActorFactory$(ObjectSuffix): ../../source/quanticvortex/qvActorFactory.cpp 
	@makedir "../../source/quanticvortex/../obj/debug"
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvActorFactory.cpp" $(CmpOptions) $(ObjectSwitch)../../source/quanticvortex/$(IntermediateDirectory)/qvActorFactory$(ObjectSuffix) $(IncludePath)
../../source/quanticvortex/$(IntermediateDirectory)/qvActorManager$(ObjectSuffix): ../../source/quanticvortex/qvActorManager.cpp 
	@makedir "../../source/quanticvortex/../obj/debug"
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvActorManager.cpp" $(CmpOptions) $(ObjectSwitch)../../source/quanticvortex/$(IntermediateDirectory)/qvActorManager$(ObjectSuffix) $(IncludePath)
../../source/quanticvortex/$(IntermediateDirectory)/qvEventManager$(ObjectSuffix): ../../source/quanticvortex/qvEventManager.cpp 
	@makedir "../../source/quanticvortex/../obj/debug"
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvEventManager.cpp" $(CmpOptions) $(ObjectSwitch)../../source/quanticvortex/$(IntermediateDirectory)/qvEventManager$(ObjectSuffix) $(IncludePath)
../../source/quanticvortex/$(IntermediateDirectory)/qvGameLogic$(ObjectSuffix): ../../source/quanticvortex/qvGameLogic.cpp 
	@makedir "../../source/quanticvortex/../obj/debug"
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvGameLogic.cpp" $(CmpOptions) $(ObjectSwitch)../../source/quanticvortex/$(IntermediateDirectory)/qvGameLogic$(ObjectSuffix) $(IncludePath)
../../source/quanticvortex/$(IntermediateDirectory)/qvGameLogicFactory$(ObjectSuffix): ../../source/quanticvortex/qvGameLogicFactory.cpp 
	@makedir "../../source/quanticvortex/../obj/debug"
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvGameLogicFactory.cpp" $(CmpOptions) $(ObjectSwitch)../../source/quanticvortex/$(IntermediateDirectory)/qvGameLogicFactory$(ObjectSuffix) $(IncludePath)
../../source/quanticvortex/$(IntermediateDirectory)/qvGameStateMachine$(ObjectSuffix): ../../source/quanticvortex/qvGameStateMachine.cpp 
	@makedir "../../source/quanticvortex/../obj/debug"
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticMinds/Sylfur-D.C/QuanticVortex/engine/source/quanticvortex/qvGameStateMachine.cpp" $(CmpOptions) $(ObjectSwitch)../../source/quanticvortex/$(IntermediateDirectory)/qvGameStateMachine$(ObjectSuffix) $(IncludePath)
##
## Clean
##
clean:
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvEngineManager$(ObjectSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvEngineManager$(DependSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvEngineManager$(PreprocessSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvQuanticVortex$(ObjectSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvQuanticVortex$(DependSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvQuanticVortex$(PreprocessSuffix)
	$(RM) ../../source/quanticvortex/extern/IrrINI/$(IntermediateDirectory)/CIrrIniIrr$(ObjectSuffix)
	$(RM) ../../source/quanticvortex/extern/IrrINI/$(IntermediateDirectory)/CIrrIniIrr$(DependSuffix)
	$(RM) ../../source/quanticvortex/extern/IrrINI/$(IntermediateDirectory)/CIrrIniIrr$(PreprocessSuffix)
	$(RM) ../../source/quanticvortex/extern/IrrINI/$(IntermediateDirectory)/CIrrIniStub$(ObjectSuffix)
	$(RM) ../../source/quanticvortex/extern/IrrINI/$(IntermediateDirectory)/CIrrIniStub$(DependSuffix)
	$(RM) ../../source/quanticvortex/extern/IrrINI/$(IntermediateDirectory)/CIrrIniStub$(PreprocessSuffix)
	$(RM) ../../source/quanticvortex/extern/IrrINI/$(IntermediateDirectory)/IrrINI$(ObjectSuffix)
	$(RM) ../../source/quanticvortex/extern/IrrINI/$(IntermediateDirectory)/IrrINI$(DependSuffix)
	$(RM) ../../source/quanticvortex/extern/IrrINI/$(IntermediateDirectory)/IrrINI$(PreprocessSuffix)
	$(RM) ../../source/quanticvortex/extern/getopt/$(IntermediateDirectory)/getopt$(ObjectSuffix)
	$(RM) ../../source/quanticvortex/extern/getopt/$(IntermediateDirectory)/getopt$(DependSuffix)
	$(RM) ../../source/quanticvortex/extern/getopt/$(IntermediateDirectory)/getopt$(PreprocessSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvDefaultElementViewFactory$(ObjectSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvDefaultElementViewFactory$(DependSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvDefaultElementViewFactory$(PreprocessSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvDefaultGameViewFactory$(ObjectSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvDefaultGameViewFactory$(DependSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvDefaultGameViewFactory$(PreprocessSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvHumanView$(ObjectSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvHumanView$(DependSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvHumanView$(PreprocessSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvSceneView$(ObjectSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvSceneView$(DependSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvSceneView$(PreprocessSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvGuiView$(ObjectSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvGuiView$(DependSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvGuiView$(PreprocessSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvPhysicsManager$(ObjectSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvPhysicsManager$(DependSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvPhysicsManager$(PreprocessSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvEngineInputTranslatorFactory$(ObjectSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvEngineInputTranslatorFactory$(DependSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvEngineInputTranslatorFactory$(PreprocessSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvInputReceiver$(ObjectSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvInputReceiver$(DependSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvInputReceiver$(PreprocessSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvActor$(ObjectSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvActor$(DependSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvActor$(PreprocessSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvActorFactory$(ObjectSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvActorFactory$(DependSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvActorFactory$(PreprocessSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvActorManager$(ObjectSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvActorManager$(DependSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvActorManager$(PreprocessSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvEventManager$(ObjectSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvEventManager$(DependSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvEventManager$(PreprocessSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvGameLogic$(ObjectSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvGameLogic$(DependSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvGameLogic$(PreprocessSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvGameLogicFactory$(ObjectSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvGameLogicFactory$(DependSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvGameLogicFactory$(PreprocessSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvGameStateMachine$(ObjectSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvGameStateMachine$(DependSuffix)
	$(RM) ../../source/quanticvortex/$(IntermediateDirectory)/qvGameStateMachine$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe



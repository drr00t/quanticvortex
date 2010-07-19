##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=QuanticVortex_Tests
ConfigurationName      :=Debug
IntermediateDirectory  :=../../obj/Debug
OutDir                 := $(IntermediateDirectory)
WorkspacePath          := "E:\Projetos\QuanticVortex\engine samples"
ProjectPath            := "E:\Projetos\QuanticVortex\engine tests\builds\codelite"
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
OutputFile             :=../../bin/win32-gcc/$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)WIN32 $(PreprocessorSwitch)_DEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
MakeDirCommand         :=makedir
CmpOptions             := -g $(Preprocessors)
LinkOptions            :=  
IncludePath            :=  "$(IncludeSwitch)." "$(IncludeSwitch)../../source" "$(IncludeSwitch)../../../dependencies/include/UnitTest++" "$(IncludeSwitch)../../../dependencies/include/irrlicht/include" "$(IncludeSwitch)../../../dependencies/include/bullet" "$(IncludeSwitch)../../../dependencies/include/poco" "$(IncludeSwitch)../../../dependencies/include/cAudio/include" "$(IncludeSwitch)../../../engine/include" 
RcIncludePath          :=
Libs                   :=$(LibrarySwitch)UnitTest++ $(LibrarySwitch)QuanticVortex_d 
LibPath                := "$(LibraryPathSwitch)." "$(LibraryPathSwitch)../../../dependencies/libs/win32-gcc" "$(LibraryPathSwitch)../../../engine/bin/win32-gcc" 


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects=$(IntermediateDirectory)/source_main$(ObjectSuffix) 

##
## Main Build Targets 
##
all: $(OutputFile)

$(OutputFile): makeDirStep $(Objects)
	@$(MakeDirCommand) $(@D)
	$(LinkerName) $(OutputSwitch)$(OutputFile) $(Objects) $(LibPath) $(Libs) $(LinkOptions)
	@echo Executing Post Build commands ...
	copy ..\..\..\engine\bin\win32-gcc\QuanticVortex_d.dll ..\..\bin\win32-gcc\QuanticVortex_d.dll
	copy ..\..\..\dependencies\bin\win32-gcc\Irrlicht_d.dll ..\..\bin\win32-gcc\Irrlicht_d.dll
	copy ..\..\..\dependencies\bin\win32-gcc\cAudio_d.dll ..\..\bin\win32-gcc\cAudio_d.dll
	copy ..\..\..\dependencies\bin\win32-gcc\OpenAL32.dll ..\..\bin\win32-gcc\OpenAL32.dll
	copy ..\..\..\dependencies\bin\win32-gcc\wrap_oal.dll ..\..\bin\win32-gcc\wrap_oal.dll
	copy ..\..\..\dependencies\bin\win32-gcc\cAp_EAXLegacyPreset.dll ..\..\bin\win32-gcc\cAp_EAXLegacyPreset.dll
	@echo Done

makeDirStep:
	@$(MakeDirCommand) "../../obj/Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/source_main$(ObjectSuffix): ../../source/main.cpp $(IntermediateDirectory)/source_main$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "E:/Projetos/QuanticVortex/engine tests/source/main.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/source_main$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/source_main$(DependSuffix): ../../source/main.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/source_main$(ObjectSuffix) -MF$(IntermediateDirectory)/source_main$(DependSuffix) -MM "E:/Projetos/QuanticVortex/engine tests/source/main.cpp"

$(IntermediateDirectory)/source_main$(PreprocessSuffix): ../../source/main.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/source_main$(PreprocessSuffix) "E:/Projetos/QuanticVortex/engine tests/source/main.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/source_main$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/source_main$(DependSuffix)
	$(RM) $(IntermediateDirectory)/source_main$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe



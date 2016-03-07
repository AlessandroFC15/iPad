##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=iPad
ConfigurationName      :=Debug
WorkspacePath          := "C:\Users\FACOMP\Documents\Aula"
ProjectPath            := "C:\Users\FACOMP\git\iPad\iPad"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=FACOMP
Date                   :=07/03/2016
CodeLitePath           :="C:\Program Files\CodeLite"
LinkerName             :=C:/cygwin64/bin/x86_64-pc-cygwin-g++.exe
SharedObjectLinkerName :=C:/cygwin64/bin/x86_64-pc-cygwin-g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="iPad.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=windres
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/cygwin64/bin/x86_64-pc-cygwin-ar.exe rcu
CXX      := C:/cygwin64/bin/x86_64-pc-cygwin-g++.exe -std=c++11
CC       := C:/cygwin64/bin/x86_64-pc-cygwin-gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/cygwin64/bin/x86_64-pc-cygwin-as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/IPad.cpp$(ObjectSuffix) $(IntermediateDirectory)/Data.cpp$(ObjectSuffix) $(IntermediateDirectory)/TouchID.cpp$(ObjectSuffix) $(IntermediateDirectory)/Device.cpp$(ObjectSuffix) $(IntermediateDirectory)/Tablet.cpp$(ObjectSuffix) $(IntermediateDirectory)/SamsungTablet.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/FACOMP/git/iPad/iPad/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/IPad.cpp$(ObjectSuffix): IPad.cpp $(IntermediateDirectory)/IPad.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/FACOMP/git/iPad/iPad/IPad.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/IPad.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/IPad.cpp$(DependSuffix): IPad.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/IPad.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/IPad.cpp$(DependSuffix) -MM "IPad.cpp"

$(IntermediateDirectory)/IPad.cpp$(PreprocessSuffix): IPad.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/IPad.cpp$(PreprocessSuffix) "IPad.cpp"

$(IntermediateDirectory)/Data.cpp$(ObjectSuffix): Data.cpp $(IntermediateDirectory)/Data.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/FACOMP/git/iPad/iPad/Data.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Data.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Data.cpp$(DependSuffix): Data.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Data.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Data.cpp$(DependSuffix) -MM "Data.cpp"

$(IntermediateDirectory)/Data.cpp$(PreprocessSuffix): Data.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Data.cpp$(PreprocessSuffix) "Data.cpp"

$(IntermediateDirectory)/TouchID.cpp$(ObjectSuffix): TouchID.cpp $(IntermediateDirectory)/TouchID.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/FACOMP/git/iPad/iPad/TouchID.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TouchID.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TouchID.cpp$(DependSuffix): TouchID.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/TouchID.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/TouchID.cpp$(DependSuffix) -MM "TouchID.cpp"

$(IntermediateDirectory)/TouchID.cpp$(PreprocessSuffix): TouchID.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TouchID.cpp$(PreprocessSuffix) "TouchID.cpp"

$(IntermediateDirectory)/Device.cpp$(ObjectSuffix): Device.cpp $(IntermediateDirectory)/Device.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/FACOMP/git/iPad/iPad/Device.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Device.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Device.cpp$(DependSuffix): Device.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Device.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Device.cpp$(DependSuffix) -MM "Device.cpp"

$(IntermediateDirectory)/Device.cpp$(PreprocessSuffix): Device.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Device.cpp$(PreprocessSuffix) "Device.cpp"

$(IntermediateDirectory)/Tablet.cpp$(ObjectSuffix): Tablet.cpp $(IntermediateDirectory)/Tablet.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/FACOMP/git/iPad/iPad/Tablet.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Tablet.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Tablet.cpp$(DependSuffix): Tablet.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Tablet.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Tablet.cpp$(DependSuffix) -MM "Tablet.cpp"

$(IntermediateDirectory)/Tablet.cpp$(PreprocessSuffix): Tablet.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Tablet.cpp$(PreprocessSuffix) "Tablet.cpp"

$(IntermediateDirectory)/SamsungTablet.cpp$(ObjectSuffix): SamsungTablet.cpp $(IntermediateDirectory)/SamsungTablet.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/FACOMP/git/iPad/iPad/SamsungTablet.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/SamsungTablet.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SamsungTablet.cpp$(DependSuffix): SamsungTablet.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/SamsungTablet.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/SamsungTablet.cpp$(DependSuffix) -MM "SamsungTablet.cpp"

$(IntermediateDirectory)/SamsungTablet.cpp$(PreprocessSuffix): SamsungTablet.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SamsungTablet.cpp$(PreprocessSuffix) "SamsungTablet.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/



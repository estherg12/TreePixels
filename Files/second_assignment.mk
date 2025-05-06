##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=second_assignment
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=C:/LabDDSS/GitHub/second-assignment-bit-byte/second_assignment
ProjectPath            :=C:/LabDDSS/GitHub/second-assignment-bit-byte/second_assignment/second_assignment
IntermediateDirectory  :=../build-$(WorkspaceConfiguration)/second_assignment
OutDir                 :=$(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Esther
Date                   :=1/17/2025
CodeLitePath           :="C:/Program Files/CodeLite"
MakeDirCommand         :=mkdir
LinkerName             :=C:/msys64/mingw64/bin/g++.exe
SharedObjectLinkerName :=C:/msys64/mingw64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputDirectory        :=C:/LabDDSS/GitHub/second-assignment-bit-byte/second_assignment/build-$(WorkspaceConfiguration)/bin
OutputFile             :=..\build-$(WorkspaceConfiguration)\bin\$(ProjectName).exe
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := 
RcCompilerName         :=C:/msys64/mingw64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := C:/msys64/mingw64/bin/ar.exe -r
CXX      := C:/msys64/mingw64/bin/g++.exe
CC       := C:/msys64/mingw64/bin/gcc.exe
CXXFLAGS :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
CFLAGS   :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/msys64/mingw64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/NodeBST.cpp$(ObjectSuffix) $(IntermediateDirectory)/ElementList.cpp$(ObjectSuffix) $(IntermediateDirectory)/Queue.cpp$(ObjectSuffix) $(IntermediateDirectory)/List.cpp$(ObjectSuffix) $(IntermediateDirectory)/Image.cpp$(ObjectSuffix) $(IntermediateDirectory)/ListOfList.cpp$(ObjectSuffix) $(IntermediateDirectory)/Core.cpp$(ObjectSuffix) $(IntermediateDirectory)/ElementQueue.cpp$(ObjectSuffix) $(IntermediateDirectory)/BST.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/ElementListOfList.cpp$(ObjectSuffix) $(IntermediateDirectory)/Statistics.cpp$(ObjectSuffix) $(IntermediateDirectory)/Pixel.cpp$(ObjectSuffix) $(IntermediateDirectory)/ListSum.cpp$(ObjectSuffix) $(IntermediateDirectory)/InputOutput.cpp$(ObjectSuffix) $(IntermediateDirectory)/ElementListSum.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"
	@if not exist "$(OutputDirectory)" $(MakeDirCommand) "$(OutputDirectory)"

$(IntermediateDirectory)/.d:
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/LabDDSS/GitHub/second-assignment-bit-byte/second_assignment/second_assignment/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/NodeBST.cpp$(ObjectSuffix): NodeBST.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/LabDDSS/GitHub/second-assignment-bit-byte/second_assignment/second_assignment/NodeBST.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/NodeBST.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/NodeBST.cpp$(PreprocessSuffix): NodeBST.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/NodeBST.cpp$(PreprocessSuffix) NodeBST.cpp

$(IntermediateDirectory)/ElementList.cpp$(ObjectSuffix): ElementList.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/LabDDSS/GitHub/second-assignment-bit-byte/second_assignment/second_assignment/ElementList.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ElementList.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ElementList.cpp$(PreprocessSuffix): ElementList.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ElementList.cpp$(PreprocessSuffix) ElementList.cpp

$(IntermediateDirectory)/Queue.cpp$(ObjectSuffix): Queue.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/LabDDSS/GitHub/second-assignment-bit-byte/second_assignment/second_assignment/Queue.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Queue.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Queue.cpp$(PreprocessSuffix): Queue.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Queue.cpp$(PreprocessSuffix) Queue.cpp

$(IntermediateDirectory)/List.cpp$(ObjectSuffix): List.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/LabDDSS/GitHub/second-assignment-bit-byte/second_assignment/second_assignment/List.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/List.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/List.cpp$(PreprocessSuffix): List.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/List.cpp$(PreprocessSuffix) List.cpp

$(IntermediateDirectory)/Image.cpp$(ObjectSuffix): Image.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/LabDDSS/GitHub/second-assignment-bit-byte/second_assignment/second_assignment/Image.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Image.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Image.cpp$(PreprocessSuffix): Image.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Image.cpp$(PreprocessSuffix) Image.cpp

$(IntermediateDirectory)/ListOfList.cpp$(ObjectSuffix): ListOfList.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/LabDDSS/GitHub/second-assignment-bit-byte/second_assignment/second_assignment/ListOfList.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ListOfList.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ListOfList.cpp$(PreprocessSuffix): ListOfList.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ListOfList.cpp$(PreprocessSuffix) ListOfList.cpp

$(IntermediateDirectory)/Core.cpp$(ObjectSuffix): Core.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/LabDDSS/GitHub/second-assignment-bit-byte/second_assignment/second_assignment/Core.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Core.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Core.cpp$(PreprocessSuffix): Core.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Core.cpp$(PreprocessSuffix) Core.cpp

$(IntermediateDirectory)/ElementQueue.cpp$(ObjectSuffix): ElementQueue.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/LabDDSS/GitHub/second-assignment-bit-byte/second_assignment/second_assignment/ElementQueue.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ElementQueue.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ElementQueue.cpp$(PreprocessSuffix): ElementQueue.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ElementQueue.cpp$(PreprocessSuffix) ElementQueue.cpp

$(IntermediateDirectory)/BST.cpp$(ObjectSuffix): BST.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/LabDDSS/GitHub/second-assignment-bit-byte/second_assignment/second_assignment/BST.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/BST.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/BST.cpp$(PreprocessSuffix): BST.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/BST.cpp$(PreprocessSuffix) BST.cpp

$(IntermediateDirectory)/ElementListOfList.cpp$(ObjectSuffix): ElementListOfList.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/LabDDSS/GitHub/second-assignment-bit-byte/second_assignment/second_assignment/ElementListOfList.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ElementListOfList.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ElementListOfList.cpp$(PreprocessSuffix): ElementListOfList.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ElementListOfList.cpp$(PreprocessSuffix) ElementListOfList.cpp

$(IntermediateDirectory)/Statistics.cpp$(ObjectSuffix): Statistics.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/LabDDSS/GitHub/second-assignment-bit-byte/second_assignment/second_assignment/Statistics.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Statistics.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Statistics.cpp$(PreprocessSuffix): Statistics.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Statistics.cpp$(PreprocessSuffix) Statistics.cpp

$(IntermediateDirectory)/Pixel.cpp$(ObjectSuffix): Pixel.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/LabDDSS/GitHub/second-assignment-bit-byte/second_assignment/second_assignment/Pixel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Pixel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Pixel.cpp$(PreprocessSuffix): Pixel.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Pixel.cpp$(PreprocessSuffix) Pixel.cpp

$(IntermediateDirectory)/ListSum.cpp$(ObjectSuffix): ListSum.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/LabDDSS/GitHub/second-assignment-bit-byte/second_assignment/second_assignment/ListSum.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ListSum.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ListSum.cpp$(PreprocessSuffix): ListSum.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ListSum.cpp$(PreprocessSuffix) ListSum.cpp

$(IntermediateDirectory)/InputOutput.cpp$(ObjectSuffix): InputOutput.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/LabDDSS/GitHub/second-assignment-bit-byte/second_assignment/second_assignment/InputOutput.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/InputOutput.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/InputOutput.cpp$(PreprocessSuffix): InputOutput.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/InputOutput.cpp$(PreprocessSuffix) InputOutput.cpp

$(IntermediateDirectory)/ElementListSum.cpp$(ObjectSuffix): ElementListSum.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/LabDDSS/GitHub/second-assignment-bit-byte/second_assignment/second_assignment/ElementListSum.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ElementListSum.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ElementListSum.cpp$(PreprocessSuffix): ElementListSum.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ElementListSum.cpp$(PreprocessSuffix) ElementListSum.cpp

##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)



#include <fstream>
#include "easylogging++.h"
#include "PipelineManager.h"
#include "FileManager.h"
#include "ContextManager.h"
int main(int argc, char* argv[]) {
    gPipelineInstance->Init();
    gFileInstance->Init();
    gPipelineInstance->ReadPath("D:/InstallSource/Pipeline/bin/pipeline/");
    gPipelineInstance->GenPipeline();
    gPipelineInstance->BindNodeFile();
  
    gPipelineInstance->FilterNode();

    gContextInstance->WriteReport("report.csv");

    gPipelineInstance->WriteReport();
 
    return 0;
}
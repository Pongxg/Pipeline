#include <fstream>
#include "easylogging++.h"
#include "PipelineManager.h"
#include "FileManager.h"
int main(int argc, char* argv[]) {
    gPipelineInstance->Init();
    gFileInstance->Init();
    gPipelineInstance->ReadPath("D:/InstallSource/Pipeline/bin/pipeline/");
    gPipelineInstance->GenPipeline();

  

    gPipelineInstance->WriteReport();
    return 0;
}
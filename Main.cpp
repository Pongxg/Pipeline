#include <fstream>
#include "easylogging++.h"
#include "PipelineManager.h"

int main(int argc, char* argv[]) {
    gPipelineInstance->Init();
    gPipelineInstance->ReadPath("D:/InstallSource/Pipeline/bin/pipeline/");
    gPipelineInstance->GenPipeline();
    gPipelineInstance->WriteReport();
    return 0;
}
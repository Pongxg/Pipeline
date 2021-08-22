#include <fstream>
#include "easylogging++.h"
#include "PipelineManager.h"

int main(int argc, char* argv[]) {
    std::string path = "pipeline";
    gPipelineInstance->Init();
    gPipelineInstance->ReadPath(path);
    gPipelineInstance->GenPipeline();
    gPipelineInstance->WriteReport();
    return 0;
}
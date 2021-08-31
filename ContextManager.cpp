#include "ContextManager.h"


ContextManager* Singleton<ContextManager>::m_pSingleton = NULL;

ContextManager::ContextManager() {

}


ContextManager::~ContextManager() {

}


bool ContextManager::WriteReport(std::string name)
{
    
    std::ofstream stream("report.csv");
    csv2::Writer<csv2::delimiter<','>> writer(stream);

    writer.write_rows(m_vecOutputs);
    stream.close();

    return true;
}

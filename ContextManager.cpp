#include "ContextManager.h"
#include "TaskNode.h"
#include "easylogging++.h"

ContextManager* Singleton<ContextManager>::m_pSingleton = NULL;

ContextManager::ContextManager() {

}


ContextManager::~ContextManager() {

}


bool ContextManager::AddKnowTaskNode(std::string name, TaskNode* node)
{
    TaskNodePair pair = m_mapKnowNode.insert(std::pair(name, node));
    if (!pair.second)
    {
        LOG(WARNING) << "AddKnowTaskNode::know node already exsit:" << name ;
        return false;
    }
    return true;
}


bool ContextManager::AddUnknowClassTaskNode(std::string unname, TaskNode* node)
{
    TaskNodePair pair = m_mapUnknowClassNode.insert(std::pair(unname, node));
    if (!pair.second)
    {
        LOG(WARNING) << "AddUnknowClassTaskNode::unknow node already exsit:" << unname;
        return false;
    }
    return true;
}

bool ContextManager::AddUnknowHandlerTaskNode(std::string unname, TaskNode* node)
{
    TaskNodePair pair = m_mapUnknowHandlerNode.insert(std::pair(unname, node));
    if (!pair.second)
    {
        LOG(WARNING) << "AddUnknowHandlerTaskNode::unknow node already exsit:" << unname;
        return false;
    }
    return true;

}

bool ContextManager::AddUnknowTaskNode(std::string unname, TaskNode* node)
{

    TaskNodePair pair = m_mapUnknowNode.insert(std::pair(unname, node));
    if (!pair.second)
    {
        LOG(WARNING) << "AddUnknowTaskNode::unknow node already exsit:" << unname;
        return false;
    }
    return true;
}

bool ContextManager::AddExeTaskNode(std::string unname, TaskNode* node)
{
    TaskNodePair pair = m_mapExeNode.insert(std::pair(unname, node));
    if (!pair.second)
    {
        LOG(WARNING) << "AddExeTaskNode::unknow node already exsit:" << unname;
        return false;
    }
    return true;
}

bool ContextManager::FindTaskNode(std::string& name, TaskNode* node)
{
    TaskNodeIter iter = m_mapExeNode.find(name);
    if (iter != m_mapExeNode.end())
    {
        
        return true;
    }
    return false;
}


bool ContextManager::OrderReport()
{
    int nodesize = m_mapKnowNode.size() + m_mapUnknowClassNode.size() + m_mapUnknowHandlerNode.size()+ m_mapUnknowNode.size();
    int unkownNodesize = m_mapUnknowClassNode.size() + m_mapUnknowHandlerNode.size() + m_mapUnknowNode.size();
    int exeNodesize = m_mapExeNode.size(); 

    std::vector < std::string >  outputList;
    outputList.reserve(10);
    outputList.push_back("节点数目"); outputList.push_back(std::to_string(nodesize));
    outputList.push_back("未知节点数目"); outputList.push_back(std::to_string(unkownNodesize));
    outputList.push_back("未知源节点数目"); outputList.push_back(std::to_string(exeNodesize));
    m_vecOutputs.push_back(outputList);

    for (int i = 0; i < 6; ++i)
    {
      
    }

    TaskNodeIter iter = m_mapUnknowNode.begin();
    for (; iter != m_mapUnknowNode.end(); ++iter)
    {
        std::vector < std::string >  outputList;
        outputList.reserve(10);

        outputList.push_back("未知节点ID:找不到源码");
        outputList.push_back(iter->first);
        outputList.push_back(iter->second->m_strName);
        outputList.push_back(iter->second->comment);
        outputList.push_back(iter->second->classRef);
        outputList.push_back(iter->second->m_strHandlerName);
        m_vecOutputs.push_back(outputList);
    }
    iter = m_mapUnknowHandlerNode.begin();
    for (; iter != m_mapUnknowHandlerNode.end(); ++iter)
    {
        std::vector < std::string >  outputList;
        outputList.reserve(10);
        outputList.push_back("未知节点Handle:找不到源码");
        outputList.push_back(iter->first);
        outputList.push_back(iter->second->m_strName);
        outputList.push_back(iter->second->comment);
        outputList.push_back(iter->second->classRef);
        outputList.push_back(iter->second->m_strHandlerName);
        m_vecOutputs.push_back(outputList);
    }
     iter = m_mapUnknowClassNode.begin();
    for (; iter != m_mapUnknowClassNode.end(); ++iter)
    {
        std::vector < std::string >  outputList;
        outputList.reserve(10);
        outputList.push_back("未知节点Class:找不到源码");
        outputList.push_back(iter->first);
        outputList.push_back(iter->second->m_strName);
        outputList.push_back(iter->second->comment);
        outputList.push_back(iter->second->classRef);
        outputList.push_back(iter->second->m_strHandlerName);
        m_vecOutputs.push_back(outputList);
    }
     iter = m_mapKnowNode.begin();
    for (; iter != m_mapKnowNode.end(); ++iter)
    {
        std::vector < std::string >  outputList;
        outputList.reserve(10);
        std::string data = "已知节点File";
        outputList.push_back("已知节点File");
        outputList.push_back(iter->first);
        outputList.push_back(iter->second->m_strName);
        outputList.push_back(iter->second->comment);
        outputList.push_back(iter->second->classRef);
        outputList.push_back(iter->second->m_strHandlerName);
        m_vecOutputs.push_back(outputList);
    }

    iter = m_mapExeNode.begin();
    for (; iter != m_mapExeNode.end(); ++iter)
    {
        std::vector < std::string >  outputList;
        outputList.reserve(10);
        std::string data = "未知源节点";
        outputList.push_back("未知源节点");
        outputList.push_back(iter->first);
        outputList.push_back(iter->second->m_strName);
        outputList.push_back(iter->second->comment);
        outputList.push_back(iter->second->classRef);
        outputList.push_back(iter->second->m_strHandlerName);
        m_vecOutputs.push_back(outputList);
    }
    return true;
}

bool ContextManager::WriteReport(std::string _file_name)
{
    OrderReport();
    std::ofstream stream(_file_name);
    csv2::Writer<csv2::delimiter<','>> writer(stream);

    writer.write_rows(m_vecOutputs);
    stream.close();

    return true;
}

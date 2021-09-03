#include "Pipeline.h"
#include "nlohmann/json.hpp"
#include "easylogging++.h"
#include "PipelineManager.h"
#include "ContextManager.h"
#include <iostream>
#include <locale>
Pipeline::Pipeline()
{
}

Pipeline::~Pipeline()
{
}

bool Pipeline::ParseFile(std::string m_strFilePath)
{
    nlohmann::json json_dto;
    std::ifstream jfile(m_strFilePath.c_str());
    if (!jfile.is_open())
    {
        LOG(ERROR) << "open json file failed:" << m_strFilePath;
        return false;
    }
    try
    {
        jfile >> json_dto;
        if (json_dto.is_discarded())
        {
            LOG(ERROR) << "parse json data failed:" << m_strFilePath;
            return false;
        }
        m_strName = json_dto["pipelineName"];


        const nlohmann::json node = json_dto["node"];
        for (auto& elem : node)
        {
            TaskNode* tnode = gPipelineInstance->CreateNode(elem.at("nodeType"));
            tnode->Init(elem);
            m_mapTaskNodes[elem.at("id")] = tnode;
          
        }

        nlohmann::json dag = json_dto["dag"];
        if (dag.size() <= 0)
        {
            LOG(ERROR) << "ParseFile::dag node is null:" << m_strFilePath;
            return false;
        }
        for (auto& elem : dag)
        {
            if (!DagConnect(elem))
            {
                return false;
            }
        }

        m_strStartNodeID = json_dto["startNodeId"];

        std::map<std::string, TaskNode*>::iterator  iter = m_mapTaskNodes.find(m_strStartNodeID);
        if (iter == m_mapTaskNodes.end())
        {
            LOG(ERROR) << "ParseFile::start node non existent:" << m_strStartNodeID;
            return false;
        }

        m_pStartNode = iter->second;
    }
    catch (std::exception& e)
    {
        LOG(ERROR) << e.what() <<" File: " << m_strFilePath;
        return false;
    }

    return true;
}


TaskNode* Pipeline::FindTaskNode(std::string& _dag_name)
{
    std::string::size_type pos;
    pos = _dag_name.find("#");
    int length = _dag_name.size();
    if (pos != std::string::npos)
    {
        std::string subProcessName = _dag_name.substr(0, pos);
        std::map<std::string, TaskNode*>::iterator  iter = m_mapTaskNodes.find(subProcessName);
        if (iter == m_mapTaskNodes.end())
        {
            LOG(ERROR) << "FindTaskNode::sub task node non existent:" << subProcessName;
            return NULL;
        }

        return iter->second;
    }
    else
    {
        std::map<std::string, TaskNode*>::iterator  iter = m_mapTaskNodes.find(_dag_name);
        if (iter == m_mapTaskNodes.end())
        {
            LOG(ERROR) << "FindTaskNode::task node non existent:" << _dag_name;
            return NULL;
        }
        return iter->second;
    }
    return NULL;
}

TaskNode* Pipeline::FindStartNode()
{
    return m_pStartNode;
}


bool Pipeline::FindNodeHandler(std::string name, std::string& _handle_name)
{
    std::map<std::string, TaskNode*>::iterator  iter = m_mapTaskNodes.find(name);
    if (iter == m_mapTaskNodes.end())
    {
        return false;
    }
    _handle_name = iter->second->GetHandler();;
    return true;
}
#include <codecvt>
bool Pipeline::WriteReport()
{
    if (!m_pStartNode)
    {
        LOG(ERROR) << "WriteReport::pipeline head node non exists:" << m_strName;
        return false;
    }
    std::string filename = m_strName + ".dot";
    std::ofstream outFile;
    outFile.open(filename.c_str(), std::ios::out);
    if (outFile.fail())
    {
        LOG(ERROR) << "WriteReport::out dot file fail:" << m_strName;
        return false;
    }
    outFile << "strict digraph G {\n";
    outFile << "edge [fontname=\"FangSong\"];\n"; 
    outFile << "node [fontname=\"FangSong\"];\n";
    std::map<std::string, TaskNode*>::iterator iter = m_mapGraphNodes.begin();
    for (; iter != m_mapGraphNodes.end(); ++iter)
    {
        iter->second->WriterReport(outFile);
    }
    outFile << "}\n";
    outFile.close();

    std::string pngName = m_strName + ".png";
    std::string dotCmd = "dot -Tpng "+ filename +" > "+ pngName;
    system(dotCmd.c_str());
    return true;
}


std::map<std::string, TaskNode*> Pipeline::GetGraph()
{
    return m_mapGraphNodes;
}


bool Pipeline::BindNodeFile()
{
    std::map<std::string, TaskNode*>::iterator iter = m_mapGraphNodes.begin();
    for (; iter != m_mapGraphNodes.end();++iter) {
        iter->second->BindNodeFile();
    }
    return true;
}

bool Pipeline::TraverNodeFile()
{
    std::map<std::string, TaskNode*>::iterator iter = m_mapGraphNodes.begin();
    for (; iter != m_mapGraphNodes.end(); ++iter) {
        if (iter->second->m_nType != TASK_SUB_PROCESS && iter->second->m_nType != TASK_ANY && iter->second->m_nType != TASK_CONDITION && iter->second->m_pFileNode == NULL)
        {
            std::string name = iter->second->id;
            if (iter->second->classRef != "")
            {
                gContextInstance->AddUnknowClassTaskNode(iter->second->classRef, iter->second);                        
            }
            else if (iter->second->m_strHandlerName != "")
            {
                gContextInstance->AddUnknowHandlerTaskNode(iter->second->m_strHandlerName, iter->second);
            }
            else
            {
                gContextInstance->AddUnknowTaskNode(iter->second->id, iter->second);
            }

            LOG(ERROR) << "TraverNodeFile nodeType:" << iter->second->nodeType << " taskType:" << iter->second->taskType << "classRef:" << iter->second->classRef << "comment" << iter->second->comment;
        }
        else if(iter->second->m_nType != TASK_SUB_PROCESS && iter->second->m_nType != TASK_ANY && iter->second->m_nType != TASK_CONDITION)
        {
            gContextInstance->AddKnowTaskNode(iter->second->m_pFileNode->filePath, iter->second);
            if (iter->second->m_pFileNode->execPos.size() >0 )
            {
                gContextInstance->AddExeTaskNode(iter->second->m_pFileNode->filePath, iter->second);
            }
        }
        else 
        {
            LOG(ERROR) << "TraverNodeFile SubProcess:" << iter->second->nodeType << " taskType:" << iter->second->taskType << "classRef:" << iter->second->classRef << "comment" << iter->second->comment;
        }
    }
    return true;
}

bool Pipeline::DagConnect(const nlohmann::json _json)
{
    std::string sourceNodeId = _json.at("sourceNodeId");

    TaskNode* sourceNode = FindTaskNode(sourceNodeId);
    if (sourceNode == NULL)
    {
        LOG(ERROR) << "DagConnect::source node is null:" << sourceNodeId;
        return false;
    }
    sourceNode->SetSourceName(sourceNodeId);
    std::map<std::string, TaskNode*>::iterator iter = m_mapGraphNodes.find(sourceNode->GetName());
    if (iter == m_mapGraphNodes.end())
    {
        m_mapGraphNodes[sourceNode->GetName()] = sourceNode;
    }

    nlohmann::json  targetNodeIds = _json.at("targetNodeIds");
    if (targetNodeIds.size() <= 0)
    {
        LOG(ERROR) << "DagConnect::dest node list empty:" << sourceNodeId;
        return false;
    }
    for (auto it = targetNodeIds.begin(); it != targetNodeIds.end(); it++) {

        std::string destName = *it;
        TaskNode* destNode = FindTaskNode(destName);
        if (destNode == NULL)
        {
            LOG(ERROR) << "DagConnect::dest node is null:" << sourceNodeId <<" destName: "<< destName;
            return false;
        }
        destNode->SetDestName(destName);
        std::map<std::string, TaskNode*>::iterator iter = m_mapGraphNodes.find(destNode->GetName());
        if (iter == m_mapGraphNodes.end())
        {
    
            m_mapGraphNodes[destNode->GetName()] = destNode;
        }
        sourceNode->AddChild(destNode);
    }
    return true;
}


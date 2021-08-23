#include "Pipeline.h"
#include "nlohmann/json.hpp"
#include "easylogging++.h"
#include "PipelineManager.h"

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
            TaskNode *node = gPipelineInstance->CreateNode(elem.at("taskType"));
            node->Init(elem);
            m_mapTasks[elem.at("id")] = node;
        }

        nlohmann::json dag = json_dto["dag"];
        for (auto& elem : dag)
        {
            if (!DagConnect(elem))
            {
                return false;
            }
        }

        m_strStartNodeID = json_dto["startNodeId"];

        std::map<std::string, TaskNode*>::iterator  iter = m_mapTasks.find(m_strStartNodeID);
        if (iter == m_mapTasks.end())
        {
            LOG(ERROR) << "ParseFile::start node non existent:" << m_strStartNodeID;
            return false;
        }

        m_pStartNode = iter->second;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return false;
    }

    return true;
}


bool Pipeline::DagConnect(const nlohmann::json _json)
{
    std::string sourceNodeId = _json.at("sourceNodeId");
    std::map<std::string, TaskNode*>::iterator  iter = m_mapTasks.find(sourceNodeId);
    if (iter == m_mapTasks.end())
    {
        LOG(ERROR) << "DagConnect::source node non existent:" << sourceNodeId;
        return false;
    }
    TaskNode* sourceNode =  iter->second;
    if (sourceNode == NULL)
    {
        LOG(ERROR) << "DagConnect::source node is null:" << sourceNodeId;
        return false;
    }
    nlohmann::json  targetNodeIds = _json.at("targetNodeIds");
    if (targetNodeIds.size() <= 0)
    {
        LOG(ERROR) << "DagConnect::dest node list empty:" << sourceNodeId;
        return false;
    }
    for (auto it = targetNodeIds.begin(); it != targetNodeIds.end(); it++) {

        iter = m_mapTasks.find(it.key());
        if (iter == m_mapTasks.end())
        {
            LOG(ERROR) << "DagConnect::dest node non existent:" << it.key();
            return false;
        }
        TaskNode* destNode = iter->second;
        if (sourceNode == NULL)
        {
            LOG(ERROR) << "DagConnect::dest node is null:" << sourceNodeId;
            return false;
        }
        iter->second->AddChild(destNode);
    }
    return true;
}

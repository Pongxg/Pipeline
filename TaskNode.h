#pragma once
#include "nlohmann/json.hpp"
class TaskNode
{
public:
	TaskNode();
	virtual ~TaskNode();
	virtual bool Init(const nlohmann::json &json);
	virtual bool Execute() = 0;
    virtual bool WriterReport() = 0;
    bool AddChild(TaskNode* _node);
    void SetName(std::string _node_name);

public:
    std::string     id = "";
    std::string     nodeType = "";
    std::string     taskType = "";
    std::string     classRef = "";
    bool            sync = false;
    bool            alarm = false;
    int             concurrencyThreshold = 3600;
    int             timeout = 4;
    int             retryTimes = 0;
    std::string     comment;
    nlohmann::json  properties;
    nlohmann::json  propertiesMapping;
    std::string     subPipeline = "";
    nlohmann::json  dag;

    std::vector<TaskNode*>m_vecChildList;

    std::string   m_strNodeName = "";
};

typedef TaskNode* (*NodeFunction)(void);

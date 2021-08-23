#pragma once
#include "nlohmann/json.hpp"
class TaskNode
{
public:
	TaskNode();
	virtual ~TaskNode();
	virtual bool Init(const nlohmann::json &json);
	virtual bool Execute() = 0;

    bool AddChild(TaskNode* _node);
private:
    std::string     id;
    std::string     nodeType;
    std::string     taskType;
    std::string     classRef;
    bool            sync;
    bool            alarm;
    int             concurrencyThreshold;
    int             timeout;
    int             retryTimes;
    std::string     comment;
    nlohmann::json  properties;
    nlohmann::json  propertiesMapping;


    std::vector<TaskNode*>m_vecChildList;
};

typedef TaskNode* (*NodeFunction)(void);

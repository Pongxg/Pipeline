#pragma once
#include "nlohmann/json.hpp"
#include "Util.h"
class TaskNode
{
public:
	TaskNode();
	virtual ~TaskNode();
	virtual bool Init(const nlohmann::json &_json);
	virtual bool Execute() = 0;
    virtual bool BindNodeFile();
    virtual bool WriterReport(std::ostream& _out, std::string _node_prefix = "", std::string _label_prefix = "", int depth = 0);
    virtual std::string GetNodeName() = 0;

    bool AddChild(TaskNode* _node);
    virtual void SetSourceName(std::string _node_name);
    virtual void SetDestName(std::string _node_name);
    std::string GetName() { return m_strName; }
    
    std::string GetHandler();

    int GetType() { return m_nType; }

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
    std::string     comment = "";
    std::string     subPipeline = "";

    std::vector<TaskNode*>m_vecChildList;

    std::string  m_strName = "";
    std::string  m_strHandlerName = "";

    std::string  m_strSrcName = "";
    std::string  m_strDestName = "";

    int m_nType = TASK_SIMPLE;

    //graphviz attribute
    std::string  m_strNodeName = "";
    std::string  m_strLabelName = "";
    std::string  m_strFillcolor = "";
    std::string  m_strShape = "";
    std::string  m_strStyle = "";

    FileNode*   m_pFileNode = NULL;
};

typedef TaskNode* (*NodeFunction)(void);

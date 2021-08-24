#include "TaskNode.h"

TaskNode::TaskNode()
{
}

TaskNode::~TaskNode()
{

}

bool TaskNode::Init(const nlohmann::json& _json)
{
    for (auto it = _json.begin(); it != _json.end(); it++) {
        if (it.key() == "id")
            id = it.value();
        if (it.key() == "nodeType")
            nodeType = it.value();
        if (it.key() == "taskType")
            taskType = it.value();
        if (it.key() == "classRef")
            classRef = it.value();
        if (it.key() == "sync")
            sync = it.value();
        if (it.key() == "alarm")
            alarm = it.value();
        if (it.key() == "concurrencyThreshold")
            concurrencyThreshold = it.value();
        if (it.key() == "timeout")
            timeout = it.value();
        if (it.key() == "retryTimes")
            retryTimes = it.value();
        if (it.key() == "comment")
            comment = it.value();
        if (it.key() == "properties")
            properties = it.value();
        if (it.key() == "propertiesMapping")
            propertiesMapping = it.value();
        if (it.key() == "subPipeline")
            subPipeline = it.value();
        if (it.key() == "dag")
            dag = it.value();
    }

	return true;
}

bool TaskNode::AddChild(TaskNode* _node)
{
    m_vecChildList.push_back(_node);
    return true;
}
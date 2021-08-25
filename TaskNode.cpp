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

void TaskNode::SetName(std::string _node_name)
{
    m_strNodeName = _node_name;
    m_strLabelName = _node_name;
}

std::string TaskNode::GetHandler()
{
    return m_strHandlerName;
}


bool TaskNode::WriterReport(std::ostream& _out)
{
    _out << m_strNodeName;
    _out << " [";
    if (m_strLabelName != "") {
        _out << " label=\"" << m_strLabelName <<"\"";
    }
    if (m_strFillcolor != "") {
        _out << " fillcolor=\"" << m_strFillcolor << "\"";
    }
    if (m_strShape != "") {
        _out << " shape=\"" << m_strShape << "\"";
    }
    if (m_strStyle != "") {
        _out << " style=\"" << m_strStyle << "\"";
    }
    _out << "]";
    _out << ";\n";


    for (int i = 0; i < m_vecChildList.size(); ++i)
    {
        _out << m_strNodeName << "->"<< m_vecChildList[i]->GetName();
        _out << ";\n";

        m_vecChildList[i]->WriterReport(_out);
    }

    return true;
}

#include "TaskNode.h"
#include "Util.h"

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
        //if (it.key() == "properties")
        //    properties = it.value();
        //if (it.key() == "propertiesMapping")
        //    propertiesMapping = it.value();
        if (it.key() == "subPipeline")
            subPipeline = it.value();
        //if (it.key() == "dag")
        //    dag = it.value();
    }

	return true;
}

bool TaskNode::AddChild(TaskNode* _node)
{
    m_vecChildList.push_back(_node);
    return true;
}

void TaskNode::SetSourceName(std::string _node_name)
{
    if (m_strName != "") return;
    m_strName = _node_name;

    std::vector<char>  vecBuff;
    vecBuff.resize(_node_name.size());
    vecBuff.assign(_node_name.begin(), _node_name.end()); 
    ReplaceChar(vecBuff,'-','_');
    m_strNodeName.resize(vecBuff.size());
    m_strNodeName.assign(vecBuff.begin(), vecBuff.end());
    vecBuff.clear();
    m_strLabelName = _node_name;
}

void TaskNode::SetDestName(std::string _node_name)
{
    if (m_strName != "") return;
    m_strName = _node_name;

    std::vector<char>  vecBuff;
    vecBuff.resize(_node_name.size());
    vecBuff.assign(_node_name.begin(), _node_name.end());
    ReplaceChar(vecBuff, '-', '_');
    m_strNodeName.resize(vecBuff.size());
    m_strNodeName.assign(vecBuff.begin(), vecBuff.end());
    vecBuff.clear();
    m_strLabelName = _node_name;
}


std::string TaskNode::GetHandler()
{
    return m_strHandlerName;
}


bool TaskNode::WriterReport(std::ostream& _out, std::string _node_prefix, std::string _label_prefix, int depth)
{
    std::string strNodeName = m_strNodeName;
    std::string strlabelName = m_strLabelName;

    if (depth > 0)
    {
        strNodeName = _node_prefix + "__" + m_strNodeName;
        strlabelName = _label_prefix + "#" + m_strLabelName;
    }
  

    _out << strNodeName;
    _out << " [";
    if (strlabelName != "") {
        _out << " label=\"" << strlabelName <<"\"";
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
        std::string nodeName = m_vecChildList[i]->GetNodeName();

        if (depth > 0)
        {
            nodeName = _node_prefix + "__" + m_vecChildList[i]->GetNodeName();
        }
        _out << strNodeName << "->"<< nodeName;
        _out << ";\n";
    }

    return true;
}

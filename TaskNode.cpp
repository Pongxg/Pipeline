#include "TaskNode.h"
#include "Util.h"
#include "FileManager.h"
#include "easylogging++.h"
#include "PipelineManager.h"

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
        {
            //std::string value =  it.value();
            //std::wstring result;
            //UTF8ToUnicode(value, result);
            //comment=  UnicodeToAscii(result);

            comment = it.value();
        }
        if (it.key() == "subPipeline")
        {
            subPipeline = it.value();
        }
        if (it.key() == "properties")
        {
            nlohmann::json  propertiesJson = _json.at("properties");
            for (auto iter = propertiesJson.begin(); iter != propertiesJson.end(); iter++) {
                if (iter.key() == "handler")
                {
                    m_strHandlerName = propertiesJson["handler"];
                }
                else if (iter.key() == "toolType")
                {
                    m_strHandlerName = propertiesJson["toolType"];
                }
            }
        }
            
        //if (it.key() == "propertiesMapping")
        //    propertiesMapping = it.value();
     
        
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

bool TaskNode::BindNodeFile()
{
    if (m_nType == TASK_SUB_PROCESS || m_nType == TASK_ANY || m_nType == TASK_CONDITION)
        return false;
    FileNode* node = NULL;
    if (classRef != "")
    {
        node = gFileInstance->GetBindFile(classRef);
    }
    else if(m_strHandlerName != "")
    {
        node = gFileInstance->GetBindNodeFile(m_strHandlerName,taskType);
    }

    if (node != NULL)
    {
        m_pFileNode = node;
    }
    else
    {
        LOG(ERROR) << "TaskNode::BindNodeFile nodeType:" << nodeType << " taskType:" << taskType <<"classRef:" << classRef <<"comment"<< comment;
    }
    return true;
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
    bool bFinder = false;
    std::string comment = "";
    if ((m_pFileNode && m_pFileNode->execPos.size() > 0) || (!m_pFileNode && m_nType == TASK_SIMPLE))
    {
        bFinder = true;
    }
    if (comment == "" && m_pFileNode && m_pFileNode->comment != "")
    {
        comment = m_pFileNode->comment;
    }


    std::string info = "ÖÐÎÄ";
    _out << strNodeName;
    _out << " [";

    if (strlabelName != "") {
        _out << " label=\"" << strlabelName << "\n"<< info <<"\"";
    }
    if (!bFinder)
    {
        if (m_strFillcolor != "") {
            _out << " fillcolor=\"" << m_strFillcolor << "\"";
        }
    }
    else
    {
        _out << " fillcolor = red ";
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

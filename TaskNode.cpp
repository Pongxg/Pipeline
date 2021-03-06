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
            std::string value =  it.value();
            std::wstring result;
            UTF8ToUnicode(value, result);
            comment=  UnicodeToAscii(result);

 /*           comment = it.value();*/
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

    if (m_strNodeName == "" && m_strLabelName == "")
    {
        m_strNodeName = id;
        m_strLabelName = id;
    }
    if (depth > 0)
    {
        strNodeName = _node_prefix + "__" + m_strNodeName;
        strlabelName = _label_prefix + "#" + m_strLabelName;
    }
    bool bFinder = false;

    if ((m_pFileNode && m_pFileNode->execPos.size() > 0) || (!m_pFileNode && m_nType == TASK_SIMPLE))
    {
        m_strFillcolor = "red";
    }
    std::string cmt = comment;
    if (cmt == "" && m_pFileNode && m_pFileNode->comment != "")
    {
        cmt = m_pFileNode->comment;
    }
    std::string ascString = strNodeName;
    std::string uniString = ASCII2UTF_8(ascString);
    _out << uniString;

    ascString = " [";
    uniString = ASCII2UTF_8(ascString);
    _out << uniString;


    if (strlabelName != "") {
        ascString = " label=\"" + strlabelName + "\n" + cmt + "\"";
        uniString = ASCII2UTF_8(ascString);
        _out << uniString;
    }
    if (m_strFillcolor != "") {
     
        ascString = " color=\"" + m_strFillcolor + "\"";
        uniString = ASCII2UTF_8(ascString);
        _out << uniString;
    
    }

    if (m_strShape != "") {
        ascString = " shape=\"" + m_strShape + "\"";
        uniString = ASCII2UTF_8(ascString);
        _out << uniString;
    }
    //if (m_strStyle != "") {
    //    ascString = " style=\"" + m_strStyle + "\"";
    //    uniString = ASCII2UTF_8(ascString);
    //    _out << uniString;
    //}

    ascString = "]";
    uniString = ASCII2UTF_8(ascString);
    _out << uniString;

    ascString = ";\n";
    uniString = ASCII2UTF_8(ascString);
    _out << uniString;



    for (int i = 0; i < m_vecChildList.size(); ++i)
    {
        std::string nodeName = m_vecChildList[i]->GetNodeName();

        if (depth > 0)
        {
            nodeName = _node_prefix + "__" + m_vecChildList[i]->GetNodeName();
        }

        ascString = strNodeName + "->" + nodeName;
        uniString = ASCII2UTF_8(ascString);
        _out << uniString;

        ascString = ";\n";
        uniString = ASCII2UTF_8(ascString);
        _out << uniString;
    }

    return true;
}

#include "SubProcess.h"
#include "PipelineManager.h"
#include "easylogging++.h"
#include "Util.h"
#include "Pipeline.h"
SubProcess::SubProcess()
{
	m_nType = TASK_SUB_PROCESS;
}

SubProcess::~SubProcess()
{
}

TaskNode* SubProcess::CreateNode()
{
	return new SubProcess();
}

bool SubProcess::Init(const nlohmann::json& _json)
{
	TaskNode::Init(_json);
	std::string pipelinePath;
	bool bFind = gPipelineInstance->FindPipelinePath(subPipeline, pipelinePath);
	if (!bFind)
	{
		LOG(ERROR) << "SubProcess:subPipeline not find:" << subPipeline;
		return false;
	}
	m_pPipeline = gPipelineInstance->CreatePipeline(pipelinePath);
	if (!m_pPipeline)
	{
		LOG(WARNING) << "SubProcess:create subPipeline fail:" << pipelinePath;
		return false;
	}

	return true;
}

bool SubProcess::Execute()
{
	return true;
}

Pipeline* SubProcess::GetPipline()
{
	return m_pPipeline;
}

void SubProcess::SetSourceName(std::string _node_name)
{
	m_strName = _node_name;
	std::string::size_type pos;
	pos = _node_name.find("#");
	int length = _node_name.size();
	if (pos != std::string::npos)
	{
		std::string nodeName = _node_name.substr(0, pos);
		m_strName = nodeName;

		m_strSrcName = _node_name.substr(pos+1, length);
		std::vector<char>  vecBuff;
		vecBuff.resize(m_strSrcName.size());
		vecBuff.assign(m_strSrcName.begin(), m_strSrcName.end());
		ReplaceChar(vecBuff, '-', '_');
		m_strSrcName.resize(vecBuff.size());
		m_strSrcName.assign(vecBuff.begin(), vecBuff.end());
		vecBuff.clear();

	}


	std::vector<char>  vecBuff;
	vecBuff.resize(m_strName.size());
	vecBuff.assign(m_strName.begin(), m_strName.end());
	ReplaceChar(vecBuff, '-', '_');
	m_strNodeName.resize(vecBuff.size());
	m_strNodeName.assign(vecBuff.begin(), vecBuff.end());
	vecBuff.clear();
	m_strLabelName = m_strName;
}

void SubProcess::SetDestName(std::string _node_name)
{
	m_strName = _node_name;
	std::string::size_type pos;
	pos = _node_name.find("#");
	int length = _node_name.size();
	if (pos != std::string::npos)
	{
		std::string nodeName = _node_name.substr(0, pos);
		m_strName = nodeName;
		m_strDestName = _node_name.substr(pos + 1, length);
		std::vector<char>  vecBuff;
		vecBuff.resize(m_strDestName.size());
		vecBuff.assign(m_strDestName.begin(), m_strDestName.end());
		ReplaceChar(vecBuff, '-', '_');
		m_strDestName.resize(vecBuff.size());
		m_strDestName.assign(vecBuff.begin(), vecBuff.end());
		vecBuff.clear();
	}
	std::vector<char>  vecBuff;
	vecBuff.resize(m_strName.size());
	vecBuff.assign(m_strName.begin(), m_strName.end());
	ReplaceChar(vecBuff, '-', '_');
	m_strNodeName.resize(vecBuff.size());
	m_strNodeName.assign(vecBuff.begin(), vecBuff.end());
	vecBuff.clear();
	m_strLabelName = m_strName;
}



std::string SubProcess::GetNodeName() {
	if (m_pPipeline == NULL)
	{
		LOG(ERROR) << "GetNodeName:subPipeline is NULL:" << m_strName;
		return "";
	}
	TaskNode* taskNode = m_pPipeline->FindStartNode();
	if(taskNode == NULL)
	{
		LOG(ERROR) << "GetNodeName:start Node is NULL" << m_strName;
		return "";
	}

	std::string strNodeName = m_strNodeName + "__" + taskNode->GetNodeName();

	return strNodeName;
}



bool SubProcess::WriterReport(std::ostream& _out, std::string _node_prefix, std::string _label_prefix, int depth)
{
	if (m_pPipeline == NULL)
	{
		LOG(ERROR) << "WriterReport:get subPipeline is NULL" << m_strName ;
		return false;
	}
	std::map<std::string, TaskNode*>  taskNodes = m_pPipeline->GetGraph();

	std::string strNodeName = m_strNodeName;
	std::string strlabelName = m_strLabelName;

	if (depth > 0)
	{
		strNodeName = _node_prefix + "__" + m_strNodeName;
		strlabelName = _label_prefix + "#" + m_strLabelName;
	}
	std::map<std::string, TaskNode*>::iterator iter = taskNodes.begin();
	for (; iter != taskNodes.end(); ++iter)
	{
		iter->second->WriterReport(_out, strNodeName, strlabelName, depth + 1);
	}

	for (int i = 0; i < m_vecChildList.size(); ++i)
	{
		std::string nodeName = m_vecChildList[i]->GetNodeName();
		std::string endName = m_strNodeName + "__" + m_strSrcName;
		if (depth > 0)
		{
			nodeName = _node_prefix + "__" + m_vecChildList[i]->GetNodeName();
			endName = _node_prefix + "__" + endName;
		}
		_out << endName << "->" << nodeName;
		_out << ";\n";
	}

	return true;
}
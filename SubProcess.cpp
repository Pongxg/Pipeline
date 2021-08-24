#include "SubProcess.h"
#include "PipelineManager.h"
#include "easylogging++.h"

SubProcess::SubProcess()
{
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
		LOG(ERROR) << "SubProcess:create subPipeline fail:" << pipelinePath;
		return false;
	}

	return true;
}

bool SubProcess::Execute()
{
	return true;
}
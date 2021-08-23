#include "SubProcess.h"

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
	return true;
}

bool SubProcess::Execute()
{
	return true;
}
#include "ApiNode.h"

ApiNode::ApiNode()
{
}

ApiNode::~ApiNode()
{
}

TaskNode* ApiNode::CreateNode()
{
	return new ApiNode();
}

bool ApiNode::Init(const nlohmann::json& _json)
{
	TaskNode::Init(_json);
	return true;
}

bool ApiNode::Execute()
{
	return true;
}

bool ApiNode::WriterReport()
{
	return true;
}
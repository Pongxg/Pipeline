#include "ConditionNode.h"

ConditionNode::ConditionNode()
{
}

ConditionNode::~ConditionNode()
{
}

TaskNode* ConditionNode::CreateNode()
{
	return new ConditionNode();
}

bool ConditionNode::Init(const nlohmann::json& _json)
{
	TaskNode::Init(_json);
	return true;
}

bool ConditionNode::Execute()
{
	return true;
}

bool ConditionNode::WriterReport()
{
	return true;
}
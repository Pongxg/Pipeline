#include "SimpleTaskNode.h"

SimpleTaskNode::SimpleTaskNode()
{
}

SimpleTaskNode::~SimpleTaskNode()
{
}

TaskNode* SimpleTaskNode::CreateNode()
{
	return new SimpleTaskNode();
}

bool SimpleTaskNode::Init(const nlohmann::json& _json)
{
	TaskNode::Init(_json);
	return true;
}

bool SimpleTaskNode::Execute()
{
	return true;
}
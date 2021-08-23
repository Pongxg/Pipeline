#include "AnyNode.h"

AnyNode::AnyNode()
{
}

AnyNode::~AnyNode()
{
}
TaskNode* AnyNode::CreateNode()
{
	return new AnyNode();
}

bool AnyNode::Init(const nlohmann::json& _json)
{
	TaskNode::Init(_json);
	return true;
}

bool AnyNode::Execute()
{
	return true;
}

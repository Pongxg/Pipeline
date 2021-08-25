#include "MessageNode.h"

MessageNode::MessageNode()
{
}

MessageNode::~MessageNode()
{
}

TaskNode* MessageNode::CreateNode()
{
	return new MessageNode();
}

bool MessageNode::Init(const nlohmann::json& _json)
{
	TaskNode::Init(_json);
	return true;
}

bool MessageNode::Execute()
{
	return true;
}
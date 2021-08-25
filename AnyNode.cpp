#include "AnyNode.h"

AnyNode::AnyNode()
{
	m_strFillcolor = "bisque";
	m_strShape = "parallelogram";
	m_strStyle = "filled";
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

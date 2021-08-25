#include "ConditionNode.h"

ConditionNode::ConditionNode()
{
	m_strFillcolor = "cyan";
	m_strShape = "diamond";
	m_strStyle = "filled";

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

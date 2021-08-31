#include "ConditionNode.h"
#include"Util.h"
ConditionNode::ConditionNode()
{
	m_strFillcolor = "cyan";
	m_strShape = "diamond";
	m_strStyle = "filled";
	m_nType = TASK_CONDITION;
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

bool ConditionNode::WriterReport(std::ostream& _out, std::string _node_prefix, std::string _label_prefix, int depth)
{
	return TaskNode::WriterReport(_out, _node_prefix, _label_prefix, depth);
}
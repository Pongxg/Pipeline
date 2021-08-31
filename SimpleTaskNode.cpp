#include "SimpleTaskNode.h"
#include "Util.h"
SimpleTaskNode::SimpleTaskNode()
{
	m_nType = TASK_SIMPLE;
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

bool SimpleTaskNode::WriterReport(std::ostream& _out, std::string _node_prefix, std::string _label_prefix, int depth)
{
	return TaskNode::WriterReport(_out, _node_prefix, _label_prefix, depth);
}
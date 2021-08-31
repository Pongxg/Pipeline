#include "MessageNode.h"
#include "Util.h"
MessageNode::MessageNode()
{
	m_nType = TASK_MSG;
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

bool MessageNode::WriterReport(std::ostream& _out, std::string _node_prefix, std::string _label_prefix, int depth)
{
	return TaskNode::WriterReport(_out, _node_prefix, _label_prefix, depth);
}
#include "AnyNode.h"
#include  "Util.h"
AnyNode::AnyNode()
{
	m_strFillcolor = "bisque";
	m_strShape = "parallelogram";
	m_strStyle = "filled";
	m_nType = TASK_ANY;
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

bool AnyNode::WriterReport(std::ostream& _out, std::string _node_prefix, std::string _label_prefix, int depth)
{
	return TaskNode::WriterReport(_out, _node_prefix, _label_prefix, depth);
}
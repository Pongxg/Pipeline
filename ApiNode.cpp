#include "ApiNode.h"
#include "Util.h"
ApiNode::ApiNode()
{
	m_nType = TASK_API;
}

ApiNode::~ApiNode()
{
}

TaskNode* ApiNode::CreateNode()
{
	return new ApiNode();
}

bool ApiNode::Init(const nlohmann::json& _json)
{
	TaskNode::Init(_json);
	return true;
}

bool ApiNode::Execute()
{
	return true;
}


bool ApiNode::WriterReport(std::ostream& _out, std::string _node_prefix, std::string _label_prefix, int depth)
{
	return TaskNode::WriterReport(_out, _node_prefix, _label_prefix, depth);
}
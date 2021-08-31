#pragma once
#include "TaskNode.h"

class ConditionNode :public TaskNode
{
public:
	ConditionNode();
	~ConditionNode();
	static TaskNode* CreateNode();
	virtual bool Init(const nlohmann::json& json);
	virtual bool Execute();
	bool WriterReport(std::ostream& _out, std::string _node_prefix, std::string _label_prefix, int depth);
	virtual std::string GetNodeName() { return m_strNodeName; }
private:

};


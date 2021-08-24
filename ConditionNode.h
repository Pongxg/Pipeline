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
	virtual bool WriterReport();
private:

};


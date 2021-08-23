#pragma once
#include "TaskNode.h"
class SimpleTaskNode:public TaskNode
{
public:
	SimpleTaskNode();
	~SimpleTaskNode();
	static TaskNode* CreateNode();
	virtual bool Init(const nlohmann::json& json);
	virtual bool Execute();
private:

};


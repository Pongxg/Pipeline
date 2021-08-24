#pragma once
#include "TaskNode.h"
class AnyNode :public TaskNode
{
public:
	AnyNode();
	~AnyNode();
	static TaskNode* CreateNode();
	virtual bool Init(const nlohmann::json& json);
	virtual bool Execute();
	virtual bool WriterReport();

private:

};


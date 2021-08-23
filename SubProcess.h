#pragma once
#include "TaskNode.h"
class SubProcess :public TaskNode 
{
public:
	SubProcess();
	~SubProcess();
	static TaskNode* CreateNode();
	virtual bool Init(const nlohmann::json& json);
	virtual bool Execute();
private:

};


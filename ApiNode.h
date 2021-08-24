#pragma once
#include "TaskNode.h"
class ApiNode :public TaskNode
{
public:
	ApiNode();
	~ApiNode();
	static TaskNode* CreateNode();
	virtual bool Init(const nlohmann::json& json);
	virtual bool Execute();
	virtual bool WriterReport();
private:

};


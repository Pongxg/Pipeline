#pragma once
#include "TaskNode.h"
class MessageNode :public TaskNode
{
public:
	MessageNode();
	~MessageNode();
	static TaskNode* CreateNode();
	virtual bool Init(const nlohmann::json& json);
	virtual bool Execute();
private:

};


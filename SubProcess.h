#pragma once
#include "TaskNode.h"
class Pipeline;
class SubProcess :public TaskNode 
{
public:
	SubProcess();
	~SubProcess();
	static TaskNode* CreateNode();
	virtual bool Init(const nlohmann::json& json);
	virtual bool Execute();
	virtual bool WriterReport();
private:
	Pipeline* m_pPipeline = NULL;
};


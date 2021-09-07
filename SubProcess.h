#pragma once
#include "TaskNode.h"
#include <string>
class Pipeline;
class SubProcess :public TaskNode 
{
public:
	SubProcess();
	~SubProcess();
	static TaskNode* CreateNode();
	virtual bool Init(const nlohmann::json& json);
	virtual bool Execute();
	virtual void SetSourceName(std::string _node_name);
	virtual void SetDestName(std::string _node_name);
	Pipeline* GetPipline();
	bool WriterReport(std::ostream& _out, std::string _node_prefix , std::string _label_prefix , int depth );
	virtual std::string GetNodeName();
private:
	Pipeline* m_pPipeline = NULL;
	std::string m_strSrcName;
	std::string m_strDestName;
};


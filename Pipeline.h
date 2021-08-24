#pragma once
#include "Util.h"
class TaskNode;
class Pipeline
{
public:
	Pipeline();
	~Pipeline();
	bool ParseFile(std::string m_strFilePath);
	bool WriteReport();
private:
	bool DagConnect(const nlohmann::json _json);
	
	std::string m_strName = "";
	std::string m_strStartNodeID = "";
	TaskNode* m_pStartNode = nullptr;
	std::map<std::string, TaskNode*> m_mapTasks;
};

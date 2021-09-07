#pragma once
#include "Util.h"
class TaskNode;
class Pipeline
{
public:
	Pipeline();
	~Pipeline();
	bool ParseFile(std::string m_strFilePath);
	TaskNode* FindTaskNode(std::string& _dag_name);
	TaskNode* FindStartNode();
	bool FindNodeHandler(std::string name, std::string& _handle_name);
	bool WriteReport();
	std::map<std::string, TaskNode*> GetGraph();
	std::map<std::string, TaskNode*> GetTaskNodes();
	bool BindNodeFile();

	bool TraverNodeFile();

private:
	bool DagConnect(const nlohmann::json _json);
	
	std::string m_strName = "";
	std::string m_strStartNodeID = "";
	TaskNode* m_pStartNode = nullptr;
	std::map<std::string, TaskNode*> m_mapTaskNodes;
	std::map<std::string, TaskNode*> m_mapGraphNodes;
	//std::vector<TaskNode*> m_vecDagSource;
	
};

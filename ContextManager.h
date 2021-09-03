#pragma once
#include "Singleton.h"
#include "csv2.h"
#include <vector>
#include <map>
class TaskNode;

typedef std::map<std::string, TaskNode*> TaskNodeMap;
typedef TaskNodeMap::iterator  TaskNodeIter;
typedef std::pair<TaskNodeIter, bool > TaskNodePair;


class ContextManager :public Singleton<ContextManager>
{
public:
	ContextManager();
	~ContextManager();
	bool AddKnowTaskNode(std::string name,TaskNode* node);
	bool AddUnknowClassTaskNode(std::string unname, TaskNode* node);
	bool AddUnknowHandlerTaskNode(std::string unname, TaskNode* node);
	bool AddUnknowTaskNode(std::string unname, TaskNode* node);
	bool AddExeTaskNode(std::string unname, TaskNode* node);

	bool FindTaskNode(std::string& name, TaskNode* node);

	bool OrderReport();
	bool WriteReport(std::string _file_name);
private:
	TaskNodeMap m_mapUnknowClassNode;
	TaskNodeMap m_mapUnknowHandlerNode;
	TaskNodeMap m_mapUnknowNode;
	TaskNodeMap m_mapKnowNode;
	TaskNodeMap m_mapExeNode;


	std::vector<std::vector<std::string>> m_vecOutputs;
};

#define gContextInstance ContextManager::GetInstance() 
#pragma once
#include <string>
class TaskNode;
class Node {
public:
	Node();
	virtual ~Node();
	void SetName(std::string _name);
	std::string GetName();
	void SetTaskNode(TaskNode* _node);
	TaskNode* GetTaskNode();
protected:
	std::string m_strName = "";
	TaskNode* m_pTaskNode = NULL;
};
#pragma once
#include "Node.h"

class  GraphNode;
class Edge {
public:
	Edge();
	virtual ~Edge();
	
	void SetLabel(std::string _name);
	std::string GetLabel();
	void SetSrcNode(GraphNode* _node);
	GraphNode* GetSrcNode();
	void SetDestNode(GraphNode* _node);
	GraphNode* GetSDestNode();
	bool WriterReport(std::ostream& _out, std::string _prefix, int _depth);
private:
	GraphNode* m_pSrcNode = NULL;
	GraphNode* m_pDestNode = NULL;
	std::string m_strLabelName = "";
};

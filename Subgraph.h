#pragma once
#include "Node.h"
#include <vector>
class GraphNode;
class Edge;
class Subgraph:public Node  {
public:
	Subgraph();
	virtual ~Subgraph();
	 
	void SetLabel(std::string _name);
	std::string GetLabel();
	GraphNode* AddNode(const std::string& _label, const std::string& _id);
	Edge* AddEdge(GraphNode* _src, GraphNode* _dest, const std::string& _label);
	Subgraph* AddSubgraph(const std::string& label, const std::string& _id);
	bool WriterReport(std::ostream& _out, std::string _prefix, int _depth);
private:

	std::string m_strLabel;
	std::vector<GraphNode*> m_vecNodes;
	std::vector<Edge*> m_vecEdges;
	std::vector<Subgraph*> m_vecSubgraphs;

};




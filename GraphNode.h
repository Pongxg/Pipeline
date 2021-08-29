#pragma once
#include "Node.h"
class GraphNode :public Node {
public:
	GraphNode();
	virtual ~GraphNode();
	
	void SetLabel(std::string _name);
	std::string GetLabel();
	bool WriterReport(std::ostream& _out, std::string _prefix, int _depth);
private:

	std::string  m_strLabel = "";
	std::string  m_strFillcolor = "";
	std::string  m_strShape = "";
	std::string  m_strStyle = "";

};
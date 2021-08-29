#include "Edge.h"
#include "GraphNode.h"
#include "Util.h"
Edge::Edge() {

}
Edge::~Edge() {

}

void Edge::SetLabel(std::string _name) {
	m_strLabelName = _name;
}
std::string Edge::GetLabel() {
	return m_strLabelName;
}
void Edge::SetSrcNode(GraphNode* _node) {
	m_pSrcNode = _node;
}
GraphNode* Edge::GetSrcNode() {
	return m_pSrcNode;
}
void Edge::SetDestNode(GraphNode* _node) {
	m_pDestNode = _node;
}
GraphNode* Edge::GetSDestNode() {
	return m_pDestNode;
}

bool Edge::WriterReport(std::ostream& _out, std::string _prefix, int _depth) {
	if (m_pSrcNode == NULL || m_pDestNode == NULL)
	{
		return false;
	}
	_out << m_pSrcNode->GetName() << std::string("->") << m_pDestNode->GetName();

	//if (!_attributes.Empty()) {
	//	_out << " [";
	//	_attributes.Print(out);
	//	_out << "]";
	//}

	_out << ";\n";

	return true;
}
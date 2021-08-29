#include "GraphNode.h"
#include "Util.h"
GraphNode::GraphNode() {

}
GraphNode::~GraphNode() {

}

void GraphNode::SetLabel(std::string _name) {
	m_strLabel = _name;
}
std::string GraphNode::GetLabel() {
	return m_strLabel;
}
bool GraphNode::WriterReport(std::ostream& _out, std::string _prefix, int _depth)
{
    _out << m_strName;
    _out << " [";
    if (m_strLabel != "") {
        _out << " label=\"" << m_strLabel << "\"";
    }
    if (m_strFillcolor != "") {
        _out << " fillcolor=\"" << m_strFillcolor << "\"";
    }
    if (m_strShape != "") {
        _out << " shape=\"" << m_strShape << "\"";
    }
    if (m_strStyle != "") {
        _out << " style=\"" << m_strStyle << "\"";
    }
    _out << "]";
    _out << ";\n";
    return true;
}
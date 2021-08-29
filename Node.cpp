#include "Node.h"
#include "TaskNode.h"

Node::Node() {

}
Node::~Node() {

}
void Node::SetName(std::string _name) {
	m_strName = _name;
}
std::string Node::GetName()
{
	return m_strName;
}
void Node::SetTaskNode(TaskNode* _node) {
	m_pTaskNode = _node;
}
TaskNode* Node::GetTaskNode() {
	return m_pTaskNode;
}
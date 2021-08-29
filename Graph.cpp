#include "Graph.h"
#include "Subgraph.h"
#include "GraphNode.h"
#include "Edge.h"
Graph::Graph()
{

}
Graph::~Graph()
{

}

GraphNode* Graph::AddNode(const std::string& _label, const std::string& _id)
{
    GraphNode* node = new GraphNode();
    node->SetLabel(_label);
    node->SetName(_id);
    m_vecNodes.push_back(node);
    return node;
}
Edge* Graph::AddEdge(GraphNode* _src, GraphNode* _dest, const std::string& _label)
{
    Edge* edge = new Edge();
    edge->SetLabel(_label);
    edge->SetSrcNode(_src);
    edge->SetDestNode(_dest);
    m_vecEdges.push_back(edge);
    return edge;
}
Subgraph* Graph::AddSubgraph(const std::string& _label, const std::string& _id)
{
    Subgraph* sg = new Subgraph();
    sg->SetName(_id);
    sg->SetLabel(_label);
    m_vecSubgraphs.push_back(sg);
    return sg;
}

bool Graph::WriterReport(std::ostream& _out, std::string _prefix, int _depth)
{

    //// Default styles.
    //if (!_defaultNodeAttributes.Empty()) {
    //    out << linePrefix;
    //    out << "node [";
    //    _defaultNodeAttributes.Print(out);
    //    out << "];\n";
    //}

    //if (!_defaultEdgeAttributes.Empty()) {
    //    out << linePrefix;
    //    out << "edge [";
    //    _defaultEdgeAttributes.Print(out);
    //    out << "];\n";
    //}


    std::vector<GraphNode*>::iterator nodeIt;
    for (nodeIt = m_vecNodes.begin(); nodeIt != m_vecNodes.end(); nodeIt++) {
        GraphNode* node = *nodeIt;
        node->WriterReport(_out, _prefix, _depth);
    }

    std::vector<Subgraph*>::iterator sgIt;
    for (sgIt = m_vecSubgraphs.begin(); sgIt != m_vecSubgraphs.end(); sgIt++) {
        Subgraph* sg = *sgIt;
        sg->WriterReport(_out, _prefix, _depth);
    }


    std::vector<Edge*>::iterator edgeIt;
    for (edgeIt = m_vecEdges.begin(); edgeIt != m_vecEdges.end(); edgeIt++) {
        Edge* edge = *edgeIt;
        edge->WriterReport(_out, _prefix, _depth);
    }
    return true;
}
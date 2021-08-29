#pragma once

#include "AttributeSet.h"
#include "Graph.h"


class RootGraph : public Graph {
private:
  GraphAttributeSet _attributes;

public:
  RootGraph(bool isDigraph = false) : Graph( isDigraph),
    _attributes(GraphAttributeSet()) {};
  RootGraph(bool isDigraph, const std::string& label) :
    Graph( isDigraph, label), _attributes(GraphAttributeSet())
  {};
  RootGraph(bool isDigraph, const std::string& label, std::string id) :
    Graph( isDigraph, label, id), _attributes(GraphAttributeSet())
  {};

  virtual ~RootGraph() {
  }

  GraphAttributeSet& GetAttributes() {
    return _attributes;
  }

  /**
   * Writes the graph to the specified filename in the DOT format.
   *
   * Returns true if successful, false otherwise.
   */
  bool WriteToFile(const std::string& filename);

  virtual void Print(std::ostream& out, unsigned tabDepth = 1);
};


#pragma once

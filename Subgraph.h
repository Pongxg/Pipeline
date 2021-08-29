#pragma once

#include "AttributeSet.h"
#include "Graph.h"


class Subgraph : public Graph {
private:
  SubgraphAttributeSet _attributes;

public:
  Subgraph(const std::string& id,  bool isDigraph = false,
    std::string label = "") : Graph( isDigraph, label, id),
    _attributes(SubgraphAttributeSet()) {
  }

  virtual ~Subgraph() {};

  SubgraphAttributeSet& GetAttributes() {
    return _attributes;
  }

  virtual void Print(std::ostream& out, unsigned tabDepth);
};


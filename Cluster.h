#pragma once
#include "AttributeSet.h"
#include "Graph.h"


class Cluster : public Graph {
private:
  ClusterAttributeSet _attributes;

public:
  Cluster(const std::string& id, bool isDigraph = false,
    std::string label = "") : Graph(isDigraph, label, id),
    _attributes(ClusterAttributeSet()) {
  }

  virtual ~Cluster() {};

  /** Getters and setters **/
  ClusterAttributeSet& GetAttributes() {
    return _attributes;
  }

  virtual void Print(std::ostream& out, unsigned tabDepth);
};


#include "graph.hpp"
#include <iostream>
namespace itis {

  Graph::Graph() = default;

  void Graph::AddEdge(int first_, int second_, int weight_)
  {
    Edge edge = Edge(first_, second_, weight_);
    graph.push_back(edge);
    edge_amount ++;
  }

  void Graph::Clear() {
    graph.clear();
    edge_amount = 0;
  }
}
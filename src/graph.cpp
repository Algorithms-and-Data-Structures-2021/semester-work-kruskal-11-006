#include "graph.hpp"
namespace itis {

  Graph::Graph() = default;

  void Graph::AddEdge(int first_, int second_, int weight_)
  {

    // создаем ребро, добавляем его в вектор, увеличичваем количество ребер
    Edge edge = Edge(first_, second_, weight_);
    graph.push_back(edge);
    edge_amount ++;
  }

  void Graph::Clear() {

    // очищаем вектор с ребрами, обнуляем их количество
    graph.clear();
    edge_amount = 0;
  }

  Graph::~Graph(){
    Clear();
  }
}
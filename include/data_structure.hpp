#pragma once
#include "vector"
#include "private/edge.hpp" // ребро графа

namespace itis {


  struct Graph{
   public:

    std::vector<Edge> graph;

    void AddEdge(int f, int s, int w)
    {
      Edge edge(f, s, w);
      graph.push_back(edge);
    }


  };

}
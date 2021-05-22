#pragma once
#include "vector"
#include "edge.hpp"  // ребро графа

using namespace std;


namespace itis {


  struct Graph {
   public:

   vector<Edge> graph;

   int edge_amount = 0;

   explicit Graph();

   void AddEdge(int first_, int second_, int weight_);

   void Clear();
  };
}
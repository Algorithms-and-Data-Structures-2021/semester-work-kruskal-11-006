#include "graph.hpp"

#pragma once

namespace itis{


  class Kruskal {

   public:
    int totalVertices = 0;//total vertices

    vector<pair<int,int>> subsets;
    // subsets will hold list of [parent - rank] pairs
    // which we will use in Union Find
    // by path compression algorithm

    vector<Edge> mst;//declare a container to store edges of MST

    //constructor
    explicit Kruskal();

    void Clear();

    void Kruskal_update(int totalVertices);

    virtual ~Kruskal();

    static bool comparator( Edge &a , Edge& b);

    void createMST( Graph& graph);

    int _find(  int i);

    void makeUnion( int x, int y);

    void displayMST(  const vector<Edge>&  edges);
  };
}

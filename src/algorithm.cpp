#include "algorithm.h"
#include<iostream>
#include<algorithm>

namespace itis {

  Kruskal::Kruskal()= default;

  void Kruskal::Kruskal_update(int Vertices){
    totalVertices = Vertices;
    subsets.resize(Vertices);
      //resize subsets equal to total vertices

      for( int i= 0; i<totalVertices; ++i)
      {
        subsets[i].first =i; //set parent value equal to respective index
        subsets[i].second = 0; //set rank value equal to zero
      }
    }

  void Kruskal::Clear() {
    subsets.clear();
    mst.clear();
    totalVertices = 0;
  }

  bool Kruskal::comparator( Edge &a , Edge& b)
  {
    return a.weight < b.weight;
  }

  void Kruskal::createMST( Graph& graph)
  {
    //sort the edges of graph in increasing order of their weights
    sort( graph.graph.begin(), graph.graph.end(), comparator );

    int i=0, e=0;
    // i =  variable to keep track of total vertices
    // e = variable to keep track of total edges in MST formed so far
    // total edges in MST  == (total vertices - 1)

    //iterate through list of edges in a graph
    while( e < (totalVertices-1) && i < graph.graph.size() )
    {
      //store current edge
      Edge currEdge = graph.graph[i++];

      //find absolute parent
      //to detect if current edge form a cycle with MST formed so far
      int x = _find( currEdge.first);//pass current source vertex
      int y = _find( currEdge.second);//pass current destination vertex

      if( x != y)//is they don't form a cycle
      {
        //push current edge to MST
        mst.push_back( currEdge );
        //then make that two vertex Union
        // in other words to create edge between two vertices
        makeUnion( x, y);
      }
    }

    //finally display the MST created by the above function
    displayMST( mst );

  }

  int Kruskal::_find(  int i){
    if( subsets[i].first!=i)//if index is not equal to parent value
    {
      //recursively call _find()
      // and pass current parent value
      subsets[i].first = _find( subsets[i].first );

    }

    return subsets[i].first;
  }

  void Kruskal::makeUnion( int x, int y)
  {
    int xroot = _find( x);
    int yroot = _find(y);

    // if-else for rank comparison & update parent-rank values
    if( subsets[xroot].second < subsets[yroot].second)
    {
      subsets[xroot].first= yroot;
    }
    else if( subsets[xroot].second > subsets[yroot].second)
    {
      subsets[yroot].first=xroot;
    }
    else{
      subsets[xroot].first=yroot;
      subsets[yroot].second++;
    }
  }

  void Kruskal::displayMST(  const vector<Edge>&  edges)
  {
    int totalMinimumCost=0;
    cout<<"All MST edges [source - destination = weight]\n";

    for( auto edge : edges)
    {
//      cout<<edge.first<<" - "<<edge.second<<" = "<<edge.weight<<'\n';
      totalMinimumCost+=edge.weight;
    }
    cout<<"total minimum cost = "<<totalMinimumCost<<endl;
  }

  Kruskal::~Kruskal() {
    Clear();
  }

}
#include "algorithm.h"
#include<iostream>
#include<algorithm>

namespace itis {

  Kruskal::Kruskal()= default;

  void Kruskal::Kruskal_update(int Vertices){
    totalVertices = Vertices;
    subsets.resize(Vertices); //изменение размера подмножеств, равных общему количеству вершин

      for( int i= 0; i<totalVertices; ++i)
      {
        subsets[i].first =i; //установить значение родителя, равное соответствующему индексу
        subsets[i].second = 0; //установить значение ранга равным нулю
      }
    }

  void Kruskal::Clear() {

    // очищаем подмножества и остовное дерево, обнуляем количество граней
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
    sort( graph.graph.begin(), graph.graph.end(), comparator ); // сортировка ребер графа в порядке возрастания их весов

    int i=0, e=0;
    // i = переменная для отслеживания общего количества вершин
    // e = переменная для отслеживания общего количества созданных ребер в остове

    while( e < (totalVertices-1) && i < graph.graph.size() ) // проходим по списку ребер в графе
    {
      Edge currEdge = graph.graph[i++]; // хранит текущее ребро

      //определяем, образует ли текущее ребро цикл в остове, сформированным до сих пор
      int x = _find( currEdge.first);
      int y = _find( currEdge.second);

      if( x != y) // если они не образуют цикл
      {
        mst.push_back( currEdge ); // добавляем текущее ребро в остов
        makeUnion( x, y); // объединяем две вершини, дргуими словами, создаем ребро между этими вершинами
      }
    }

    displayMST( mst ); // отображаем остов, созданный вышеуказанной функцией

  }

  int Kruskal::_find(  int i){
    if( subsets[i].first!=i)
    {
      subsets[i].first = _find( subsets[i].first ); // рекурсивно проходим по всем подмножествам
    }

    return subsets[i].first;
  }

  void Kruskal::makeUnion( int x, int y)
  {
    int xroot = _find( x);
    int yroot = _find(y);

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
      cout<<edge.first<<" - "<<edge.second<<" = "<<edge.weight<<'\n';
      totalMinimumCost+=edge.weight;
    }
    cout<<"total minimum cost = "<<totalMinimumCost<<endl;
  }

  Kruskal::~Kruskal() {
    Clear();
  }
}
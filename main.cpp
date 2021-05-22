#include "algorithm.h"
#include <iostream>
#include <iterator>
#include <sstream>
using namespace itis;
using namespace std;

int main() {

    Graph g;
    //add edeges to graph
    g.AddEdge(0, 1, 50);
    g.AddEdge(0, 2, 100);
    g.AddEdge(0, 3, 50);
    g.AddEdge(1, 4, 30);
    g.AddEdge(3, 4, 100);
    g.AddEdge(2, 4, 100);
    g.AddEdge(2, 5, 100);

    //create and object of kruskal class
    Kruskal graph(g.edge_amount);

    //call kruskal class's member function to find MST
    graph.createMST(g);

    g.Clear();

  g.AddEdge(7, 9, 11);
  g.AddEdge(8, 10, 2);
  g.AddEdge(3, 10, 3);
  g.AddEdge(6, 8, 3);
  g.AddEdge(9, 10, 19);
  g.AddEdge(9, 10, 20);
  g.AddEdge(4, 6, 5);
  g.AddEdge(7, 9, 3);
  g.AddEdge(7, 9, 1);
  g.AddEdge(6, 8, 14);
  g.AddEdge(7, 4, 100);
  g.AddEdge(10, 11, 5);

            Kruskal graph1(g.edge_amount);

    //call kruskal class's member function to find MST
    graph1.createMST(g);

    return 0;
}


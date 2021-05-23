#include "algorithm.h"

using namespace itis;
using namespace std;

int main() {

  Graph g; // создаем граф

  // добавляем ребра в граф
  g.AddEdge(0, 1, 50);
  g.AddEdge(0, 2, 100);
  g.AddEdge(0, 3, 50);
  g.AddEdge(1, 4, 30);
  g.AddEdge(3, 4, 100);
  g.AddEdge(2, 4, 100);
  g.AddEdge(2, 5, 100);

  // создаем алгоритм и обновляем его по текущему количеству ребер в графе
  Kruskal graph;
  graph.Kruskal_update(g.edge_amount);

  // передаем текущий граф в функцию и создаем минимальное остовное дерево
  graph.createMST(g);

  // очищаем граф и алгоритм, чтобы работать со следующим графом
  g.Clear();
  graph.Clear();

  // добавляем ребра в граф
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

  // обновляем алгоритм по текущему количеству ребер
  graph.Kruskal_update(g.edge_amount);

  // передаем текущий граф в функцию и создаем минимальное остовное дерево
  graph.createMST(g);

  // очищаем граф и алгоритм, чтобы работать со следующим графом
  g.Clear();
  graph.Clear();

  // добавляем ребра в граф
  g.AddEdge(0, 1, 10);
  g.AddEdge(0, 2, 10);
  g.AddEdge(1, 2, 5);

  // обновляем алгоритм по текущему количеству ребер
  graph.Kruskal_update(g.edge_amount);

  // передаем текущий граф в функцию и создаем минимальное остовное дерево
  graph.createMST(g);

  return 0;
}


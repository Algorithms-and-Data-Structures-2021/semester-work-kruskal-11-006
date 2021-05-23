#include "graph.hpp"

#pragma once

namespace itis{


  class Kruskal {

   public:
    int totalVertices = 0; // количество вершин
    vector<pair<int,int>> subsets; // подмножества будут содержать список пар [родитель - ранг]
    vector<Edge> mst;// вектор, который содержит минимальное остовное дерево

    explicit Kruskal(); // конструктор

    void Clear(); // очистка данных в алгоритме

    void Kruskal_update(int totalVertices); // обновление данных о графе в алгоритме

    static bool comparator( Edge &a , Edge& b); // сравнивает вес ребер, используется в сортировке ребер по величине

    void createMST( Graph& graph); // создает минимальное остовное дерево

    int _find(  int i); // поиск повторяющихся вершин в подмножестве, нужен для построения остовного дерева

    void makeUnion( int x, int y); // вспомогательная функция, нужна для построения остовного дерева

    void displayMST(  const vector<Edge>&  edges); // выводит минимальное остовное дерево

    virtual ~Kruskal(); // деструктор, то же самое, что и Clear()
  };
}

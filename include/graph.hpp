#pragma once
#include "vector"
#include "edge.hpp"  // ребро графа

using namespace std;


namespace itis {


  struct Graph {
   public:
   vector<Edge> graph; // вектор, который будет содержать в себе все ребра графа
   int edge_amount = 0; // общее количество ребер

   explicit Graph(); // конструктор

   void AddEdge(int first_, int second_, int weight_); // добавить ребро в граф

   void Clear(); // очистить граф

    virtual ~Graph(); // деструктор, то же самое, что Clear()
  };
}
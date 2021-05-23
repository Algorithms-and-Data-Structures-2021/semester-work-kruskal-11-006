#pragma once


namespace itis {

  struct Edge {
   public:
    int first; // первая вершина
    int second; // вторая вершина
    int weight; // вес ребра между этими вершинами

    explicit Edge( int first_, int second_, int weight_); // конструктор
  };
}
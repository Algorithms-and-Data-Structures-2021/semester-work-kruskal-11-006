#pragma once


namespace itis {

  struct Edge {
   public:
    int first;
    int second;
    int weight;

    explicit Edge( int first_, int second_, int weight_);
  };
}
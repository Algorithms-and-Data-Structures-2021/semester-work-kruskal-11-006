#ifndef SEMESTER_WORK_TEMPLATE_EDGE_HPP
#define SEMESTER_WORK_TEMPLATE_EDGE_HPP

#endif  //SEMESTER_WORK_TEMPLATE_EDGE_HPP
#pragma once


namespace itis {

  struct Edge {
   public:
    int first;
    int second;
    int weight;

    Edge( int first, int second, int weight)
    {
      this->first = first;
      this->second = second;
      this->weight = weight;
    }


  };

}
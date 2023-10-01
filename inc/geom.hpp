#ifndef GEOM_H
#define GEOM_H
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include<vector>
#define NUM_POINTS 10 

template  <typename T> 
class Point { 
  public:
  T m_x;
  T m_y;
  T distance(Point &p) const;
  Point(T x, T y):m_x(x), m_y(y){};
  void sort_points(std::vector<Point<T>> &p);
  static bool compare (const Point<T> &p1, const Point<T> &p2);
 };

template <class T>
void print (std::vector<Point<T>> &p,bool graphic=true);


#endif
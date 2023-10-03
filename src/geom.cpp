#include "geom.hpp"

// mvik: 
/* - notice how the syntax for template is
-notice return type followed by namespace followed by function name*/
template <class T> 
T Point<T>::distance(Point<T> &p) const {
    return ( pow((p.m_x-this->m_x),2) + pow((p.m_y - this->m_y),2) ) ;
}

template <class T> 
bool Point<T>::compare (const Point<T> &p1, const Point<T> &p2) {
    if (p1.m_y < p2.m_y) {
      return true; 
    } else if (p1.m_y == p2.m_y) {
      return (p1.m_x < p2.m_x);
    } else {
      return false;
    }
}

template <typename T>
void Point<T>::sort_points(std::vector<Point<T>> &p) {
  std::sort(p.begin(), p.end(),Point<T>::compare);
}

 
template <class T>
void print (std::vector<Point<T>> &p, bool graphic) {
  for (auto &iter:p) {    
    std::cout << iter.m_x << " " << iter.m_y << std::endl;
  }
}

template class Point<int>;
template void print<int>(std::vector<Point<int>>&, bool);
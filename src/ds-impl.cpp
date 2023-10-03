
// Alternate way of initializing a template if dont have access to template implementation cpp files
// not so great an idea after all since including a cpp file inside another file will result in double compilation
#ifndef DSIMPL_CPP
#define DSIMPL_CPP

#include "ds.cpp"
#include "geom.cpp"

template class List<int>;
template class Point<int>;
template class Graph<int>;
template void print<int>(std::vector<Point<int>>&, bool);
#endif 
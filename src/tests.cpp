#include "tests.hpp"

void linked_list_test() {
  List<int> ll(10);
  ll.insertNode(); 
  ll.printList();
  ll.reverseList();
  ll.printList();

// mvik : the x coordinate actually represents the column value in 2-D Matrix
static void display_points_on_terminal(std::vector<Point<int>> &p, int range) {
  const int xgrid = range;
  const int ygrid = range;
  char grid[range][range];
  for (auto row=0; row < ygrid ; row++) {
    for (auto col=0; col < xgrid; col++) {
      grid[row][col] = ' ';
    }
  }

  int count = 65;
  for ( auto &iter: p ) {  
    grid[iter.m_y][iter.m_x] = static_cast<char>(count);
    count++;
  }
  std::cout<< "---------------------\n" ;
  for (auto row=0; row < ygrid ; row++) {
    for (auto col=0; col < xgrid; col++) {
      std::cout<< grid[col][row] << '\t' ;
    }
    std::cout << std::endl;
  }
  std::cout<< "---------------------\n" ;
}

void geom_test() {
  std::vector<Point<int>> p;
  
  const int range=10;
  for (int i=0; i < 5; i++) {
    p.push_back(Point<int>(rand()%range, rand()%range));
  }
 
  print<int>(p);
  display_points_on_terminal(p, range);
  p[0].sort_points(p);
  
  display_points_on_terminal(p, range);
  print<int>(p);
}

void graph_test() {
  Graph<int> g(6);
  g.addEdge(0, 1); 
  g.addEdge(0, 2); 
  g.addEdge(1, 2); 
  g.addEdge(2, 0); 
  g.addEdge(2, 3); 
  g.addEdge(3, 4); 
  g.addEdge(4, 5); 

  std::cout << "Following is Breadth First Traversal "
      << "(starting from vertex 2) \n"; 
  g.BFS(2);
  std::cout << "Following is Depth First Traversal "
      << "(starting from vertex 2) \n"; 
  g.DFS(0);
}

void  bstNode_test() {
    auto *root = new bstNode(5); 
    root = root->insert(root, 3);
    root = root->insert(root, 3);
    root = root->insert(root, 3);
    //cout << "LCA of " << v1 << " " << v2 <<" =  "<< lca(root,v1,v2) <<endl;

}

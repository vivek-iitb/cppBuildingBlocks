#ifndef DS_H
#define DS_H

#include<iostream>
#include <cstdlib>
#include <ctime>
#include <list>
#include<set>


// ========================================================== 
// mvik: LinkedList Class
template<typename T>
class Node {
 public:
  T m_data;
  Node *m_next;

  Node():m_next(nullptr){}; // MVIK: very important to not use default, m_head may be dangling
  Node(T data):m_next(nullptr) {    
    this->m_data = data;        
  }

  ~Node() { 
    delete m_next; 
  }
};

template<class T>
class List {
 private:
  Node<T> *m_head;
 public:
  List(T data);
  List():m_head(nullptr){};
  void printList();
  void reverseList();     
  void insertNode();
  ~List() {
    if (m_head) {
      delete m_head ;
    }
  }
};


// ========================================================== 
// mvik: GraphClass
template <class T> 
class GNode {
  T val;
};

template <class T>
class Graph {
 private: 
  std::list <T> *m_adj;
  long m_nv ;
 public:
  Graph():m_adj(nullptr),m_nv(0){};
  Graph(long nv):m_adj(nullptr),m_nv(nv){
    this->m_nv = nv;
    m_adj = new std::list<T>[m_nv];
  };
  void addEdge(T v, T w);
  void BFS(T s);
  void DFS(T s);
  void DFSutil(T s, bool visited[]);
}; 

// Mvik: Binary Tree

struct treeNode {
  int m_val;
  treeNode *m_left, *m_right;
  treeNode():m_val(-1),m_left(nullptr), m_right(nullptr){};
  treeNode(int val):m_val(val), m_left(nullptr), m_right(nullptr){};
  treeNode* insert(treeNode*, int);
  void inorder_print(treeNode*);
  ~treeNode(){
    if (m_left) {
      delete m_left;
      m_left = nullptr;
    } 
    if (m_right) {
      delete m_right;
      m_right= nullptr;
    }
  };
};


class binaryTree {
 private:
  treeNode *m_root ;
 public:
  binaryTree():m_root(NULL){};
  void insert_node(){};
  void print_root() {
    std::cout<< m_root << std::endl;
  }
  ~binaryTree() {
    if (m_root) {
      delete m_root;
    }
  }
};

#endif

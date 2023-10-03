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


using namespace std;
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode():val(-1),left(nullptr), right(nullptr){};
    ~TreeNode(){};
};

// mvik: class Binary Tree
class binaryTree {
private:
    TreeNode *root ;
public:
    binaryTree():root(NULL){};
    void insert_node(){};
    void print_root() {
        std::cout<< root << endl;
    }
    
};

struct bstNode {
    int nodeval ;
    bstNode *left, *right;
    bstNode():nodeval(-1), left(nullptr), right(nullptr){};
    bstNode(int val):nodeval(val), left(nullptr), right(nullptr){};
    void inorder_print(bstNode*);
    bstNode* insert(bstNode*, int);
};



#endif

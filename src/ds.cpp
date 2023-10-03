#include "ds.hpp"

// mvik: Array functions

#if 0 
static int **my2DAlloc(int rows=0, int cols=0) {
int **rowptr ;
rowptr = (int **) malloc (rows *sizeof(int*)) ; 
for (int i =0 ; i< rows ; i++ ) {
  rowptr[i] = (int *) malloc (cols *sizeof (int)) ;
}
return rowptr; 
//int ** myarray = my2DAlloc (2,2) ;
}


#endif 

template<class T>
List<T>::List(T data):m_head(nullptr) {
  if (m_head == nullptr) {      
    m_head = new Node<T>(data);    
  } else {
    m_head->m_data=data;
  }
}

template <class T> 
void List<T>::insertNode() {
  srand(time(NULL)) ;  
  auto cur = this->m_head;
  //mvik: corner case
  if (!cur) {
    return;
  }
  
  for (int i= 0 ; i < 10 ; i++) {
    Node<T> *tmp = new Node<T>(rand()%10);    
    cur->m_next = tmp;         
    cur = cur->m_next;    
    }
}

template <class T>
void List<T>::reverseList() {
  Node<T> *current, *prev, *next;
  current = this->m_head;
  prev = NULL;
  next = NULL;
  while (current !=NULL) {
    next = current->m_next; // cache nxt
    current->m_next = prev; // assign the next of cur to prev of cur which is initially null
    prev = current ; // move ahead
    current = next ; // move ahead
  }
 
  this->m_head=prev;
}

template <class T>
void List<T>::printList() {
  Node<T> *current = this->m_head;
  while (current != NULL){
    std::cout<< current->m_data << "->" ;
    current = current->m_next;
  }
  std::cout<< "NULL\n" ;  
}

//==============================================================================
//mvik: Generic Graph

template <class T>
void Graph<T>::addEdge(T v , T w) {
  m_adj[v].push_back(w);
  m_adj[w].push_back(v);
}

template <class T>
void Graph<T>::BFS(T s) {
  
  bool visited[m_nv] ;
  // mark all vertex unvisitied
  for ( int i = 0 ; i < m_nv ; i++ ) {
    visited[i] = 0;
  }
  // Create a queue 
  std::list<T> queue ;
  // Set the node argument to be true and push in stack 
  visited[s] = true;
  queue.push_back(s); 

  while (!queue.empty()) {
    s = queue.front();
    std::cout << s << " " ;
    queue.pop_front();

    for (auto i=m_adj[s].begin() ; i != m_adj[s].end() ; ++i ) {
      if (visited[*i] == false) {
        visited[*i] = true;
        queue.push_back(*i);
      }
    }
  }
}

template <class T>
void Graph<T>::DFSutil (T s , bool visited[] ) {
  //std::list <T>::iterator i;
  // visit the neighbors of the given node
  visited[s] = true;
  std::cout << s << " -- " ;
  for(auto i=m_adj[s].begin()  ; i != m_adj[s].end(); i++) {
    if (visited[*i] == false) {
      DFSutil(*i,visited);
    }
  }
}

template <class T>
void Graph<T>::DFS (T s ) {
  // 1. this step marks all node as not visited
  bool *visited = new bool[m_nv];
  for ( int i = 0 ; i < m_nv ; i++ ) {
    visited[i] = false;
  }
  // 3. Recursively call it 
  DFSutil(s,visited);
}

// mvik: BST routines
bstNode* bstNode::insert(bstNode *root, int val) {
    if (!root)
    {
        root = new bstNode(-1);
        root->nodeval = val;
        return root;
    }

    if (val < root->nodeval)
    {
        root->left = insert(root->left, val);
    }
    else 
    {
        root->right = insert(root->right, val);
    }
    return root;
}
void bstNode::inorder_print(bstNode *root) {
    if (!root) return ;
    inorder_print(root->left);
    cout << root->nodeval << endl;
    inorder_print(root->right);
}

template class List<int>;;
template class Graph<int>;

/*
int lca(bstNode* root, int val1, int val2)
{
  if (!root) return -1; 
  cout << "root - node val " << root->nodeval << endl;
  if (val1  < root->nodeval && val2 < root->nodeval)  
      return lca(root->left, val1, val2);  
  else if (val1  > root->nodeval && val2  > root->nodeval)  
      return lca(root->right, val1, val2);  
  else
      return  root->nodeval;
}
*/
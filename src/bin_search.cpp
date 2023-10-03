//  main.cpp
//  Foo
//
//  Created by Vivek Mishra on 3/25/21.
//


#include <iostream>
#include <vector>
using namespace std;


int bin_search(vector<int> sorted, int target) ;

int main()
{
  int n = 3;

  // Create a vector of size n with
  // all values as 10.
  vector<int> vect(n, 10);

  for (int x : vect)
    cout << x << " " << endl;


  int i = 20;
  int *ip = & i;
  cout << *ip << " aaa "<< i << endl;
  //int j = *ip; // would assign *ip, i.e., 10 to j
  //int k = ip; // integer object assigned a pointer ? warning
  *ip = *ip + 2 ; // legal ? same as i = i + 2
  cout << *ip << " "<< i << endl;
  ip = ip + 2 ; // legal ? pointer ip is incremented by ???
  //cout << *ip << " "<< i << endl;
  vector<int> sorted {1,2,7,8,10,100,200};
  
  cin >> i ;
  cout << "something" << bin_search(sorted, i);


  return 0;
}


int bin_search(vector<int> sorted, int target) {
	unsigned int m=0;
	unsigned int n =sorted.size();
	
  while(m<=n) {
    auto k = m+n/2;
    if (sorted[k]==target) {
      return k;
    } else if (target < sorted[k] ) {
      n =k-1;
    } else {
      m=k+1;
    }   
  }
  return -1;
}

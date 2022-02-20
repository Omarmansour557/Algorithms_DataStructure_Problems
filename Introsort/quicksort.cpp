#include <bits/stdc++.h>
using namespace std;

/**
 * implement quicksort algorithm using last element as a pivot
 * 
 * @param
 *  a --> int array to be sorted
 *  begin --> iterator points to the lower index
 *  end --> iterator points to the maximum index
 * 
 * @return
 * void as quicksort is an inplace sorting algorithm
*/

vector<int>::iterator partition(vector<int>::iterator begin,vector<int>::iterator end){
  vector<int>::iterator pivot = end -1;
  vector<int>::iterator j = begin-1;
  /*
  the idea here is to chech whether the pivot is bigger than the element in index j
  then swap them(element in index j and element of index i).
  in order to make sure that the smaller elements compare to the pivot is behind the pivot.
  
  */
  for(auto i = begin; i!=(end-1);i++){
    if(*pivot > *i){
      iter_swap(i,j+1);
      j++;
    }
  }
    iter_swap(pivot,j+1);
    pivot = j+1;
    return pivot;

  }



void quicksort(vector<int> &a, vector<int>::iterator begin , vector<int>::iterator end){
  if(distance(begin, end)>0){
    vector<int>::iterator correct_place  = partition(begin, end);
    quicksort(a, begin, correct_place);
    quicksort(a,correct_place+1, end);
  }



}
// int main(){
//     vector<int> a {3,4,5,8,1,2,233,-6};
//     quicksort(a,begin(a), end(a));
//     for(auto i : a){
//         cout<<i<<endl;
//     }
// }


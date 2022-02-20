#include <bits/stdc++.h>
// #include "quicksort.cpp"
using namespace std;

// Function to perform heapsort on the given range of elements
void heapsort(vector<int>::iterator begin, vector<int>::iterator end)
{
    make_heap(begin, end);
    sort_heap(begin, end);
    return;
}

void insertionSort(vector<int> &vec, vector<int>::iterator begin, vector<int>::iterator end){
  for(auto i = begin+1; i != end; i++){
      auto key = i;
      for(auto j = i-1;j>=begin;j-- ){
          if(*key<*j){
              swap(*key,*j);
              key--;
          }
          else
            break;
      }

  }
}


/**
 * implement introsort algorithm
 * 
 * @param
 *  a --> int array to be sorted
 *  begin --> iterator points to the lower index
 *  end --> iterator points to the maximum index
 *  max_depth --> number of maximum recursion depth before changing to heapsort
 * 
 * @return
 * 
*/
void introsort(vector<int> &a, vector<int>::iterator begin, vector<int>::iterator end, int max_depth)
{
    if(a.size()<=1) return;
    else if (max_depth==0) heapsort(begin, end);
    else if (distance(begin,end)<=16) insertionSort(a,a.begin(),a.end());
    else if(distance(begin,end)>16){
        auto correctPlace = partition(begin,end);
        introsort(a,begin,correctPlace,max_depth-1);
        introsort(a,correctPlace+1,end,max_depth-1);

    }

    
}

// int main(){
//     vector<int> a {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
//     int max_depth =floor(log(a.size()));
//     introsort(a,begin(a),end(a),max_depth);
//     for(auto i : a){
//         cout<<i<<endl;
//     }
// }
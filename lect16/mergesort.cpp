//mergesort.cpp
#include <iostream>
#include <assert.h>

using namespace std;


void mergeSort(vector<int>& v){
   
}


int main(int argc, char const *argv[])
{
  
    vector<int> v1 = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> v2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> v3 = {1, 9, 2, 8, 3, 7, 4, 6, 5};
    vector<int> v4 = {5, 4, 6, 3, 7, 2, 8, 1, 9};
    vector<int> w  = {5, 4, 6, 3, 7, 2, 8, 1};
    vector<int> x;
    vector<int> exp_v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> exp_w = {1, 2, 3, 4, 5, 6, 7, 8};
  
    mergeSort(v1);
    mergeSort(v2);
    mergeSort(v3);
    mergeSort(v4);
    mergeSort(w);
    mergeSort(x);
    cout << "Run mergesort tests" << endl;
    assert(v1 == vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9}));
    cout << "Passed odd list 1 " << endl;
    assert(v2 == vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9}));
    cout << "Passed sorted list " << endl;
    assert(v3 == vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9}));
    cout << "Passed odd list 2  " << endl;
    assert(v4 == vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9}));
    cout << "Passed odd list 3 " << endl;
    assert(w == vector<int>({1, 2, 3, 4, 5, 6, 7, 8}));
    cout << "Passed even list  " << endl;
    assert(x == vector<int>{});
    cout << "Passed empty list " << endl;

    return 0;
}

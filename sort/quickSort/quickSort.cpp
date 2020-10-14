#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int partition(vector<int> &v, int left, int right){
    // if select pivot as front or back, if reverse order big O will be N^2
    int mid = (left + right)/2;
    swap(v[left], v[mid]);
    int pivot = v[left];
    
    int l = left;
    int r = right;
    
    while(l<r){
        
        // r should be bigger than pivot
        while(pivot < v[r]){
            r--;
        }
        
        // l should be smaller than pivot
        while(l<r && pivot >= v[l]){
            l++;
        }
        swap(v[l], v[r]);
    }
    
    // swap pivot and last l value
    v[left] = v[l];
    v[l] = pivot;
    
    return l;
    
}

void quickSort(vector<int> &v, int left, int right){
    
    if(left >= right) return;
    
    int pivot = partition(v, left, right);
    quickSort(v, left, pivot-1);
    quickSort(v, pivot+1, right);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<int> v = {1,9,7,2,5,3,6};
    
    quickSort(v, 0, v.size()-1);
    
    for(auto vv : v){
        cout << vv << " ";
    }
}

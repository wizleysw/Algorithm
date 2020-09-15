#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void merge(vector<int> &v, int l, int r){
    int mid = (l+r)/2;
    int left = l;
    int right = mid+1;
    int pos = left;

    vector<int> v2 = v;
    
    // 한자리씩 비교하면서 채워넣음
    while(left<=mid && right<=r){
        if(v[left] > v[right]){
            v2[pos++] = v[right++];
        } else {
            v2[pos++] = v[left++];
        }
    }
    
    // 왼쪽을 다 사용한 경우
    if(left>mid){
        while(right<=r){
            v2[pos++] = v[right++];
        }
    } else {
        while(left<=mid){
            v2[pos++] = v[left++];
        }
    }
    v = v2;
}

void mergeSort(vector<int> &v, int l, int r){
    if(l>=r) return;
    
    int mid = (l+r)/2;
    mergeSort(v, l, mid);
    mergeSort(v, mid+1, r);
    merge(v, l, r);
}

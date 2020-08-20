#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

int V, E;

int findSet(vector<int> &set, int x){
    if(set[x] == x) return x;
    return set[x] = findSet(set, set[x]);
}

void unionSet(vector<int> &set, int x, int y){
    x = findSet(set, x);
    y = findSet(set, y);
    set[y] = x;
}

void kruskal(vector<tuple<int,int,int>> &edge, vector<int> &set){
    int total = 0;
    int cnt = 0;
    
    // O(E)
    for(auto e: edge){
        
        if(cnt == V-1) break;
        
        int w = get<0>(e);
        int a = get<1>(e);
        int b = get<2>(e);
        
        if(findSet(set, a) != findSet(set, b)){
            unionSet(set, a, b);
            total += w;
            cnt++;
        }
    }
    
    cout << total << "\n";
    
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> V >> E;

    vector<int> vertex(V+1);
    vector<int> disjointSet(V+1);
    vector<tuple<int, int, int>> edge(E);
    
    for(int i=0; i<disjointSet.size(); i++){
        disjointSet[i] = i;
    }
    
    int v1, v2, w;
    for(int i=0; i<E; i++){
        cin >> v1 >> v2 >> w;
        edge[i] = {w,v1,v2};
    }
    
    // O(log|E|)
    sort(edge.begin(), edge.end());

    kruskal(edge, disjointSet);
    
    return 0;
}


#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
int V, E;

int RESULT = 0;

void prim(vector<int> &vertex, vector<vector<pair<int,int>>> &edge, vector<int> &visited, int start){
    
    visited[start] = true;
    
    // O(E)
    for(auto e : edge[start]){
        if(visited[e.second]) continue;
        pq.push(e);
    }
    
    // O(log|V|)
    while(!pq.empty()){
        int w = pq.top().first;
        int next = pq.top().second;
        pq.pop();
        
        if(visited[next]) continue;
        
        RESULT += w;
        return prim(vertex, edge, visited, next);
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> V >> E;

    vector<int> vertex(V+1);
    vector<int> visited(V+1);
    vector<vector<pair<int,int>>> edge(V+1);
    
    int v1, v2, w;
    for(int i=0; i<E; i++){
        cin >> v1 >> v2 >> w;
        edge[v1].push_back(make_pair(w, v2));
        edge[v2].push_back(make_pair(w, v1));
    }
    
    prim(vertex, edge, visited, 1);
    
    cout << RESULT << "\n";
  
    return 0;
}


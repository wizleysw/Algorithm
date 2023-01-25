#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int V;
int E;

void bfs(vector<vector<int>> &edge, vector<bool> &visited, int start){
    queue<int> que;
    
    visited[start] = true;
    que.push(start);
    
    int stage = 0;
    
    while(!que.empty()){
        queue<int> que2;
        
        cout << "breadth : " << ++ stage << "\n";
        
        while(!que.empty()){
            int current = que.front();
            que.pop();
            
            cout << current << "\n";
            
            for(auto next : edge[current]){
                if(!visited[next]){
                    visited[next] = true;
                    que2.push(next);
                }
            }
        }
        que = que2;
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // vertex count
    // edge count;
    cin >> V >> E;
    
    vector<vector<int>> edge(V+1);
    vector<bool> visited(V+1, false);
    
    int from, to;
    for(int e=0; e<E; e++){
        cin >> from >> to;
        edge[from].push_back(to);
    }
    
    for(int vertex=1; vertex<=V; vertex++){
        if(!visited[vertex]){
            bfs(edge, visited, vertex);
        }
    }
    
    return 0;
    
}


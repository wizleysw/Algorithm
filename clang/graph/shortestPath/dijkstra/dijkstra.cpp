#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

int N, M;

vector<int> dijkstra(vector<vector<pair<int,int>>> edge, int start){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    
    vector<int> distance(N);
    fill(distance.begin(), distance.end(), INF);
    
    distance[start] = 0;
    pq.push(make_pair(0, start));
    
    while(!pq.empty()){
        int weight = pq.top().first;
        int vertex = pq.top().second;
        pq.pop();
        
        if(distance[vertex] < weight) continue;

        for(auto e : edge[vertex]){
            int w = e.first;
            int nextv = e.second;
            
            if(distance[nextv] > weight+w){
                distance[nextv] = weight+w;
                pq.push(make_pair(distance[nextv], nextv));
            }
        }
    }
    
    return distance;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // N -> number of vertex
    // M -> number of edge
    cin >> N >> M;
    
    vector<vector<pair<int,int>>> edge(N);
    
    int from, to, weight;
    for(int i=0; i<M; i++){
        cin >> from >> to >> weight;
        edge[from].push_back(make_pair(weight, to));
    }
    
    auto result = dijkstra(edge, 0);
    
    for(auto r : result){
        cout << r << " ";
    }
    cout << "\n";
    
}


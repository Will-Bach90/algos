#include <iostream>
#include <limits.h>
#include <queue>
using namespace std;

#define V 6 // vertices in graph

bool bfs(int rGraph[V][V], int s, int t, int parent[]){ // for finding augmenting paths
    bool visited[V];
    memset(visited, 0, sizeof(visited)); // mark all nodes as not visited
    
    queue<int> q; 
    q.push(s); // add source
    visited[s] = true; // mark source as visited
    parent[s] = -1; // no parent node of source

    // bfs loop
    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int v = 0; v < V; v++){
            if(visited[v] == false && rGraph[u][v] > 0) {
                if(v ==t){
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return false;
}

int fordFulkerson(int graph[V][V], int s, int t){ //returns max flow from source to sink
    int u, v;

    int rGraph[V][V]; // residual graph
    for(u = 0; u < V; u++){
        for(v = 0; v < V; v++){
            rGraph[u][v] = graph[u][v];
        }
    }

    int parent[V];
    int max_flow = 0; // no flow initially

    while(bfs(rGraph, s, t, parent)){
        int path_flow = INT_MAX;
        for(v = t; v!=s; v = parent[v]){
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        for(v = t; v!=s; v = parent[v]){ // update residual capacities of edges and reverse edges along path
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
        
        max_flow += path_flow;
    }

    return max_flow;
}

int main() {

    int graph[V][V] = { {0, 16, 13, 0, 0, 0},
                        {0, 0, 10, 12, 0, 0},
                        {0, 4, 0, 0, 14, 0},
                        {0, 0, 9, 0, 0, 20},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 0, 0}
                      };

    cout << "The max flow is " << fordFulkerson(graph, 0, 5) << endl;

    return 0;
}
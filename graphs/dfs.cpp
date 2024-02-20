#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph{
    private:
        int V;
        vector<int> *adj;
        void DFSrecursive(int v, vector<bool> &visited);
    public:
        Graph(int V);
        void addEdge(int v, int w);
        void DFS(int v);
};

Graph::Graph(int V){
    this->V = V;
    adj = new vector<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::DFSrecursive(int v, vector<bool> &visited){
    visited[v] = true;
    cout << v << " ";
    for(auto adjacent: adj[v]){
        if(!visited[adjacent]){
            DFSrecursive(adjacent, visited);
        }
    }
}

void Graph::DFS(int v){
    vector<bool> visited(V, false);
    DFSrecursive(v, visited);
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Depth First Search (starting at node 2): \n";
    g.DFS(2);
    cout << endl;
    return 0;
}
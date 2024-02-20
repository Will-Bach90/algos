#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Graph{
    private:
        int V; // number of vertices
        vector<int> *adj; // pointer to vector of adjacency lists
    public:
        Graph(int V);
        void addEdge(int v, int w);
        void BFS(int s);
};

Graph::Graph(int V){
    this->V = V;
    adj = new vector<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::BFS(int s){
    vector<bool> visited(V, false);

    queue<int> q;

    visited[s] = true;
    q.push(s);

    while(!q.empty()){
        s = q.front();
        cout << s << " ";
        q.pop();

        for(auto adjacent: adj[s]){
            if(!visited[adjacent]){
                visited[adjacent] = true;
                q.push(adjacent);
            }
            
        }
    }
}


int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Breadth First Search (starting at node 2): \n";
    g.BFS(2);
    cout << endl;
    return 0;
}
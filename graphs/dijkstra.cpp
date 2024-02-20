#include <iostream>
#include <queue>
#include <vector>
#include <limits>

using namespace std;

using pii = pair<int, int>;

const int INF = numeric_limits<int>::max();

class Graph{
    private:
        int V; //number of vertices
        vector<pii> *adj; // including weight
    public:
        Graph(int V);
        void addEdge(int u, int v, int w);
        void dijkstra(int s);
};

Graph::Graph(int V){
    this->V = V;
    adj = new vector<pii>[V];
}

void Graph::addEdge(int u, int v, int w){
    adj[u].push_back(make_pair(v, w));
}

void Graph::dijkstra(int src){
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    vector<int> dist(V, INF);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        for(auto adjacent: adj[u]){
            int v = adjacent.first;
            int weight = adjacent.second;

            if(dist[v] > dist[u] + weight){
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    cout << "Vertex\tDistance from Source\n";
    for(int i = 0; i < V; i++){
        cout << i << "\t\t" << dist[i] << "\n";
    }
}

int main() {
        Graph g(9);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.dijkstra(0);

    return 0;
}

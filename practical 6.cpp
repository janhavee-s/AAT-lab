// Bellman–Ford Algorithm
#include <iostream>
#include <climits>
using namespace std;

struct Edge {
    int src, dest, weight;
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    Edge edges[E];

    for(int i = 0; i < E; i++) {
        cout << "Enter source, destination and weight: ";
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    int dist[V];

    for(int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    // Relax edges V-1 times
    for(int i = 1; i <= V - 1; i++) {
        for(int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;

            if(dist[u] != INT_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    // Check for negative weight cycle
    for(int j = 0; j < E; j++) {
        if(dist[edges[j].src] != INT_MAX &&
           dist[edges[j].src] + edges[j].weight < dist[edges[j].dest]) {
            cout << "Graph contains negative weight cycle";
            return 0;
        }
    }

    cout << "Vertex Distance from Source\n";
    for(int i = 0; i < V; i++)
        cout << i << "\t\t" << dist[i] << endl;

    return 0;
}


// Floyd–Warshall Algorithm
#include <iostream>
#include <climits>
using namespace std;

#define INF 99999

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    int dist[V][V];

    cout << "Enter adjacency matrix (use 99999 for INF):\n";
    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            cin >> dist[i][j];

    for(int k = 0; k < V; k++)
        for(int i = 0; i < V; i++)
            for(int j = 0; j < V; j++)
                if(dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    cout << "Shortest distance matrix:\n";
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            if(dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


// Travelling Salesman Problem (TSP)
#include <iostream>
#include <climits>
using namespace std;

#define N 4
#define INF 99999

int dist[N][N] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

int dp[1 << N][N];

int tsp(int mask, int pos) {
    // All cities visited
    if(mask == (1 << N) - 1)
        return dist[pos][0];

    if(dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INF;

    for(int city = 0; city < N; city++) {
        if((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] +
                         tsp(mask | (1 << city), city);
            ans = min(ans, newAns);
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    for(int i = 0; i < (1 << N); i++)
        for(int j = 0; j < N; j++)
            dp[i][j] = -1;

    cout << "Minimum travelling cost: " << tsp(1, 0);

    return 0;
}
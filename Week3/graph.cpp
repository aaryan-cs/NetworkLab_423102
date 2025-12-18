#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <climits>

using namespace std;

typedef pair<char, int> Edge; 
map<char, vector<Edge>> adj;

void addEdge(char u, char v, int weight) {
    adj[u].push_back({v, weight});
    adj[v].push_back({u, weight});
}

void printGraph() {
    for (const auto& entry : adj) {
        char node = entry.first;
        const vector<Edge>& neighbors = entry.second;

        cout << node << " : ";
        for (const Edge& e : neighbors) {
            cout << "(" << e.first << ", " << e.second << ") ";
        }
        cout << endl;
    }
}

void MST_Prims(char start) {
    map<char, bool> inMST;
    map<char, char> parent;
    map<char, int> key;

    for (auto& x : adj) key[x.first] = INT_MAX;
    key[start] = 0;

    priority_queue<pair<int, char>, vector<pair<int,char>>, greater<pair<int,char>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        char u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;

        for (auto &edge : adj[u]) {
            char v = edge.first;
            int w = edge.second;

            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    cout << "\nMST (Prim's Algorithm):\n";
    int totalWeight = 0;

    for (auto &x : parent) {
        cout << x.second << " -> " << x.first << " (weight = " << key[x.first] << ")\n";
        totalWeight += key[x.first];
    }

    cout << "Total Weight of MST = " << totalWeight << "\n";
}

void SPT_Dijkstra(char start) {
    map<char, int> dist;
    map<char, char> parent;

    for (auto &x : adj) dist[x.first] = INT_MAX;
    dist[start] = 0;

    priority_queue<pair<int,char>, vector<pair<int,char>>, greater<pair<int,char>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        char u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d != dist[u]) continue;

        for (auto &edge : adj[u]) {
            char v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "\nSPT (Dijkstra's Shortest Path Tree):\n";
    for (auto &x : parent) {
        cout << parent[x.first] << " -> " << x.first
             << "   dist = " << dist[x.first] << endl;
    }
}

int main() {
    addEdge('a', 'c', 6);
    addEdge('a', 'b', 6);
    addEdge('a', 'd', 6);
    addEdge('b', 'd', 2);
    addEdge('c', 'd', 2);

    printGraph();

    MST_Prims('a');
    SPT_Dijkstra('a');

    return 0;
}

#include<bits/stdc++.h>
using namespace std;
struct Graph {
    vector<vector<int>> adj;
    int V;
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }
    void addEdge(int v, int u) {
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    void sortGraph() {
        for (int i = 0; i < V; i++) {
            sort(adj[i].begin(), adj[i].end());
        }
    }

    void printGraph() {
        for (int i = 0; i < V; i++) {
            cout << i << ": ";
            for(int x : adj[i]) cout << x << " ";
            cout << endl;
        }
    }
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);
        cout << "BFS: ";
        while(!q.empty()) {
            int u = q.front(); q.pop();
            cout << u << " ";

            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }
    void DFS_recursive(int u, vector<bool> &visited) {
        visited[u] = true;
        cout << u << " ";
        for(int v : adj[u]) {
            if (!visited[v]) {
                DFS_recursive(v, visited);
            }
        }
    }
    void DFS(int start) {
        vector<bool> visited(V, false);
        cout << "DFS: ";
        DFS_recursive(start, visited);
        cout << endl;
    }
};


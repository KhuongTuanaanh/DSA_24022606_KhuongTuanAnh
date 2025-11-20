#include <bits/stdc++.h>
using namespace std;
const int MAX_Dinh = 1000;
const int MAX_Canh = 200000;
struct Edge {
    int to, w, next;
};
Edge edges[MAX_Canh];
int head[MAX_Dinh];
int dist_arr[MAX_Dinh];
bool visited[MAX_Dinh];
int soCanhHienTai = 0;
void addEdge(int u, int v, int w) {
    edges[soCanhHienTai].to = v;
    edges[soCanhHienTai].w = w;
    edges[soCanhHienTai].next = head[u];
    head[u] = soCanhHienTai;
    soCanhHienTai++;
}
void dijkstra(int n, int source) {
    for (int i = 1; i <= n; i++) {
        dist_arr[i] = INF;
        visited[i] = false;
    }
    dist_arr[source] = 0;
    for (int i = 1; i <= n; i++) {
        int v = -1;
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && (v == -1 || dist_arr[j] < dist_arr[v])) {
                v = j;
            }
        }
        if (v == -1 || dist_arr[v] == INF) break;
        visited[v] = true;
        for (int e = head[v]; e != -1; e = edges[e].next) {
            int u = edges[e].to;
            int w = edges[e].w;
            if (!visited[u] && dist_arr[u] > dist_arr[v] + w) {
                dist_arr[u] = dist_arr[v] + w;
            }
        }
    }
}

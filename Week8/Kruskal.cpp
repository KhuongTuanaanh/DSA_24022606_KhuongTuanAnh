#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int u, v, c;
};
int lab[100];
int find_root(int u) {
    if (lab[u] < 0) return u;
    return lab[u] = find_root(lab[u]);
}
void union_trees(int u, int v) {
    u = find_root(u);
    v = find_root(v);
    if (u == v) return;

    if (lab[u] > lab[v]) swap(u, v);
    lab[u] += lab[v];
    lab[v] = u;
}

bool cmp(const Edge& a, const Edge& b) {
    return a.c < b.c;
}
int kruskal(vector<Edge>& edges, int n) {

    for (int i = 1; i <= n; i++) lab[i] = -1;
    sort(edges.begin(), edges.end(), cmp);
    int mst_weight = 0, cnt = 0;
    for (auto &e : edges) {
        if (find_root(e.u) != find_root(e.v)) {
            union_trees(e.u, e.v);
            mst_weight += e.c;
            cnt++;
            if (cnt == n - 1) break;
        }
    }

    if (cnt == n - 1) return mst_weight;
    return -1;
}


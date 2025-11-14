#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];
int vis[N];
bool cycle = false;
void dfs(int u, int p) {
    vis[u] = 1;
    for (int v: adj[u]) {
        if (v == p) continue;
        if (!vis[v]) {
            dfs(v, u);
        } else {
            cycle = true;
        }
    }
}
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    int cnt = count(vis + 1, vis + n + 1, 1);
    cout << (cycle || cnt != n ? "NO\n" : "YES\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

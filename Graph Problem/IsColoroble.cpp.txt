#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> adj[N];
vector<bool> visited(N, false), inStack(N, false);
int n, m;

bool dfs(int node) {
    visited[node] = true;
    inStack[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor)) return true; // cycle found
        }
        else if (inStack[neighbor]) {
            // found a node that is in the current recursion path
            return true;
        }
    }

    inStack[node] = false; // backtrack
    return false;
}

bool hasCycle() {
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i)) return true;
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    if (hasCycle()) cout << "Cycle detected\n";
    else cout << "No cycle\n";
}

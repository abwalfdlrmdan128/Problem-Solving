#include <bits/stdc++.h>
using namespace std;

int visited[2001];
int flag = 0;
int bugs, interactions;
void dfs(vector<int> graph[], int src, int color) {
    if (flag) return;
    visited[src] = color;
    for (int i = 0; i < graph[src].size(); i++) {
        int neighbor = graph[src][i];
        if (!visited[neighbor]) {
            dfs(graph, neighbor, (color == 1 ? 2 : 1));
        } else if (visited[neighbor] == visited[src]) {
            flag = 1;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int testCases;
    cin >> testCases;
    for (int t = 1; t <= testCases; t++) {
        cin >> bugs >> interactions;
        vector<int> graph[2001];
        for (int i = 0; i < interactions; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        flag = 0;
        fill(visited, visited + 2001, 0);
        for (int i = 1; i <= bugs && !flag; i++) {
            if (!visited[i]) {
                dfs(graph, i, 1);
            }
        }
        cout << "Scenario #" << t << ":\n";
        if (flag)
            cout << "Suspicious bugs found!\n";
        else
            cout << "No suspicious bugs found!\n";
    }
    return 0;
}

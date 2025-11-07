#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
bool isBipartite(int n) {
    vector<int>color(n+1,-1); 
    for (int start=1;start<=n;start++) {
        if (color[start] == -1) {
            queue<int> q;
            q.push(start);
            color[start]=0; 
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : adj[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u]; 
                        q.push(v);
                    } 
                    else if (color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    adj.resize(n+1);
    for (int i=0;i<m;i++) {
        int u,v;
        cin >>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (isBipartite(n)) cout << "YES"<<endl;
    else cout << "NO"<<endl;
}

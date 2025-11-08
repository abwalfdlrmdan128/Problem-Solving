#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>>Adj;
vector<int> visited;
int dfs(int node) {
    visited[node]=1;
    int depth=1;
    for (int emp:Adj[node]) {
        depth=max(depth, 1 + dfs(emp));
    }
    return depth;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    Adj.assign(n, {});
    visited.assign(n, 0);
    vector<int> manager(n);
    for (int i =0;i<n;i++) {
        cin>>manager[i];
        if(manager[i]!=-1) {
            Adj[manager[i]-1].push_back(i);
        }
    }
    int ans=0;
    for (int i=0;i<n;i++) {
        if (manager[i]==-1) {
            ans=max(ans, dfs(i));
        }
    }
    cout << ans <<endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>>Adj;
vector<int> visited;
void dfs(int node) {
    visited[node] = 1;
    for(auto child : Adj[node]) {
        if(visited[child] == 0) dfs(child);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    Adj.assign(n+1, {});
    visited.assign(n+1, 0);
    vector<int> p(n);
    for (int i =1;i<=n;i++) {
        int x;
        cin>>x;
        Adj[x].push_back(i);
        Adj[i].push_back(x);
    }
    int ans=0;
    for (int i=1;i<=n;i++) {
        if (visited[i]==0) {
           dfs(i);
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}

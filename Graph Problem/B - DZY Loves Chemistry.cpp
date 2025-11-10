#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<int>>Adj;
vector<bool>visited;
void dfs(int u){
    visited[u]=true;
    for (int v:Adj[u])
        if (!visited[v]) dfs(v);
}
int main() {
    ll n,m;
    cin >>n>>m;
    Adj.resize(n+1);
    visited.assign(n+1,false);
    for (int i=0;i<m;i++) {
        ll x,y;
        cin>>x>>y;
        Adj[x].push_back(y);
        Adj[y].push_back(x);
    }

    ll cnt=0;
    for (int i=1;i<=n;i++) {
        if (!visited[i]) {
            dfs(i);cnt++;
        }
    }
    ll ans =1LL<<(n-cnt);
    cout<<ans<<endl;
}

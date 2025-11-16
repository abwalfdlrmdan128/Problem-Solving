#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e3;
vector<int>vec;
vector<vector<int>>Adj;
vector<bool>visited;
void dfs(int v) {
    visited[v]=true;
    for(auto u:Adj[v]) {
        if(visited[u]==false) {
            dfs(u);
        }
    }
    vec.push_back(v);
}
void solve() {
while (true) {
    int n,m;
    cin>>n>>m;
    if(n==0&&m==0)break;
    vec.clear();
    visited.assign(n,false);
    Adj.assign(n+1,vector<int>());
    for(int i=0;i<m;i++) {
        int u,v;
        cin>>u>>v;
        Adj[u].push_back(v);
        //Adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i])
            dfs(i);
    }
    reverse(vec.begin(),vec.end());
    for(int i=0;i<vec.size();i++) {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}
}
int main(){
    int t=1;
    //cin>>t;
    while (t--)
    {
        solve();
    }

}

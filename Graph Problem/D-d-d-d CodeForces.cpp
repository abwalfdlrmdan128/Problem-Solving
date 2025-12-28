#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=3e5+5;
ll  n,f[N],ans,l;
vector<pair<ll,ll>> Adj[N];
void BFS() {
    int n,m,l;
    cin>>n>>m>>l;
    vector<int>vals(l);
    for(int i=0;i<l;i++) {
        cin>>vals[i];
    }
    vector<vector<int>>adj(n+1);
    for (int i = 0; i < m; i++) {
        int u,v;
        cin>>u>>v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    int tot= accumulate(vals.begin(),vals.end(),0);
    int even=0,odd=0;
    if(tot&1)odd=tot;
    else even=tot;
    for (int i = 0; i < l;i++) {
        int tot2=tot-vals[i];
        if(tot2&1)odd=max(odd,tot2);
        else even=max(even,tot2);
    }
    vector<vector<int>>dist(n+1,vector<int>(2,2e9+1));
    dist[1][0]=0;
    queue<int>q;
    q.emplace(1);
    while(!q.empty()){
        auto u=q.front();
        q.pop();
        for(auto v:adj[u]){
            for(auto d:{0,1}){
                if(dist[u][d]+1<dist[v][d^1]){
                    dist[v][d^1]=dist[u][d]+1;
                    q.emplace(v);
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout<<(dist[i][0]<=even || dist[i][1]<=odd);
    }
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1;
    cin >> t;
    while (t--) {BFS();}
    return 0;
}

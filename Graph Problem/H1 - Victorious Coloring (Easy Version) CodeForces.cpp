#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=3e5+5;
ll  n,f[N],ans,l;
vector<pair<ll,ll>> Adj[N];
void DFS(ll x,ll p,ll c) {
for(auto i:Adj[x]) {
    if(i.first==p)continue;
    DFS(i.first,x,i.second);
    f[x]+=min(f[i.first],i.second);
}
    if(f[x]+c<=l)ans+=l-f[x]-c,f[x]=l-c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1;
   cin >> t;
    while (t--) {
        cin>>n;
        for(ll i=1;i<=n;i++) Adj[i].clear();
        for(ll i=1,u,v,w;i<n;i++){
            cin>>u>>v>>w;
            Adj[u].push_back({v,w});
            Adj[v].push_back({u,w});
        }
        ll q;cin>>q;while(q--){
            cin>>l;
            for(ll i=1;i<=n;i++) f[i]=0;
            ans=0;
                DFS(1,0,0);
            cout<<ans<<endl;
        }
    }
    return 0;
}

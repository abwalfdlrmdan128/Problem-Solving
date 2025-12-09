#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+5;
ll n,m,k;
vector<pair<ll,ll>> Adj[N];
bool Visited[N]={false};
vector<vector<ll>> Dis(N,vector<ll>(N,1e18));vector<pair<ll,ll>>A;
bool compare(pair<int,vector<int>>&v1,pair<int,vector<int>>&v2) {
    return v1.second.size()<v2.second.size();
}
struct Edge {
    int u,v,w;
    bool operator<(const Edge&d) const {
        return w<d.w;
    }
};

void Dijkstra(int src) {
 for(int i =0;i<N;i++) {
     Visited[i]=false;
           }
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    Dis[src][src]=0;
    pq.push(make_pair(Dis[src][src],src));
    while(!pq.empty()) {
        auto [cost, node] = pq.top();
        pq.pop();
        if(Visited[node]) continue;
        Visited[node] = true;
        for(auto &x : Adj[node]) {
            ll nxt = x.first;
            ll w = x.second;
            if(Dis[src][nxt] > cost + w) {
                Dis[src][nxt]= cost + w;
                pq.push({Dis[src][nxt], nxt});
            }
        }
    }
}


struct DSU {
int Parent[N];
int SZ[N];
    int n,c;
    DSU(int n):n(n) {
        c=n;
        init();
    }
    void init() {
        for(int i=0;i<=n;i++) {
            Parent[i]=i;
            SZ[i]=1;
        }
    }
    int GetParent(int u) {
        if(u==Parent[u])return u;
        return Parent[u]=GetParent(Parent[u]);// path Compression
    }
   bool AreFriend(int u, int v) {
        return GetParent(u)==GetParent(v);
    }
    void Unite(int u,int v) {
        u=GetParent(u);
        v=GetParent(v);
        if(u==v)return;
        if(SZ[u]>SZ[v]) {swap(u,v);}
        Parent[u]=v;
        c--;
        SZ[v]+=SZ[u];
    }
    int GetSZ() {
        return c;
    }
};
struct MST {
    // Kruskal
    int n, m;
    vector<Edge> E;
    MST(int n, int m, vector<Edge> &edges) : n(n), m(m), E(edges) {}
    ll kruskal() {
        sort(E.begin(), E.end());
        DSU dsu(n);
        ll cost = 0,cnt=0;
        for (auto &e : E) {
            if (!dsu.AreFriend(e.u, e.v)) {
                dsu.Unite(e.u, e.v);
                cost += e.w;
                cnt++;
            }
        }
        if(cnt==n-1)return cost;
        else return -1;
    }
};



void solve_Dijkstra() {
    cin>>n>>m>>k;
    for(int i=0;i<m;i++) {
        ll u,v,w;
        cin>>u>>v>>w;
        Adj[u].push_back(make_pair(v,w));
        Adj[v].push_back(make_pair(u,w));
    }
   A.resize(k);
    for (int i=0;i<k;i++) {
      cin>>A[i].first>>A[i].second;
    }
    for(int i=1;i<=n;i++) {
        Dijkstra(i);
    }
    ll minm=1e18;
    for(int i=1;i<=n;i++) {
        for(auto [u,w]: Adj[i]) {
            ll ans=0;
            for(auto [a,b]:A) {
                ans+=min({Dis[a][b],Dis[a][i]+Dis[b][u],Dis[a][u]+Dis[b][i]});
            }
            minm=min(minm,ans);
        }
    }
    cout<<minm<<endl;
}
void solve_DSU() {
int n,m;
    cin>>n>>m;
    DSU dsu(n);int maxm=1;
    while(m--) {
        int u,v;
        cin>>u>>v;
        if(!dsu.AreFriend(u,v)) {
            dsu.Unite(u,v);
            int uu=dsu.GetParent(u);
            maxm=max(maxm,dsu.SZ[uu]);
        }
        cout<<dsu.GetSZ()<<" "<<maxm;
        cout<<endl;
    }
}
void solve_MST() {
    int n,m;
    cin>>n>>m;
    vector<Edge>Edges(m);
    for (int i=0;i<m;i++) {
        cin>>Edges[i].u>>Edges[i].v>>Edges[i].w;
    }
    MST mst(n,m,Edges);
    ll ans=mst.kruskal();
    if(ans==-1) {
        cout<<"IMPOSSIBLE"<<endl;
    }else {
        cout<<ans<<endl;
    }
}


void Star() {
    int n,m;
    cin>>n>>m;
    vector<vector<bool>>bad(n+1,vector<bool>(n+1,false));
    for(int i =0;i<m;i++) {
        int a,b;
        cin>>a>>b;
        bad[a][b]=bad[b][a]=true;
    }
    int star=-1;
    for(int i=1;i<=n;i++) {
        bool ok=true;
        for(int j=1;j<=n;j++) {
            if (bad[i][j]) {
                ok=false;
                break;
            }
        }
        if(ok){
            star=i;
            break;
        }
    }
    cout<<n-1<<endl;
    for(int i=1;i<=n;i++) {
        if(i==star)continue;
        cout<<star<<" "<<i<<endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin >> t;
    while (t--) {
        solve_Dijkstra();
    }

    return 0;
}

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll n,m;
vector<pair<ll,ll>> Adj[N];
bool Visited[N]={false};
vector<ll> Dis(N),A;
struct Edge {
    int u,v,w;
    bool operator<(const Edge&d) const {
        return w<d.w;
    }
};

void Dijkstra() {
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    for(int i=0;i<n;i++) {
        Dis[i+1]=A[i];
        pq.push(make_pair(A[i],i+1));
    }
    while(!pq.empty()) {
        auto [cost, node] = pq.top();
        pq.pop();
        if(Visited[node]) continue;
        Visited[node] = true;
        for(auto &x : Adj[node]) {
            ll nxt = x.first;
            ll w = x.second;
            if(Dis[nxt] > cost + w) {
                Dis[nxt] = cost + w;
                pq.push({Dis[nxt], nxt});
            }
        }
    }
}
struct DSU {
int Parent[N];
int SZ[N];
    int n;
    DSU(int n):n(n) {
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
        SZ[v]+=SZ[u];
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
    cin>>n>>m;
    for(int i=0;i<m;i++) {
        ll u,v,w;
        cin>>u>>v>>w;
        w*=2;
        Adj[u].push_back(make_pair(v,w));
        Adj[v].push_back(make_pair(u,w));
    }
   A.resize(n);
    for (int i=0;i<n;i++) {
      cin>>A[i];
    }
    Dijkstra();
    for (int i=0;i<n;i++) {
        cout<<Dis[i+1]<<" ";
    }
    cout<<endl;
}
void solve_DSU() {
int n,q;
    cin>>n>>q;
    DSU Dsu(n);
    while (q--) {
        int type,u,v;
        cin>>type>>u>>v;
        if(type==1) {
            Dsu.Unite(u,v);
        }else {
            cout<<(Dsu.AreFriend(u,v)?"Yes":"No")<<endl;
        }
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

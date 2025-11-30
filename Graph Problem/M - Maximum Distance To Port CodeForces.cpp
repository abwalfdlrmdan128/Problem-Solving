#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200000 + 5;
const int INF=1e9;
vector<int> dist(N, INF);
int n,m,k;
vector<int>products(n);
vector<vector<int>>Adj(N);
void BFS(int src) {
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v : Adj[u]) {
            if(dist[v]==INF) {
                dist[v] = dist[u]+1;
                q.push(v);
            }
        }
    }
    vector<int>vec(k+1,0);
    for(int i=1;i<=n;i++) {
        int p=products[i];
        vec[p]=max(vec[p],dist[i]);
    }
    for(int i=1;i<=k;i++) {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}
void solve() {
    cin>>n>>m>>k;
    products.assign(n + 1, 0);
    for(int i=1;i<=n;i++) {
        cin>>products[i];
    }
    for(int i=1;i<=m;i++) {
        int x,y;
        cin>>x>>y;
        Adj[x].push_back(y);
        Adj[y].push_back(x);
    }
    BFS(1);
}
int main() {
    int t=1;
    //cin >> t;
    while (t--) {
      solve();
    }
    return 0;
}

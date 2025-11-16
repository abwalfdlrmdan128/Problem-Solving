#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e3;
vector<int>vec;
map<ll,vector<ll>> Adj;
set<ll> visited;
void dfs(int v) {
   visited.insert(v);
    vec.push_back(v);
    for(auto u:Adj[v]) {
        if(visited.find(u)==visited.end()) {
            dfs(u);
        }
    }
}
void solve() {

    int n,m;
    cin>>n;
    //if(n==0&&m==0)break;
    vec.clear();

    for(int i=0;i<n;i++) {
        int u,v;
        cin>>u>>v;
       Adj[u].push_back(v);
        Adj[v].push_back(u);
    }
    int start=0;
  for(auto u:Adj) {
      if(u.second.size()==1) {
          start=u.first;
          break;
      }
  }
    dfs(start);
    //reverse(vec.begin(),vec.end());
    for(int i=0;i<vec.size();i++) {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int t=1;
    //cin>>t;
    while (t--)
    {
        solve();
    }

}

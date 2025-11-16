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
    int n;
    cin>>n;
    vector<pair<ll,ll>>v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i].first>>v[i].second;
    }
    bool ok=false;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            int xA=v[i].first+v[i].second;
            int yA=v[j].first+v[j].second;
            if(xA==v[j].first && yA==v[i].first) {
                cout<<"YES"<<endl;
                return;
            }
        }
    }
    cout<<"NO"<<endl;
}
int main(){
    int t=1;
    //cin>>t;
    while (t--)
    {
        solve();
    }

}

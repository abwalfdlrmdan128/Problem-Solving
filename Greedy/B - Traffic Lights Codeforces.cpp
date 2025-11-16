#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
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
   double l,d,v,g,r;
    cin>>l>>d>>v>>g>>r;
    double ArTime=d/v;
    double rounnd=g+r;
    double Tmod=fmod(ArTime,rounnd);
    double total=0;
    if(Tmod>=g) {
        total+=ArTime+((l-d)/v)+(rounnd-Tmod);
    }else {
        total+=ArTime+((l-d)/v);
    }
    cout<<fixed<<setprecision(8)<<total<<endl;
}
int main(){
    int t=1;
    //cin>>t;
    while (t--)
    {
        solve();
    }

}

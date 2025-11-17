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
 int a,b,n;
    cin>>a>>b>>n;
    cout<<(n*b<=a or a==b?1:2)<<endl;

}
int main(){
    int t=1;
    cin>>t;
    while (t--)
    {
        solve();
    }

}

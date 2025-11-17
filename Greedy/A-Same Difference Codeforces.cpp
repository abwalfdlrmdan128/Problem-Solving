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
  int n;
    cin>>n;
    string s;
    cin>>s;
    map<char,int>mp;
    for(int i=0;i<n;i++) {
        mp[s[i]]++;
    }
    if(mp[s[n-1]]>1) {
        cout<<n-mp[s[n-1]]<<endl;
    }else {
        cout<<n-1<<endl;
    }

}
int main(){
    int t=1;
    cin>>t;
    while (t--)
    {
        solve();
    }

}

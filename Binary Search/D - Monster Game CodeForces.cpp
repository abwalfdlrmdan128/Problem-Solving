#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=3e5+5;
const ll LIM=1e18;
ll Gcd(ll a,ll b){ return b?gcd(b,a%b):a;}
bool compare(ll &x,ll &y) {
    return x>y;
}
bool isSuffix(const string& a, const string& b) {
    if (a.size() > b.size()) return false;
    return b.substr(b.size() - a.size()) == a;
}
vector<vector<ll>>Adj(N);
vector<ll>sz(N);
bool visitde[N];
void DFS(ll u) {
    visitde[u]=true;
    sz[u]=1;
    for (ll v : Adj[u]) {
        if (!visitde[v]) {
            DFS(v);
            sz[u]+=sz[v];
        }
    }
}
vector<vector<int>>dp;
string x,y;
int n;
int solve(int i,bool f) {
    if(i==n)return 0;
    if(dp[i][f]!=-1)return dp[i][f];
    int res=INT_MAX;
    int xi=f^0;
    int cost=(x[i]-'0'!=xi)+(y[i]-'0'!=0);
    res=min(res,cost+solve(i+1,0));

    xi=f^1;
    cost=(x[i]-'0'!=xi)+(y[i]-'0'!=1);
    res=min(res,cost+solve(i+1,1));
    return dp[i][f]=res;
}
void query() {
  int n;
    cin>>n;//>>s>>x;
    vector<ll>vec1(n);
    vector<ll>vec2(n);
    //ll sum=0;
    for(int i=0;i<n;i++) {
        cin>>vec1[i];
        //sum+=vec[i];
    }
    for(int i=0;i<n;i++) {
        cin>>vec2[i];
        //sum+=vec[i];
    }
   sort(vec1.rbegin(),vec1.rend());
    vector<ll>prefix(n+1,0);
    for(int i=0;i<n;i++) {
        prefix[i+1]=prefix[i]+vec2[i];
    }
    ll ans=0;
    for(int i=0;i<n;i++) {
        ll x=vec1[i];
        ll cnt=i+1;
        ll k=upper_bound(prefix.begin(),prefix.end(),cnt)-prefix.begin()-1;
        ans=max(ans,x*k);
    }
    cout<<ans<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--) {
        query();
    }
    return 0;
}

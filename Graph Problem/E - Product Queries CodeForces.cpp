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
    cin>>n;
    vector<ll>vec(n);map<ll,ll>mp;
    for(int i=0;i<n;i++) {
        cin>>vec[i];
    }
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(),vec.end()), vec.end());
    vector<ll>dis(N,-1);
    queue<ll>q;//vector<int>values;
    for(ll x:vec) {
        if(x<=N&&dis[x]==-1) {
            dis[x]=1;
            q.push(x);
        }
    }
    while(!q.empty()) {
        ll u=q.front();
        q.pop();
        for(ll v:vec) {
            ll c=u*v;
            if(c>n)break;
            if(c<=N&&dis[c]==-1) {
                dis[c]=dis[u]+1;
                q.push(c);
            }
        }
    }
    for(int i=1;i<=n;i++) {
            cout<<dis[i]<<" ";
    }
    cout << "\n";
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

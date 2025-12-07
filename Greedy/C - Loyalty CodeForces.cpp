#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
#define pb push_back
#define ll long long 
const int INF = 1e9;

void solve() {
    ll n,x;
    cin>>n>>x;
    vector<ll>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(rall(a));
    deque<ll>q;

    for(auto e:a)q.pb(e);
    ll ans=0,s=0;vector<ll>lol;
    while(!q.empty()){
        if((s+q[0])/x != s/x) {
            s+=q[0];
            ans+=q[0];
            lol.pb(q[0]);
            q.pop_front();
            continue;
        }
        lol.pb(q.back());
        s=s+q.back();
        q.pop_back();
    }
    cout<<ans<<'\n';
    for(auto w:lol)cout<<w<<'\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+5;
ll color[2];
vector<vector<ll>> Adj(N);
void DFS(ll p,ll u,bool s) {
    ++color[s];
    for(auto i:Adj[u]) {
        if(i==p) continue;
        DFS(u,i,!s);
    }
}

void solve() {
    ll n,cnt1=0,cnt2=0;
    cin>>n;
    vector<ll> a(n),b(n),c(n);
    set<ll> s1,s2,s3;
    for (ll i=0;i<n;i++) {
        cin>>a[i];s1.insert(a[i]);
    }

    for (ll i=0;i<n;i++) {
        cin>>b[i];
        s2.insert(b[i]);
    }
    for (ll i=0;i<n;i++) {
        cin>>c[i];s3.insert(c[i]);
    }
    if(s1.size()==s2.size()&&s1.size()==s3.size()&&s1.size()==1&&*s1.begin()<*s2.begin()&&*s2.begin()<*s3.begin()) {
            cout<<n*n*n<<endl;
        }else {
            /*
             b= 1 2 3 4 5
             bcircle= 1 2 3 4 5 1 2 3 4 5
             */
            vector<ll> bcircle(2*n+1),ccircle(2*n+1);
            for (ll i =0;i<2*n;i++) {
                bcircle[i]=b[i%n];ccircle[i]=c[i%n];
            }
            for(ll t=0;t<n;t++) {
                bool ok1=true;
                for(ll i=0;i<n;i++) {  // foreach valu in arry a make n shift for b
                    if(!(a[i]<bcircle[i+t])) {
                        ok1=false;break;
                    }
                }
                if(ok1)cnt1++;
                bool ok2=true;
                for(ll i=0;i<n;i++) {
                    if(!(b[i]<ccircle[i+t])) {
                        ok2=false;break;
                    }
                }
                if(ok2)cnt2++;
            }
            cout<<cnt2*cnt1*n<<endl;
        }
    }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

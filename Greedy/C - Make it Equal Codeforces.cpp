#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IsOn(n,k) (((n)>>(k))&1)



void solve() {
    ll n,k;
    cin>>n>>k;
    multiset<ll> s,T;
    for(int i=0;i<n;i++) {
        ll x;
        cin>>x;
        s.insert(x);
    }
    for(int i=0;i<n;i++) {
        ll x;
        cin>>x;
        T.insert(x);
    }
    if(s==T){
        cout<<"YES"<<endl;return;
    }
   else {
       map<ll,ll> mp1;
       for(auto x:T) {
           mp1[min(x%k,(k-x%k))]++;
       }
       for(auto x:s) {
           mp1[min(x%k,(k-x%k))]--;
       }
       for(auto x:mp1) {
           if(x.second!=0) {
               cout<<"NO"<<endl;
               return;
           }
       }
       cout<<"YES"<<endl;
   }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    vector<ll>a(n),b(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    ll bob=0,alice=0;
    for(int i=0;i<n;i++) {
        if(a[i]>=(k/2))alice++;
        if(b[i]>=(m/2))bob++;
    }
if(alice>bob) {
    cout<<"Alice"<<endl;
}else if(bob>alice) {
    cout<<"Bob"<<endl;
}else {
    ll maxm1=*max_element(a.begin(),a.end());
    ll maxm2=*max_element(b.begin(),b.end());
    if(maxm1>maxm2) {
        cout<<"Alice"<<endl;
    }else {
        cout<<"Bob"<<endl;
    }
}
}
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   int t=1;cin>>t;
   while(t--) {
     solve();
   }
   return 0;
}

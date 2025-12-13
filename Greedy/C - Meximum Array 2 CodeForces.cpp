#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool compare(ll &x,ll &y) {
    return x>y;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin >> t;
    while (t--) {
         int n,k,q;
        cin>>n>>k>>q;
        vector<ll> v(n);
        for(int i=0;i<n;i++) {
            v[i]=i%k;// the interval range must be greater than or equal the l-r+1
        }
        vector<pair<int,int>>vec;
        while(q--) {
            int c,l,r;
            cin>>c>>l>>r;
            l--,r--;
            if(c==1) {
              for(int i=l;i<=r;i++) {
                  v[i]=k;
              }
            }else {
               vec.push_back({l,r});
            }
        }
         for(int i=0;i<vec.size();i++){
            for(int j=vec[i].first;j<=vec[i].second;j++) {
                    if(v[j]==k)v[j]=k+1;
                }
         }
        for(int i=0;i<n;i++) {
            cout<<v[i]<< " \n"[i+1 == n];
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IsOn(n,k) (((n)>>(k))&1)



void solve() {
  int n;
    cin>>n;
    vector<int>a(n),b(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i=0;i<n;i++) {
        cin>>b[i];
    }
    int cnt=0;
    while(true) {
        cnt++;
        bool dec=false;
        for(int i=0;i<n;i++) {
            if(a[i]>b[i]) {
                a[i]--;
                dec=true;
                break;
            }
        }
        for(int i=0;i<n;i++) {
            if(a[i]<b[i]) {
                a[i]++;
                break;
            }
        }
        if(!dec)break;
    }
    cout<<cnt<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}

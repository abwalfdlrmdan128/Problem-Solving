#include <bits/stdc++.h>
using namespace std;
bool compare(const pair<int,int>&a,const pair<int,int>&b) {return a.second < b.second;}
#define ll long long
void solve() {
  int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++) {
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end());
    ll ans=0;
    for(int i=1;i<=n;i++) {
        if(vec[i-1]<0) {
            ans+=-1*vec[i-1];
            ans+=i;
        }
        else if(vec[i-1]==0) {
            ans+=i;
        }else {
            ans+=abs(vec[i-1]-i);
        }
    }
    cout<<ans<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin >> t;
    while (t--) solve();
    return 0;
}

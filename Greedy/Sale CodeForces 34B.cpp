#include <bits/stdc++.h>
using namespace std;
bool compare(const pair<int,int>&a,const pair<int,int>&b) {return a.second < b.second;}
#define ll long long
void solve() {
  int n,m;
    cin>>n>>m;
    vector<int>vec(n);
    int cnt=0;
    for(int i=0;i<n;i++) {
        cin>>vec[i];
        if(vec[i]<0) cnt++;
    }
    sort(vec.begin(),vec.end());
    ll sum= 0;
    for(int i=0;i<min(cnt,m);i++) {
        sum+=-1*vec[i];
    }
    cout<<sum<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin >> t;
    while (t--) solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
bool compare(const pair<int,int>&a,const pair<int,int>&b) {return a.second < b.second;}
#define ll long long
void solve() {
  int n,m;
    cin>>n>>m;
    vector<int>vec(m);
    for(int i=0;i<m;i++) {
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end());
    int l=0,r=n-1;int minm=INT_MAX;
    while(r<m) {
        minm=min(minm,(vec[r]-vec[l]));
        l++;r++;
    }
    cout<<minm<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin >> t;
    while (t--) solve();
    return 0;
}

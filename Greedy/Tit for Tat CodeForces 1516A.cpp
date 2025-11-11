#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool compare(const pair<int, int> p1, const pair<int, int> p2) {
    if (p1.first != p2.first) return p1.first>p2.first;
    return p1.second>p2.second;
}
void solve() {
  int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin>>v[i];
    for (int i = 0; i <n-1&&k>0; i++) {
     int take=min(v[i],k);
        v[i]-=take;
        v[n-1]+=take;
        k-=take;
    }
    for(int i=0;i<n;i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin >> t;
    while (t--) {
solve();
    }
    return 0;
}

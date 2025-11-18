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
    vector<int>vec(n);
    for(int i=0;i<n;i++) cin>>vec[i];
    sort(vec.rbegin(),vec.rend());
    int total=0;
    for(int i=0;i<n;i++) {
        int number=i/k;
        total+=(vec[i]*(number+1));
    }
    cout<<total<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin >> t;
    while (t--) {
solve();
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool compare(const pair<int, int> p1, const pair<int, int> p2) {
    if (p1.first != p2.first) return p1.first>p2.first;
    return p1.second>p2.second;
}
void solve() {
   int n,d;
    cin>>n>>d;
    vector<int>vec(n);
    for(int i=0;i<n;i++) cin>>vec[i];
    int mod=d%n;
    vector<int>rotated;
    for(int i=d;i<n;i++) rotated.push_back(vec[i]);
    for(int i=0;i<d;i++)rotated.push_back(vec[i]);
    for(int i=0;i<rotated.size();i++) cout<<rotated[i]<<" ";
    cout<<endl;
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

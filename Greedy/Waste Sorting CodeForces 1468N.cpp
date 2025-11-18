#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool compare(const pair<int, int> p1, const pair<int, int> p2) {
    if (p1.first != p2.first) return p1.first>p2.first;
    return p1.second>p2.second;
}
void solve() {
   ll c1,c2,c3;
    cin>>c1>>c2>>c3;
    ll a1,a2,a3,a4,a5;
    cin>>a1>>a2>>a3>>a4>>a5;
    if(a1>c1||a2>c2||a3>c3) {
        cout<<"NO"<<endl;
        return;
    }
    ll rem1=c1-a1,rem2=c2-a2,rem3=c3-a3;
    ll ans4=max(0ll,a4-rem1),ans5=max(0ll,a5-rem2);
    if(ans4+ans5<=rem3) {
        cout<<"YES"<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }
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

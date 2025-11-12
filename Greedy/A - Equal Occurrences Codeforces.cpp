#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool compare(const pair<int, int> p1, const pair<int, int> p2) {
    if (p1.first != p2.first) return p1.first>p2.first;
    return p1.second>p2.second;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
       // vector<int>vec(n);
        map<int,int>mp;
        for (int i = 0; i < n; i++) {
            int x;cin>>x;mp[x]++;
        }
        vector<int>v;
        for (auto p:mp) {
            v.push_back(p.second);
        }
        int maxm=*max_element(v.begin(), v.end());
        int ans=-10000;
        for(int i=1;i<=maxm;i++) {
            int cnt=0;
            for(auto x:v) {
                if(x>=i)cnt++;
            }
            ans=max(cnt*i,ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}

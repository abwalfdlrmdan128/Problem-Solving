#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool compare(const pair<int, int> p1, const pair<int, int> p2) {
    if (p1.first != p2.first) return p1.first>p2.first;
    return p1.second>p2.second;
}
void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> sets(n);
    vector<int> cnt(m+1, 0);int cnt2=0;
    for (int i = 0; i < n; i++) {
        int l;cin>>l;
        for (int j = 0; j < l; j++) {
            int x;cin>>x;sets[i].push_back(x);
        }
        for (int j = 0; j < sets[i].size(); j++) {
          if(j<=l) {cnt[sets[i][j]]++;}
        }
    }
    for (int i=1;i<=m;i++) {
        if (cnt[i]==0&&i<=m){cout<<"NO"<<endl;return;}
    }
    for (int i=0;i<n;i++) {
        bool f=false;
        for (int x:sets[i]) {
            if (cnt[x]==1&&!f){f=true;break;}
        }
        if(!f)cnt2++;
    }
   cout<<((cnt2>=2)?"YES":"NO")<<endl;
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

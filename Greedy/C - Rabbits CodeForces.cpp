#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool compare(ll &x,ll &y) {
    return x>y;
}
void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int num=0;
    for(int i=0;i<n;i++) {
        if(s[i]=='0') num++;
    }
    vector<bool>vis(n),change(n);
    for(int i=0;i<n;i++) {
        if(vis[i]) continue;
        if(s[i]=='0') {
            if(i==0 || i+1==n) {
                // if(s[i]=='0'&&num%2==1)vis[i]=1;
                continue;
            }
            if((s[i-1]=='0') ||(s[i+1]=='0'))continue;
            if(i>=2 && s[i-2]=='0' && (!vis[i-2]||change[i-2])) {
                vis[i]=change[i]=1;
            }
            else if(i+2<n && s[i+2]=='0') {
                vis[i+2]=vis[i]=1;
            }
            else {
                cout<<"No"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--) {
      solve();
    }
    return 0;
}

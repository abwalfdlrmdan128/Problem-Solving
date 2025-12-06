#include <bits/stdc++.h>
#define ll long long
#define sz(s) (int)(s).size()
#define all(s) (s).begin(),(s).end()
using namespace std;
void solve();
int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n+1);
    int mn = 1, mx = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] < a[mn]) mn = i;
        if (a[i] > a[mx]) mx = i;
    }
    string s; cin >> s;
    s = "." + s;
    if (s[1] == '1' || s[n] == '1'||s[mn] == '1' || s[mx] == '1'){
       cout<<"-1\n";
       return;
    }
    cout << 5 << "\n";
    for(auto d:{1,n}){
        cout<<min(d,mn)<<' '<<max(d,mn)<<'\n';
        cout<<min(d,mx)<<' '<<max(d,mx)<<'\n';
    }
    cout << min(mn, mx) << " " << max(mn, mx) << "\n";
}

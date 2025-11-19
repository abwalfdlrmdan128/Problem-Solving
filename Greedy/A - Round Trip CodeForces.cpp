#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
  int t;cin >> t;
  while (t--) {
    ll r, x, d, n;
    cin >> r >> x >> d >> n;
    string s;cin >> s;
    int ans = 0;
    for(auto ch : s) {
      if(ch == '1') {
        r = max(0LL, r - d);
        ans++;
      }
      else {
        if(r < x) {
          r = max(0LL, r - d);
          ans++;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}

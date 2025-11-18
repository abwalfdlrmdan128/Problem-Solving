#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t=1;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) {
                cnt++;
            }
        }
        int ans = a * n + max(n * b, (cnt / 2 + 1) * b);
        cout << ans << endl;
    }
    return 0;
}

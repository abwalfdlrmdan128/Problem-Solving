#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> last(n+1,-1);
        int ans = 1e9;
        for (int i = 0; i < n; i++) {
            if (last[a[i]]!=-1) {
                ans=min(ans, i -last[a[i]] + 1);
            }
            last[a[i]] = i;
        }
        if (ans ==1e9) cout << -1 <<endl;
        else cout << ans <<endl;
    }
    return 0;
}

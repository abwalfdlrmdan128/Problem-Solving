#include <bits/stdc++.h>
#define int long long
#define double long double

using namespace std;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int tests;
    cin >> tests;

    for (int _ = 1; _ <= tests; _++) {
        int n;
        cin >> n;

        vector<int> a(n + 5);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        int ans = 0;
        for (int i = 2; i <= n; i += 2) {
            int sum = a[i - 1] + a[i + 1];
            int diff = sum - a[i];

            if (diff <= 0) {
                continue;
            }

            ans += diff;
            a[i + 1] -= diff;
            if (a[i + 1] < 0) {
                a[i - 1] -= a[i + 1];
                a[i + 1] = 0;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}

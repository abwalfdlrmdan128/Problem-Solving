#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<pair<ll, ll>> getPrimeFactors(ll n) {
    vector<pair<ll, ll>> primeFactors;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int count = 0;
            while (n % i == 0) n /= i, count++;
            primeFactors.push_back({i, count});
        }
    }
    if (n > 1) primeFactors.push_back({n, 1});
    return primeFactors;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, cnt = 0;
    cin >> n;

    for (ll i = 1; i <= n; i++) {
        auto vec = getPrimeFactors(i);
        if (vec.size() == 2) cnt++;
    }

    cout << cnt << endl;
    return 0;
}


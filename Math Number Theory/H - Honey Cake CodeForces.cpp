#include <bits/stdc++.h>
using namespace std;

int main(){
    int w, h, d;
    cin >> w >> h >> d;
    int n; cin >> n;

    int W = gcd(n, w);
    n /= W;
    int H = gcd(n, h);
    n /= H;
    int D = gcd(n, d);
    n /= D;

    if (n == 1) {
        cout << W - 1 << ' ' << H - 1 << ' ' << D - 1;
    }
    else cout << -1;


    return 0;
}

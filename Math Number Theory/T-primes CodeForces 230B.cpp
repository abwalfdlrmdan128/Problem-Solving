  //------------------------fadel--------------------------------\\

/*
أسير في طريقي بمفردي
لا الدار داري
ولا الرفاقُ رِفاقي
ولا المكان يعرِفني
عبثت بديارٍ لست أملكها
*/
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
void fastIO(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

}
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef pair<int, int> pi;
typedef pair<int, pi> p3i;

typedef pair<ll, ll> pll;
typedef pair<ll, pll> p3ll;

typedef pair<ll, ld> plld;
typedef pair<double, pi> pd2i;

typedef vector<int> vi;
typedef vector<pll> vpll;
typedef vector<pi> v2i;
typedef vector<p3i> v3i;
typedef vector<char> vch;
typedef vector<vch> vvch;
typedef vector<ll> vll;
typedef vector<pll> v2ll;
typedef vector<p3ll> v3ll;

typedef vector<string> vs;
typedef vector<bool> vb;

typedef vector<vi> vvi;
typedef vector<vll> vvl;

typedef priority_queue<ll> pq_max;
typedef priority_queue<int, vi, greater<int>> pq_min;

#define ON(n,k)  ((n) | (1<<k))
#define OFF(n,k) ((n) & ~(1<<k))
#define IsOn(n,k) (((n)>>(k))&1)
#define MP make_pair
#define PB push_back
#define EmB emplace_back
#define Em emplace
#define len(s)   (int)s.length()
#define sz(v)    (int)v.size()
#define all(a)   a.begin(),a.end()
#define all_r(a)   a.rbegin(),a.rend()
#define clr(x, val)    memset((x), (val), sizeof(x))
#define maxEle *max_element
#define minEle *min_element
#define tests int t=1;/*cin>>t;*/int i = 0; while(i++ < t)
#define SetPre(n, x)  cout << fixed << setprecision(n) << x
#define MOD 1000000007L
vector<ll> getDivisors(ll n);
bool IsPlaindrom(string s) {
map<char,int> mp;
    for(int i = 0; i < s.length(); i++) {
        mp[s[i]]++;
    }
    if(mp.size()==1) {
        return true;
    }else {
        int odd=0;
        for(auto [x,y] : mp) {
            if(y&1) {
                odd++;
            }
        }
        if(odd>1) {
            return false;
        }else {
            return true;
        }
    }
}
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
bool Is_Prime(ll num);
void solve() {
    int size = int(1e6) + 4;
    vector<bool> isPrime(size, true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i * i <= size; i++){
        if(isPrime[i]){
            for(int j = i * i; j <= size; j += i){
                isPrime[j] = false;
            }
        }
    }
    ll n;
    cin>>n;
    while (n--){
        ll x;
        cin>>x;
    bool valid=false;
    double s1=sqrt(x);
    ll s2=ll(s1);
    if(s1 == s2) {
        if(isPrime[s2]) valid = true;
    }
    cout << (valid ? "YES" : "NO") << endl;
}
}
int main()
{
    fastIO();
        tests{
         solve();
           // cout<<endl;
           // cout<<(1000^1001);
             }
    return 0;
}

vector<ll> getDivisors(ll n){
    vector<ll> divs;
    for (ll i = 1; i*i <= n; i++) {
        if(n%i == 0) {
            divs.push_back(i);
            if(i*i != n) divs.push_back(n/i);
        }
    }
    return divs;
}
/*bool Is_Prime(ll num) {
    int size = int(1e6) + 4;
    vector<bool> isPrime(size, true);
    isPrime[0] = isPrime[1] = false;

    for(int i = 2; i * i <= size; i++){
        if(isPrime[i]){
            for(int j = i * i; j <= size; j += i){
                isPrime[j] = false;
            }
        }
    }
    if(isPrime[num]) {
        return true;
    }
    return false;
}*/


#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<ll,ll>> getPrimeFactors(ll n){
    vector<pair<ll,ll>> primeFactors;
    for (ll i = 2; i*i <= n; i++) {
        if(n%i == 0) {
            int count = 0;
            while(n%i == 0) n /= i, count++;
            primeFactors.push_back({i,count});
        }
    }
    if(n > 1) primeFactors.push_back({n,1});
    return primeFactors;
}
vector<int>primes;
const int M=205;
vector<bool> isPrime(M+1,true);
void sieve() {
    isPrime[0]=isPrime[1]=false;
    for (int i=2;i<=M;i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (ll j=1LL*i*i;j<=M;j+=i)
                isPrime[j]=false;
        }
    }
}
vector<ll> a,c;
vector<ll> dp;
ll solve(int i) {
    if (dp[i]!=-1)return dp[i];
    ll b=c[i];
    for (int j=0;j<i;j++) {
        if (a[j]<=a[i]) {
            b=max(b,c[i]+solve(j));
        }
    }
    return dp[i]=b;
}
void solve() {
    ll n;cin>>n;
    a.resize(n);c.resize(n);
    dp.assign(n,-1);
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    for (int i=0;i<n;i++) {
        cin>>c[i];
    }
    ll total=0;
    for (int i=0;i<n;i++) {
        total+=c[i];
    }
    ll ans=0;
    for (int i=0;i<n;i++) {
        ans=max(ans, solve(i));
    }
    cout<<total-ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int t=1;
    cin >> t;
    while(t--) {
        solve();
    }
}

 

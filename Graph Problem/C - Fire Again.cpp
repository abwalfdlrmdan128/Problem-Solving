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
// 8 Dimaintional
int dx[]={2,2,-2,-2,1,-1,1,-1};
int dy[]={1,-1,1,-1,2,2,-2,-2};

// 4 Dimaintional
int Dx[]={1,-1,0,0};
int Dy[]={0,0,1,-1};
const int N=2005;

pair<int,int> BFS(vector<pair<int,int>>srcs,int n,int m) {
    vector<vector<int>> visited(n+1, vector<int>(m+1, -1));
    queue<pair<int,pair<int,int>>>q;
    pair<int,int>ans;
    for(int i=0;i<srcs.size();i++) {
        q.push({srcs[i].first,{srcs[i].second,0}});
        visited[srcs[i].first][srcs[i].second]=1;
    }
    while (!q.empty()) {
        pair<int,pair<int,int>>p=q.front();q.pop();
        ans={p.first,p.second.first};
        for(int i=0;i<4;i++) {
            int nx=p.first+Dx[i];
            int ny=p.second.first+Dy[i];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&visited[nx][ny]==-1) {
                q.push({nx,{ny,p.second.second+1}});
                visited[nx][ny]=1;
            }
        }
    }
    return ans;
}
void FIO() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

}
void Fast() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
}
int main(){
   Fast();FIO();
    int t=1;
    //cin >> t;
    while(t--) {
        int n,m,k;
        cin>>n>>m>>k;
        vector<pair<int,int>>vec(k);
        for(int i=0;i<k;i++) {
            cin>>vec[i].first>>vec[i].second;
        }
        pair<int,int> ans=BFS(vec,n,m);
        cout<<ans.first<<" "<<ans.second<<endl;
        }
    }




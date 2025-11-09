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
    int dx[]={2,2,-2,-2,1,-1,1,-1};
    int dy[]={1,-1,1,-1,2,2,-2,-2};
    const int N=20005;
    int BFS(int start,int end) {
        vector<int>visited(N,-1);
        queue<pair<int,int>>q;
        q.push({start,0});
        visited[start]=1;
        while (!q.empty()) {
            pair<int,int>p=q.front();q.pop();
            if(p.first==end) {
                return p.second;
            }
            if(p.first-1>0&&visited[p.first-1]==-1) {
                q.push({p.first-1,p.second+1});
                visited[p.first-1]=1;
            }
            if(p.first*2<=N&&visited[p.first*2]==-1) {
                q.push({p.first*2,p.second+1});
                visited[p.first*2]=1;
            }
        }
        return -1;
    }
    int main(){
        ios_base::sync_with_stdio(false), cin.tie(nullptr);
        int t=1;
        //cin >> t;
        while(t--) {
            int x,y;
            cin>>x>>y;
            int ans=BFS(x,y);
            cout<<ans<<endl;
            }
        }


 

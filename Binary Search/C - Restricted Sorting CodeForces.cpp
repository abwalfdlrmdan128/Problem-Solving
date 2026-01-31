    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    const int N=2e5+12;
    const ll LIM=1e18;
    void solve () {
        int n;
        cin>>n;
       vector<int>vec(n);
        ll maxm=-1000000000,minm=1000000000;map<int,int>mp,mp2;
        for(int i=0;i<n;i++) {
            cin>>vec[i];
            if(vec[i]>maxm) maxm=vec[i];
            if(vec[i]<minm) minm=vec[i];
            mp[vec[i]]=i;
        }
        if(is_sorted(vec.begin(),vec.end())) {
            cout<<-1<<endl;
        }else {
            vector<int>sorted=vec;
            sort(sorted.begin(),sorted.end());
            for(int i=0;i<n;i++) {
                mp2[sorted[i]]=i;
            }
            int l=1,r=1e9;
            int ans=1;
            while(l<=r) {
                int m=l+(r-l)/2;
                bool ok=true;
                for(int i=0;i<n;i++) {
                    if(vec[i]<m+minm&&vec[i]>maxm-m&&i>=0) {
                        if((vec[i]!=sorted[i])||(mp2[sorted[i]]!=mp[vec[i]])) {
                           // if(abs(vec[i]-sorted[i])<m) {
                                ok=false;
                                break;}//}
                    }
                }
                if(!ok){
                    r=m-1;
                }else{
                    ans=m;l=m+1;
                }}
            cout<<ans<<"\n";
        }
    }
    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int t=1;
        cin>>t;
        while(t--) {
            solve();
        }
        return 0;
    }

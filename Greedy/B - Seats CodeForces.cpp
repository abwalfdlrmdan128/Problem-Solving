    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    const int N=2e5+12;
    const ll LIM=1e18;
    void solve () {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int ones=0,zeros;int first=-1,last=-1;
        for(int i=0;i<s.size();i++) {
            char c=s[i];
            if(c=='1'){
                ones++;
                if(first==-1) {
                    first=i;
                }
                last=i;
        }
            else zeros++;
        }
if(ones==0) {
    cout<<(n+2)/3<<endl;
    return;
}
        ll sum=0;
        sum+=(first+1)/3;
        sum+=((n-1-last)+1)/3;
        int p=first;
        for (int i =first+1;i<=last;i++) {
            if (s[i]=='1') {
                sum+=(i-p-1)/3;
                if(i==last) {
                    p=last;
                }
                else {
                    p=i;
                }
            }
        }
        int p1=last;
        for (int i =last+1;i<n;i++) {
            if (s[i]=='1') {
                sum+=(i-p1-1)/3;
                    p1=i;
            }
        }
        cout<<sum+ones<<endl;
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

    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    const int N=2e5+12;
    const ll LIM=1e18;
    void solve () {
        int n;
        cin>>n;
        int l=1,r=n;
        vector<int> res(n);
        bool turn=false;
        for (int i=n-1; i>=0;i--) {
            if(!turn){
                res[i]=l++;
            } else {
                res[i]=r--;
            }
            turn=!turn;
        }
        for (int i=0;i<n;i++) {
            cout<<res[i] << " ";
        }
        cout<<endl;
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

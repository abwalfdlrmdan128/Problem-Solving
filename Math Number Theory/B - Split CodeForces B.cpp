    #include <bits/stdc++.h>
using namespace std;
#define ll long long
int dx[]={0, 0, -1, 1};
int dy[]={-1, 1, 0, 0};
int n;
vector<vector<int>>grid;
vector<vector<int>>memo;
int dp(int i, int j) {
    if(i<0||i>=n||j<0||j>=n) return 0;
    if(memo[i][j]!=-1) return memo[i][j];
    int val=grid[i][j];
    for (int k =0;k<4;k++) {
        int ni=i+dx[k];
        int nj=j+dy[k];
        if (ni >=0&&ni<n&&nj>=0&&nj<n)
            val+=grid[ni][nj];
    }
    return memo[i][j]=val;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
     int n;
        cin >> n;
        vector<int>vec(2*n);map<ll,ll>mp;set<ll>st;
        for(int i=0;i<2*n;i++) {
            cin >> vec[i];
            mp[vec[i]]++;
            st.insert(vec[i]);
        }
        int num1=0,num2=0;
        for(auto i:st) {
            if(mp[i]%2==0) {
                num1++;
            }else {
                num2++;
            }
        }
     if(num2==0) {
         if(num1%2==0) {
            if(n%2==0) {
                cout<<num1*2+num2<<endl;
            }else {
                cout<<num1*2+num2-2<<endl;
            }
         }else {
             if(n%2==1) {
                 cout<<num1*2+num2<<endl;
             }else {
                 cout<<num1*2+num2-2<<endl;
             }
         }
     }else {
         cout<<num1*2+num2<<endl;
     }

    }
    return 0;
}

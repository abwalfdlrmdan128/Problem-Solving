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
        ll n, k;
        cin >> n >> k;
        if (n <= k){
            cout<<(k/n)+((k%n)==0?0:1)<< endl;
        }
        else{
            if (n % k == 0){
                cout << 1 << endl;
            }
            else cout << 2 << endl;
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
bool compare(const pair<int,int>&a,const pair<int,int>&b) {return a.second < b.second;}
#define ll long long
void solve() {
  int n;
    cin>>n;
    vector<int>vec1,vec2;
    ll sum1=0,sum2=0;
    for(int i=0;i<n;i++) {
       int x;
        cin>>x;
        if(x<0) {
            sum1+=x;
        }else {
           sum2+=x;
        }
    }
    cout<<sum2-sum1<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin >> t;
    while (t--) solve();
    return 0;
}

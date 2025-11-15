#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IsOn(n,k) (((n)>>(k))&1)



void solve() {
  int n;
    cin>>n;
    vector<int>a;
    if(n==3) {
        cout<<"-1 3 -1"<<endl;
        return;
    }
    if(n==2) {
        cout<<-1<<" "<<2<<endl;
        return;
    }
    if(n%2==1) {
        for(int i=0;i<n;i++) {
            if(i%2==0)a.push_back(-1);
            else {
                a.push_back(3);
            }
        }
    }else {
        for(int i=0;i<n;i++) {
            if(i+2<n) {
                if(i%2==0) {
                    a.push_back(-1);
                }else {
                    a.push_back(3);
                }
            }else {
                a.push_back(-1);
                a.push_back(2);
                break;
            }
        }
    }
for(int i=0;i<a.size();i++) {
    cout<<a[i]<<" ";
}
    cout<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}

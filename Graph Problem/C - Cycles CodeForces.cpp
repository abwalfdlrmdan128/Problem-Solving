#include <bits/stdc++.h>
using namespace std;
#define ll  long long

int const N=200;
int n,v;
bool ed[N][N];

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while (t--) {
        cin>>n;
        int v=1;
        while (n){
            for (int i =0;i<=n&& i<v;i++){
                ed[i][v]=ed[v][i]=1;
                n-=i;
            }
            v++;
        }
        cout<<v<<endl;
        for (int i=0; i<v; i++){
            for (int j=0;j<v;j++)cout<<ed[i][j];
            cout<<endl;
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int sumdigits(ll y) {
   int sum=0;
   while(y>0){
      sum+=y%10;
      y/=10;
   }
   return sum;
}
bool solve(ll p,ll q) {
   __int128 x=(p);
   __int128 y=(q);
   return (2*y<=3*x);
}

int main() {
   int t=1;
   cin>>t;
   while(t--) {
      /*int n;
      cin>>n;
      vector<ll>a(n),b(n);map<ll,ll>mp,mp2;*/
      ll p,q;
      cin>>p>>q;
      __int128 x=(p);
      __int128 y=(q);
      if(q>p&&solve(p,q)) {
         if(((3*x)-(2*y))>=0)cout<<"Bob"<<endl;
         else cout<<"Alice"<<endl;
      }else {
         cout<<"Alice"<<endl;
      }
   }
   return 0;
}

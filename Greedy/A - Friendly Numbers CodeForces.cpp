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
int main() {
   int t=1;
   cin>>t;
   while(t--) {
      ll x;
      cin>>x;
      int count=0;
      for(ll y=x+1;y<=x+90;y++) {
         if(y-sumdigits(y)==x)count++;
      }
      cout<<count << endl;
   }
   return 0;
}

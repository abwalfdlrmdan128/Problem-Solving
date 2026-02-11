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
      int n;
      cin>>n;
      vector<ll>a(n),b(n);map<ll,ll>mp,mp2;
      for(int i=0;i<n;i++) {
         cin>>b[i];
         mp[b[i]]++;
         mp2[b[i]]=i;
      }
      for(int i=0;i<n;i++) {
         cin>>a[i];
      }
      bool f=false;
      for(int i=0;i<n;i++) {
         if(mp[a[i]]==0) {
            cout<<"NO"<<endl;f=true;
            break;
         }
      }
      if(f==true) {
         continue;
      }
      int cur=-1;
      bool flage=true;
      for(int i=0;i<n;i++) {
         if(i==0||a[i]!=a[i-1]) {
            int pos=mp2[a[i]];
            if(pos<cur) {
               flage=false;
               break;
            }
            cur=pos;
         }
      }
      if(flage==true) {
         cout<<"YES"<<endl;
      }else {
         cout<<"NO"<<endl;
      }
   }
   return 0;
}

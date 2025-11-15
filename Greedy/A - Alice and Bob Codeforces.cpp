#include<bits/stdc++.h>
using namespace std;
int main(){
    int t=1;
    cin>>t;
    while (t--)
    {
        int n,pos;
        cin>>n>>pos;
        int maxm=0,minm=0;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            if(a>pos)maxm++;
            else if(a<pos) minm++;
        }
        if(maxm==minm&&minm==0)cout<<1<<endl;
        else{
            if(maxm>minm){
                cout<<pos+1<<endl;
            }else{
                cout<<pos-1<<endl;
            }
        }
    }
  
}

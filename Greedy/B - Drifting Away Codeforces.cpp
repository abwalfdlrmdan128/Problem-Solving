#include<bits/stdc++.h>
using namespace std;
void solve() {
    string s;
    cin>>s;
    int n=s.length();
    if(n==1) {
        cout<<1<<endl;
       return;
    }
    for(int i=1;i<n;i++) {
        if(s[i-1]=='>' && s[i]=='<') {
            cout<<-1<<endl;
            return ;
        }
        if(s[i-1]=='*' && s[i]=='<') {
            cout<<-1<<endl;
            return ;
        }
        if(s[i-1]=='>' && s[i]=='*') {
            cout<<-1<<endl;
            return ;
        }
        if(s[i-1]=='*' && s[i]=='*') {
            cout<<-1<<endl;
            return ;
        }
    }
    int x=0,y=0;
    for(int i=0;i<n;i++) {
 if(s[i]=='<') {
      x++;
    }else {
        break;
    }
    }
    for(int i=n-1;i>=0;i--) {
if(s[i]=='>') {
    y++;
}else {
    break; 
}
    }
    cout<<n-min(x,y)<<endl;
}
int main(){
    int t=1;
    cin>>t;
    while (t--)
    {
        solve();
    }

}

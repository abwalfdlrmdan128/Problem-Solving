#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool compare(const pair<int, int> p1, const pair<int, int> p2) {
    if (p1.first != p2.first) return p1.first>p2.first;
    return p1.second>p2.second;
}
void solve() {
   int n;
    cin>>n;
    string s;
    cin>>s;
    vector<char>s2,s3;
    for(int i=0;i<n;i++) {
        if(i==0) {
            if(s[i]=='1') {
                s2.push_back('2');
                s3.push_back('1');
            }else {
                s2.push_back('1');
                s3.push_back('1');
            }
        }else {
            if(s[i]=='1') {
                if(s2.back()=='2') {
                    s2.push_back('1');
                    s3.push_back('0');
                }else if(s2.back()=='1') {
                    s2.push_back('2');
                    s3.push_back('1');
                }else {
                    s2.push_back('2');
                    s3.push_back('1');
                }
            }else {
                if(s2.back()=='1') {
                    s2.push_back('0');
                    s3.push_back('0');
                }else if(s2.back()=='2') {
                    s2.push_back('1');
                    s3.push_back('1');
                }else {
                    s2.push_back('1');
                    s3.push_back('1');
                }
            }
        }
    }
    for(int i=0;i<s3.size();i++) cout<<s3[i];
    cout<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin >> t;
    while (t--) {
solve();
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
vector<int>adj[N];
vector<int>topo;
bool vis[N];
void DFS(int parent){
    vis[parent]=true;
    topo.push_back(parent);
    for(auto child:adj[parent]){
        if(!vis[child]){
            DFS(child);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> v(n+1);
        for (int i=1;i<=n;i++) {
            cin>>v[i].first>>v[i].second;
        }
        for (int i = 1; i <=n ;i++) {
            int op1=v[i].first,op2=v[i].second;
            if(v[op2].first==op1||v[op2].second==op1)adj[i].push_back(op2);
            else if(v[op1].first==op2||v[op1].second==op2)adj[i].push_back(op1);
        }
        for (int i = 1; i <=n ; ++i) {
            if(!vis[i])DFS(i);
        }
        for (auto it: topo)cout << it << ' ';
    }
    return 0;
}

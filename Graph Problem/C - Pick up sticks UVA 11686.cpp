#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj; 
vector<int> visited;  
vector<int> order;     
bool hasCycle;
void DFS(int node) {
    visited[node]=1; 
    for (int nxt:adj[node]) {
        if (visited[nxt]==0) {
            DFS(nxt);
            if (hasCycle) return;
        } else if (visited[nxt]==1) {
            hasCycle=true;
            return;
        }
    }
    visited[node]=2; 
    order.push_back(node);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    while (cin>>n>>m&&!(n== 0 &&m==0)) {
        adj.assign(n+1,{});
        visited.assign(n+1,0);
        order.clear();
        hasCycle = false;
        for (int i = 0; i < m; i++) {
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b); 
        }
        for (int i = 1; i <= n; i++) {
            if (visited[i]==0)DFS(i);
            if (hasCycle)break;
        }

        if (hasCycle) {
            cout<< "IMPOSSIBLE"<<endl;
        } else {
            reverse(order.begin(),order.end());
            for (int x:order) {
                cout<<x<<endl;
            }
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[105];
bool visited[105];
void DFS(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            DFS(v);
        }
    }
}
int main() {
    int n, m;
    cin>>n>>m;
    for (int i=0;i<m;i++) {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    bool connected =true;
    for (int i=1;i<= n;i++) {
        if (!visited[i]) connected=false;
    }
    if (connected&&m==n&&n>=3) {
        cout<<"FHTAGN!"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}

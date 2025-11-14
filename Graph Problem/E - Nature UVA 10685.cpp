#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>Adj[N];
vector<int>visited(N);
int cnt=1;
void DFS(int u) {
visited[u]=1;
    for(auto v:Adj[u]) {
        if(visited[v]==0) {
            cnt++;
            DFS(v);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(true) {
        int n,m;
        cin>>n>>m;
        if(n==0&&m==0) {
           break;
        }
        map<string,int>Namechanged;
        string name;
        for(int i=1;i<=n;i++) {
            cin>>name;
            Namechanged[name]=i;
        }
        for(int i=1;i<=n;i++) {
            Adj[i].clear();
            visited[i]=0;
        }
        for(int i=0;i<m;i++) {
            string pre,predator;
            cin>>pre>>predator;
            int u=Namechanged[pre];
            int v=Namechanged[predator];
            Adj[u].push_back(v);
            Adj[v].push_back(u);
        }
        int maxm=0;
        for(int i=1;i<=n;i++) {
            if (visited[i]==0) {
                DFS(i);
                maxm=max(cnt,maxm);
                cnt=1;
            }
        }
        cout<<maxm<<endl;
    }
    return 0;
}

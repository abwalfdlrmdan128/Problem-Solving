#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<pair<int,int>>> Adj;
vector<int> dis;
void Dijkstra(int src, int n) {
    dis.assign(n+1, 0);
    priority_queue<pair<int,int>> pq;
    dis[src] = INT_MAX;
    pq.push({dis[src], src});
    while (!pq.empty()) {
        auto [cap, u] = pq.top(); pq.pop();
        if (cap < dis[u]) continue;
        for (auto &e : Adj[u]) {
            int v = e.first;
            int w = e.second;
            int newCap = min(dis[u], w);
            if (newCap > dis[v]) {
                dis[v] = newCap;
                pq.push({newCap, v});
            }
        }
    }
}
string nextPermutation(string s) {
    if(next_permutation(s.begin(), s.end()))
        return s;
    return "NO";
}
void solve() {
string s;
    cin>>s;
    int j,k;
    cin>>j>>k;
    sort(s.begin(), s.end());
    vector<string>vec;
    vec.push_back(s);
    while(next_permutation(s.begin(), s.end())) {
        vec.push_back(s);
    }
    sort(vec.begin(), vec.end());
    int A=0;
    for(int i=0;i<vec[j-1].size();i++) {
        if(vec[k-1][i]==vec[j-1][i]) {
            A++;
        }
    }
    cout<<A<<"A"<<vec[j-1].size()-A<<"B"<<endl;
}

int main() {
  int t=1;
    cin>>t;
    while(t--) {
solve();
    }
    return 0;
}

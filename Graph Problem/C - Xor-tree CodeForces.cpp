#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
vector<int> tree[N+1];
int init[N+1], goal[N+1];
vector<int> answer;
void dfs(int u, int parent, int depth, int even, int odd) {
    int current = init[u];
    if (depth % 2 == 0)
        current ^= (even % 2);
    else
        current ^= (odd % 2);
    if (current != goal[u]) {
        answer.push_back(u);
        if (depth % 2 == 0)
            even++;
        else
            odd++;
    }
    for (int v : tree[u]) {
        if (v == parent) continue;
        dfs(v, u, depth + 1,even,odd);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    for (int i=1;i<=n;i++){
        cin >> init[i];
       
    }
    for (int i=1;i<=n;i++){
        cin >> goal[i];
   
}
    dfs(1, 0, 0, 0, 0);
    cout << answer.size() <<endl;
    for (int x : answer)
        cout << x <<endl;

    return 0;
}

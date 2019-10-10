using namespace std;
#define ll long long
#include <bits/stdc++.h>

unordered_set<int> visited;
int balance = 0;

void dfs(int node, vector<vector<int>> &graph, vector<int> &money){
    if (visited.find(node) != visited.end()){
        return;
    }

    visited.insert(node);
    balance += money[node];
    for (int neighbor : graph[node]){
        dfs(neighbor, graph, money);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> money(n);
    vector<vector<int>> graph(n, vector<int>());
    for (int i = 0; i < n; i++) cin >> money[i];
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for (int i = 0; i < n; i++){
        balance = 0;
        dfs(i, graph, money);
        if (balance != 0){
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    cout << "POSSIBLE\n";
}
using namespace std;
#define ll long long
#include <bits/stdc++.h>


vector<vector<char>> board;

bool valid(vector<int> &pos){
    return pos[0] >= 0 && pos[0] < board.size() && pos[1] >= 0 && pos[1] < board[0].size();
}

void get_land_cluster(vector<int> &start, vector<vector<int>> &cluster){
    if (!valid(start) || board[start[0]][start[1]] == '1' || find(cluster.begin(), cluster.end(), start) != cluster.end()){
        return;
    }
    
    cluster.push_back(start);
    int r = start[0], c = start[1];
    vector<vector<int>> moves {{r+1, c}, {r-1, c}, {r, c+1}, {r, c-1}};
    for (auto &m : moves){
        get_land_cluster(m, cluster);
    }
}

int main(){
    int n;
    vector<int> start(2), end(2);
    cin >> n >> start[0] >> start[1] >> end[0] >> end[1];
    start[0]--; start[1]--; end[0]--; end[1]--;
    for (int i = 0; i < n; i++) {
        board.push_back(vector<char>());
        for (int j = 0; j < n; j++) {
            char x;
            cin >> x;
            board[i].push_back(x);
        }
    }
    
    vector<vector<int>> start_cluster, end_cluster;
    get_land_cluster(start, start_cluster);
    get_land_cluster(end, end_cluster);


    double cost = INT_MAX;
    for (auto &i : start_cluster){
        for (auto &j : end_cluster){
            cost = min(pow(i[0] - j[0], 2) + pow(i[1] - j[1], 2), cost);
        }
    }

    cout << cost << "\n";
}
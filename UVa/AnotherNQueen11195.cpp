using namespace std;
#define ll long long
#include <bits/stdc++.h>

//column for a given row index
int n;
vector<int> column;
vector<vector<bool>> col_blocked; 
set<vector<int>> solutions;

bool can_place(int r, int c){
    if (col_blocked[r][c]) return false;

    for (int prev = 0; prev < r; prev++) {
        if (column[prev] == c || abs(c - column[prev]) == abs(r - prev)) return false;
    }

    return true;
}

void solve(int placed = 0, int r = 0){
    if (placed == n){
        solutions.insert(column);
    }

    if (r == n) return;

    for (int c = 0; c < n; c++){
        if (can_place(r, c)){
            column[r] = c;
            solve(placed + 1, r + 1);
            column[r] = -1;
        }
    }
}

int main(){
    int tc = 1;
    while (cin >> n){
        if (n == 0) break;
        
        column.resize(n); col_blocked.resize(n);
        fill(column.begin(), column.end(), -1);
        fill(col_blocked.begin(), col_blocked.end(), vector<bool>(n, false));
        solutions.clear();
        
        for (int i = 0; i < n; i++){
            string l;
            cin >> l;
            for (int j = 0; j < l.length(); j++){
                if (l[j] == '*') col_blocked[i][j] = true;
            }
        }

        solve();
        cout << "Case " << tc << ": " << solutions.size() << "\n";
        // for (auto r : solutions) {
        //     for (auto x : r) {
        //         cout << x << " ";
        //     }
        //     cout << endl;
        // }
        tc++;
    }
}
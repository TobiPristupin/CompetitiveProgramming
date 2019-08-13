using namespace std;
#define ll long long
#include <bits/stdc++.h>
using grid_t = vector<vector<bool>>;


bool can_place(grid_t &grid, int r, int c){
    if (grid[r][c] == 1){
        return false;
    }

    for (int col = 0; col < grid.size(); col++){
        if (col != c && grid[r][col] == 1){
            return false;
        }
    }

    for (int row = 0; row < grid.size(); row++){
        if (row != r && grid[row][c] == 1){
            return false;
        }
    }

    return true;
}

int solve(grid_t &grid, int n){
    if (n == 0){
        return 1;
    }

    int sols = 0;
    for (int r = 0; r < grid.size(); r++){
        for (int c = 0; c < grid.size(); c++){
            if (can_place(grid, r, c)){
                grid[r][c] = true;
                sols += solve(grid, n-1);
                grid[r][c] = false;
            }
        }   
    }

    return sols;
}

int main(){
    int n, sol = 1;
    while (cin >> n){
        if (n == 0) break;
        
        grid_t grid(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++){
            string l;
            cin >> l;
            for (int j = 0; j < l.length(); j++){
                if (l[j] == '*') grid[i][j] = true;
            }
        }

        cout << "Case " << sol << ": " << solve(grid, n) << "\n";
    }
}
using namespace std;
#define ll long long
#include <bits/stdc++.h>


int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        vector<int> col_order(n);
        for (int i = 0; i < n; i++) col_order[i] = i;
        int min_sum = INT_MAX;
        do {
            int sum = 0;
            for (int r = 0; r < n; r++){
                sum += grid[r][col_order[r]];
            }
            min_sum = min(sum, min_sum);
            
        } while (next_permutation(col_order.begin(), col_order.end()));

        cout << min_sum << endl;
        
    }
}
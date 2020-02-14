using namespace std;
#define ll long long
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    while (!(n == 0 && m == 0)){
        vector<vector<int>> arr(n, vector<int>(m));
        for (int r = 0; r < n; r++) for (int c = 0; c < m; c++) cin >> arr[r][c];
        int q;
        cin >> q;
        vector<pair<int, int>> queries(q);
        for (int i = 0; i < q; i++){
            int l, u;
            cin >> l >> u;
            queries[i] = make_pair(l, u);
        }

        for (pair<int, int> query : queries){
            int l = query.first, u = query.second;
            int best_size = 0;
            for (int r = 0; r < n; r++){
                auto it = lower_bound(arr[r].begin(), arr[r].end(), l);
                int c = distance(arr[r].begin(), it);
                if (r+best_size >= n){
                    break;
                }

                int size = 0;
                while (r+size < n && c+size < m && arr[r+size][c+size] <= u){
                    size++;
                    best_size = max(size, best_size);
                }
            }

            cout << best_size << "\n";
        }

        cout << "-\n";
        cin >> n >> m;
    }
}
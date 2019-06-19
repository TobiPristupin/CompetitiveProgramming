using namespace std;
#define ll long long
#include <bits/stdc++.h>

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> board(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> board[i][j];
    int ans = 0;

    for (int r = 0; r < n; r++){
        int first_actor = -1, last_actor = -1;
        for (int c = 0; c < m; c++){
            if (board[r][c] == 1){
                if (first_actor == -1){
                    first_actor = c;
                }
                last_actor = c;
            }
        }

        for (int c = 0; c < m; c++){
            if (board[r][c] == 0){
                if (c > first_actor && first_actor != -1) ans++;
                if (c < last_actor && last_actor != -1) ans++;
            }
        }
    }


    for (int c = 0; c < m; c++){
        int first_actor = -1, last_actor = -1;
        for (int r = 0; r < n; r++){
            if (board[r][c] == 1){
                if (first_actor == -1){
                    first_actor = r;
                }
                last_actor = r;
            }
        }

        for (int r = 0; r < n; r++){
            if (board[r][c] == 0){
                if (r > first_actor && first_actor != -1) ans++;
                if (r < last_actor && last_actor != -1) ans++;
            }
        }
    }

    cout << ans << "\n";
}
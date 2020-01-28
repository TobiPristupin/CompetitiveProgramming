using namespace std;
#define ll long long
#include <bits/stdc++.h>

int best = -1;
int best_c = -1;

void drop(vector<vector<char>> board, int column){
    int r = 0, c = column;
    char x = board[r][c];
    while (!isdigit(x)){
        if (board[r][c] == '.'){
            r++;
            continue;
        } else if (x == '_' || x == '|') {
            return;
        } else if (x == '\\'){
            c++;
            while (true){
                if (board[r][c] == '.'){
                    r++;
                    break;
                }
                if (board[r][c] == '\\' || board[r][c] == '|' || board[r][c] == '/'){
                    return;
                }
                c++;
            }
        } else if (x == '/'){
            c--;
            while (true){
                if (board[r][c] == '.'){
                    r++;
                    break;
                }
                if (board[r][c] == '\\' || board[r][c] == '|' || board[r][c] == '/'){
                    return;
                }
                c--;
            }
        }

        x = board[r][c];
    }

    int score = board[r][c] - '0';
    if (score > best){
        best = score;
        best_c = column;
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int b;
    cin >> b;
    for (int tcase = 1; tcase <= b; tcase++){
        best = -1, best_c = -1;
        int w, h;
        cin >> w >> h;
        vector<vector<char>> board(h, vector<char>(w));
        for (int r = 0; r < h; r++) for (int c = 0; c < w; c++) cin >> board[r][c];
        
        for (int c = 1; c < w - 1; c++){
            drop(board, c);
        }

        if (best < 1){
            cout << "Board #" << tcase << ": Don’t even bother dropping a coin. You can’t win!\n";
        } else {
            cout << "Board #" << tcase << ": Drop at column " << best_c << " for a score of " << best << " points.\n";
        }

        if (tcase != b) cout << "\n";
    } 
}
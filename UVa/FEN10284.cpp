using namespace std;
#define ll long long
#include <bits/stdc++.h>

int emptyy = 0, attacked = 1, occupied = 2;

bool valid(int r, int c){
    return r >= 0 && r < 8 && c >= 0 && c < 8;
}

void performAttack(vector<vector<int>> &board, vector<vector<int>> &positions){
    for (vector<int> pos : positions){
        if (valid(pos[0], pos[1]) && board[pos[0]][pos[1]] != occupied){
            board[pos[0]][pos[1]] = attacked;
        }
    }

}

void king(vector<vector<int>> &board, int r, int c){
    vector<vector<int>> positions = {{r+1, c}, {r-1, c}, {r, c+1}, {r, c-1}, {r+1, c+1}, {r-1, c-1}, {r+1, c-1}, {r-1, c+1}};
    performAttack(board, positions);
}

void rook(vector<vector<int>> &board, int r, int c){
    for (int d = 1; d < 8; d++){
        if (!valid(r, c+d) || board[r][c+d] == occupied) break;
        board[r][c+d] = attacked;
    }
    for (int d = 1; d < 8; d++){
        if (!valid(r, c-d) || board[r][c-d] == occupied) break;
        board[r][c-d] = attacked;
    }
    for (int d = 1; d < 8; d++){
        if (!valid(r+d, c) || board[r+d][c] == occupied) break;
        board[r+d][c] = attacked;
    }
    for (int d = 1; d < 8; d++){
        if (!valid(r-d, c) || board[r-d][c] == occupied) break;
        board[r-d][c] = attacked;
    }
}

void pawnBlack(vector<vector<int>> &board, int r, int c){
    vector<vector<int>> positions = {{r+1, c+1}, {r+1, c-1}};
    performAttack(board, positions);
}

void pawnWhite(vector<vector<int>> &board, int r, int c){
    vector<vector<int>> positions = {{r-1, c+1}, {r-1, c-1}};
    performAttack(board, positions);
}

void knight(vector<vector<int>> &board, int r, int c){
    vector<vector<int>> positions = {{r+2, c+1}, {r-2, c+1}, {r+1, c+2}, {r-1, c+2}, {r+2, c-1}, {r-2, c-1}, {r+1, c-2}, {r-1, c-2}};
    performAttack(board, positions);
}

void bishop(vector<vector<int>> &board, int r, int c){
    for (int d = 1; r + d < 8 && c + d < 8; d++) {
        if (board[r+d][c+d] == occupied) break;
        board[r+d][c+d] = attacked; 
    }
    for (int d = 1; r - d >= 0 && c - d >= 0; d++) {
        if (board[r-d][c-d] == occupied) break;
        board[r-d][c-d] = attacked;
    }
    for (int d = 1; r - d >= 0 && c + d < 8; d++) {
        if (board[r-d][c+d] == occupied) break;
        board[r-d][c+d] = attacked;
    }
    for (int d = 1; r + d < 8 && c - d >= 0; d++) {
        if (board[r+d][c-d] == occupied) break;
        board[r+d][c-d] = attacked; 
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    string fen;
    while (cin >> fen){
        vector<vector<int>> board(8, vector<int>(8, emptyy));
        
        int r = 0, c = 0;
        for (char x : fen){
            if (x == '/'){
                r++;
                c = 0;
            } else if (isdigit(x)){
                c += ((int) x - 48);
            } else {
                board[r][c] = occupied;
                c++;
            }
        }

        r = 0, c = 0;
        for (char x : fen){
            if (x == 'k' || x == 'K'){
                king(board, r, c);
                c++;
            } else if (x == 'r' || x == 'R'){
                rook(board, r, c);
                c++;
            } else if (x == 'p'){
                pawnBlack(board, r, c);
                c++;
            } else if (x == 'P'){
                pawnWhite(board, r, c);
                c++;
            } else if (x == 'n' || x == 'N'){
                knight(board, r, c);
                c++;
            } else if (x == 'b' || x == 'B'){
                bishop(board, r, c);
                c++;
            } else if (x == 'q' || x == 'Q'){
                rook(board, r, c);
                bishop(board, r, c);
                c++;
            } else if (x == '/'){
                r++;
                c = 0;
            } else {
                c += ((int) x - 48);
            }
        }

        int ans = 0;
        for (vector<int> row : board){
            ans += count(row.begin(), row.end(), 0);
        }
        cout << ans << "\n";
    }
}
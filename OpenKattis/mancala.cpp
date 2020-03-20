using namespace std;
#define ll long long
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int p;
    cin >> p;
    while (p--){
        int k, n;
        cin >> k >> n;
        vector<int> board(2000, 0);
        board[0] = n;
        while (board[0] != 0){
            int counters = 0;
            for (int i = 0; i < board.size(); i++){
                if (board[i] == 0){
                    board[i] = counters;
                    break;
                }
                counters++;
                board[i]--;
            }
        }



        int j = board.size() - 1;
        while (board[j] == 0){
            j--;
        }

        cout << k << " " << j << endl;

        for (int i = 1; i <= j; i++){
            cout << board[i] << " ";
            if (i % 10 == 0) cout << "\n";
        }
        cout << "\n";
    }
}
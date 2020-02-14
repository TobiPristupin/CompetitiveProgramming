using namespace std;
#define ll long long
#include <bits/stdc++.h>

vector<int> row(8, -1);
int soln = 1, a, b;

bool can_place(int r, int c){
    if (row[c] != -1){
        return false;
    }

    for (int prev = 0; prev < c; prev++){
        if (r == row[prev] || abs(r - row[prev]) == abs(c - prev)){
            return false;
        }
    }

    return true;
}


void solve(int c){
    if (c == 8 && row[b-1] == a-1){
        if (soln < 10) cout << " " << soln << "      ";
        else cout << soln << "      ";
                
        for (int i = 0; i < 8; i++) {
            cout << row[i]+1;
            if (i != 7) cout << " ";
        }
        cout << "\n";
        soln++;
        return;
    }

    for (int r = 0; r < 8; r++){
        if (can_place(r, c)){
            row[c] = r;
            solve(c+1);
            row[c] = -1;
        }
    }
}


int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        soln = 1;
        cout << "SOLN       COLUMN\n";
        cout << " #      1 2 3 4 5 6 7 8\n\n";
        cin >> a >> b;
        solve(0);
        fill(row.begin(), row.end(), -1);
        if (t != 0) cout << "\n";
    }
}
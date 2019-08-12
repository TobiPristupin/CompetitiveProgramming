using namespace std;
#define ll long long
#include <bits/stdc++.h>

bool valid(vector<int> &row){
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if (i != j && abs(row[i] - row[j]) == abs(i - j)){
                return false;
            }
        }
    }

    return true;
}


int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        cout << "SOLN       COLUMN\n";
        cout << " #      1 2 3 4 5 6 7 8\n\n";
        
        int a, b;
        cin >> a >> b;
        vector<int> row_order(8);
        for (int i = 0; i < 8; i++) row_order[i] = i;
        int soln = 1;
        do {
            if (row_order[b-1] != a-1) continue;

            if (valid(row_order)){
                if (soln < 10) cout << " " << soln << "      ";
                else cout << soln << "      ";
                
                for (int i = 0; i < 8; i++) {
                    cout << row_order[i]+1;
                    if (i != 7) cout << " ";
                }
                cout << "\n";
                soln++;
            }

        } while (next_permutation(row_order.begin(), row_order.end()));
        
        if (t != 0) cout << "\n";
    }
}
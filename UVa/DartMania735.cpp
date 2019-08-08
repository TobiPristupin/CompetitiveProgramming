using namespace std;
#define ll long long
#include <bits/stdc++.h>

set<int> valid {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 
22, 24, 26, 27, 28, 30, 32, 33, 34, 36, 38, 39, 
40, 42, 45, 48, 50, 51, 54, 57, 60};

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    while (n > 0){
        set<vector<int>> combs;
        int perms = 0;
        for (const int &a : valid){
            for (const int &b : valid){
                int c = n - a - b;
                if (valid.find(c) != valid.end()){
                    perms++;
                    vector<int> perm = {a, b, c};
                    sort(perm.begin(), perm.end());
                    combs.insert(perm);
                }
            }
        }

        if (perms == 0){
            cout << "THE SCORE OF " << n << " CANNOT BE MADE WITH THREE DARTS.\n";
        } else {
            cout << "NUMBER OF COMBINATIONS THAT SCORES " << n << " IS " << combs.size() << ".\n";
            cout << "NUMBER OF PERMUTATIONS THAT SCORES " << n << " IS " << perms << ".\n";
        }

        
        for (int i = 0; i < 70; i++) cout << "*";
        cout << "\n";
        cin >> n;
    }

    cout << "END OF OUTPUT\n";
}
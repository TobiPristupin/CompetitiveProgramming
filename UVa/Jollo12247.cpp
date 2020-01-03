using namespace std;
#define ll long long
#include <bits/stdc++.h>

int solve(vector<int> &sister, vector<int> &prince){
    int optimal_deal = 1;
    do {
        do {
            
            int s = 0, p = 0;
            if (sister[0] > prince[0]) s++;
            else p++;

            if (sister[1] > prince[1]) s++;
            else p++;

            if (s == 2){
                return -1;
            } else if (p == 2){
                optimal_deal = max(1, optimal_deal);
            } else if (p == 1 && s == 1){
                optimal_deal = max(optimal_deal, sister[2] + 1);
            }

        } while (next_permutation(prince.begin(), prince.end()));
    } while (next_permutation(sister.begin(), sister.end()));

    return optimal_deal;
}

int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    while (a != 0){
        vector<int> sister = {a, b, c}, prince = {x, y};
        sort(sister.begin(), sister.end());
        sort(prince.begin(), prince.end());
        int deal = solve(sister, prince);
        while (deal == a || deal == b || deal == c || deal == x || deal == y){
            deal++;
        }
        if (deal > 52) cout << -1 << "\n";
        else cout << deal << "\n";
        
        cin >> a >> b >> c >> x >> y;
    }
}
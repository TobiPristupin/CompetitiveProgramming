using namespace std;
#define ll long long
#include <bits/stdc++.h>

struct Square {
    int row, col, pop;
};

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        vector<Square> city;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++){
            int r, c, v;
            cin >> r >> c >> v;
            city.push_back({r, c, v});
        }

        int best_cost = -1;
        vector<pair<int, int>> best_spots;
        for (int a = 0; a < 21 && best_cost != 0; a++){
            for (int b = a + 1; b < 22 && best_cost != 0; b++) {
                for (int c = b + 1; c < 23 && best_cost != 0; c++) {
                    for (int d = c + 1; d < 24 && best_cost != 0; d++){
                        for (int e = d + 1; e < 25 && best_cost != 0; e++){
                            vector<pair<int, int>> spots = {{a/5, a%5}, {b/5, b%5}, {c/5, c%5}, {d/5, d%5}, {e/5, e%5}};
                            int cost = 0;
                            for (Square sq : city){
                                int square_cost = INT_MAX;
                                for (auto loc : spots){
                                    square_cost = min(square_cost, sq.pop * (abs(sq.row - loc.first) + abs(sq.col - loc.second)));
                                }
                                cost += square_cost;
                            }
                            if (best_cost == -1 || cost < best_cost){
                                best_cost = cost;
                                best_spots = spots;
                            }  
                        }
                    }
                }
            }
        }

        for (int i = 0; i < 5; i++){
            cout << best_spots[i].first * 5 + best_spots[i].second;
            if (i != 4) cout << " ";  
        }
        cout << "\n";
    }
}
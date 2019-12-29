using namespace std;
#define ll long long
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n, budget, hotel, weeks;
    while (cin >> n >> budget >> hotel >> weeks){
        int min_cost = -1;
        for (int i = 0; i < hotel; i++){
            int price;
            bool available = false;
            cin >> price;
            for (int j = 0; j < weeks; j++){
                int beds;
                cin >> beds;
                if (beds >= n){
                    available = true;
                }
            }

            if (available){
                if (min_cost == -1 || price * n < min_cost){
                    min_cost = price * n;
                }
            }
        }

        if (min_cost == -1 || min_cost > budget) cout << "stay home\n";
        else cout << min_cost << "\n";
    }
}
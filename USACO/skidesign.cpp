/*
ID: tobiasp1
TASK: skidesign
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){ 
    freopen ("skidesign.in", "r", stdin);
    freopen ("skidesign.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, x;
    vector<ll> hills;
    cin >> n;
    while (cin >> x) hills.push_back(x);
    
    sort(hills.begin(), hills.end());
    if (hills.back() - hills.front() <= 17){
        cout << 0 << "\n";
        return 0;
    }

    ll low = hills.front(), high = hills.front() + 17;
    ll best_cost = LLONG_MAX;
    for (int i = 0; i < hills.back() - hills.front() - 17 + 1; i++){
        ll cost = 0;
        for (int j = 0; j < hills.size(); j++){
            if (hills[j] < low) cost += pow(low - hills[j], 2);
            else if (hills[j] > high) cost += pow(hills[j] - high, 2);
        }

        if (cost >= best_cost){
            break;
        }

        best_cost = min(cost, best_cost);
        low++;
        high++;
    }


    cout << best_cost << "\n";
    return 0;
}
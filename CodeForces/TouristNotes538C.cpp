using namespace std;
#define ll long long
#include <bits/stdc++.h>

int main(){
    ll n, m;
    cin >> n >> m;

    if (m > n){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    
    vector<vector<ll>> heights;
    ll d, h, best = 0;
    cin >> d >> h;
    if (d != 1){
        heights.push_back({1, h + d - 1});
    }
    heights.push_back({d, h});
    while (cin >> d >> h) heights.push_back({d, h});
    if (heights.back()[0] < n){
        heights.push_back({n, heights.back()[1] + (n - heights.back()[0])});
    }

    for (ll i = 0; i < heights.size(); i++){
        if (i == 0) {
            best = heights[i][1];
            continue;
        }

        vector<ll> last = heights[i - 1];
        vector<ll> curr = heights[i];
        if (curr[0] - last[0] < abs(curr[1] - last[1])){
            cout << "IMPOSSIBLE\n";
            return 0;
        }

        if (curr[1] >= last[1]){
            ll days_available = curr[0] - last[0] - (curr[1] - last[1]);
            best = max(best, curr[1] + (days_available / 2));
        } else {
            ll days_available = curr[0] - last[0] - (last[1] - curr[1]);
            best = max(best, last[1] + (days_available / 2));
        }
    }

    cout << best << "\n";
}
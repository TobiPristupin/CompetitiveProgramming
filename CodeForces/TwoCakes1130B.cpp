#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, a;
    cin >> n;
    vector<vector<ll>> tiers(2 * n, vector<ll>());
    for (int i = 0; i < 2 * n; i++){
        cin >> a;
        tiers.at(a).push_back(i);
    }
    
    ll x = 0, y = 0, steps = 0;
    for (int i = 1; i <= n; i++){
        ll a = tiers[i][0];
        ll b = tiers[i][1];
        steps += min(abs(x - a) + abs(y - b), abs(x - b) + abs(y - a));
        x = a;
        y = b;

    }

    cout << steps << "\n";

    return 0;
}
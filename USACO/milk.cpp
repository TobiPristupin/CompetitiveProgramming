/*
ID: tobiasp1
TASK: milk
LANG: C++                 
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    freopen ("milk.in", "r", stdin);
    freopen ("milk.out", "w", stdout);
    ll n, m; 
    vector<pair<ll, ll>> vec;
    cin >> n >> m;
    for (ll i = 0; i < m; i++){
        ll units, cost;
        cin >> cost >> units;
        vec.push_back(make_pair(cost, units)); 
    }

    sort(vec.begin(), vec.end());
    ll cost = 0;
    for (pair<ll, ll> farmer : vec){
        cost += min(n, farmer.second) * farmer.first;
        n -= min(n, farmer.second);
        if (n <= 0){
            break;
        }
    }

    cout << cost << "\n";
}
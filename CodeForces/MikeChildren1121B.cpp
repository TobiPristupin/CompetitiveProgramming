#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, c;
    vector<ll> candy;
    unordered_map<ll, ll> sums;
    cin >> n;
    while (cin >> c) candy.push_back(c);
    ll best = 0;
    for (ll x : candy){
        for (ll y : candy){
            if (x != y){
                sums[x + y]++;
                best = max(best, sums[x + y]);
            }
        }
    }

    cout << best / 2 << "\n";
    return 0;    
}
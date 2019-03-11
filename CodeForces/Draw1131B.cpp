#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, x, y;
    cin >> n;
    vector<pair<ll, ll>> scores;
    cin >> x >> y;
    scores.push_back(make_pair(x, y));
    while (cin >> x >> y){
        if (scores.back().first != x || scores.back().second != y){
            scores.push_back(make_pair(x, y));
        }
    }

    ll draws = 1, a = 0, b = 0;
    for (pair<ll, ll> s : scores){
        if (a < b){
            a += min(s.first - a, b - a);
            draws += (a == b ? 1 : 0);
        } else if (b < a){
            b += min(s.second - b, a - b);
            draws += (a == b ? 1 : 0);
        } 

        if (a == b){
            draws += min(s.first - a, s.second - b);
        }

        a = s.first;
        b = s.second;
    } 
    
    cout << draws << "\n";

    return 0;
}
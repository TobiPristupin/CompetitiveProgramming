/*
ID: tobiasp1
TASK: combo
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll circle_mod(ll x, ll m){
    if (x >= m){
        return (x % m) != 0 ? (x % m) : m;
    } else {
        while (x <= 0){
            x += m;
        }
        return x;
    }
}

int main(){
    freopen ("combo.in", "r", stdin);
    freopen ("combo.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    int n, a, b, c, d, e, f;
    cin >> n >> a >> b >> c >> d >> e >> f;
    unordered_set<int> sols;
    for (int i = -2; i <= 2; i++){
        for (int j = -2; j <= 2; j++){
            for (int k = -2; k <= 2; k++){
                int aa = circle_mod(a + i, n), 
                bb = circle_mod(b + j, n), 
                cc = circle_mod(c + k, n),
                dd = circle_mod(d + i, n), 
                ee = circle_mod(e + j, n), 
                ff = circle_mod(f + k, n);
                sols.insert(aa * 100 + bb * 10 + cc);
                sols.insert(dd * 100 + ee * 10 + ff);
            }
        }
    }
    cout << sols.size() << "\n";
    return 0;
} 

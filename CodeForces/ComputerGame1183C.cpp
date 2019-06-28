using namespace std;
#define ll long long
#include <bits/stdc++.h>

int main(){
    ll q;
    cin >> q;
    while (q--){
        ll k, n, a, b;
        cin >> k >> n >> a >> b;
        k--;
        if (k / static_cast<double>(b) < n){
            cout << -1 << "\n"; 
            continue;
        }

        ll x = (b*n - k) / (b - a);
        x = abs(x);
        cout << min(x, n) << "\n";


    }
    return 0;
}
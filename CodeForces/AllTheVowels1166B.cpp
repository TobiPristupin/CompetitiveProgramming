#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll k, n = 0, m = 0;
    cin >> k;
    for (int i = 5; i <= k / 5; i++){
        if (k % i == 0 && k / i >= 5){
            n = i;
            m = k / i;
        }
    }

    if (n == 0 && m == 0){
        cout << -1 << endl;
        return 0;
    }

    string vowels = "aeiou", ans = "";
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            ans += vowels.substr((i + j) % 5, 1);
        }
    }

    cout << ans << endl;
}
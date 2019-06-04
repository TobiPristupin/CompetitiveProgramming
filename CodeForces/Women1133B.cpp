#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, k, x;
    cin >> n >> k;
    vector<ll> candy(k);
    while (cin >> x) candy[x % k] += 1;
    ll pairs = 0;
    pairs += candy[0] / 2;
    if (k % 2 == 0) pairs += candy[k / 2] / 2;
    ll lim = (k % 2 == 0) ? k / 2 - 1 : k / 2;
    for (int i = 1; i <= lim; i++){
        pairs += min(candy[i], candy[k - i]);
    }

    cout << pairs * 2 << endl;
}
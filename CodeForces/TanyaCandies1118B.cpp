#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    vector<ll> even(1, 0), odd(1, 0);
    ll n, x;
    cin >> n;

    for (int i = 1; i <= n; i++){
        cin >> x;
        if (i % 2 == 0){
            even.push_back(even.back() + x);
            odd.push_back(odd.back());
        } else {
            odd.push_back(odd.back() + x);
            even.push_back(even.back());
        }
    }

    int good = 0, sum_even = 0, sum_odd = 0;
    for (int rem = 1; rem <= n; rem++){
        if (rem % 2 == 1){
            sum_even = even.at(rem) + odd.back() - odd.at(rem);
            sum_odd = odd.at(rem - 1) + even.back() - even.at(rem);
        } else {
            sum_even = even.at(rem - 1) + odd.back() - odd.at(rem);
            sum_odd = odd.at(rem) + even.back() - even.at(rem);
        }
        good += sum_even == sum_odd;
    }

    cout << good << endl;

    return 0;
}
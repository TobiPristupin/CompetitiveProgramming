#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll smallest_divisor(ll n){
    for (ll i = 3; i * i <= n; i += 2){
        if (n % i == 0){
            return i;
        }
    }

    return n;
}

int main(){
    ll n;
    cin >> n;
    ll substractions = 0;
    if (n % 2 != 0){
        n -= smallest_divisor(n);
        substractions++;
    }
    
    cout << substractions + (n / 2) << endl;
    return 0;
}
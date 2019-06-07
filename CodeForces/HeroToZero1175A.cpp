using namespace std;
#define ll long long
#include <bits/stdc++.h>

int main(){
    ll t;
    cin >> t;
    for (int i = 0; i < t; i++){
        ll n, k;
        cin >> n >> k;
        ll steps = 0;
        while (n != 0){
            if (n % k == 0){
                n /= k;
                steps++;
            } else {
                steps += n % k;
                n -= n % k;
            }
        }

        cout << steps << "\n";
    }
}
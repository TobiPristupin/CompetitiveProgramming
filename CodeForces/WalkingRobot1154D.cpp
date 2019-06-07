using namespace std;
#define ll long long
#include <bits/stdc++.h>

int main(){
    ll n, b, a;
    cin >> n >> b >> a;
    ll max_a = a;
    vector<int> sunlight(n);
    for (ll i = 0; i < n; i++) cin >> sunlight[i];
    
    ll pos = 0;
    while (pos != n){
        if (a == 0 && b == 0){
            cout << pos << "\n";
            return 0;
        }

        if (sunlight[pos] == 1){
            if (b == 0 || a == max_a){
                a--;
            } else {
                b--;
                a++;
            }
        } else {
            if (a > 0){
                a--;
            } else {
                b--;
            }
        }

        pos++;
    }

    cout << pos << "\n";
}
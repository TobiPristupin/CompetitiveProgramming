#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
    ll n, s, keg;
    vector<ll> kegs;
    cin >> n >> s;
    while (cin >> keg){
        kegs.push_back(keg);
    }

    ll smallest = *min_element(kegs.begin(), kegs.end());
    for (int i = 0; i < kegs.size(); i++){
        s -= kegs[i] - smallest;
        kegs[i] = smallest;
        if (s <= 0){
            cout << smallest << "\n";
            return 0;
        }
    }
    ll x = kegs[0] - ((s + n - 1) / n);
    cout << (x >= 0 ? x : -1) << "\n";
}


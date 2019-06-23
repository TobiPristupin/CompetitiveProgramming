using namespace std;
#define ll long long
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<ll> warriors(n), attacks(q);
    for (int i = 0; i < n; i++) {
        cin >> warriors[i];
        warriors[i] += (i >= 1 ? warriors[i - 1] : 0); 
    }
    for (int i = 0; i < q; i++) cin >> attacks[i];

    ll arrows = 0;
    for (ll k : attacks){
        arrows += k;
        if (arrows >= warriors.back()){
            arrows = 0;
        }

        auto it = upper_bound(warriors.begin(), warriors.end(), arrows);
        cout << warriors.size() - distance(warriors.begin(), it) << "\n"; 
    }
}
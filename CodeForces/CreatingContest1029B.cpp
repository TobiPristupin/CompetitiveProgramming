#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, x;
    vector<ll> probs;
    cin >> n;
    while (cin >> x) probs.push_back(x);

    ll longest = 1, curr = 1;
    for (ll i = 0; i < probs.size() - 1; i++){
        if (probs[i] * 2 >= probs[i + 1]){
            curr++;
            longest = max(curr, longest);
        } else {
            longest = max(curr, longest);
            curr = 1;
        }
    }

    cout << longest << "\n";
}

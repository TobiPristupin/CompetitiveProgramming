#include <bits/stdc++.h>
#define ll long long
using namespace std;

unordered_set<int> primes {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};


int main(){
    ll n;
    int a;
    vector<int> powers;
    cin >> n;
    while (cin >> a) powers.push_back(a);

    sort(powers.begin(), powers.end());
    int biggest_change = 0;
    for (ll i = powers.size() - 1; i >= 0; i--){
        for (int d = 1; d <= powers[i]; d++){
            if (powers[i] % d == 0){
                int change = powers[i] - powers[i] / d - powers[0] * d + powers[0];
                biggest_change = max(change, biggest_change);
            }
        }
        
    }

    cout << accumulate(powers.begin(), powers.end(), 0) - biggest_change << "\n";
    
}
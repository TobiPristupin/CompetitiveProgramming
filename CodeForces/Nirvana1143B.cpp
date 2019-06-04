#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    string n;
    cin >> n;
    ll best = pow(9, n.length() - 1);
    for (int set = 0; set <= n.length(); set++){
        ll x = 1;
        for (int i = 0; i < n.length(); i++){
            if (i < set) x *= stoi(n.substr(i, 1));
            else if (i == set) x*= stoi(n.substr(i, 1)) - 1;
            else x *= 9;
        }
        best = max(x, best);
    }

    cout << best << endl;
}
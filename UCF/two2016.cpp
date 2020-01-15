using namespace std;
#define ll long long
#include <bits/stdc++.h>

bool power_of_two(ll x){
    return ((x & (x - 1)) == 0);
}

bool split(ll x){
    string s = to_string(x);
    for (int i = 1; i < s.length(); i++){
        string a = s.substr(0, i), b = s.substr(i, s.length());
        if (power_of_two(stoll(a)) && power_of_two(stoll(b))){
            return true;
        }
    }

    return false;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        bool exit = false;
        for (ll p = 0; p <= 62 && !exit; p++){
            for (ll q = 62; q >= 0 && !exit; q--){
                ll x = pow(2, p) - pow(2, q);
                if (x > n && split(x)){
                    cout << "The next hyper-even after " << n << " is " << x  << "\n";
                    exit = true;
                }
            }
        }
    }
}
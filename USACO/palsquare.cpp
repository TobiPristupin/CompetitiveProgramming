/*
ID: tobiasp1
TASK: palsquare
LANG: C++                 
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool palindrome(string s){
    for (int c = 0; c < s.length() / 2; c++){
        if (s[c] != s[s.length() - c - 1]){
            return false;
        }
    }

    return true;
}

string to_base(ll x, ll b){
    string letters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string digits = "";
    lldiv_t divmod;

    if (b == 1){
        for (int i = 0; i < x; i++){
            digits += "1";
        }
        return digits;
    }

    do {
        divmod = div(x, b);
        x = divmod.quot;
        digits += letters.at(divmod.rem);
    } while (x > 0);

    reverse(digits.begin(), digits.end());
    return digits;
}

int main(){
    freopen ("palsquare.in", "r", stdin);
    freopen ("palsquare.out", "w", stdout);
    int b;
    cin >> b;

    for (int n = 1; n <= 300; n++){

        if (palindrome(to_base(n * n, b))){
            cout << to_base(n, b) << " " << to_base(n * n, b) << "\n";
        } 
    }

    return 0;
}
/*
ID: tobiasp1
TASK: dualpal
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
    string digits = "";
    lldiv_t divmod;
    do {
        divmod = div(x, b);
        x = divmod.quot;
        digits += to_string(divmod.rem);
        
    } while (x > 0);

    reverse(digits.begin(), digits.end());
    return digits;
}

bool is_dualpal(int s){
    int c = 0;
    for (int b = 2; b <= 10; b++){
        if (palindrome(to_base(s, b))){
            c++;
            if (c == 2){
                return true;
            }
        }
    }

    return false;
}


int main(){
    freopen ("dualpal.in", "r", stdin);
    freopen ("dualpal.out", "w", stdout);
    int n, s, c = 0;
    cin >> n >> s;
    s++;
    while (c < n){
        if (is_dualpal(s)){
            cout << s << "\n";
            c++;
        }
        s++;
    }
}
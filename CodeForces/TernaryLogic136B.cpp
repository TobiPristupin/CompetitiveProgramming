#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll to_ternary(ll x){
    string digits = "";
    lldiv_t divmod;
    do {
        divmod = div(x, 3LL);
        x = divmod.quot;
        digits += to_string(divmod.rem);
        
    } while (x > 0);

    reverse(digits.begin(), digits.end());
    return stoll(digits);
}

ll from_ternary(ll x){
    ll sum = 0, digit = 0;
    do {
        sum += (x % 10) * pow(3, digit);
        digit++;
        x /= 10;
    } while (x > 0);
    
    return sum;
}

int main(){
    ll inta, intc;
    cin >> inta >> intc;
    inta = to_ternary(inta);
    intc = to_ternary(intc);
    string a = to_string(inta), c = to_string(intc);
    while (a.length() < c.length()) a = "0" + a;
    while (c.length() < a.length()) c = "0" + c;
    
    string b = "";
    for (ll i = 0; i < a.length(); i++){
        int cdigit = stoi(c.substr(i, 1));
        int adigit =  stoi(a.substr(i, 1));
    
        if (cdigit < adigit){
            int add = 0;
            for (int x : {1, 2, 3}){
                if ((adigit + x) % 3 ==  cdigit){
                    add = x;
                    break;
                }
            }
            b += to_string(add);
        } else {
            b +=  to_string(cdigit - adigit);
        }
    }
    
    cout << from_ternary(stoll(b)) << "\n";
    return 0;
}
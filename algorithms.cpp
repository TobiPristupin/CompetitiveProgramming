#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

/*
Properties of mod:
(a+b) % m = (a mod m + b mod m) mod m
(a*b) % m = (a mod m * b mod m) mod m
*/

void fast_io(){
    ios::sync_with_stdio(0);
    cin.tie(0);
}

//string to binary using mod properties to avoid overflow. Remember to mod again if required
long long string_to_binary_mod(string bin, long long mod){
    long long sum = 0;
    reverse(bin.begin(), bin.end());
    for(int i = 0; i < bin.length(); i++){
        sum += fmod((stoll(bin.substr(i, 1)) * pow(2, i)), mod);
    }

    return sum;
}

//Example convert to base
long long to_ternary(long long x){
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

//Example convert from base to decimal
long from_ternary(long x){
    long sum = 0, digit = 0;
    do {
        sum += (x % 10) * pow(3, digit);
        digit++;
        x /= 10;
    } while (x > 0);
    
    return sum;
}
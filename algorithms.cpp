#include <bits/stdc++.h>

using namespace std;
#define ll long long


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
ll string_to_binary_mod(string bin, ll mod){
    ll sum = 0;
    reverse(bin.begin(), bin.end());
    for(int i = 0; i < bin.length(); i++){
        sum += fmod((stoll(bin.substr(i, 1)) * pow(2, i)), mod);
    }

    return sum;
}

//Example convert to base
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

//Example convert from base to decimal
ll from_ternary(ll x){
    ll sum = 0, digit = 0;
    do {
        sum += (x % 10) * pow(3, digit);
        digit++;
        x /= 10;
    } while (x > 0);
    
    return sum;
}

vector<ll> sieve_erastothenes(unsigned ll limit){
    vector<bool> prime(limit, true);
    for (int p = 2; p*p <= limit; p++){
        if (prime[p]){
            for (int i = p*p; i <= limit; i += p){
                prime[i] = false;
            }
        }
    }

    vector<ll> ans;
    for (int i = 2; i <= limit; i++){
        if (prime[i]){
            ans.push_back(i);
        }
    }

    return ans;
}

bool is_prime(ll n) { 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
    if (n % 2 == 0 || n % 3 == 0) return false; 
  
    for (ll i = 5; i * i <= n; i += 6) 
        if (n % i == 0 || n % (i+2) == 0) 
           return false; 
  
    return true; 
} 

int main(){
    cout << is_prime(pow(10, 10) - 1) << endl;
}
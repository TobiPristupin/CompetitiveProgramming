#include <bits/stdc++.h>
using namespace std;
#define ll long long

// int main(){
//     ios::sync_with_stdio(0), cin.tie(0);
//     return 0;
// } 

/*
Properties of mod:
(a+b) % m = (a mod m + b mod m) mod m
(a*b) % m = (a mod m * b mod m) mod m
*/


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

ll binary_search(vector<ll> vec, ll x){
    ll lo = 0, hi = vec.size() - 1, mid;
    while (lo <= hi){
        mid = (lo + hi) / 2;
        if (vec.at(mid) < x){
            lo = mid + 1;
        } else if (vec.at(mid) > x){
            hi = mid - 1;
        } else {
            return mid;
        }
    }

    return -1;
}

ll binary_insertion_pos(vector<ll> vec, ll x){
    ll lo = 0, hi = vec.size() - 1, mid;
    while (lo <= hi){
        mid = (lo + hi) / 2;
        if (vec.at(mid) < x){
            lo = mid + 1;
        } else if (vec.at(mid) > x){
            hi = mid - 1;
        } else {
            return mid;
        }
    }

    return lo;
}

bool palindrome(ll x){
    string s = to_string(x);
    for (int c = 0; c < s.length() / 2; c++){
        if (s[c] != s[s.length() - c - 1]){
            return false;
        }
    }

    return true;
}

bool valid_parenthesis(string s){
    stack<char> stak;
    vector<char> opening = {'('}, closing = {')'};
    for (char c : s){
        if (find(opening.begin(), opening.end(), c) != opening.end()){
            stak.push(c);
        } else if (find(closing.begin(), closing.end(), c) != closing.end()){
            int index = distance(find(closing.begin(), closing.end(), c), closing.begin());
            if (stak.empty() || stak.top() != opening[index]){
                return false;
            }
            stak.pop();
        }
    }

    return stak.empty();
}

int main(){
    vector<ll> vec {1, 2, 3, 4, 5, 6, 7, 8};
    cout << valid_parenthesis("))") << endl;
}
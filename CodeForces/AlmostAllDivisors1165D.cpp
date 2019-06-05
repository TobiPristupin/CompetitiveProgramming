using namespace std;
#define ll long long
#include <bits/stdc++.h>

vector<ll> primes;

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

int num_divisors(ll n){
    int total = 1;
    for (ll p : primes){
        int count = 0;
        while (n % p == 0){
            n = n / p;
            count++;
        }
        total *= (count + 1);
    }

    return total;
}

int main(){
    primes = sieve_erastothenes(pow(10, 6));
    ll t;
    cin >> t;
    for (int i = 0; i < t; i++){
        ll n;
        cin >> n;
        vector<ll> divisors(n, 0);
        for (int j = 0; j < n; j++){
            cin >> divisors[j];
        }

        sort(divisors.begin(), divisors.end());
        ll guess = divisors.front() * divisors.back();
        ll limit = divisors.size() % 2 == 0 ? divisors.size() / 2 : ((signed) divisors.size()) / 2 + 1;
        for (int j = 0; j < limit; j++){
            if (divisors[j] * divisors[divisors.size() - j - 1] != guess){
                guess = -1;
                break;
            }
        }

        if (guess != -1 && num_divisors(guess) - 2 != divisors.size()){
            guess = -1;
        }

        cout << guess << "\n";
    }
}

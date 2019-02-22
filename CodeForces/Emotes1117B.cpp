#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);

    ll n, m, k, x, first = 0, second = 0;
    vector<ll> vec;
    cin >> n >> m >> k;
    while (cin >> x){
        if (x >= first){
            second = first;
            first = x;
        } else if (x > second){
            second = x;
        }
    }
    
    ll sum = first * k + second;
    cout << (m / (k + 1)) * sum + (m % (k + 1)) * first << "\n";
}
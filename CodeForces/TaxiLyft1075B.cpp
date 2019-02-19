#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, m, x;
    cin >> n >> m;
    vector<ll> people, is_taxi, taxis, riders;
    unordered_map<ll, ll> taxi_customers;
    for (ll i = 0; i < n + m; i++) cin >> x, people.push_back(x);
    for (ll i = 0; i < n + m; i++) cin >> x, is_taxi.push_back(x);
    for (ll i = 0; i < n + m; i++){
        if (is_taxi[i]){
            taxis.push_back(people[i]);
            taxi_customers[people[i]] = 0;
        } else {
            riders.push_back(people[i]);
        }
    }

    if (taxis.size() == 1){
        cout << riders.size() << "\n";
        return 0;
    }

    ll taxi = taxis[0], next_taxi = taxis[1], j = 0;
    for (ll i = 0; i < riders.size(); i++){
        ll rider = riders[i];
        while (abs(next_taxi - rider) < abs(taxi - rider)){
            j++;
            taxi = next_taxi;
            next_taxi = taxis[j + 1];
        }

        taxi_customers[taxi] +=  1;
    }

    for (ll taxi : taxis){
        cout << taxi_customers[taxi] << " ";
    } 
    
    cout << endl;
    return 0;
}
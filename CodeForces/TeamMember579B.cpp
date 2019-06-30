using namespace std;
#define ll long long
#include <bits/stdc++.h>
 
int main(){
    ll n;
    cin >> n;
    map<ll, vector<ll>> strengths;
    vector<ll> teams(2*n);
    for (int i = 1; i <= 2*n; i++){
        for (int j = 1; j <= i-1; j++){
            ll a;
            cin >> a;
            strengths.insert({a, {i, j}});
        }
    }
 

    for (auto it = strengths.rbegin(); it != strengths.rend(); ++it){
        vector<ll> best_team = it->second;
        if (teams[best_team[0]-1] == 0 && teams[best_team[1]-1]==0){
            teams[best_team[0]-1] = best_team[1];
            teams[best_team[1]-1] = best_team[0];
        }
    }

  
    for (auto x : teams) cout << x << " ";
    cout << "\n";
}
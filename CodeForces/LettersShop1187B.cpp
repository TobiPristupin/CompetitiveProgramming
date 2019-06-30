using namespace std;
#define ll long long
#include <bits/stdc++.h>

int main(){
    ll n, m;
    string s;
    cin >> n >> s >> m;
    vector<string> names(m);
    for (int i = 0; i < m; i++) cin >> names[i];

    unordered_map<string, vector<ll>> letters; 
    for (int i = 0; i < n; i++) letters[s.substr(i, 1)].push_back(i);
    
    for (string &t : names){
        unordered_map<string, ll> counter;
        for (int i = 0; i < t.length(); i++) counter[t.substr(i, 1)]++;
        
        ll cost = 0;
        for (auto &letter : counter){
            cost = max(cost, letters[letter.first][letter.second - 1] + 1);
        }
        cout << cost << "\n";
    }
    
}
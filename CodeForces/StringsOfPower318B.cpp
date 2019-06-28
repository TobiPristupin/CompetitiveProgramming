using namespace std;
#define ll long long
#include <bits/stdc++.h>

int main(){
    string s;
    cin >> s;
    ll ans = 0;
    vector<int> heavy, metal;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == 'h' && s.substr(i, 5) == "heavy"){
            heavy.push_back(i);
            i += 4;
        } else if (s[i] == 'm' && s.substr(i, 5) == "metal"){
            metal.push_back(i);
            i += 4;
        }
    }

    for (int h : heavy){
        auto it = upper_bound(metal.begin(), metal.end(), h);
        ans +=  distance(it, metal.end());
    }

    cout << ans << endl;
}
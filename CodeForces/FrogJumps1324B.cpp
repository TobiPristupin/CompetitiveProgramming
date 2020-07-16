using namespace std;
#define ll long long
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        s = "R" + s + "R";
        
        vector<int> rights;
        for (int c = 0; c < s.length(); c++){
            if (s[c] == 'R') rights.push_back(c);
        }
        
        adjacent_difference(rights.begin(), rights.end(), rights.begin());
        cout << *max_element(rights.begin(), rights.end()) << "\n";
    }
}
using namespace std;
#define ll long long
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    while (n--){
        int cost = 0;
        int k;
        cin >> k;
        unordered_map<char, int> values;
        while (k--){
            char c;
            int v;
            cin >> c >> v;
            values[c] = v;
        }

        int m;
        cin >> m;
        cin.ignore();
        while (m--){
            string l;
            getline(cin, l);
            for (char &c : l){
                cost += values[c];
            }   
        }

        cout << setprecision(2) << fixed  << cost / 100.0 <<  "$\n"; 
    }

}
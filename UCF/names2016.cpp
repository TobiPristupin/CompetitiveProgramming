using namespace std;
#define ll long long
#include <bits/stdc++.h>

bool vowel(char c){
    set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    return vowels.find(c) != vowels.end();
}

set<string> solve(string a, string b){
    set<string> sols;
    for (int i = a.size() - 1; i >= 1; i--){
        string start = a.substr(0, i);
        for (int j = 1; j < b.size(); j++){
            string end = b.substr(j);           
            if ((vowel(start.back()) && !vowel(end.front())) || (!vowel(start.back()) && vowel(end.front()))){
                sols.insert(start + end);
            }
        }
    }
    return sols;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n; 
    for (int tcase = 1; tcase <= n; tcase++){
        string a, b;
        cin >> a >> b;
        set<string> names1 = solve(a, b);
        set<string> names2 = solve(b, a);
        names1.insert(names2.begin(), names2.end());
        
        cout << "Couple #" << tcase << ": " << names1.size() << " possible names\n";
        for (auto x : names1) cout << x << "\n";
        if (tcase < n) cout << "\n";
    }
}
/*
ID: tobiasp1
TASK: barn1
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    freopen ("barn1.in", "r", stdin);
    freopen ("barn1.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    int m, s, c, x;
    vector<int> cows; 
    vector<int> spaces;
    cin >> m >> s >> c;
    while (cin >> x) cows.push_back(x);
    sort(cows.begin(), cows.end());

    for (int i = 0; i < cows.size() - 1; i++){
        spaces.push_back(cows.at(i + 1) - cows.at(i));
    }

    sort(spaces.rbegin(), spaces.rend());
    int covered = cows.back() - cows.front() + 1;
    for (int i = 0; i < m - 1 && i < spaces.size(); i++){
        covered -= spaces.at(i) - 1;
    }

    cout << covered << "\n";

    return 0;
} 

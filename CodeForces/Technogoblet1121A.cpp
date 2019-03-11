#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, k, x;
    cin >> n >> m >> k;
    vector<pair<int, int>> studs;
    vector<int> schools(m, 0);
    for (int i = 0; i < n; i++) cin >> x, studs.push_back(make_pair(x, -1));
    for (int i = 0; i < n; i++){
        cin >> x;
        studs[i].second = x - 1;
        schools[x - 1] = max(schools[x - 1], studs[i].first);
    }

    int teams = 0;
    for (int i = 0; i < k; i++){
        cin >> x;
        if (studs[x - 1].first != schools[studs[x - 1].second]){
            teams++;
        }
    }

    cout << teams << "\n";


    return 0;
}
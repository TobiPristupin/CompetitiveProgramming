using namespace std;
#define ll long long
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    for (int tcase = 1; tcase <= t; tcase++){
        int n;
        cin >> n;
        vector<int> speeds(n);
        for (int i = 0; i < n; i++){
            cin >> speeds[i];
        }

        cout << "Case " << tcase << ": " << *max_element(speeds.begin(), speeds.end()) << "\n";
    }
}
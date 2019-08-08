using namespace std;
#define ll long long
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int f, r;
    while (cin >> f >> r){
        vector<double> front(f), rear(r), ratios;
        for (int i = 0; i < f; i++) cin >> front[i];
        for (int i = 0; i < r; i++) cin >> rear[i];
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < f; j++) {
                ratios.push_back(rear[i]/front[j]);
            }
        }

        sort(ratios.begin(), ratios.end());
        
        double ans = 0;
        for (int i = 0; i < ratios.size() - 1; i++) {
            ans = max(ans, ratios[i + 1] / ratios[i]);
        }

        cout << fixed << setprecision(2) << ans << "\n";
    }
}
using namespace std;
#define ll long long
#include <bits/stdc++.h>

bool simulate(int k, vector<int> &rugs){
    for (int i = 0; i < rugs.size() - 1; i++){
        if (rugs[i + 1] - rugs[i] > k){
            return false;
        } else if (rugs[i + 1] - rugs[i] == k){
            k -= 1;
        }
    }

    return true;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    for (int tcase = 1; tcase <= t; tcase++){
        int n;
        cin >> n;
        vector<int> rugs(n+1);
        rugs[0] = 0; //Floor
        for (int i = 1; i <= n; i++) cin >> rugs[i];

        int lo = 0, hi = pow(10, 7) + 1;
        int k = (lo + hi) / 2;
        int best = hi;
        int tries = 0;
        while (tries <= 24){
            if (simulate(k, rugs)){
                best = min(best, k);
                hi = k - 1;
            } else {
                lo = k + 1;
            }
            tries++;
            k = (lo + hi) / 2;
        }

        cout << "Case " << tcase << ": " << best << "\n";
    }
}
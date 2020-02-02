using namespace std;
#define ll long long
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    while (cin >> n){
        vector<int> weights(pow(2, n));
        vector<int> potency(pow(2, n), 0);
        for (int i = 0; i < pow(2, n); i++) cin >> weights[i];

        for (int i = 0; i < weights.size(); i++){
            bitset<14> bit(i);
            for (int j = 0; j < n; j++){
                bit.flip(j);
                potency[i] += weights[bit.to_ullong()];
                bit.flip(j);
            }
        }
        
        int ans = 0;
        for (int i = 0; i < potency.size(); i++){
            bitset<14> bit(i);
            for (int j = 0; j < n; j++){
                bit.flip(j);
                ans = max(ans, potency[i] + potency[bit.to_ullong()]);
                bit.flip(j);
            }
        }

        cout << ans << endl;
    }
}
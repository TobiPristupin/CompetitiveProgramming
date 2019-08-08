using namespace std;
#define ll long long
#include <bits/stdc++.h>



// int eval(int n){

// }

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int i;
        cin >> i;
        vector<int> coeffs(i+1, 0);
        for (int j = 0; j <= i; j++) cin >> coeffs[j];
        int d, k;
        cin >> d >> k;
        ll n = 1, cum_index = 0;
        for (; n*d <= 1000000; n++){
            cum_index += n * d;
            if (cum_index >= k){
                break;
            }
        }
        
        ll ans = 0;
        for (int c = 0; c < coeffs.size(); c++){
            ans += coeffs[c] * pow(n, c);
        }

        cout << ans << "\n";
    }
}
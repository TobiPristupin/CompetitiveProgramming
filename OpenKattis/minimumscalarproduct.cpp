using namespace std;
#define ll long long
#include <bits/stdc++.h>

int main(){
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++){
        int n;
        cin >> n;
        vector<ll> x(n), y(n);
        for (int i = 0; i < n; i++) cin >> x[i];
        for (int i = 0; i < n; i++) cin >> y[i];

        sort(x.begin(), x.end());
        sort(y.begin(), y.end(), greater<int>());

        ll product = 0;
        for (int i = 0; i < n; i++){
            product += x[i] * y[i];
        }

        cout << "Case #" << t << ": " << product << "\n";
    }
}
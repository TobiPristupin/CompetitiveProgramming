using namespace std;
#define ll long long
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n, d, r;
    cin >> n >> d >> r;
    while (!(n==0 && d==0 && r==0)){
        vector<int> morning(n), evening(n);
        for (int i = 0; i < n; i++) cin >> morning[i];
        for (int i = 0; i < n; i++) cin >> evening[i];
        sort(morning.begin(), morning.end());
        sort(evening.begin(), evening.end(), greater<int>());
        int ans = 0;
        for (int i = 0; i < n; i++){
            ans += max(morning[i] + evening[i] - d, 0) * r;
        }
        cout << ans << "\n";
        cin >> n >> d >> r;
    }
}
using namespace std;
#define ll long long
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        bool found = false;
        for (int i = 1; i < n - 1; i++){
            vector<bool> left(n+1, false), right(n+1, false) ;
            
            for (int j = i - 1; j >= 0; j--) left[arr[j]] = true;
            for (int j = i + 1; j < n; j++) right[arr[j]] = true;

            for (int k = 0; k <= n; k++){
                if (left[k] && right[k]){
                    cout << "YES\n";
                    found = true;
                    break;
                }
            }

            if (found) break;
        }

        if (!found) {
            cout << "NO\n";
        }
    }
}
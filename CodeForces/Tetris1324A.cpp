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
        vector<int> heights(n);
        for (int i = 0; i < n; i++) cin >> heights[i];
        int min = *min_element(heights.begin(), heights.end());
        for (int i = 0; i < n; i++) heights[i] -= min;

        bool found = false;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (heights[i] % 2 != heights[j] % 2){
                    cout << "NO\n";
                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        if (!found) cout << "YES\n";
    }
}
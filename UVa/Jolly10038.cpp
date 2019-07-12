using namespace std;
#define ll long long
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    while (cin >> n){
        unordered_set<int> seen;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        for (int i = 0; i < n - 1; i++){
            if (abs(arr[i] - arr[i + 1]) >= 1 && abs(arr[i] - arr[i + 1]) <= n-1){
                seen.insert(abs(arr[i] - arr[i + 1]));
            }
        }

        cout << (seen.size() == n-1 ? "Jolly" : "Not jolly") << "\n";
    }
}
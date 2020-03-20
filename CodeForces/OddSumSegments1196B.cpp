using namespace std;
#define ll long long
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int q;
    cin >> q;
    while (q--){
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        int odds = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (arr[i] % 2 == 1) odds++;
        }

        if (odds < k || (odds - k + 1) % 2 == 0) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        vector<int> lengths(k-1, 1);
        lengths.push_back(odds - k + 1);
        int length_idx = 0;
        for (int i = 0; i < n; i++){
            if (arr[i] % 2 == 1) {
                lengths[length_idx]--;
                if (lengths[length_idx] == 0) {
                    if (length_idx == lengths.size() - 1){
                        cout << n;
                        break;
                    } else {
                        cout << i + 1 << " ";
                        length_idx++;
                    }
                }
            }
        }
        cout << "\n";

        

    }
}
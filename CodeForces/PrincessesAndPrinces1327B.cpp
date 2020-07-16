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
        vector<bool> princes(n, true);
        vector<vector<int>> lists(n, vector<int>());
        int need_optimization = -1;
        for (int i = 0; i < n; i++){
            int k;
            cin >> k;
            for (int j = 0; j < k; j++) {
                int x;
                cin >> x;
                lists[i].push_back(x-1);
            }
        }

        for (int i = 0; i < n; i++){
            bool found = false;
            for (int p : lists[i]){
                if (princes[p]){
                    princes[p] = false;
                    found = true;
                    break;
                }
            }

            if (!found) need_optimization = i;
            
        }

        if (need_optimization == -1){
            cout << "OPTIMAL\n";
            continue;
        }


        bool found = false;
        for (int p = 0; p < n; p++){
            if (princes[p]){
                found = true;
                cout << "IMPROVE\n" << need_optimization + 1 << " " << p + 1 << "\n";
                break;
            }
        }

        if (!found) cout << "OPTIMAL\n";

    }
}
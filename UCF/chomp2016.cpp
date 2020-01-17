using namespace std;
#define ll long long
#include <bits/stdc++.h>

struct chain {
    int start, end, sum;
};

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int p;
    cin >> p;
    for (int tcase = 1; tcase <= p; tcase++){
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        int total_sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            total_sum += arr[i];
        }

        int ans = 0;
        vector<chain> chains;
        for (int i = 0; i < n; i++){
            for (int j = i; j < n; j++){
                int sum = accumulate(arr.begin() + i, arr.begin() + j + 1, 0);
                chains.push_back({i, j, sum});
            }
        }

        // for (auto x : chains) cout << x.start << " " << x.end << " " << x.sum << endl;
        // cout << endl;

        for (chain x : chains){
            for (chain y : chains){
                if ((total_sum - x.sum - y.sum) % k == total_sum % k){
                    if (y.start - x.end >= 2){
                        ans++;
                    }
                }
            }
        }

        cout << "Plate #" << tcase << ": " << ans << "\n";

    }
}




 // for (int back = 0; back < n; back++){
        //     for (int i = 0; back + i < n; i++){
        //         int sum_back = accumulate(arr.begin() + back, arr.begin() + back + i + 1, 0);
                
        //         for (int front = back + i + 2; front < n; front++){
        //             for (int j = 0; front + j < n; j++){
                        
        //                 int sum_front = accumulate(arr.begin() + front, arr.begin() + front + j + 1, 0);
                        
        //                 if ((sum - sum_back - sum_front) % k == sum % k){
        //                     ans++;
        //                 }

        //                 // for (int k = back; k <= back + i; k++){
        //                 //     cout << arr[k]  << " ";
        //                 // }
        //                 // cout << " -- " << sum_back << " ";
        //                 // cout << "  |   ";
        //                 // for (int k = front; k <= front + j; k++){
        //                 //     cout << arr[k] << " ";
        //                 // }
        //                 // cout << " -- " << sum_front << " ";

        //                 // cout << endl;
        //             }
        //         }
        //     }
        // }
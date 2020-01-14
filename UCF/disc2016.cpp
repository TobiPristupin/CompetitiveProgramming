using namespace std;
#define ll long long
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    freopen ("disc.out", "w", stdout);
    int t;
    cin >> t;
    int tcase = 1;
    while (t--){
        int n;
        cin >> n;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];
        sort(vec.begin(), vec.end());

        int s = 0;
        do {
            int temp = 0;
            for (int i = 0; i + 1< n; i++){
                temp += abs(vec[i] - vec[i + 1]);
            }
            s = max(s, temp);
        } while (next_permutation(vec.begin(), vec.end()));

        cout << "Wave #" << tcase << ": " << s << "\n";
        tcase++;
    }
}
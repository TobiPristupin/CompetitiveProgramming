#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k, x;
    cin >> n >> k;
    vector<int> problems(n), start_testing(n), processes(k);
    vector<bool> used(n, false);
    for (int i = 0; i < n; i++){
        cin >> x;
        problems[i] = x;
        auto min = min_element(processes.begin(), processes.end());
        start_testing[i] = *min;
        *min += x;
    } 

    int tested = 0, percent = 0, t = 0, interesting = 0;
    while (tested != n){
        for (int i = 0; i < n; i++){
            if (t >= start_testing[i] && t <= start_testing[i] + problems[i]){
                if (!used[i] && t - start_testing[i] == percent && percent != 0){
                    interesting++;
                    used[i] = true;
                }
            }
        }

        for (int i = 0; i < n; i++){
            if (t >= start_testing[i] && t <= start_testing[i] + problems[i]){
                if (t == start_testing[i] + problems[i]){
                        tested++;
                        percent = round((double) tested / n * 100);
                }
            }
        }
        t++;
    }

    cout << interesting << endl;
}

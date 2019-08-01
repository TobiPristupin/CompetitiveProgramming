using namespace std;
#define ll long long
#include <bits/stdc++.h>



int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    while (!(n == 0 && m == 0)){
        vector<pair<int, int>> times;
        int start, end, repeat;
        for (int i = 0; i < n; i++){
            cin >> start >> end;
            times.push_back(make_pair(start, end));
        }

        for (int i = 0; i < m; i++){
            cin >> start >> end >> repeat;
            for (int j = 0; end + j <= 1000000; j += repeat){
                times.push_back(make_pair(start + j, end + j));
            }
        }

        sort(times.begin(), times.end());
        bool conflict = false;
        for (int i = 0; i < times.size() - 1; i++){
            if (times[i].second > times[i+1].first) {
                conflict = true;
                break;
            }
        }

        cout << (conflict ? "CONFLICT" : "NO CONFLICT") << "\n";
        //for (auto x : times) cout << x.first << " " << x.second << endl;
        cin >> n >> m;
    }
    
    
}
using namespace std;
#define ll long long
#include <bits/stdc++.h>

void printvec(vector<int> &vec){
    for (int i = 0; i < vec.size(); i++){
        cout << vec[i];
        if (i != (signed) vec.size() - 1) cout << " ";
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int m, n;
    while (cin >> m >> n){
        //(row, col, value) transposed
        vector<tuple<int, int, int>> elements;
        for (int i = 1; i <= m; i++){
            int r;
            cin >> r;
            //(row, col, value) transposed
            vector<tuple<int, int, int>> add(r, make_tuple(0, i, 0));
            for (int i = 0; i < r; i++){
                int c;
                cin >> c;
                get<0>(add[i]) = c;
            }
            for (int i = 0; i < r; i++){
                int v;
                cin >> v;
                get<2>(add[i]) = v;
            }
            elements.insert(elements.end(), add.begin(), add.end());
        }

        sort(elements.begin(), elements.end());
        
        cout << n << " " << m << "\n";
        for (int r = 1; r <= n; r++){
            vector<int> cols, vals;
            int count = 0;
            for (auto &x : elements){
                if (get<0>(x) == r) {
                    count++;
                    cols.push_back(get<1>(x));
                    vals.push_back(get<2>(x));
                }
            }
            
            cout << count;
            if (count != 0) cout << " ";
            printvec(cols);
            printvec(vals);
        }
    }

}
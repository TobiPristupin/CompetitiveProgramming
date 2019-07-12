using namespace std;
#define ll long long
#include <bits/stdc++.h>


using v = vector<vector<char>>;

void rotate(v &vec){
    for (int i = 0; i < vec.size(); i++){
        for (int j = i + 1; j < vec.size(); j++){
            swap(vec[i][j], vec[j][i]);
        }
    }

    for (int r = 0; r < vec.size() / 2; r++){
        swap(vec[r], vec[vec.size() - r - 1]);
    }

}

int count(v &a, v &b){
    int count = 0;
    for (int r = 0; r <= a.size() - b.size(); r++){
        for (int c = 0; c <= a.size() - b.size(); c++){
            bool equal = true;
            for (int i = 0; i < b.size() && equal; i++){
                for (int j = 0; j < b.size() && equal; j++){
                    if (b[i][j] != a[r+i][c+j]){
                        equal = false;
                    }
                }
            }
            if (equal) count++;
        }
    }
    return count;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int N, n;
    cin >> N >> n;
    while (!(N == 0 && n == 0)){
        v large(N), small(n);
        string s;
        for (int i = 0; i < N; i++) {
            cin >> s;
            vector<char> v(s.begin(), s.end());
            large[i] = v;
        }
        for (int i = 0; i < n; i++) {
            cin >> s;
            vector<char> v(s.begin(), s.end());
            small[i] = v;
        }

        for (int i = 0; i < 4; i++){
            cout << count(large, small);
            if (i != 3) cout << " ";
            rotate(large);
        }
        cout << "\n";
        
        cin >> N >> n;
    }
    
}
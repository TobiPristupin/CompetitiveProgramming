/*
ID: tobiasp1
TASK: transform
LANG: C++                 
*/

#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
using namespace std;

vector<vector<string>> rotate(vector<vector<string>> vec, int rots){
    for (int rot = 0; rot < rots; rot++){
        for (int r = 0; r < vec.size(); r++){
            for (int c = r + 1; c < vec.size(); c++){
                swap(vec[r][c], vec[c][r]);
            }
    }

        for (int r = 0; r < vec.size(); r++){
            for (int c = 0; c < vec.size() / 2; c++){
                swap(vec[r][c], vec[r][vec[0].size() - c - 1]);
            }
        }
    }

    return vec;
}

vector<vector<string>> reflect(vector<vector<string>> vec){
    for (int r = 0; r < vec.size(); r++){
        for (int c = 0; c < vec[0].size() / 2; c++){
            vec[r][c] = vec[r][vec[0].size() - c - 1];
        }
    }

    return vec;
}

bool eq(vector<vector<string>> const &a, const vector<vector<string>> &b){
    return equal(a.begin(), a.end(), b.begin());
}

vector<vector<string>> read_vec(int n){
    string x;
    vector<vector<string>> vec(n, vector<string>());
    for (int i = 0; i < n; i++){
        cin >> x;
        for (int c = 0; c < x.length(); c++){
            vec[i].push_back(x.substr(c, 1));
        }
    }
    
    return vec;
}

int main(){
    freopen ("transform.in", "r", stdin);
    freopen ("transform.out", "w", stdout);
    int n;
    string x;
    cin >> n;
    vector<vector<string>> a = read_vec(n), b = read_vec(n);

    if (eq(rotate(a, 1), b)){
        cout << 1 << "\n";
    } else if (eq(rotate(a, 2), b)){
        cout << 2 << "\n";
    } else if (eq(rotate(a, 3), b)){
        cout << 3 << "\n";
    } else if (eq(reflect(a), b)){
        cout << 4 << "\n";
    } else if (eq(rotate(reflect(a), 1), b) || eq(rotate(reflect(a), 2), b) || eq(rotate(reflect(a), 3), b)){
        cout << 5 << "\n";
    } else if (eq(a, b)){
        cout << 6 << "\n";
    } else {
        cout << 7 << "\n";
    }
}
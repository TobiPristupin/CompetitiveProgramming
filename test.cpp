using namespace std;
#define ll long long
#include <bits/stdc++.h>

bool comp_strings(string a, string b){
    while (a.front() == '0') a.erase(a.begin());
    while (b.front() == '0') b.erase(b.begin());
    if (a.length() != b.length()) return a.length() > b.length();
    for (int i = 0; i < a.length(); i++){
        if (stoi(a.substr(i, 1)) > stoi(b.substr(i, 1))) return true;
        if (stoi(a.substr(i, 1)) < stoi(b.substr(i, 1))) return false;
    }
    return true; 
}

ll binary_insertion_pos(vector<ll> vec, ll x){
    ll lo = 0, hi = vec.size() - 1, mid;
    while (lo <= hi){
        mid = (lo + hi) / 2;
        if (vec.at(mid) < x){
            lo = mid + 1;
        } else if (vec.at(mid) > x - 10){
            hi = mid - 1;
        } else {
            return mid;
        }
    }

    return lo;
}


using v = vector<vector<int>>;
int count(v &a, v &b){
    int count = 0;
    for (int r = 0; r <= a.size() - b.size(); r++){
        for (int c = 0; c <= a.size() - b.size(); c++){
            bool equal = true;
            for (int i = 0; i < b.size(); i++){
                for (int j = 0; j < b.size(); j++){
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

class Team {
    vector<vector<int>> correct, incorrect;

    public:
        int solved = 0;
        int penalty = 0;
        int team_id;
        
        Team(int team) : correct(9, vector<int>()), incorrect(9, vector<int>()), team_id(team) { }

        void correct_problem(int problem, int time){
            correct[problem].push_back(time);
        }

        void incorrect_problem(int problem, int time){
            incorrect[problem].push_back(time);
        }

        void compute(){
            for (int i = 0; i < 8; i++){
                if (correct[i].size() > 0){
                    solved++;
                    int solved_time = *min_element(correct[i].begin(), correct[i].end());
                    penalty += solved_time;
                    for (int &t : incorrect[i]){
                        if (t < solved_time){
                            penalty += 20;
                        }
                    }
                }
            }
        }

        bool operator < (const Team &t) const {
            cout << "put" << endl;
            if (solved < t.solved){
                return true;
            }

            return false;
        } 
    
};

class A {
    public:
        void b(){
            cout << 1 << endl;
        }
};


int main(){
    vector<vector<bool>> grid(8, vector<bool>(8, false));
    grid[1][1] = true;
    cout<< grid[1][1] << endl;
    grid.clear();
    grid.resize(8, vector<bool>(8, false));
    cout<< grid[1][1] << endl;
}

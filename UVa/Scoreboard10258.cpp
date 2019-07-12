using namespace std;
#define ll long long
#include <bits/stdc++.h>

class Team {
    vector<vector<int>> correct, incorrect;

    public:
        int solved = 0;
        int penalty = 0;
        int team_id;
        bool submitted = false;
        
        Team(int team) : correct(9, vector<int>()), incorrect(9, vector<int>()), team_id(team) { }

        void problem(int problem, int time, char status){
            submitted = true;
            if (status == 'C') correct[problem].push_back(time);
            else if (status == 'I') incorrect[problem].push_back(time);
        }

        void compute(){
            for (int i = 0; i < correct.size(); i++) {
                if (correct[i].empty()) {
                    continue;
                }
                
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

        bool operator < (const Team &t) const {
            if (submitted == t.submitted){
                if (solved == t.solved) {
                    if (penalty == t.penalty){
                        return team_id < t.team_id;
                    }
                    return penalty < t.penalty;
                }
                return solved > t.solved;
            }
            return t.submitted;
        } 
    
};

int main(){
    // freopen ("out.txt", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    cin.ignore();
    string _;
    getline(cin, _);
    
    string ans;
    while (t--){
        vector<Team> teams;
        for (int i = 0; i < 100; i++) teams.push_back(Team(i + 1));
        
        string l;
        while (getline(cin, l)) {
            if (l.empty()){
                break;
            }

            istringstream stream(l);
            int team, prob, time;
            char status;
            stream >> team >> prob >> time >> status;
            teams[team-1].problem(prob-1, time, status);
        }

        for (Team &t : teams){
                t.compute();
        }

        sort(teams.begin(), teams.end());
        for (int i = 0; i < teams.size(); i++){
            if (teams[i].submitted){ 
                ans += to_string(teams[i].team_id) + " " + to_string(teams[i].solved) + " " + to_string(teams[i].penalty) + "\n";
            }
        }
        
        ans += "\n";
    }

    //remove last two newlines
    ans.pop_back();
    cout << ans;
}
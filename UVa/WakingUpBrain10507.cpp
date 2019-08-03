using namespace std;
#define ll long long
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    start:
        while(cin >> n >> m){
            unordered_set<char> sleeping;
            string l;
            cin >> l;
            
            unordered_map<char, vector<char>> graph;
            for (int i = 0; i < m; i++){
                string uv;
                cin >> uv;
                graph[uv[0]].push_back(uv[1]);
                graph[uv[1]].push_back(uv[0]);
                sleeping.insert(uv[0]);
                sleeping.insert(uv[1]);
            }

            for (char &c : l){
                sleeping.erase(c);
            }

            if (sleeping.size() + 3 != n){
                cout << "THIS BRAIN NEVER WAKES UP\n";
                goto start;
            }

            int time = 0;
            while (sleeping.size() > 0){
                vector<char> wake_up;
                for (auto &v : sleeping){
                    int awake_neighbors = 0;
                    for (char neighbor : graph[v]){
                        if (sleeping.find(neighbor) == sleeping.end()){
                            awake_neighbors++;
                        }
                    }
                    if (awake_neighbors >= 3){
                        wake_up.push_back(v);
                    }
                }

                if (wake_up.empty() && !sleeping.empty()){
                    cout << "THIS BRAIN NEVER WAKES UP\n";
                    goto start;
                } else {
                    for (char &v : wake_up) {
                        sleeping.erase(v);
                    }
                }
                time++;
            }

            cout << "WAKE UP IN, " << time << ", YEARS\n";
        }
}
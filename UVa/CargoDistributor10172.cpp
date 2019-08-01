using namespace std;
#define ll long long
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n, s, q, remaining = 0;
        cin >> n >> s >> q;
        vector<deque<int>> stations(n, deque<int>());
        stack<int> carrier;
        for (int i = 0; i < n; i++){
            int cargoes;
            cin >> cargoes;
            remaining += cargoes;
            while (cargoes--) {
                int id;
                cin >> id;
                stations[i].push_back(id);
            }
        }

        int time = 0, pos = 0;
        while (true){
            //unload
            while (!carrier.empty() && (stations[pos % n].size() < q || carrier.top() == pos % n + 1)){
                if (carrier.top() == pos % n + 1){
                    carrier.pop();
                    remaining--;
                } else {
                    stations[pos % n].push_back(carrier.top());
                    carrier.pop();
                }
                time++;
            }

            while (!stations[pos % n].empty() && carrier.size() < s){
                carrier.push(stations[pos % n].front());
                stations[pos % n].pop_front();
                time++;
            }

            if (remaining == 0){
                break;
            }

            pos++;
            time += 2;
        }

        cout << time << "\n";
    }
}
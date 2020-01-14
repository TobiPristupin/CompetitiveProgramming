using namespace std;
#define ll long long
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int tcase;
    cin >> tcase;
    while (tcase--){
        int players, cheats, rolls;
        cin >> players >> cheats >> rolls;
        vector<int> pos(players, 1);
        unordered_map<int, int> map;
        for (int i = 0; i < cheats; i++){
            int a, b;
            cin >> a >> b;
            map[a] = b;
        }

        int playerid = 0;
        vector<int> roll(rolls);
        for (int i = 0; i < rolls; i++) cin >> roll[i];
        for (int r : roll){
            pos[playerid] += r;
            
            if (map.find(pos[playerid]) != map.end()){
                pos[playerid] = map[pos[playerid]];
            }

            if (pos[playerid] >= 100){
                break;
            }
            
            playerid++;
            if (playerid == players){
                playerid = 0;
            }
        }

        for (int i = 0; i < pos.size(); i++){
            cout << "Position of player " << i + 1 << " is " << pos[i] << ".\n";
        }
    }
}
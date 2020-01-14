using namespace std;
#define ll long long
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    string s;
    getline(cin, s);
    while (s != "Game Over"){
        istringstream iss(s);
        vector<string> rolls(istream_iterator<string> {iss}, istream_iterator<string>());
        vector<vector<int>> frames;
        
        int i = 0;
        while (frames.size() < 9){
            vector<int> frame;
            if (rolls[i] == "X"){
                frame.push_back(10);
                i++;
            } else if (rolls[i + 1] == "/"){
                frame.push_back(stoi(rolls[i]));
                frame.push_back(10 - stoi(rolls[i]));
                i += 2;
            } else {
                frame.push_back(stoi(rolls[i]));
                frame.push_back(stoi(rolls[i + 1]));
                i += 2;
            }
            frames.push_back(frame);
        }

        vector<int> last_frame;
        if (rolls.size() - i == 3){ //10th frame has three rolls
            for (int j = rolls.size() - 3; j < rolls.size(); j++){
                if (rolls[j] == "X"){
                    last_frame.push_back(10);
                } else if (rolls[j] == "/"){
                    last_frame.push_back(10 - stoi(rolls[j - 1]));
                } else {
                    last_frame.push_back(stoi(rolls[j]));
                }
            }
        } else {
            last_frame.push_back(stoi(rolls[rolls.size() - 2]));
            last_frame.push_back(stoi(rolls[rolls.size() - 1]));
        }
        frames.push_back(last_frame);
        
        int score = 0;
        for (int i = 0; i < 10; i++){
            vector<int> frame = frames[i];

            if (i == 9){ //10th frame
                score += frame[0] + frame[1] + frame[2];
                continue;
            }


            if (frame[0] == 10){
                score += 10 + frames[i + 1][0];
                if (frames[i + 1].size() >= 2){
                    score += frames[i + 1][1];
                } else {
                    score += frames[i + 2][0];
                }
            } else if (frame[0] + frame[1] == 10){
                score += 10 + frames[i + 1][0];
            } else {
                score += frame[0] + frame[1];
            }
        }
        
        cout << score << endl;

        getline(cin, s);
    }
}
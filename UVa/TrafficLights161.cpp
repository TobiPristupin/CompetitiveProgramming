using namespace std;
#define ll long long
#include <bits/stdc++.h>

void solve(vector<int> lights){
    sort(lights.begin(), lights.end(), greater<int>());
    vector<int> green(18001, 0);
    for (int i = 0; i < lights.size(); i++){
        int light = lights[i];
        int n = 0; 
        while (light * n <= 18000){
            for (int j = light * n; j < light * n + light - 5; j++){
                if (j > 18000){
                    break;
                }

                green[j] += 1;
                if (green[j] == lights.size() && j > lights.back()){
                    int hours = j / 3600;
                    int minutes = (j % 3600) / 60;
                    int seconds = (j % 3600 % 60);

                    printf("%02d:%02d:%02d\n", hours, minutes, seconds);
                    return;
                }
            }
            
            n += 2;
        }
    }

    printf("Signals fail to synchronise in 5 hours\n");
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int x;
    vector<int> input;
    while (cin >> x){
        input.push_back(x);
    }

    vector<int> lights;
    for (int i = 0; i < input.size() - 3; i++){
        if (input[i] == 0){
            solve(lights);
            lights.clear();
        } else {
            lights.push_back(input[i]);
        }
    }
}
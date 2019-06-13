using namespace std;
#define ll long long
#include <bits/stdc++.h>

int MAX_H = 500, MAX_W = 500; 
vector<vector<char>> pic(MAX_H, vector<char>(MAX_W, '.'));

bool is_star(int r, int c){
    return pic[r][c] == '*';
}

int main(){
    ll h, w;
    char c;
    int star = 0;
    cin >> h >> w;
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++){
            cin >> c;
            if (c == '*'){
                star++;
            }
            pic[i][j] = c;
        }
    }


    for (int i = 1; i < h - 1; i++){
        for (int j = 1; j < w - 1; j++){
            if (is_star(i, j) && is_star(i-1, j) && is_star(i+1, j) && is_star(i, j-1) && is_star(i, j+1)){
                for (int k = i + 1; k < h; k++){
                    if (is_star(k, j)){
                        star--;
                    } else {
                        break;
                    }
                }

                for (int k = i - 1; k >= 0; k--){
                    if (is_star(k, j)){
                        star--;
                    } else {
                        break;
                    }
                }

                for (int k = j + 1; k < w; k++){
                    if (is_star(i, k)){
                        star--;
                    } else {
                        break;
                    }
                }

                for (int k = j - 1; k >= 0; k--){
                    if (is_star(i, k)){
                        star--;
                    } else {
                        break;
                    }
                }

                star--;

                if (star == 0){
                    cout << "YES" << "\n";
                } else {
                    cout << "NO" << "\n";
                }
                return 0;
            }
        }
    }

    cout << "NO" << "\n";
}
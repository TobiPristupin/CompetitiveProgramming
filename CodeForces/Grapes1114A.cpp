#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int andrew, dmitry, michal, green, purple, black;
    cin >> andrew >> dmitry >> michal >> green >> purple >> black;
    green -= andrew;
    purple -= dmitry;
    if (purple < 0){
        green -= -purple;
        purple = 0;
    }



    if (purple >= 0 && green >= 0 && black >= 0 && green + black + purple >= michal){
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }

    return 0;
}
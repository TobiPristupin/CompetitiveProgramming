using namespace std;
#define ll long long
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for (int tcase = 1; tcase <= n; tcase++){
        int a, b, x;
        cin >> a >> b >> x;
        int guesses = 1, guess = round((a+b)/2.0);
        while (guess != x){
            if (guess > x){
                b = guess - 1;
            } else {
                a = guess + 1;
            }
            guesses++;
            guess = round((a+b)/2.0);
        }

        cout << "Game #" << tcase << ": " << guesses << " guesses" << endl;
    }
}


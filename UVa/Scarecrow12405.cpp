using namespace std;
#define ll long long
#include <bits/stdc++.h>


int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    for (int tcase=1; tcase <= t; tcase++){
        int n;
        string s;
        cin >> n >> s;
        int crows = 0;

        for (int i = 0; i < n; i++){
            if (s[i] == '.'){
                crows++;
                s[i] = '*';
                if (i + 1 < n) s[i + 1] = '*';
                if (i + 2 < n) s[i + 2] = '*';
            }
        }


        cout << "Case " << tcase << ": " << crows << '\n';
    }
}


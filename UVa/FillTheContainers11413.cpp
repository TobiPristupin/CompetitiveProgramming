using namespace std;
#define ll long long
#include <bits/stdc++.h>

bool simulate(int k, int m, vector<int> &milk){
    int curr = k;
    for (int i = 0; i < milk.size(); i++){
        if (milk[i] > curr){
            curr = k;
            m--;
        }

        if (m == 0){
            return false;
        }

        curr -= milk[i];
    }

    return true;
}

int main(){
    int n, m;
    while (cin >> n >> m){
        vector<int> milk(n);
        int biggest = 0;
        for (int i = 0; i < n; i++) {
            cin >> milk[i];
            biggest = max(biggest, milk[i]);
        }
    
        int lo = biggest, hi = biggest * n;
        int best = hi, tries = 0;
        int k = (lo + hi) / 2;
        while (tries <= 40){
            if (simulate(k, m, milk)){
                best = min(k, best);
                hi = k;
            } else {
                lo = k + 1;
            }

            k = (lo + hi) / 2;
            tries++;
        }

        cout << best << "\n";
    }


}
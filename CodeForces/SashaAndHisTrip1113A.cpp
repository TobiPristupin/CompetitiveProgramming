#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, v, tank = 0, cost = 0;
    cin >> n >> v;
    for (int i = 1; i < n; i++){
        if (tank >= n - i){
            break;
        }
        int needed = max(0, min(v - tank, n - i - tank));
        tank += needed;
        cost += needed * i;
        tank--;
    }
    
    cout << cost << "\n";
}



































// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     int n, v, tank = 0, cost = 0, pos = 1;
//     cin >> n >> v;
//     while (pos < n){
//         if (tank >= n - pos){
//             break;
//         }

//         int needed = min(v, n - pos - tank);
//         needed = max(0, needed);
//         tank += needed;
//         cost += needed * pos;
        
//         pos++;
//         tank--;
//     }

//     cout << cost << "\n";
// }
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    int ans = -1;
    for (int i = 1; i < k; i++){
        int x = n / i * k;
        x += i - (x % k);
        ans = ((x/k)*(x%k) == n && x < ans || ans == -1 ? x : ans);
    }

    cout << ans << "\n";
}



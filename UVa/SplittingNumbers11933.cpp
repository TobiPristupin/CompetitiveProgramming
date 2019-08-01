using namespace std;
#define ll long long
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int N;
    cin >> N;
    while (N != 0){
        bitset<32> n(N), a, b;
        int ones = 0;
        for (int i = 0; i < 32; i++){
            if (n.test(i)){
                ones++;
                if (ones % 2 == 0){
                    b.set(i);
                } else {
                    a.set(i);
                }
            }
        } 
        //cout << a.to_string() << " " << b.to_string() << "\n";
        cout << a.to_ulong() << " " << b.to_ulong() << "\n";
        cin >> N;
    }
}
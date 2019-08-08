using namespace std;
#define ll long long
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    while (n != 0){
        bool found = false;
        for (int i = 01234; i <= 98765; i++){
            if (i % n == 0){
                int a = i, b = i / n;                
                unordered_set<int> digits;
                do {
                    digits.insert(a % 10);
                    a /= 10;
                } while (a > 0);
                do {
                    digits.insert(b % 10);
                    b /= 10; 
                } while (b > 0);

                if (digits.size() == 9 && digits.find(0) == digits.end() && (i / n) < 10000){
                    cout << i << " / 0" << i / n << " = " << n << "\n";
                    found = true;
                } else if (digits.size() == 10){
                    cout << i << " / " << i / n << " = " << n << "\n";
                    found = true;
                }
            }
        }
        
        if (!found) cout << "There are no solutions for " << n << ".\n";
        cin >> n;
        if (n != 0) cout << "\n";
    }

}
using namespace std;
#define ll long long
#include <bits/stdc++.h>

int main(){
    unsigned ll l, x = 0, max_value = pow(2, 32);
    cin >> l;
    stack<unsigned ll> loop;
    loop.push(1);
    string line;
    while (cin >> line){
        if (line == "add"){
            if (loop.top() + x >= max_value){
                cout << "OVERFLOW!!!" << endl;
                return 0;
            }
            x += loop.top();
        } else if (line == "for"){
            int n;
            cin >> n;
            loop.push(min(loop.top() * n, max_value));
        } else {
            loop.pop();
        }
    }

    cout << x << "\n";
}
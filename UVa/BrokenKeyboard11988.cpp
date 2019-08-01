using namespace std;
#define ll long long
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    string in;
    while (cin >> in){
        list<char> l, buffer;
        bool use_buffer = false;
        for (char &c : in){
            if (c == '['){
                use_buffer = true;
                l.splice(l.begin(), buffer);
            } else if (c == ']'){
                use_buffer = false;
                l.splice(l.begin(), buffer);
            } else {
                if (use_buffer){
                    buffer.push_back(c);
                } else {
                    l.push_back(c);
                }
            }
        }
        l.splice(l.begin(), buffer);
        for (auto x : l) cout << x;
        cout << endl;
    }
}
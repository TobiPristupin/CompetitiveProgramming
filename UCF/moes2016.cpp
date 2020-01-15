using namespace std;
#define ll long long
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int c;
    int cnumber = 1;
    cin >> c;
    unordered_set<string> s;
    while (c--){
        string name;
        cin >> name;
        if (s.find(name) == s.end()){
            s.insert(name);
            cout << "Customer #" << cnumber << ": Welcome to Moe's!!!\n";
        } else {
            cout << "Customer #" << cnumber << ": **continue working**\n";
        }

        cnumber++;
    }

}
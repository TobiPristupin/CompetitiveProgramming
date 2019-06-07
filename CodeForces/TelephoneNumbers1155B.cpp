using namespace std;
#define ll long long
#include <bits/stdc++.h>

int main(){
    ll n;
    string x;
    cin >> n >> x;
    list<char> s(x.begin(), x.end());
    bool vasya = true, all_8s_together = false;
    while (n != 11){
        if (vasya){
            if (all_8s_together) {
                s.pop_back();
                n--;
                vasya = !vasya;
                continue;
            }

            list<char>::const_iterator it;
            for (it = next(s.begin()); it != s.end(); ++it){
                if (*it == '8' && *prev(it) != '8'){
                    break;
                }
            }

            if (it == s.end()){
                all_8s_together = true;
                s.pop_back();
            } else {
                s.erase(prev(it));
            }
        } else {
            auto it = find(s.begin(), s.end(), '8');
            if (it == s.end()){
                s.pop_back();
            } else {
                s.erase(it);
            }
        }

        vasya = !vasya;
        n--;
    }
    
    if (s.front() == '8' ) cout << "YES" << endl;
    else cout << "NO" << endl;
}
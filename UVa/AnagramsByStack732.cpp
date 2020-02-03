using namespace std;
#define ll long long
#include <bits/stdc++.h>

string a, b;

void solve(vector<char> pattern, stack<char> st, string in, string out){
    if (pattern.size() == a.length() * 2){
        if (out == b){
            for (int i = 0; i < pattern.size(); i++){
                cout << pattern[i];
                if (i != pattern.size() - 1) cout << " ";
            }
            cout << endl;
        }

        return;
    }

    if (in.length() > 0){
        pattern.push_back('i');
        st.push(in[0]);
        solve(pattern, st, in.substr(1), out);
        pattern.pop_back();
        st.pop();
    }

    if (st.size() > 0 && st.top() == b[out.length()]){
        pattern.push_back('o');
        char last = st.top();
        st.pop();
        solve(pattern, st, in, out + last);
        st.push(last);
        pattern.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    while (cin >> a >> b){
        cout << "[\n";
        if (a.length() != b.length()){
            cout << "]\n";
        } else {
            vector<char> pattern;
            stack<char> st;
            solve(pattern, st, a, "");
            cout << "]\n";
        }
    }
}
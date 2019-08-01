using namespace std;
#define ll long long
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    string in;
    int testcase = 1;
    cin >> in;
    while (in != "end"){
        vector<stack<char>> containers;
        for (char &c : in){
            bool placed = false;
            for (stack<char> &st : containers){
                if (c <= st.top()){
                    st.push(c);
                    placed = true;
                    break;
                }
            }

            if (!placed){
                containers.push_back(stack<char>());
                containers.back().push(c);
            }
        }

        cout << "Case " << testcase << ": " << containers.size() << endl;
        cin >> in;
        testcase++;
    }
}



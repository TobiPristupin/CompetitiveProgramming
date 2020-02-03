using namespace std;
#define ll long long
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    while (cin >> n){
        stack<int> st;
        queue<int> qu;
        priority_queue<int> pri;
        bool is_stack = true, is_queue = true, is_priority = true;

        for (int i = 0; i < n; i++){
            int inst, x;
            cin >> inst >> x;
            if (inst == 1){
                st.push(x);
                qu.push(x);
                pri.push(x);
            } else {
                if (is_stack){
                    if (st.empty() || st.top() != x){
                        is_stack = false;
                    } else {
                        st.pop();
                    }
                }

                if (is_queue){
                    if (qu.empty() || qu.front() != x){
                        is_queue = false;
                    } else {
                        qu.pop();
                    }
                }

                if (is_priority){
                    if (pri.empty() || pri.top() != x){
                        is_priority = false;
                    } else {
                        pri.pop();
                    }
                }
            }
        }

        int ans = is_stack + is_priority + is_queue;
        if (ans > 1){
            cout << "not sure\n";
        } else if (ans == 0){
            cout << "impossible\n";
        } else {
            if (is_stack){
                cout << "stack\n";
            } else {
                cout << (is_queue ? "queue\n" : "priority queue\n");
            }
        }
    }
}
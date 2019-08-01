using namespace std;
#define ll long long
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    while (n--){
        int b, sg, sb;
        cin >> b >> sg >> sb;
        priority_queue<int> green, blue;
        int p;
        while (sg--){
            cin >> p;
            green.push(p);
        }
        while (sb--){
            cin >> p;
            blue.push(p);
        }

        while (true){
            vector<int> green_survivors, blue_survivors;
            for (int i = 0; i < b && !green.empty() && !blue.empty(); i++){
                int g = green.top(), b = blue.top();
                int died = min(g, b);
                green.pop(); blue.pop();
                if (g - died > 0) green_survivors.push_back(g - died);
                if (b - died > 0) blue_survivors.push_back(b - died);
            }

            for (int &s : green_survivors) green.push(s);
            for (int &s : blue_survivors) blue.push(s);
            if (green.empty() && blue.empty()){
                cout << "green and blue died\n";
                break;
            } else if (green.empty()){
                cout <<  "blue wins\n";
                while (!blue.empty()){
                    cout << blue.top() << "\n";
                    blue.pop();
                }
                break;
            } else if (blue.empty()){
                cout << "green wins\n";
                while (!green.empty()){
                    cout << green.top() << "\n";
                    green.pop();
                }
                break;
            }
        }

        if (n != 0) cout << "\n";
    }

}
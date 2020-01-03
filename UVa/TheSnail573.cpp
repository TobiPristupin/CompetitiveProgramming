using namespace std;
#define ll long long
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    double height, climb, slide, factor;
    cin >> height >> climb >> slide >> factor;
    while (height != 0){
        double fatigue = climb * factor / 100;
        double pos = 0;
        for (int day = 1; ; day++){
            pos += climb;
            climb = max(0.0, climb - fatigue);
            if (pos > height){
                cout << "success on day " << day << "\n";
                break;
            }

            pos -= slide;
            if (pos < 0){
                cout << "failure on day " << day << "\n";
                break;
            }
        }
        
        cin >> height >> climb >> slide >> factor;
    }

}
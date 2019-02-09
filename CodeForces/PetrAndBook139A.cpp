#include <iostream>
using namespace std;

int main(){
    int n;
    int days[7];
    cin >> n;
    for (int i = 0; i < 7; i++){
        cin >> days[i];
    }

    int day = 0;
    while (n > 0){
        n -= days[day % 7];
        day++;
    }

    day %= 7;
    cout << (day == 0 ? 7 : day) << "\n";
}
/*
ID: tobiasp1
TASK: milk2
LANG: C++                 
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int find_biggest_milking(vector<pair<int, int>> &times){
    int biggest = 0, head = times[0].first, tail = times[0].second;
    for (int i = 0; i < times.size(); i++){
        if (times[i].first <= tail){
            tail = max(tail, times[i].second);
        } else {
            head = times[i].first;
            tail = times[i].second;
        }

        biggest = max(tail - head, biggest);
    }

    return biggest;
}

int find_biggest_unactive(vector<pair<int, int>> &times){
    int biggest = 0, tail = times[0].second;
    for (int i = 0; i < times.size(); i++){
        if (times[i].first <= tail){
            tail = max(tail, times[i].second);
        } else {
            biggest = max(times[i].first - tail, biggest);
            tail = times[i].second;
        }
    }

    return biggest;
}


int main(){
    freopen ("milk2.in", "r", stdin);
    freopen ("milk2.out", "w", stdout);

    int n, start, end;
    vector<pair<int, int>> times; 

    cin >> n;
    while (cin >> start >> end){
        times.push_back(make_pair(start, end));
    }
    sort(times.begin(), times.end());

    cout << find_biggest_milking(times) << " " << find_biggest_unactive(times) << "\n";
    return 0;
}
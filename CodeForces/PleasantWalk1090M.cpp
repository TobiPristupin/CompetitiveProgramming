#include <iostream>
#include <vector>

using namespace std;

int main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int n, k, x;
    vector<int> arr;
    cin >> n >> k;
    while (cin >> x){
        arr.push_back(x);
    }

    int best = 1, curr = 1;
    for (int i = 1; i < arr.size(); i++){
        curr = arr[i] == arr[i - 1] ? 1 : curr + 1; 
        best = curr > best ? curr : best;
    }

    cout << best << "\n";
}
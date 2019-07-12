using namespace std;
#define ll long long
#include <bits/stdc++.h>

int main(){
    //ios::sync_with_stdio(0), cin.tie(0);
    int n, negatives = 0, largest_index = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        if (a >= 0){
            a = -a - 1;
        }

        if (a < 0){
            negatives++;
        }

        arr[i] = a;

        if (abs(a) > abs(arr[largest_index])){
            largest_index = i;
        }
    }

    if (negatives % 2 == 1){
        arr[largest_index] = -arr[largest_index] - 1;
    }

    for (auto x : arr) cout << x << " ";
    cout << endl;
}
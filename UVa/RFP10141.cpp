using namespace std;
#define ll long long
#include <bits/stdc++.h>

typedef tuple<string, int, float> proposal;
bool custom_sort(const proposal &a, const proposal &b){
    if (get<1>(a) == get<1>(b)){
        return get<2>(a) < get<2>(b);
    }
    return get<1>(a) > get<1>(b);
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int reqs, props;
    int tcase = 1;
    cin >> reqs >> props;
    while (reqs != 0){
        if (tcase != 1) cout << "\n";
        
        
        cin.ignore();
        for (int i = 0; i < reqs; i++){
            string x;
            getline(cin, x);
        }

        vector<proposal> proposals(props);
        for (int i = 0; i < props; i++){
            string name;
            getline(cin, name);
            float price;
            int reqs_met;
            cin >> price >> reqs_met;
            cin.ignore();
            proposals[i] = make_tuple(name, reqs_met, price);

            for (int j = 0; j < reqs_met; j++){
                string x;
                getline(cin, x);
            }
        }

        sort(proposals.begin(), proposals.end(), custom_sort);
        cout << "RFP #" << tcase << "\n";
        cout << get<0>(proposals[0]) << "\n"; 

        //for (auto x : proposals) cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) << "\n";

        cin >> reqs >> props;
        tcase++;
    }
}
#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
    ll n, k, a, b;
    cin >> n >> k;
    unordered_map<ll, ll> jobs;
    vector<pair<ll, ll>> idlers(n, make_pair(0, 0));
    vector<ll> jobless_idlers;
    for (int i = 0; i < n; i++) cin >> idlers[i].first;
    for (int i = 0; i < n; i++) cin >> idlers[i].second;
    for (int i = 0; i < n; i++){
        ll job = idlers[i].first, idler = idlers[i].second;
        if (jobs.find(job) == jobs.end()){
            jobs[job] = idler;
        } else {
            if (idler > jobs[job]){
                jobless_idlers.push_back(jobs[job]);
                jobs[job] = idler;
            } else {
                jobless_idlers.push_back(idler);
            }
        }
    }

    sort(jobless_idlers.begin(), jobless_idlers.end());
    ll cost = 0;
    for (int i = 0; i < k - jobs.size(); i++){
        cost += jobless_idlers[i];
    }

    cout << cost << "\n";
    return 0;
}
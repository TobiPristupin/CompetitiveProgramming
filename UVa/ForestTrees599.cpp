using namespace std;
#define ll long long
#include <bits/stdc++.h>


unordered_map<char, vector<char>> graph;
unordered_map<char, bool> visited;

int component_size(const char &start){
    if (visited[start]){
        return 0;
    }

    visited[start] = true;
    int sum =  1;
    for (char neighbor : graph[start]){
        sum += component_size(neighbor);
    }
    
    return sum;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    cin.ignore();
    while (t--){
        string l;
        getline(cin, l);
        while (l.find("*") == string::npos){
            graph[l[1]].push_back(l[3]);
            graph[l[3]].push_back(l[1]);
            getline(cin, l);
        }

        getline(cin, l);
        for (int i = 0; i < l.length(); i += 2){
            visited[l[i]] = false;
        }

        int trees = 0, accorns = 0;
        for (auto &vertex : visited){
            if (!vertex.second){
                if (component_size(vertex.first) > 1) trees++;
                else accorns++;
            }
        }

        cout << "There are " << trees << " tree(s) and " << accorns << " acorn(s).\n";
        graph.clear();
        visited.clear();
    }

}

// for (auto &p : graph){
//     cout << p.first << ": ";
//     for (auto x : p.second) cout << x << " ";
//     cout << endl;
// }

// for (auto &p : visited){
//     cout << p.first << ": " << p.second << " ";
    
// }
// cout << endl;
using namespace std;
#define ll long long
#include <bits/stdc++.h>

class UnionFind {
    private:
        vector<int> id, size;
        int components;
    
    public:
        UnionFind(int n){
            for (int i = 0; i < n; i++){
                id.push_back(i);
                size.push_back(1);
            }
            components = n;
        }

        int find(int a){
            int root = a;
            while (id[root] != root) {
                root = id[root];
            }

            //Path compression
            while (a != root){
                int next = id[a];
                id[a] = root;
                a = next;
            }

            return root;
        }

        void unite(int a, int b){
            int root_a = find(a), root_b = find(b);
            if (root_a == root_b){
                return;
            }

            if (size[root_a] > size[root_b]){
                id[root_b] = root_a;
                size[root_a] += size[root_b];
            } else {
                id[root_a] = root_b;
                size[root_b] += size[root_a];
            }

            components--;
        }

        int getSize(int a){return size[find(a)];}
};

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        unordered_map<string, int> ids;
        UnionFind uf(100000);
        int id = 1, f;
        cin >> f;
        while (f--){
            string a, b;
            cin >> a >> b;
            if (ids[a] == 0) {
                ids[a] = id;
                id++;
            }
            if (ids[b] == 0) {
                ids[b] = id;
                id++;
            }

            uf.unite(ids[a], ids[b]);
            cout << uf.getSize(ids[a]) << "\n";
        }
    }
}
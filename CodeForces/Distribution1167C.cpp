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

        bool connected(int a, int b){
            return find(a) == find(b);
        }

        int getComponents(){
            return components;
        }

        int getSize(int a){
            return size[find(a)];
        }

        vector<int> getArr(){
            return id;
        }
};

int main(){
    ll n, m;
    cin >> n >> m;
    UnionFind disjoint = UnionFind(n);
    for (int i = 0; i < m; i++){
        ll group_size;
        cin >> group_size;
        vector<ll> group(group_size, 0);
        for (int j = 0; j < group_size; j++){
            ll k;
            cin >> k;
            group[j] = k - 1;
        }
        for (int j = 0; j < ((signed) group.size()) - 1; j++){
            disjoint.unite(group[j], group[j + 1]);
        }
    }

    for (int i = 0; i < n; i++){
        cout << disjoint.getSize(i) << " ";
    }
    cout << "\n";
}
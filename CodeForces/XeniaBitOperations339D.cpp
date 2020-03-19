using namespace std;
#define ll long long
#include <bits/stdc++.h>

class SegmentTree {

    public:
        vector<int> arr, tree, leaf_distance;
        SegmentTree(vector<int> arr){
            this->arr = arr;
            tree.assign(arr.size()*4, -1);
            leaf_distance.assign(arr.size()*4, -1);
            build(0, arr.size()-1);
        }

        void build(int l, int r, int node=1){
            if (l == r){
                tree[node] = arr[l];
                leaf_distance[node] = 0;
            } else {
                int mid = (l + r) / 2;
                build(l, mid, node*2);
                build(mid + 1, r, node*2+1);
                leaf_distance[node] = leaf_distance[node*2] + 1;
                if (leaf_distance[node] % 2 == 1) tree[node] = tree[node*2] | tree[node*2+1];
                else tree[node] = tree[node*2] ^ tree[node*2+1];
            }
        }

        void update(int i, int v){
            update(i, 0, arr.size()-1, v);
        }

        void update(int i, int l, int r, int val, int node=1){
            if (l == r){
                tree[node] = val;
            } else {
                int mid = (l + r) / 2;
                if (i <= mid){
                    update(i, l, mid, val, node*2);
                } else {
                    update(i, mid+1, r, val, node*2+1);
                }

                if (leaf_distance[node] % 2 == 1) tree[node] = tree[node*2] | tree[node*2+1];
                else tree[node] = tree[node*2] ^ tree[node*2+1];
            }
        }
};

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> arr(pow(2, n));
    for (int i = 0; i < pow(2, n); i++) cin >> arr[i];
    
    SegmentTree tree(arr);
    // for (auto x : tree.tree) cout << x << " ";
    // cout << endl;
    // for (auto x : tree.leaf_distance) cout << x << " ";
    // cout << endl;
    
    while (m--){
        int i, v;
        cin >> i >> v;
        tree.update(i-1, v);
        cout << tree.tree[1] << "\n";
    }
}
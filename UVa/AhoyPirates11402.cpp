using namespace std;
#define ll long long
#include <bits/stdc++.h>


int set_on=1, clear=2, inverse=3, nothing=0;

class SegmentTree {
    //Sum implementation with lazy propagation

    public:
        deque<int> arr;
        vector<int> tree;
        vector<int> lazy;
        SegmentTree(deque<int> arr){
            this->arr = arr;
            tree.assign(arr.size()*4, -1);
            lazy.assign(arr.size()*4, nothing);
            build(0, arr.size()-1);
        }

        void build(int l, int r, int node=1){
            if (l == r){
                tree[node] = arr[l];
            } else {
                int mid = (l + r) / 2;
                build(l, mid, node*2);
                build(mid + 1, r, node*2+1);
                tree[node] = tree[node*2] + tree[node*2+1]; 
            }
        }

        int rsq(int i, int j){
            return rsq(i, j, 0, arr.size()-1);
        }

        int rsq(int i, int j, int l, int r, int node=1){
            update_node(l, r, lazy[node], node);
            if (l != r) propagate_lazy(l, r, node);

            if (i <= l && j >= r){ 
                return tree[node];
            } else if (i > r || j < l) { 
                return 0; 
            }

            //current interval is contained partially in [i..j]
            int mid = (l + r) / 2;
            int left = rsq(i, j, l, mid, node*2);
            int right = rsq(i, j, mid + 1, r, node*2+1);
            return left + right; //combine according to query type
        }

        void update(int i, int j, int type){
            update(i, j, 0, arr.size()-1, type);
        }

        void update(int i, int j, int l, int r, int type, int node=1){
            update_node(l, r, lazy[node], node);
            if (l != r) propagate_lazy(l, r, node);

            if (i <= l && j >= r){ //current interval is contained fully in [i..j]
                update_node(l, r,  type, node);

                if (l != r){//if we're not at a leaf
                    lazy[node] = type;
                    propagate_lazy(l, r, node);
                }
                return;
            } else if (i > r || j < l) { //current interval is completely out of [i..j]
                return;
            }

            int mid = (l + r) / 2;
            update(i, j, l, mid, type, node*2);
            update(i, j, mid+1, r, type, node*2+1);
            tree[node] = tree[node*2] + tree[node*2+1];
        }

        void update_node(int l, int r, int type, int node){
            if (type != nothing){
                if (type == inverse){
                    tree[node] = (r - l + 1) - tree[node];
                } else if (type == set_on){
                    tree[node] = (r - l + 1);
                } else {
                    tree[node] = 0;
                }
            }
        }

        void propagate_lazy(int l, int r, int node){
            if (l != r){
                int type = lazy[node];
                if (type == clear || type == set_on){
                    lazy[node*2] = type;
                    lazy[node*2+1] = type;
                } else {
                    if (lazy[node*2] == inverse) lazy[node*2] = nothing;
                    else if (lazy[node*2] == set_on) lazy[node*2] = clear;
                    else if (lazy[node*2] == clear) lazy[node*2] = set_on;
                    else lazy[node*2] = inverse;

                    if (lazy[node*2+1] == inverse) lazy[node*2+1] = nothing;
                    else if (lazy[node*2+1] == set_on) lazy[node*2+1] = clear;
                    else if (lazy[node*2+1] == clear) lazy[node*2+1] = set_on;
                    else lazy[node*2+1] = inverse;
                }
            }
            lazy[node] = 0;
        }
};

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int tc;
    cin >> tc;
    for (int tcase = 1; tcase <= tc; tcase++){
        int m;
        cin >> m;
        deque<int> pirates;
        for (int i = 0; i < m; i++){
            int t;
            string s;
            cin >> t >> s;
            for (int j = 0; j < t; j++) for (char c : s) pirates.push_back(c - '0');
        }
    
        cout << "Case "<< tcase << ":\n";
        SegmentTree tree(pirates);
        int q;
        cin >> q;
        int s_queries = 0;
        for (int query = 1; query <= q; query++){
            char type;
            int i, j;
            cin >> type >> i >> j;
            if (type == 'I'){
                tree.update(i, j, inverse);
            } else if (type == 'F'){
                tree.update(i, j, set_on);
            } else if (type == 'E'){
                tree.update(i, j, clear);
            } else {
                s_queries++;
                cout << "Q" << s_queries << ": " << tree.rsq(i, j) << "\n";
            }
        }
    }
}
using namespace std;
#define ll long long
#include <bits/stdc++.h>

class SegmentTree {
    //Sum implementation with lazy propagation

    public:
        vector<ll> arr, tree, lazy;
        SegmentTree(vector<ll> arr){
            this->arr = arr;
            tree.assign(arr.size()*4, -1);
            lazy.assign(arr.size()*4, 0);
            build(0, arr.size()-1);
        }

        void build(ll l, ll r, ll node=1){
            if (l == r){
                tree[node] = arr[l];
            } else {
                ll mid = (l + r) / 2;
                build(l, mid, node*2);
                build(mid + 1, r, node*2+1);
                tree[node] = tree[node*2] + tree[node*2+1]; //For sum queries
            }
        }

        ll rsq(ll i, ll j){
            return rsq(i, j, 0, arr.size()-1);
        }

        ll rsq(ll i, ll j, ll l, ll r, ll node=1){
            //i, j is the range for the query. l, r are the bounds for the current node
            //i and j are both inclusive
            update_and_propagate(l, r, node);

            if (i <= l && j >= r){ //current llerval is contained fully in [i..j]
                return tree[node];
            } else if (i > r || j < l) { //current llerval is completely out of [i..j]
                return 0; //0 because it shouldn't affect the sum query. If doing a max query, return -infinity.
            }

            //current llerval is contained partially in [i..j]
            ll mid = (l + r) / 2;
            ll left = rsq(i, j, l, mid, node*2);
            ll right = rsq(i, j, mid + 1, r, node*2+1);
            return left + right; //combine according to query type
        }

        void add_range(ll i, ll j, ll val){
            add_range(i, j, 0, arr.size()-1, val);
        }

        void add_range(ll i, ll j, ll l, ll r, ll val, ll node=1){
            update_and_propagate(l, r, node);

            if (i <= l && j >= r){ //current llerval is contained fully in [i..j]
                tree[node] += (r - l + 1) * val;//do update
                if (l != r){//if we're not at a leaf
                    lazy[node*2] += val;//mark update to be done later in both child nodes
                    lazy[node*2+1] += val;
                }
                return;
            } else if (i > r || j < l) { //current llerval is completely out of [i..j]
                return; 
            }

            ll mid = (l + r) / 2;
            add_range(i, j, l, mid, val, node*2);
            add_range(i, j, mid+1, r, val, node*2+1);
            tree[node] = tree[node*2] + tree[node*2+1];
        }

        //Checks if an update is pending for the current node and does it if necessary. Then it propagates the update downwards
        void update_and_propagate(ll l, ll r, ll node){
            if (lazy[node] != 0){//If pending updates to current node
                tree[node] += (r - l + 1) * lazy[node];//do the update.
                if (l != r){//not a leaf node
                    lazy[node*2] += lazy[node];//propagate the update one level downwards
                    lazy[node*2+1] += lazy[node];  
                }
                lazy[node] = 0;//remove the update for this node 
            }
        }
};

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n, c;
        cin >> n >> c;
        vector<ll> arr(n, 0);
        SegmentTree tree(arr);
        while (c--){
            int type;
            cin >> type;
            if (type == 0){
                int p, q, v;
                cin >> p >> q >> v;
                tree.add_range(p-1, q-1, v);
            } else {
                int p, q;
                cin >> p >> q;
                cout << tree.rsq(p-1, q-1) << "\n";
            }
        }

    }
}
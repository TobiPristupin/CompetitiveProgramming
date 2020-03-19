using namespace std;
#define ll long long
#include <bits/stdc++.h>

vector<ll> split(string s){
    istringstream iss(s);
    vector<ll> split(istream_iterator<ll>{iss}, istream_iterator<ll>());
    return split;
}


class SegmentTree {

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
                tree[node] = min(tree[node*2], tree[node*2+1]); //For sum queries
            }
        }

        ll rmq(ll i, ll j){
            return rmq(i, j, 0, arr.size()-1);
        }

        ll rmq(ll i, ll j, ll l, ll r, ll node=1){
            //i, j is the range for the query. l, r are the bounds for the current node
            //i and j are both inclusive
            update_and_propagate(l, r, node);

            if (i <= l && j >= r){ //current llerval is contained fully in [i..j]
                return tree[node];
            } else if (i > r || j < l) { //current llerval is completely out of [i..j]
                return pow(10, 6) + 1; //0 because it shouldn't affect the sum query. If doing a max query, return -infinity.
            }

            //current llerval is contained partially in [i..j]
            ll mid = (l + r) / 2;
            ll left = rmq(i, j, l, mid, node*2);
            ll right = rmq(i, j, mid + 1, r, node*2+1);
            return min(left, right); //combine according to query type
        }

        void add_range(ll i, ll j, ll val){
            add_range(i, j, 0, arr.size()-1, val);
        }

        void add_range(ll i, ll j, ll l, ll r, ll val, ll node=1){
            update_and_propagate(l, r, node);

            if (i <= l && j >= r){ //current llerval is contained fully in [i..j]
                tree[node] += val;//do update
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
            tree[node] = min(tree[node*2], tree[node*2+1]);
        }

        //Checks if an update is pending for the current node and does it if necessary. Then it propagates the update downwards
        void update_and_propagate(ll l, ll r, ll node){
            if (lazy[node] != 0){//If pending updates to current node
                tree[node] += lazy[node];//do the update.
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
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) cin >> arr[i];
    SegmentTree tree(arr);

    ll m;
    cin >> m;
    cin.ignore();
    while (m--){
        string l;
        getline(cin, l);
        vector<ll> query = split(l);
        ll i = query[0], j = query[1];
        if (query.size() == 2){
            if (i > j) cout << min(tree.rmq(i, n-1), tree.rmq(0, j)) << "\n";
            else cout << tree.rmq(i, j) << "\n";
        } else {
            ll v = query[2];
            if (i > j) {
                tree.add_range(i, n-1, v);
                tree.add_range(0, j, v);
            } else {
                tree.add_range(i, j, v);
            }
        }

        // for (auto x : tree.tree) cout << x << " ";
        // cout << endl;

    }
}
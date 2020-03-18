using namespace std;
#define ll long long
#include <bits/stdc++.h>

class SegmentTree {

    public:
        vector<int> arr, tree;
        SegmentTree(vector<int> arr){
            this->arr = arr;
            tree.assign(arr.size()*4, 2);
            build(0, arr.size()-1);
        }

        void build(int l, int r, int node=1){
            if (l == r){
                tree[node] = arr[l];
            } else {
                int mid = (l + r) / 2;
                build(l, mid, node*2);
                build(mid + 1, r, node*2+1);
                tree[node] = tree[node*2] * tree[node*2+1]; 
            }
        }

        int rpq(int i, int j){
            return rpq(i, j, 0, arr.size()-1);
        }

        int rpq(int i, int j, int l, int r, int node=1){
            //i, j is the range for the query. l, r are the bounds for the current node
            //i and j are both inclusive
            if (i <= l && j >= r){ //full coverage
                return tree[node];
            } else if (i > r || j < l) { //no coverage
                return 1; //0 because it shouldn't affect the sum query. If doing a max query, return -infinity.
            }

            //partial coverage
            int mid = (l + r) / 2;
            int left = rpq(i, j, l, mid, node*2);
            int right = rpq(i, j, mid + 1, r, node*2+1);
            return left * right; //combine according to query type
        }

        void update(int i, int val){
            update(i, 0, arr.size()-1, val);
        }

        void update(int i, int l, int r, int val, int node=1){
            if (i > r || i < l){
                return;
            }
            
            if (l == r){
                tree[node] = val;
                return;
            }

            int mid = (l + r) / 2;
            update(i, l, mid, val, node*2);
            update(i, mid+1, r, val, node*2+1);
            tree[node] = tree[node*2] * tree[node*2+1];
        }
};

int parse(int x){
    if (x > 0) return 1;
    else if (x < 0) return -1;
    else return 0;
}


int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k;
    while (cin >> n >> k){
        vector<int> arr(n);
        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            arr[i] = parse(x);
        }

        SegmentTree tree(arr);

        while (k--){
            char type;
            int i, j;
            cin >> type >> i >> j;
            if (type == 'P') {
                int ans = tree.rpq(i-1, j-1);
                if (ans > 0) cout << "+";
                else if (ans == 0) cout << 0;
                else cout << "-";

            } else {
                tree.update(i-1, parse(j));
            }
        }

        cout << "\n";
    }
}
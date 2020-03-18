using namespace std;
#define ll long long
#include <bits/stdc++.h>

class SegmentTree {
    //Sum implementation

    public:
        vector<int> arr, tree;
        SegmentTree(vector<int> arr){
            this->arr = arr;
            tree.assign(arr.size()*4, -1);
            build(0, arr.size()-1);
        }

        void build(int l, int r, int node=1){
            if (l == r){
                tree[node] = arr[l];
            } else {
                int mid = (l + r) / 2;
                build(l, mid, node*2);
                build(mid + 1, r, node*2+1);
                tree[node] = tree[node*2] + tree[node*2+1]; //For sum queries
            }
        }

        int rsq(int i, int j){
            return rsq(i, j, 0, arr.size()-1);
        }

        int rsq(int i, int j, int l, int r, int node=1){
            //i, j is the range for the query. l, r are the bounds for the current node
            //i and j are both inclusive
            if (i <= l && j >= r){ //full coverage
                return tree[node];
            } else if (i > r || j < l) { //no coverage
                return 0; //0 because it shouldn't affect the sum query. If doing a max query, return -infinity.
            }

            //partial coverage
            int mid = (l + r) / 2;
            int left = rsq(i, j, l, mid, node*2);
            int right = rsq(i, j, mid + 1, r, node*2+1);
            return left + right; //combine according to query type
        }

        void update(int i, int j, char type){
            update(i, j, 0, arr.size()-1, type);
        }

        void update(int i, int j, int l, int r, char type, int node=1){
            //Adds val to range [i..j] inclusive
            if (i > r || j < l) { //no coverage
                return;
            } else if (l == r){ //leaf node, do the update
                if (type == 'I'){
                    tree[node] = !tree[node];
                } else if (type == 'F'){
                    tree[node] = 1;
                } else {
                    tree[node] = 0;
                }
                return;
            }

            int mid = (l + r) / 2;
            update(i, j, l, mid, type, node*2);
            update(i, j, mid+1, r, type, node*2+1);
            tree[node] = tree[node*2] + tree[node*2+1];
        }
};

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int tc;
    cin >> tc;
    for (int tcase = 1; tcase <= tc; tcase++){
        int m;
        cin >> m;
        vector<int> pirates;
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
            if (type == 'I' || type == 'E' || type == 'F'){
                tree.update(i, j, type);
            } else {
                s_queries++;
                cout << "Q" << s_queries << ": " << tree.rsq(i, j) << "\n";
            }
        }
    }
}
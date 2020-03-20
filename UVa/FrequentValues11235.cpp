using namespace std;
#define ll long long
#include <bits/stdc++.h>

class SegmentTree {

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
                tree[node] = max(tree[node*2], tree[node*2+1]); 
            }
        }

        int rmq(int i, int j){
            return rmq(i, j, 0, arr.size()-1);
        }

        int rmq(int i, int j, int l, int r, int node=1){
            if (i <= l && j >= r){
                return tree[node];
            } else if (i > r || j < l){
                return INT_MIN;
            }
            
            int mid = (l + r) / 2;
            int left = rmq(i, j, l, mid, node*2);
            int right = rmq(i, j, mid + 1, r, node*2+1);
            return max(left, right); 


        }
};

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q;
    while (cin >> n >> q){
        vector<int> arr(n), freq(n);
        unordered_map<int, int> count;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            count[arr[i]]++;
        }

        for (int i = 0; i < n; i++){
            freq[i] = count[arr[i]];
        }

        SegmentTree tree(freq);
        
        while (q--){
            int i, j;
            cin >> i >> j;
            i--; j--;

            if (arr[i] == arr[j]){
                cout << j - i + 1 << "\n";
                continue;
            }

            int left_bound = i, right_bound = j;
            int left = INT_MIN, center = INT_MIN, right = INT_MIN; 
            if (i != 0 && arr[i-1] == arr[i]){
                while (left_bound < n - 1 && arr[left_bound] == arr[i]) left_bound++;
                left = left_bound - i;
            }

            if (j != n - 1 && arr[j+1] == arr[j]){
                while (right_bound > 0 && arr[right_bound] == arr[j]) right_bound--;
                right = j - right_bound;
            }

            center = tree.rmq(left_bound, right_bound);
            int ans = max({left, center, right});
            cout << ans << "\n";
        }
    }

}


#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
Fast IO: 
ios::sync_with_stdio(0), cin.tie(0);
*/

/*
Properties of mod:
(a+b) % m = (a mod m + b mod m) mod m
(a*b) % m = (a mod m * b mod m) mod m
*/

/*
Data Structures
vector - random access
deque - lrandom access, ike a vector but includes push_front and pop_front methods
list - Linked list, data is not contiguous. Fast insertion and deletion, no random access.
stack/queue - provide an interface that wraps around deque
bitset - optimized array of booleans
map/set
multiset - set with duplicates
priority_queue

adjacency matrix - Can only be used if V is known. V*V space complexity, only feasible if V < 1000. O(V) to enumerate neighbors
*/

/*
STL Methods
Sorting: sort, partial_sort (sort only a range), stable_sort (maintain initial order of items that are equal)
Searching: upper_bound (iterator pointing to first element greater than val in log n complexity, must be sorted beforehand), 
lower_bound (opposite from upper_bound), binary_search
*/

/*
Debug a segfault
g++ -g program.cpp
gdb ./a.out
run
backtrace
*/

vector<ll> sieve_erastothenes(unsigned ll limit){
    vector<bool> prime(limit, true);
    for (int p = 2; p*p <= limit; p++){
        if (prime[p]){
            for (int i = p*p; i <= limit; i += p){
                prime[i] = false;
            }
        }
    }

}

int num_divisors(ll n){
    vector<ll> primes = sieve_erastothenes(n);
    int total = 1;
    for (ll p : primes){
        int count = 0;
        while (n % p == 0){
            n = n / p;
            count++;
        }
        total *= (count + 1);
    }

    return total;
}


bool is_prime(ll n) { 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
    if (n % 2 == 0 || n % 3 == 0) return false; 
  
    for (ll i = 5; i * i <= n; i += 6) 
        if (n % i == 0 || n % (i+2) == 0) 
           return false; 
  
    return true; 
} 

class UnionFind {
    
    public:
        vector<int> id, size;
        int components;
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

        bool connected(int a, int b){ return find(a) == find(b);}

        int getSize(int a){return size[find(a)];}
};

bool power_of_two(ll x){
    return ((x & (x - 1)) == 0);
}

void rotate(vector<vector<int>> &vec){
    for (int i = 0; i < vec.size(); i++){
        for (int j = i + 1; j < vec.size(); j++){
            swap(vec[i][j], vec[j][i]);
        }
    }

    for (int r = 0; r < vec.size() / 2; r++){
        swap(vec[r], vec[vec.size() - r - 1]);
    }
}


vector<vector<int>> all_subsets(vector<int> vec){
    vector<vector<int>> subsets;
    int n = vec.size();
    // 1 << n is the same as 2**n
    for (int i = 0; i < (1 << n); i++){
        subsets.push_back(vector<int>());
        for (int j = 0; j < n; j++){
            if (i & (1 << j)){ //check if bit j is set
                subsets.back().push_back(vec[j]);
            }
        }
    }
    return subsets;
}

// class SegmentTree {
//     //Sum implementation with lazy propagation

//     public:
//         vector<int> arr, tree, lazy;
//         SegmentTree(vector<int> arr){
//             this->arr = arr;
//             tree.assign(arr.size()*4, -1);
//             lazy.assign(arr.size()*4, 0);
//             build(0, arr.size()-1);
//         }

//         void build(int l, int r, int node=1){
//             if (l == r){
//                 tree[node] = arr[l];
//             } else {
//                 int mid = (l + r) / 2;
//                 build(l, mid, node*2);
//                 build(mid + 1, r, node*2+1);
//                 tree[node] = tree[node*2] + tree[node*2+1]; //For sum queries
//             }
//         }

//         int rsq(int i, int j){
//             return rsq(i, j, 0, arr.size()-1);
//         }

//         int rsq(int i, int j, int l, int r, int node=1){
//             //i, j is the range for the query. l, r are the bounds for the current node
//             //i and j are both inclusive
//             update_and_propagate(l, r, node);

//             if (i <= l && j >= r){ //current interval is contained fully in [i..j]
//                 return tree[node];
//             } else if (i > r || j < l) { //current interval is completely out of [i..j]
//                 return 0; //0 because it shouldn't affect the sum query. If doing a max query, return -infinity.
//             }

//             //current interval is contained partially in [i..j]
//             int mid = (l + r) / 2;
//             int left = rsq(i, j, l, mid, node*2);
//             int right = rsq(i, j, mid + 1, r, node*2+1);
//             return left + right; //combine according to query type
//         }

//         void add_range(int i, int j, int val){
//             add_range(i, j, 0, arr.size()-1, val);
//         }

//         void add_range(int i, int j, int l, int r, int val, int node=1){
//             update_and_propagate(l, r, node);

//             if (i <= l && j >= r){ //current interval is contained fully in [i..j]
//                 tree[node] += (r - l + 1) * val;//do update
//                 if (l != r){//if we're not at a leaf
//                     lazy[node*2] += val;//mark update to be done later in both child nodes
//                     lazy[node*2+1] += val;
//                 }
//                 return;
//             } else if (i > r || j < l) { //current interval is completely out of [i..j]
//                 return; 
//             }

//             int mid = (l + r) / 2;
//             add_range(i, j, l, mid, val, node*2);
//             add_range(i, j, mid+1, r, val, node*2+1);
//             tree[node] = tree[node*2] + tree[node*2+1];
//         }

//         //Checks if an update is pending for the current node and does it if necessary. Then it propagates the update downwards
//         void update_and_propagate(int l, int r, int node){
//             if (lazy[node] != 0){//If pending updates to current node
//                 tree[node] += (r - l + 1) * lazy[node];//do the update.
//                 if (l != r){//not a leaf node
//                     lazy[node*2] += lazy[node];//propagate the update one level downwards
//                     lazy[node*2+1] += lazy[node];  
//                 }
//                 lazy[node] = 0;//remove the update for this node 
//             }
//         }
// };

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
                tree[node] = max(tree[node*2], tree[node*2+1]); //For sum queries
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

                tree[node] = tree[node*2] + tree[node*2+1];
            }
        }
};

void bfs(vector<vector<int>> graph, int start){
    vector<bool> visited(graph.size(), false);
    queue<int> search;
    search.push(start);

    while (!search.empty()){
        int node = search.front();
        search.pop();
        if (!visited[node]){
            visited[node] = true;
            for (int neighbor : graph[node]){
                search.push(neighbor);
            }
        }
    }
}



int main(){
    vector<int> arr = {2, 2, 4, 4, 4, 4, 1, 3, 3, 3};
    SegmentTree tree(arr);
    for (auto x : tree.tree) cout << x << " ";
    cout << endl;
}
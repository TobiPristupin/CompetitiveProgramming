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

        void add_range(int i, int j, int val){
            add_range(i, j, 0, arr.size()-1, val);
        }

        void add_range(int i, int j, int l, int r, int val, int node=1){
            //Adds val to range [i..j] inclusive
            if (i > r || j < l) { //no coverage
                return;
            } else if (l == r){ //leaf node, do the update
                tree[node] += val; //change according to query type
                return;
            }

            int mid = (l + r) / 2;
            add_range(i, j, l, mid, val, node*2);
            add_range(i, j, mid+1, r, val, node*2+1);
            tree[node] = tree[node*2] + tree[node*2+1];
        }
};




int main(){

}
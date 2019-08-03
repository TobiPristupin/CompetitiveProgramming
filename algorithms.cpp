#include <bits/stdc++.h>
using namespace std;
#define ll long long

//ios::sync_with_stdio(0), cin.tie(0);

/*
Properties of mod:
(a+b) % m = (a mod m + b mod m) mod m
(a*b) % m = (a mod m * b mod m) mod m
*/

/*
vector - random access
deque - lrandom access, ike a vector but includes push_front and pop_front methods
list - Linked list, data is not contiguous. Fast insertion and deletion, no random access.
stack/queue - provide an interface that wraps around deque
bitset - optimized array of booleans
map/set
multiset - set with duplicates
priority_queue

adjacency matrix - Can only be used if V is known. V*V space complexity, only feasible if V < 1000. O(V) to enumerate neighbors
adjacency list - 
 */


//string to binary using mod properties to avoid overflow. Remember to mod again if required
ll string_to_binary_mod(string bin, ll mod){
    ll sum = 0;
    reverse(bin.begin(), bin.end());
    for(int i = 0; i < bin.length(); i++){
        sum += fmod((stoll(bin.substr(i, 1)) * pow(2, i)), mod);
    }

    return sum;
}

//Example convert to base
ll to_ternary(ll x){
    string digits = "";
    lldiv_t divmod;
    do {
        divmod = div(x, 3LL);
        x = divmod.quot;
        digits += to_string(divmod.rem);
        
    } while (x > 0);

    reverse(digits.begin(), digits.end());
    return stoll(digits);
}


string to_base(ll x, ll b){
    string letters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string digits = "";
    lldiv_t divmod;

    if (b == 1){
        for (int i = 0; i < x; i++){
            digits += "1";
        }
        return digits;
    }

    do {
        divmod = div(x, b);
        x = divmod.quot;
        digits += letters.at(divmod.rem);
    } while (x > 0);

    reverse(digits.begin(), digits.end());
    return digits;
}

//Example convert from base to decimal
ll from_ternary(ll x){
    ll sum = 0, digit = 0;
    do {
        sum += (x % 10) * pow(3, digit);
        digit++;
        x /= 10;
    } while (x > 0);
    
    return sum;
}

vector<ll> sieve_erastothenes(unsigned ll limit){
    vector<bool> prime(limit, true);
    for (int p = 2; p*p <= limit; p++){
        if (prime[p]){
            for (int i = p*p; i <= limit; i += p){
                prime[i] = false;
            }
        }
    }

    vector<ll> ans;
    for (int i = 2; i <= limit; i++){
        if (prime[i]){
            ans.push_back(i);
        }
    }

    return ans;
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

ll binary_search(vector<ll> vec, ll x){
    ll lo = 0, hi = vec.size() - 1, mid;
    while (lo <= hi){
        mid = (lo + hi) / 2;
        if (vec.at(mid) < x){
            lo = mid + 1;
        } else if (vec.at(mid) > x){
            hi = mid - 1;
        } else {
            return mid;
        }
    }

    return -1;
}

bool valid_parenthesis(string s){
    stack<char> stak;
    vector<char> opening = {'('}, closing = {')'};
    for (char c : s){
        if (find(opening.begin(), opening.end(), c) != opening.end()){
            stak.push(c);
        } else if (find(closing.begin(), closing.end(), c) != closing.end()){
            int index = distance(find(closing.begin(), closing.end(), c), closing.begin());
            if (stak.empty() || stak.top() != opening[index]){
                return false;
            }
            stak.pop();
        }
    }

    return stak.empty();
}

// int component_size(const char &start){
//     if (visited[start]){
//         return 0;
//     }

//     visited[start] = true;
//     int sum =  1;
//     for (char neighbor : graph[start]){
//         sum += component_size(neighbor);
//     }
    
//     return sum;
// }

ll circle_mod(ll x, ll m){
    if (x == m){
        return x;
    }
    return (x > 0) ? x % m : (x + m) % m;
}

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

        bool connected(int a, int b){ return find(a) == find(b);}

        int getComponents(){return components;}

        int getSize(int a){return size[find(a)];}

        vector<int> getArr(){return id;}
};

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

//Add two strings that could overflow if treated as numbers
string add_strings(string a, string b){
    string ans = "";
    bool carry = false;
    while (a.length() < b.length()) a = "0" + a;
    while (b.length() < a.length()) b = "0" + b;
    for (int i = a.length() - 1; i >= 0; i--){
        int sum = stoi(a.substr(i, 1)) + stoi(b.substr(i, 1));
        if (carry){
            sum++;
            carry = false;
        }
        if (sum >= 10){
            carry = true;
            sum -= 10;
        }
        ans = to_string(sum) + ans;
    }
    if (carry) ans = "1" + ans;
    return ans;
}

//compare two numbers stored as strings to avoid overflow
bool compare_strings(string a, string b){
    while (a.front() == '0') a.erase(a.begin());
    while (b.front() == '0') b.erase(b.begin());
    if (a.length() != b.length()) return a.length() > b.length();
    for (int i = 0; i < a.length(); i++){
        if (stoi(a.substr(i, 1)) > stoi(b.substr(i, 1))) return true;
        if (stoi(a.substr(i, 1)) < stoi(b.substr(i, 1))) return false;
    }
    return true; 
}

int main(){
    vector<ll> vec {1, 2, 3, 4, 5, 6, 7, 8};
    cout << compare_strings("20", "020") << "\n";
    
    // UnionFind disjoint = UnionFind(10);

    // for (auto x : disjoint.getArr()) cout << x << " ";
    // cout << endl;

    // disjoint.unite(1, 2);
    // disjoint.unite(0, 2);
    // disjoint.unite(8, 9);
    // disjoint.unite(8, 1);
    // cout << disjoint.getSize(2) << endl;
    // disjoint.unite(6, 5);
    // cout << disjoint.getSize(6) << endl;
    

    
    // for (auto x : disjoint.getArr()) cout << x << " ";
    // cout << endl;    
}
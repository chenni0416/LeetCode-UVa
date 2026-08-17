### `std::vector`

**Core Time Complexity:** Access: $O(1)$, Push/Pop Back: $O(1)$ amortized, Insert/Erase: $O(N)$

```cpp
#include <vector>
#include <numeric>

// Initialization & Resizing (Essential for DP Tables & Graph Adjacency Lists)
std::vector<int> v;                                  // Args: None. Returns: Empty vector
std::vector<int> v2(10, -1);                         // Args: (size_t count, const T& value). Returns: Vector of size 10 filled with -1
std::vector<std::vector<int>> dp(5, std::vector<int>(10, 0)); // 2D DP table: 5 rows, 10 columns initialized to 0

// Modifying
v.push_back(5);                                      // Args: (const T& value). Returns: void. (Adds to end)
v.pop_back();                                        // Args: None. Returns: void. (Removes last element)
v.resize(15, 0);                                     // Args: (size_t count, const T& value). Returns: void. (Resizes to 15, fills new with 0)
v.assign(5, 1);                                      // Args: (size_t count, const T& value). Returns: void. (Replaces contents with five 1s)

// Capacity & Access
bool is_empty = v.empty();                           // Args: None. Returns: bool (true if size == 0)
size_t sz = v.size();                                // Args: None. Returns: size_t (number of elements)
int first_elem = v.front();                          // Args: None. Returns: reference to first element
int last_elem = v.back();                            // Args: None. Returns: reference to last element

```

### `std::deque`

**Core Time Complexity:** Push/Pop Front/Back: $O(1)$, Access: $O(1)$

```cpp
#include <deque>

// Initialization (Crucial for Sliding Window Maximum & Monotonic Queues)
std::deque<int> dq;                                  // Args: None. Returns: Empty deque

// Modifying (Double-ended operations)
dq.push_back(10);                                    // Args: (const T& value). Returns: void. (Adds to back)
dq.push_front(20);                                   // Args: (const T& value). Returns: void. (Adds to front)
dq.pop_back();                                       // Args: None. Returns: void. (Removes from back)
dq.pop_front();                                      // Args: None. Returns: void. (Removes from front)

// Access
int front_val = dq.front();                          // Args: None. Returns: reference to first element
int back_val = dq.back();                            // Args: None. Returns: reference to last element

```

### `std::stack` & `std::queue`

**Core Time Complexity:** Push, Pop, Top/Front: $O(1)$

```cpp
#include <stack>
#include <queue>

// std::stack (Crucial for DFS, Monotonic Stack)
std::stack<int> st;                                  // Args: None. Returns: Empty stack
st.push(5);                                          // Args: (const T& value). Returns: void.
int top_val = st.top();                              // Args: None. Returns: reference to top element (LIFO)
st.pop();                                            // Args: None. Returns: void. (Does NOT return the element)

// std::queue (Crucial for BFS, Topological Sort/Kahn's Algorithm)
std::queue<int> q;                                   // Args: None. Returns: Empty queue
q.push(10);                                          // Args: (const T& value). Returns: void.
int front_val = q.front();                           // Args: None. Returns: reference to first element (FIFO)
q.pop();                                             // Args: None. Returns: void. (Does NOT return the element)

```

### `std::priority_queue`

**Core Time Complexity:** Push/Pop: $O(\log N)$, Top: $O(1)$

```cpp
#include <queue>
#include <vector>

// Max-Heap (Default behavior)
std::priority_queue<int> max_pq;                     // Args: None. Returns: Empty max-heap

// Min-Heap (Crucial for Dijkstra's, Top K smallest, Prim's MST)
std::priority_queue<int, std::vector<int>, std::greater<int>> min_pq; // Args: (Type, Container, Comparator)

// Modifying & Access
max_pq.push(15);                                     // Args: (const T& value). Returns: void. (Inserts and percolates up)
int highest = max_pq.top();                          // Args: None. Returns: const reference to largest element
max_pq.pop();                                        // Args: None. Returns: void. (Removes top element, percolates down)

// Custom Comparator (e.g., pairs sorted by second element ascending)
auto cmp = [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.second > b.second;                      // Returns true if 'a' should be placed below 'b'
};
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> custom_pq(cmp);

```

### `std::unordered_map` & `std::unordered_set`

**Core Time Complexity:** Insert/Search/Erase: $O(1)$ average, $O(N)$ worst-case

```cpp
#include <unordered_map>
#include <unordered_set>

// std::unordered_map (Crucial for Two-Sum, Frequency Arrays, Prefix Sum Hash Maps)
std::unordered_map<int, int> freq;                   // Args: None. Returns: Empty hash map
freq[5] = 10;                                        // Args: [key]. Returns: reference to value. (Inserts if missing)
auto it = freq.find(5);                              // Args: (const Key& key). Returns: Iterator to element, or end() if not found
bool exists = (it != freq.end());                    // Check if element exists
int count = freq.count(5);                           // Args: (const Key& key). Returns: size_t (1 if exists, 0 otherwise)
freq.erase(5);                                       // Args: (const Key& key). Returns: size_t (number of elements removed)

// std::unordered_set (Crucial for DSU visited nodes, Graph connectivity checks)
std::unordered_set<int> visited;                     // Args: None. Returns: Empty hash set
visited.insert(10);                                  // Args: (const T& value). Returns: std::pair<iterator, bool> (bool is true if newly inserted)

```

### Binary Search Algorithms (`std::lower_bound`, `std::upper_bound`)

**Core Time Complexity:** $O(\log N)$ (Requires sorted range)

```cpp
#include <vector>
#include <algorithm>

std::vector<int> arr = {10, 20, 30, 30, 30, 40, 50}; // Must be sorted

// std::lower_bound (First element >= val. Crucial for LIS $O(N \log N)$)
auto lb = std::lower_bound(arr.begin(), arr.end(), 30); // Args: (Iterator first, Iterator last, const T& val)
int lb_idx = std::distance(arr.begin(), lb);            // Returns: 2 (Index of first 30)

// std::upper_bound (First element > val. Crucial for Bisection spaces)
auto ub = std::upper_bound(arr.begin(), arr.end(), 30); // Args: (Iterator first, Iterator last, const T& val)
int ub_idx = std::distance(arr.begin(), ub);            // Returns: 5 (Index of 40)

// std::binary_search (Boolean check only)
bool found = std::binary_search(arr.begin(), arr.end(), 30); // Args: (Iterator first, Iterator last, const T& val). Returns: true

```

### `std::bitset` & DP Array Initialization

**Core Time Complexity:** Bitset Ops: $O(1)$ or $O(N/64)$, Memset: $O(N)$

```cpp
#include <bitset>
#include <cstring>

// std::memset (Crucial for 2D/3D array DP initialization)
int memo[100][100];
std::memset(memo, -1, sizeof(memo));                 // Args: (void* dest, int ch, size_t count). Returns: void*. (Fills with -1)
std::memset(memo, 0, sizeof(memo));                  // Fills with 0. WARNING: Only use 0 or -1 for integers.

// std::bitset (Crucial for Bitmask DP, fast subsets)
std::bitset<32> mask(10);                            // Args: (unsigned long long val). Returns: Bitset representing 1010
bool is_set = mask.test(1);                          // Args: (size_t pos). Returns: bool (true if bit at pos 1 is 1)
mask.set(2);                                         // Args: (size_t pos). Returns: reference to bitset. (Sets bit 2 to 1)
mask.flip(0);                                        // Args: (size_t pos). Returns: reference to bitset. (Inverts bit 0)
int total_ones = mask.count();                       // Args: None. Returns: size_t (Number of 1 bits, i.e., Brian Kernighan's / popcount)

```

### String Manipulation & Permutations

**Core Time Complexity:** Substr/Find: $O(N)$, Next_permutation: $O(N)$, Reverse: $O(N)$

```cpp
#include <string>
#include <algorithm>

std::string s = "competitive";

// Substrings (Crucial for Interval DP / String DP)
std::string sub = s.substr(0, 4);                    // Args: (size_t pos, size_t count). Returns: std::string ("comp")

// Searching (Crucial for string matching algorithms)
size_t idx = s.find("pet");                          // Args: (const std::string& str). Returns: size_t (starting index, or std::string::npos)
bool is_found = (idx != std::string::npos);          // std::string::npos represents max value of size_t (-1)

// Reverse (Crucial for Palindromes, LCS reconstruction)
std::reverse(s.begin(), s.end());                    // Args: (Iterator first, Iterator last). Returns: void. (Modifies in-place)

// std::next_permutation (Crucial for Traveling Salesperson brute force, N! constraints)
std::string p = "abc";                               // MUST be sorted initially to get all permutations
bool has_next = std::next_permutation(p.begin(), p.end()); // Args: (Iterator first, Iterator last). Returns: bool (true if next lexicographical permutation exists)

```

### `std::pair` & Custom `struct`

**Core Time Complexity:** Creation/Access: $O(1)$, Sorting Structs: $O(N \log N)$

```cpp
#include <utility>
#include <vector>
#include <algorithm>

// std::pair (Crucial for Graph Adjacency Lists, 2D Grid coordinates)
std::pair<int, int> p1 = {1, 2};                      // Args: (T1, T2). Returns: initialized pair
std::pair<int, int> p2 = std::make_pair(3, 4);        // Args: (T1, T2). Returns: std::pair
int r = p1.first;                                     // Args: None. Returns: 1 (reference to first element)
int c = p1.second;                                    // Args: None. Returns: 2 (reference to second element)

// Array of pairs (Used heavily in BFS/DFS for 2D grids)
std::vector<std::pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

// Custom struct (Crucial for DSU edges, Dijkstra states, Sweep Line algorithms)
struct Edge {
    int u, v, weight;
    
    // Custom comparator for sorting (Crucial for Kruskal's MST)
    bool operator<(const Edge& other) const {
        return weight < other.weight;                 // Args: (const Edge&). Returns: bool (Ascending order by weight)
    }
};

std::vector<Edge> edges = {{0, 1, 10}, {1, 2, 5}};
std::sort(edges.begin(), edges.end());                // Args: (Iterator first, Iterator last). Returns: void (Uses overloaded operator<)

```

### Iterators, Loops & Hash Map Auto-Initialization

**Core Time Complexity:** Iteration: $O(N)$, Hash Map Auto-insertion: $O(1)$ average

```cpp
#include <unordered_map>
#include <vector>

std::vector<int> arr = {5, 5, 2, 2, 2, 8};
std::unordered_map<int, int> freq;

// Traditional For-Loop & Hash Map Feature (Crucial for frequency counting)
for (int i = 0; i < arr.size(); ++i) {
    // STL Feature: Direct Increment
    // If arr[i] is not in map, it auto-initializes to 0 (default constructor), then increments.
    freq[arr[i]]++;                                   // Args: [key]. Returns: reference to value. 
}

// Range-Based For-Loop (Modifying elements in-place)
for (auto& num : arr) {                               // '&' takes by reference
    num *= 2;                                         // Directly modifies the elements inside 'arr'
}

// Range-Based For-Loop with Structured Binding [C++17] (Crucial for Hash Maps)
for (const auto& [key, val] : freq) {                 // 'const auto&' prevents copying, read-only
    int current_key = key;                            // Access key directly
    int current_val = val;                            // Access value directly
}

// Explicit Iterators (Crucial for safe element removal during iteration)
for (auto it = freq.begin(); it != freq.end(); ) {    // No '++it' in the loop signature
    if (it->second == 1) {
        // Safe deletion: erase returns iterator to the next valid element
        it = freq.erase(it);                          // Args: (Iterator). Returns: Iterator to next element
    } else {
        ++it;                                         // Move to next element manually
    }
}

```

### Input / Output (Fast I/O & `std::cout`)

**Core Time Complexity:** $O(1)$ per operation, drastically reduces constant factor overhead

```cpp
#include <iostream>
#include <vector>

void fast_io_setup() {
    // Fast I/O Trick 1: Disables synchronization between C and C++ standard streams
    // Crucial to prevent Time Limit Exceeded (TLE) in CP
    std::ios_base::sync_with_stdio(false);            // Args: (bool sync). Returns: previous state

    // Fast I/O Trick 2: Unties std::cin from std::cout
    // Prevents std::cout from auto-flushing every time std::cin is called
    std::cin.tie(NULL);                               // Args: (ostream* tiestr). Returns: tied stream
}

void process_input_output() {
    int n;
    std::cin >> n;                                    // Reads input quickly

    std::vector<int> results(n, 42);

    for (int i = 0; i < n; ++i) {
        // Fast I/O Trick 3: ALWAYS use '\n' instead of std::endl
        // std::endl forces a buffer flush which is extremely slow in loops
        std::cout << results[i] << (i == n - 1 ? "" : " "); // Prints space-separated
    }
    std::cout << '\n';                                // Single flush at the very end
}

```
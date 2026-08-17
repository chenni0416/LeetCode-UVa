Here is your comprehensive Dynamic Programming (DP) Review Cheat Sheet, structured for high-yield retention and quick reference during technical interviews and competitive programming.

---

## Section 1: Recognition Signals & Constraint Analysis

### Problem Keywords & Cues

When reading a problem statement, look for these explicit phrasing patterns that strongly suggest a DP approach:

* **Optimization:** "Find the minimum/maximum steps, cost, or profit to achieve $X$."
* **Combinatorics:** "Find the total number of unique ways/paths to reach $Y$."
* **Existence/Possibility:** "Determine if it is possible to partition the array into subsets..." or "Can you reach target $T$?"
* **String Manipulation:** "Minimum operations to transform string $A$ to string $B$" or "Longest common sequence/substring."
* **Game Theory:** "Assuming both players play optimally, who wins?"

### Constraint & Complexity Mapping

In competitive programming, the input constraint $N$ is the strongest hint for the intended state dimensions and time complexity.

| Input Size Constraint | Target Time Complexity | Expected DP Archetype / State Dimensions |
| --- | --- | --- |
| $N \le 20$ | $O(2^N \cdot N)$ | **Bitmask DP** (Subset iteration, TSP) |
| $N \le 400$ | $O(N^3)$ | **Interval DP** (Matrix Chain, Burst Balloons) |
| $N \le 2000$ | $O(N^2)$ | **2D DP** (LCS, Edit Distance, 0-1 Knapsack) |
| $N \le 10^5 \text{ or } 10^6$ | $O(N)$ or $O(N \log N)$ | **1D DP** (Kadane's, House Robber, LIS with Binary Search) |
| $N \ge 10^{18}$ | $O(\log N)$ or $O(\text{digits})$ | **Digit DP** or **Matrix Exponentiation** |

### DP vs. Greedy vs. Backtracking vs. Graph

Use this checklist to rule out alternative paradigms before committing to DP:

* **Greedy vs. DP:** If you make a local optimal choice, does it restrict future optimal choices? If earlier choices change the optimal substructure of later choices, Greedy fails. Use DP.
* **Backtracking vs. DP:** Are subproblems overlapping? If you compute the exact same state (same index, same remaining capacity) multiple times, pure Backtracking will TLE. Add memoization (DP).
* **Graph (BFS/Dijkstra) vs. DP:** Can the state space have cycles? If states can revisit previous states cyclically, use Graph algorithms. If the state space is strictly a Directed Acyclic Graph (DAG), use DP.

---

## Section 2: Core DP Archetypes & Problem Patterns

### 1. 0-1 Knapsack

* **Canonical Problem:** Maximize value given items with weights, each item used at most once.
* **State Definition:** 2D. $dp[i][w]$ = Max value using first $i$ items with exact weight capacity $w$.
* **Recurrence Relation:**

$$dp[i][w] = \max(dp[i-1][w], dp[i-1][w-weight[i]] + value[i])$$


* **Base Cases & Iteration:** $dp[0][w] = 0$. Iterate $i$ from $1$ to $N$, $w$ from $1$ to $W$.
* **Variations:** Subset Sum, Partition Equal Subset Sum, Target Sum.

### 2. Unbounded Knapsack

* **Canonical Problem:** Coin Change (minimum coins to make amount $V$). Items can be used infinitely.
* **State Definition:** 1D. $dp[w]$ = Minimum coins to make amount $w$.
* **Recurrence Relation:**

$$dp[w] = \min_{i} (dp[w], dp[w-weight[i]] + 1)$$


* **Base Cases & Iteration:** $dp[0] = 0$, rest $\infty$. Iterate $w$ from $1$ to $W$ forward.
* **Variations:** Rod Cutting, Maximum Ribbon Cut.

### 3. Longest Common Subsequence (LCS)

* **Canonical Problem:** Find the longest subsequence present in both strings $A$ and $B$.
* **State Definition:** 2D. $dp[i][j]$ = Length of LCS for prefix $A[0..i-1]$ and $B[0..j-1]$.
* **Recurrence Relation:**
If $A[i-1] == B[j-1]$:

$$dp[i][j] = dp[i-1][j-1] + 1$$



Else:

$$dp[i][j] = \max(dp[i-1][j], dp[i][j-1])$$


* **Base Cases & Iteration:** $dp[0][j] = 0$ and $dp[i][0] = 0$. Forward iteration for both $i$ and $j$.
* **Variations:** Edit Distance, Longest Palindromic Subsequence, Shortest Common Supersequence.

### 4. Longest Increasing Subsequence (LIS)

* **Canonical Problem:** Length of longest strictly increasing subsequence in array $A$.
* **State Definition:** 1D. $dp[i]$ = Length of LIS ending exactly at index $i$.
* **Recurrence Relation:**

$$dp[i] = \max_{j < i, A[j] < A[i]} (dp[j] + 1)$$


* **Base Cases & Iteration:** All $dp[i] = 1$. Forward iteration.
* **Variations:** Russian Doll Envelopes, Largest Divisible Subset. *(Note: $O(N \log N)$ optimization requires patience sorting / binary search, replacing the DP array meaning).*

### 5. Kadane's Algorithm (Maximum Subarray)

* **Canonical Problem:** Find the contiguous subarray with the largest sum.
* **State Definition:** 1D (often compressed). $dp[i]$ = Maximum subarray sum ending exactly at index $i$.
* **Recurrence Relation:**

$$dp[i] = \max(A[i], dp[i-1] + A[i])$$


* **Base Cases & Iteration:** $dp[0] = A[0]$. Forward iteration.
* **Variations:** Maximum Product Subarray, Maximum Subarray Circular.

### 6. Interval DP

* **Canonical Problem:** Matrix Chain Multiplication, Minimum cost to merge stones.
* **State Definition:** 2D. $dp[l][r]$ = Optimal cost to solve the subarray from index $l$ to $r$.
* **Recurrence Relation:**

$$dp[l][r] = \min_{l \le k < r} (dp[l][k] + dp[k+1][r] + cost[l][r])$$


* **Base Cases & Iteration:** $dp[i][i] = 0$. Iterate by **length** of the interval ($length$ from $2$ to $N$), then by starting index $l$.
* **Variations:** Burst Balloons, Palindrome Partitioning.

### 7. Bitmask DP

* **Canonical Problem:** Traveling Salesperson Problem (TSP), Assigning Jobs.
* **State Definition:** 2D. $dp[mask][i]$ = Min cost to visit subset of nodes represented by `mask`, ending at node $i$.
* **Recurrence Relation:**

$$dp[mask][i] = \min_{j \in mask, j \neq i} (dp[mask \setminus \{i\}][j] + cost[j][i])$$


* **Base Cases & Iteration:** $dp[1 \ll start][start] = 0$. Iterate `mask` from $1$ to $(1 \ll N) - 1$.
* **Variations:** Hamiltonian Path, Minimum XOR Sum of Two Arrays.

---

## Section 3: State Design & Dimension Blueprint

### 1D States

Use when the problem scales strictly sequentially and previous constraints do not carry over.

* **Examples:** House Robber ($dp[i]$ = max money up to house $i$), Decoding Ways ($dp[i]$ = ways to decode prefix $i$).
* **Key Question:** "Does knowing just the current index give me enough info to make the next choice?"

### 2D States

Use when two distinct parameters govern the problem space.

* **Index + Capacity:** Standard Knapsack ($i$, $w$).
* **Sequence A + Sequence B:** String matching ($i$, $j$).
* **Subarray Bounds:** Interval problems ($l$, $r$).

### 3D & Multi-Parameter States

Add dimensions when explicit limits, directions, or boolean flags are introduced.

* **Explicit Limits:** Stock Trading with $k$ transactions. $dp[i][k][flag]$ = index $i$, $k$ transactions used, $flag$ for currently holding stock.
* **Grid Restrictions:** Pathfinding with $k$ obstacle removals. $dp[r][c][k]$.

### Bitmask / Bit Compression

Use a 32-bit or 64-bit integer to represent a set of booleans when $N \le 20$.

* **State Representation:** `mask = 5` (binary `101`) means items 0 and 2 are active/visited.
* **Bitwise Operations:**
* Check if $i$-th bit is set: `(mask & (1 << i)) != 0`
* Set $i$-th bit: `mask | (1 << i)`
* Unset $i$-th bit: `mask & ~(1 << i)`



---

## Section 4: Implementation Strategy & Optimization Techniques

### Top-Down (Memoization) vs. Bottom-Up (Tabulation)

| Feature | Top-Down (Memoization) | Bottom-Up (Tabulation) |
| --- | --- | --- |
| **Logic & Structure** | Intuitive, mimics the mathematical recurrence naturally. | Requires figuring out exact topological sort / loop order. |
| **State Space** | Computes **only** visited states. Ideal for sparse state spaces. | Computes **all** states up to the target. Best for dense matrices. |
| **Performance Risk** | Recursion stack overhead; risk of Stack Overflow. | No stack overhead; generally faster constant factors. |
| **Space Optimization** | Highly difficult to compress memory dynamically. | Easily supports space rolling (e.g., $O(N) \rightarrow O(1)$). |

### Space Optimization Patterns

**1. Rolling Arrays (Reducing Matrix to Array)**
Whenever $dp[i][\dots]$ only depends on $dp[i-1][\dots]$, you can drop the $i$ dimension.

* **0-1 Knapsack (Reverse Iteration):** To prevent an item from being reused in the same step, update the 1D array backward.
`for w from W down to weight[i]: dp[w] = max(dp[w], dp[w - weight[i]] + value[i])`
* **Unbounded Knapsack (Forward Iteration):** To allow multiple uses, update forward.
`for w from weight[i] to W: dp[w] = max(dp[w], dp[w - weight[i]] + value[i])`

**2. State Variable Compression (Reducing Array to Scalars)**
When $dp[i]$ only depends on a fixed number of previous states ($dp[i-1]$ and $dp[i-2]$).

* **Fibonacci / House Robber:** Keep variables `prev1` and `prev2`. Update them sequentially in $O(1)$ space.

---

## Section 5: Step-by-Step Problem Solving Framework

When facing an unknown DP problem under pressure, execute this 5-step checklist:

1. **Identify the Subproblem & DAG Topology:**
Break the main problem into smaller, independent chunks. Map out visually how a small example transitions to the next step. Ensure there are no cyclic dependencies.
2. **Define the Exact Semantic Meaning of `dp[...]`:**
Write down a plain English sentence defining your state. (e.g., *"Let $dp[i][k]$ be the maximum profit on day $i$ having completed at most $k$ transactions."*) Do not skip this; vague definitions lead to broken logic.
3. **Formulate the State Transition & Boundary Conditions:**
Translate the physical choices (take it, leave it, split it) into a mathematical recurrence. Define the base cases explicitly (e.g., array length 0, capacity 0, out of bounds).
4. **Choose the Iteration Order / Topological Order:**
Determine if you need to iterate left-to-right, right-to-left, by interval length, or via bitmask numeric order. The rule is: *Every state required by the recurrence must be calculated before the current state.*
5. **Apply Space Compression if Constraints Demand:**
Start with the unoptimized $N$-dimensional array to ensure correctness. Once the logic holds, analyze memory limits. If you only look back $1$ step, implement a rolling array.
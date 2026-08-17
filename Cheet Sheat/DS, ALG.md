Welcome to your competitive programming and technical interview cheat sheet. As a Principal Coach, my goal is to strip away the noise and give you the pure, high-yield signals you need to map problem descriptions directly to optimal solutions.

Memorize this framework. It will transform how you approach technical assessments.

---

### Section 1: Constraint Analysis & Time Complexity Mapping

In competitive programming, the input constraint ($N$) is the biggest hint the problem author gives you. Use this table to immediately deduce the expected time complexity and filter your algorithm choices.

| Input Size ($N$) | Target Time Complexity | Expected Algorithm / Data Structure |
| --- | --- | --- |
| $N \le 12$ | $O(N!)$ | Permutations, Backtracking, Traveling Salesperson (TSP) |
| $N \le 25$ | $O(2^N)$ | Combinations, Subsets, Backtracking, Bitmask DP |
| $N \le 100$ | $O(N^3)$ | Floyd-Warshall, Matrix Multiplication, 3D DP |
| $N \le 10^4$ | $O(N^2)$ | Nested Loops, 2D DP, Insertion/Selection Sort |
| $N \le 10^5$ | $O(N \log N)$ | Sorting, Binary Search, Heap, Divide & Conquer, Segment Trees |
| $N \le 10^6 \text{ or } 10^7$ | $O(N)$ | Two Pointers, Sliding Window, Monotonic Stack, Prefix Sum, Hash Map |
| $N \ge 10^9$ | $O(\log N)$ or $O(1)$ | Binary Search (on Answer), Math formulas, Bit Manipulation |

---

### Section 2: Recognition Keywords & Problem Paradigms

Interviews and CP problems are often standard algorithms heavily disguised by lore. When you read a problem, scan for these specific triggers.

| Keyword / Phrase in Problem | Intended Algorithmic Paradigm |
| --- | --- |
| "Explore all configurations", "Find all valid..." | Backtracking / DFS |
| "Minimize the maximum", "Maximize the minimum" | Binary Search on Answer (Bisection) |
| "Contiguous subarray/substring matching a condition" | Sliding Window |
| "Pairs in a sorted array" | Two Pointers |
| "Next greater/smaller element" | Monotonic Stack |
| "Top K", "Dynamically finding min/max" | Heap / Priority Queue |
| "Connectivity", "Grouping", "Number of islands (dynamic)" | Union-Find (DSU) |
| "Shortest path in an unweighted graph" | BFS (Breadth-First Search) |

---

### Section 3: The Search Space (Binary Search & Bisection)

Binary search is not just for finding numbers in a sorted array; it is a powerful optimization technique for navigating massive search spaces in $O(\log N)$ time.

* **Standard Binary Search:** Used for finding exact elements, lower bounds, or upper bounds in a pre-sorted array. It relies on the array's inherent order to halve the search space at each step.
* **Bisection (Binary Search on Answer):** Used when the answer lies within a known continuous range, and the problem asks you to optimize a threshold (e.g., *Koko Eating Bananas*, *Book Allocation*).
* **The Paradigm:** You define a monotonic boolean predicate function `isValid(x)` that returns `True` if threshold $x$ is possible, and `False` otherwise.
* **The Execution:** Because the output of `isValid(x)` flips exactly once (e.g., `[F, F, F, T, T, T]`), you can binary search over the *range of possible answers* to find the exact flip point in $O(N \log(\text{max\_val}))$.



---

### Section 4: Linear Optimization (Reducing $O(N^2)$ to $O(N)$)

If your brute-force solution requires nested loops over an array, use these techniques to collapse the time complexity down to linear $O(N)$.

* **Two Pointers:**
* *Opposite Directional:* Start at both ends and move inwards. Best for sorted arrays (e.g., *Two Sum II*) or bounding areas (e.g., *Container With Most Water*, *Trapping Rain Water*).
* *Same Directional (Fast/Slow):* Move both pointers from the start at different speeds. Best for cycle detection or linked list manipulation.


* **Sliding Window:**
* *Fixed-Size:* The window size $K$ is constant. Compute the initial window, then slide it by adding the new element and removing the oldest element (e.g., *Maximum Sum Subarray of Size K*).
* *Variable-Size:* The window expands by moving the `right` pointer to ingest elements, and shrinks by moving the `left` pointer to restore the required condition (e.g., *Longest Substring Without Repeating Characters*).


* **Prefix Sum:** Precomputes running totals to allow $O(1)$ range sum queries.
* *Advanced Usage:* Combine Prefix Sums with Hash Maps to solve "Subarray Sum Equals K" in $O(N)$ time by storing the frequencies of previously seen prefix sums and checking if `current_sum - K` exists in the map.



---

### Section 5: Data Structure Selection Matrix

Choosing the wrong data structure guarantees a suboptimal solution. Use this matrix to select the exact tool for the job.

| Data Structure | Standard Time Complexities | When and Why to Use It |
| --- | --- | --- |
| **Stack** | Push/Pop: $O(1)$ | LIFO (Last-In, First-Out). Best for reversing order, bracket/parentheses matching, and expression parsing (RPN). |
| **Monotonic Stack** | Push/Pop: $O(1)$ amortized | Finding the "Next greater/smaller element" in an array in $O(N)$ time. Maintains elements in strict increasing/decreasing order. |
| **Queue** | Enqueue/Dequeue: $O(1)$ | FIFO (First-In, First-Out). The backbone of BFS. Used for scheduling and processing elements in the order they arrived. |
| **Monotonic Queue** | Push/Pop: $O(1)$ amortized | Sliding Window Maximum/Minimum. Uses a Deque to keep track of the extreme value in a moving window in $O(N)$ time. |
| **Heap (Priority Queue)** | Push/Pop: $O(\log N)$ <br>

<br> Peek: $O(1)$ | Maintaining a dynamically changing set of elements to instantly query the minimum or maximum. Best for "Top K" problems, Dijkstra's algorithm, or merging K sorted lists. |
| **Hash Map / Set** | Insert/Lookup: $O(1)$ avg | Frequency counting, fast membership testing, and mapping elements to indices to avoid nested loop lookups. |
| **Trie (Prefix Tree)** | Insert/Search: $O(L)$ <br>

<br> *(L = word length)* | String prefix matching, building autocomplete systems, routing tables, and 2D grid word searches (Boggle). |
| **Union-Find (DSU)** | Union/Find: $O(\alpha(N))$ <br>

<br> *(Effectively $O(1)$)* | Dynamic graph connectivity. Best for grouping items, finding the number of disconnected islands as edges are added, and Kruskal's MST. |

---

### Section 6: Graph & Tree Traversals

Understand the fundamental differences between exploration algorithms so you never code the wrong search strategy.

* **BFS (Breadth-First Search):**
* **Mechanism:** Uses a Queue. Explores uniformly, level-by-level (radius expands outward).
* **Use Case:** Finding the *shortest path* on unweighted graphs, level-order tree traversals, and multi-source shortest path problems.


* **DFS (Depth-First Search):**
* **Mechanism:** Uses a Stack (or Recursion). Plunges as deep as possible down one path before backtracking.
* **Use Case:** Finding connected components, checking reachability, maze solving, and tree traversals (pre-order, in-order, post-order).


* **Backtracking vs. DFS:**
* While backtracking uses DFS under the hood, it specifically involves **state restoration**. The paradigm is: *Choose* an option, *Explore* recursively, then *Unchoose* (revert the state) to try the next option. Includes aggressive pruning to cut dead-end execution branches early.


* **Topological Sort:**
* **Mechanism:** Kahn's Algorithm (using an in-degree array and Queue) or post-order DFS.
* **Use Case:** Resolving execution dependencies (e.g., Course Schedule), ordering tasks, and detecting cycles in Directed Acyclic Graphs (DAGs).



---

### Section 7: Meta-Solving Framework

When the timer starts, do not touch the keyboard. Run the problem through this 4-step mental checklist:

1. **Check Constraints ($N$):** Look at the bottom of the prompt. If $N \le 20$, think Backtracking/Bitmasks. If $N \le 10^5$, immediately rule out $O(N^2)$ solutions and look for a sorting or $O(N \log N)$ / $O(N)$ approach.
2. **Identify Keywords:** Scan for trigger phrases like "Sorted", "Contiguous", "Top K", or "Maximize the minimum". Map these directly to Section 2 of this guide.
3. **Determine the Core Bottleneck:** Ask yourself, "What is making the brute force slow?"
* *Example:* "I am re-calculating the sum of this subarray repeatedly." $\rightarrow$ Precompute a Prefix Sum.
* *Example:* "I am scanning the window every time it moves to find the highest number." $\rightarrow$ Use a Monotonic Queue.


4. **Outline the Exact Structure:** Verbally or on paper, state the algorithm, the required data structures, and the Big-O complexities before you write a single line of code. If you cannot explain the mechanics clearly, you are not ready to code.
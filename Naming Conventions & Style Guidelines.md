ans, res
cnt, mn, mx, sum
adj, vis, dist, rt
idx, pos, cur, nxt, prv

Const UPPER_SNAKE_CASE
using ll = long long;
using pii = pair<int, int>;


1-N: 1-indexed 

for (int i = 0; i < n; ++i){


}

[L, R)
length R - L
// 線段樹的節點區間切分：完美的 [L, mid) 與 [mid, R)
void build(int node, int L, int R) {
    if (R - L == 1) { // 區間長度直接是 R - L，等於 1 代表抵達葉節點
        tree[node] = a[L];
        return;
    }
    
    int mid = L + (R - L) / 2;
    // 左子樹負責 [L, mid)，右子樹負責 [mid, R)
    // 沒有任何的 +1 或 -1，邏輯極度清晰！
    build(node * 2, L, mid);
    build(node * 2 + 1, mid, R);
}

cerr << ...
void solve() {

}


Time Complexity
N = ?
STL ?
DFS => DP
Recusion => Iteration
How to solve boundarry condition? definition of state
What if? N*1000?

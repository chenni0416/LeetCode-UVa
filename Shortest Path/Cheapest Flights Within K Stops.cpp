
//n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // int cost;
        vector<int> minCost(n, 1e9);
        vector<bool> visted(n, false);
        minCost[src] = 0;
        k++;
        while (k--) {

            int u = -1;
            for (int i = 0; i < n; ++i) {
                if (!visted[i] && (u == -1 || minCost[i] < minCost[u])) {
                    u = i;
                }
            }
            visted[u] = true;
            vector<int> temp = minCost;
            for (auto f : flights) {
                int u = f[0], v = f[1], w = f[2];
                if (temp[u] != 1e9 && !visted[v]) {
                    // cout << u << "\n";
                    // cout << temp[u] + w << "\n";
                    minCost[v] = min(minCost[v], temp[u] + w);
                    // cout << minCost[v] << "\n";
                }
                // if (f[0] == u) {
                //     minCost[f[1]] = min(minCost[f[1]], minCost[u] + f[2]);
                // }
                // else if (f[1] == dst && minCost[f[0]] != 1e9) {
                //     minCost[dst] = min(minCost[dst], minCost[f[0]] + f[2]);
                // }
            }

            // for (auto cost : minCost) cout << cost << " ";
            // cout << "\n";

        }

        return (minCost[dst] == 1e9) ? -1 : minCost[dst];
        // }

        
    }
};
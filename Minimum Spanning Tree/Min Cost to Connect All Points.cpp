class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int cost = 0, u = 0;
        int n = points.size();
        vector<bool> vsted(n, false);
        vector<int> minCost(n, INT_MAX);
        minCost[0] = 0;
        // vsted[0] = true;
        //u, 
        for (int i = 0; i < n-1; ++i) {
            vsted[u] = true;
            int curr = INT_MAX;
            int next_u;
            for (int p = 0; p < n; ++p) {
                if (!vsted[p]) {
                    int dis = abs(points[p][0] - points[u][0]) + abs(points[p][1] - points[u][1]);
                    minCost[p] = min(minCost[p], dis);
                    if (minCost[p] < curr) {
                        curr = minCost[p];
                        next_u = p;
                    }
                }
            }
            // cout << "curr = " << curr << ", next_u = " <<next_u << "\n";
            cost += curr;
            u = next_u;
        }
        return cost;

    }
};
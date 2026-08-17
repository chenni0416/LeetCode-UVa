// left & right: the number of histogram >= curr
// 5 + 1*5
// TLE: a lot of heights are the same 


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> l(n, 0);
        vector<int> r(n, 0);

        for (int i = 1; i < n; ++i) {
            for (int j = i-1; j >= 0; --j) {
                if (heights[i] > heights[j]) break;
                if (heights[i] == heights[j]) { //TLE
                    l[i] += (l[j] + 1);
                    break;
                }
                l[i] += 1;
            } 
        }

        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (heights[i] > heights[j]) break;
                if (heights[i] == heights[j]) { //TLE
                    r[i] += (r[j] + 1);
                    break;
                }
                r[i] += 1;
            } 
        }
        
        // for (int n : l) cout << n << " ";
        // cout << "\n";
        
        // for (int n : r) cout << n << " ";
        // cout << "\n";   
        
        int ans = heights[0] * (1 + l[0] + r[0]);
        for (int i = 1; i < n; ++i) {
            ans = max(ans, heights[i] * (1 + l[i] + r[i]) );


        }
        return ans;

    }
};
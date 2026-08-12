//Notes: [[1], [2]] can not reach from left; only from top;

#include<bits/c++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vi dp(grid[0].size()+1, 0);
        for(int i=0; i<grid[0].size(); i++)
        {
            dp[i+1] = dp[i]+grid[0][i]; 
            // cout << dp[i+1] << " ";
        }

        for(int i=1; i<grid.size(); i++)
        {
            dp[1] = dp[1]+grid[i][0];//[BUG] [[1], [2]] 
            for(int j=1; j<grid[0].size(); j++)
            {
                // cout << "left = " << dp[j-1] << "up = " << dp[j] << "\n";
                // dp[1] = min(dp[0]+2, dp[1]+2);
                dp[j+1] = min(dp[j]+grid[i][j], dp[j+1]+grid[i][j]); //[BUG] [[1], [2]] 
            }
        }
        return dp[grid[0].size()];
    }
};

int main()
{

}
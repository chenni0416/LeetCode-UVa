//notes: slow but dp
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vi dp(nums.size(), 1);
        int ans = 1;
        for(int i=1; i<nums.size(); i++)
        {
            for(int j=i-1; j>=0; j--)
            {
                if(nums[j] < nums[i]) //not =
                {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            // cout << i << " " << dp[i] << "\n";
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

int main()
{
    //negative
    vvi testcases = {{1}, {1,2}, {7,7,7}, {1,2,3,4}, {4,3,2,1}, {1,7,2,5,6,2}, {6,8,2,34,-1,346,-3,235}};
    //dp = [1,2,2,3,4,2]
    // vvi testcases = {{1,7,2,5,6,2}};

    // ans = 1,2,1,4,1,4
    int ans;
    Solution s;
    for(auto testcase: testcases)
    {
        cout << "ans = " << s.lengthOfLIS(testcase);
    }
}
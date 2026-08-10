#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
#define print(x) cout << #x << " = x" << "\n";
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vi dp(amount+1, INT_MAX);
        dp[0] = 0;
        for(int coin:coins)
        {
            // vi prev = dp;
            for(int i=coin; i<=amount; i++)
            {
                // if(i%coin != 0) continue;
                if(dp[i-coin] == INT_MAX) continue;
                dp[i] = min(dp[i], dp[i-coin]+1); // test using the same coin many times
            }
        }
        return (dp[amount] == INT_MAX) ? -1 : dp[amount];
    }
};

int main()
{
    vii testcases = {{1,2,5}, {2}, {1}, {1, 5}, {1,1,1}, {1,10}, {1,2,5}};
    vi amounts = {11, 3, 0, 10, 10, 10, 10};
    vi anses = {3, -1, 0, 2, 10, 1, 2};
    int ans;
    Solution s;
    for(int i=0; i<testcases.size(); i++)
    {
        ans = s.coinChange(testcases[i], amounts[i]);
        if(ans == anses[i])
        {
            cout << "correct\n";
            continue;
        }
        else
        {
            cout << "expect " << anses[i] << "got " << ans << "\n";
        }

    }
}
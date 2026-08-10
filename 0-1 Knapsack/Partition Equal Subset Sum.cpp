
//Notes: DP!!! I thougt backtracking at first time!
//Notes: [BUG] [1,2,5], expected false, got true [WHY] need to add prev to prevent from using the same data
//Notes: I need to add program to check my answer!



#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
#define print(x) cout << #x << " = " << x << "\n";
// botton up
// class Solution {
// public:
//     bool canPartition(vector<int>& nums) {
//         int sum = 0;
//         for(int n:nums) sum += n;
//         if(sum%2 != 0) return false; // >n/2?
//         sum/=2;
//         vector<bool> dp(sum+1, false);
//         dp[0] = true;
//         // dp[nums[0]] = true;
//         for(int n:nums)
//         {
//             // cout << "hello\n";
//             // print(n);
//             if(n>sum) return false;    //
//             vector<bool> prev = dp;
//             // cout << "how are  you\n"; 
//             for(int i=n; i<sum+1; i++) //i=1,2
//             {
//                 // print(i);
//                 // print(dp[i]);
//                 // print(dp[i-n]);
//                 dp[i] = prev[i] or prev[i-n]; //[BUG]: when i=2, n=1, dp[i-n] = true //[FIX] add prev
//                 // print(dp[i]);
//             }
//             if(dp[sum]) return true;
//         }
//             // cout << "how are  you\n"; 

//         return dp[sum];
//     }
// };

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    bool ans;
    vii testcases = {{1}, {1,2}, {1,3}, {2,2}, {3,1,2}, {1,2,5}};
    vi anses = {0, 0, 0, 1, 1, 0};
    // bool` ans;
    Solution s;
    for(int i=0; i<testcases.size(); i++)
    {
        // cout <<"ans = "<< s.canPartition(testcase) << "\n\n";
        ans = s.canPartition(testcases[i]);
        if(ans == anses[i]) continue;
        cout << "expected = " << anses[i] << " got = ";
        print(ans);


    }
    
}
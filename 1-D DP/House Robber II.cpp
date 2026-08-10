//status: 
//Notes: 


/*


*/
#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
#define print_v(x) cout << #x << " = " << x <<"\n";
#define print(x) cout << x << "\n";
#define print_nums(nums) {\
    cout << #nums << " = ";\
    for(int n:nums) cout << n << " ";\
    cout << "\n";\
}
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        // //print_nums(nums);

        vi max_money(nums.size(), 0); // the last ?
        // int ans;
        max_money[1] = nums[0];
        // from idx = 0-
        //[  1,2,3,1]
        //[0,1,2,4] i=1, nums[i]=2, max_money[2] = max(max_money[0]+nums[i], max_money[1]);
        //i=2, max_money[3] = max(max_money[1]+nums[2], max_money[2]);
        //
        // the last index = 3
        //print("into first for loop");
        // find out the max money from idx = 0-nums.size()-2
        for(int i=1; i<nums.size()-1; i++) // i = 1-2
        {
            //print_v(i);
            max_money[i+1] = max(max_money[i-1]+nums[i], max_money[i]);
            
        }
        //print_nums(max_money);

        int ans = max_money[nums.size()-1];
        //    [2, 3, 1]
        // [0, 2, 3, 3]
        max_money[1] = nums[1];
        // find out the max money from idx = 1-nums.size()-1

        for(int i=2; i<nums.size(); i++)
        {
            max_money[i] = max(max_money[i-2]+nums[i], max_money[i-1]);
        }
        ans = max(ans, max_money[nums.size()-1]);

        return ans;
    }
};


int main()
{
    vvi testcases = {{1}, {1,2}, {1,2,3}, {1,2,3,1}, {4,3,2,1}, {1,4,1,4,1,4}, {4,1,4,1,4,1}};
    Solution s;
    for(auto testcase: testcases)
    {
        int ans = s.rob(testcase);
        // cout << s.rob(testcase);
        print_v(ans);
    }
}
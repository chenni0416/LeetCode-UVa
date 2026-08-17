// positive integer: in 1-n+1
// if 
// [-1, 0, 2, 4]
// [-1, 2, 0, 4] if n > 0: swap nums[nums[i]-1], nums[i]
// [1,2,3,4]
// [-1, 0, 1]
// [1] => 2
// [0] => 1
// [2] => 1
// [-1, 0] => 1
// [3,4,-1,1] => []
// []
// KEY: ans = [1, n+1]
// BUG: [1, 1] 
// 1. idx = 0: num = 1, or num <= 0 or nums  => num <= idx + 1 or num > n
// 2. idx = 1: num = 2, or num <= idx+1

// when to change?  num > i + 1 && num <= n && 
// idx = 2: num in 2 = 1,2,3, >n,
// when not change? num in i = num <= i + 1 or num > n;

// again
// when to change?
// n = 3
// idx = 1, nums[i] == 0, 1, 2, 3, 4 => not change: 0, 2, 4 change: 1, 3
// [1, 1] // if nums[nums[i]-1] != nums[i]
// 
// 
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size(); // 1-n
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[i] != i + 1 && nums[nums[i]-1] != nums[i]) { // BUG: ignore nums[nums[i]-1] already == nums[i]
            // if (nums[i] > 0 && nums[i] <= n ) {

                swap(nums[nums[i]-1], nums[i]);
            }
        }
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                ans = i + 1;
                break;
            }
        }
        return (ans == -1) ? n + 1 : ans;
    }
};

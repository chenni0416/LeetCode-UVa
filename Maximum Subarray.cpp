class Solution {
public:
    //[1, 2]
    //[-1, 2]:

    //[1, -2]: if reduce?: start from next 1? NO
    //[5, 4, -1, 7, 8]
    //when to move starting point? prefixSum
    //currPreSum - MinPreSum
    int maxSubArray(vector<int>& nums) {
        vector<int> preSum(nums.size()+1, 0);
        for(int i=1; i<=nums.size(); i++)
        {
            preSum[i] = preSum[i-1] + nums[i-1];
        }

        int ans = nums[0], minCurrSum=min(0, nums[0]);
        //porblem: all negative
        //[0, -2, -3, -6, -10]
        for(int i=2; i<=nums.size(); i++)
        {

            ans = max(preSum[i]-minCurrSum, ans);
            minCurrSum = min(minCurrSum, preSum[i]);
        }
        return ans;

    }
};
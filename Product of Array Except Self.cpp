class Solution {
public:
    //[0, 1, 0]:all zero [0, 0, 0]
    //[0, 1, 1]:only one zero, others zero, product
    //[0, 1, 3, 4, 0]
    //prefix:[1,1, 2, 6]
    //suffix:[1, 4, 12, 24] 
    //space:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix = 1;
        int suffix = 1;
        vector<int> ans(nums.size(), 1);
        for(int i=1; i<nums.size(); i++)
        {
            prefix *= nums[i-1];
            ans[i] = prefix;
        }
        // for(int i=1; i<nums.size(); i++)
        // {
        //     cout << ans[i] << " ";
        // }
        // cout << "\n";
        for(int i=nums.size()-2; i>=0; i--)
        {
            suffix *= nums[i+1];
            ans[i] *= suffix; //i=2 ans[2]=2*suffix=4
        } 
        return ans;       

    }
};
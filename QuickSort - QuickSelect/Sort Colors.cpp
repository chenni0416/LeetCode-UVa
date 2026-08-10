class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> frqs = {0, 0, 0};
        for(int n:nums) frqs[n] +=1;
        int idx = 0;
        for(int i=0; i<nums.size(); i++)
        {
            
            if(frqs[idx] == 0) idx++;
            nums[i] = idx;
            frqs[i] -= 1;
        }
    }
};
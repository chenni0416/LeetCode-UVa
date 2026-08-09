class Solution {
public:
    //consecutive seq: 000 001 010...
    //starting point: (num-1) not in num
    //map for idx in nums => exist
    //
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> find_idx;
        int ans = 0;
        for(int i=0; i<nums.size(); i++)
        {
            find_idx[nums[i]] = i;
        }
        for(int n:nums)
        {
            int length = 1;
            if(find_idx.find(n-1) == find_idx.end())
            {
                while(find_idx.find(++n) != find_idx.end())
                {
                    length += 1;
                }
            }
            ans = max(ans, length);
        }
        return ans;
    }
};
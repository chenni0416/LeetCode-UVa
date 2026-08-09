class Solution {
public:
    //1. [1, 1], [1, 1]
    //2 [3]
    // starting point
    // [0, 0, 0]
    // [1, 2, 3]
    // [   1, 2, 3, 2 ,1, 1, 2]
    // [0, 1, 3, 6, 8, 9, 10, 13]
    // [0, 0, 0, 0, 0]
    int subarraySum(vector<int>& nums, int k) {
        //segmentation fault? 
        vector<int> prefixSum(nums.size()+1, 0); // Sun > int?
        unordered_map<int, int> dict;
        int ans=0;
        dict[0] = 1;
        for(int i=0; i<nums.size(); i++)
        {
            prefixSum[i+1] = prefixSum[i] + nums[i];
            ans += (dict[prefixSum[i+1]-k]);
            if(dict.find(prefixSum[i+1]) == dict.end()) dict[prefixSum[i+1]] =1;
            else dict[prefixSum[i+1]] +=1;
        }
        // return ans;
        // int ans=0;
        // int l=0, r=1;
        // for(int i=1; i<)


        // while(l<r and r<=nums.size())
        // {
        //     if(prefixSum[r]-prefixSum[l] == k)
        //     {
        //         r++; // l not ++ [1, 2, 0]
        //         ans++;
        //     }
        //     else if(prefixSum[r]-prefixSum[l] >= k) l++;
        //     else r++;

        // }



        return ans;



    }
};
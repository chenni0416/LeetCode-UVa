/*
[1,2,3,4] 
[1,2,4,3]
[1,3,2,4]
[1,3,4,2]
[1,4,3,2]
[1,4,2,3]

pivot = nums.size()-1 -1; 
swap_idx = from pivot +1 to nums.size()-1

*/



class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        gen_permute(ans, nums, 0);
        return ans;
        
    }

    void gen_permute(vector<vector<int>>& ans, vector<int>& nums, int pivot)
    {
        // vector<int> opt;
        // if(pivot<0) return;    
        //add => pivot=1:
        if(pivot==nums.size()-1)
        {
            ans.push_back(nums);
            // for (int n : nums) cout << n << " ";
            // cout << "\n";
        }
        for(int i=pivot; i<nums.size(); i++)
        {
            // ans.push_back(nums);
            swap(nums[pivot], nums[i]);

            // cout << string(pivot * 2, ' ') // 根據層級印出縮排，打造樹狀結構
            //     << "pivot=" << pivot << ", i=" << i << " | nums: ";
            gen_permute(ans, nums, pivot+1);




            swap(nums[pivot], nums[i]);
        }
    }
};
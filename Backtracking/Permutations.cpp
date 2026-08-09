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



// class Solution {
// public:
//     vector<vector<int>> permute(vector<int>& nums) {

//         vector<vector<int>> ans;
//         gen_permute(ans, nums, 0);
//         return ans;
        
//     }

//     void gen_permute(vector<vector<int>>& ans, vector<int>& nums, int pivot)
//     {
//         // vector<int> opt;
//         // if(pivot<0) return;    
//         //add => pivot=1:
//         if(pivot==nums.size()-1)
//         {
//             ans.push_back(nums);
//             // for (int n : nums) cout << n << " ";
//             // cout << "\n";
//         }
//         for(int i=pivot; i<nums.size(); i++)
//         {
//             // ans.push_back(nums);
//             swap(nums[pivot], nums[i]);

//             // cout << string(pivot * 2, ' ') // 根據層級印出縮排，打造樹狀結構
//             //     << "pivot=" << pivot << ", i=" << i << " | nums: ";
//             gen_permute(ans, nums, pivot+1);




//             swap(nums[pivot], nums[i]);
//         }
//     }
// };

#include <bits/stdc++.h>
using namespace std;


#define print(indent, x) cout <<indent<< #x << " = " << x << "\n";
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        gen_permute(ans, nums, 0);
        return ans;
        
    }
    
    void printAns(string indent, vector<vector<int>>& ans)
    {
        // print(ans.size());
        cout <<indent << "ans = ";
        for(auto row:ans)
        {
            cout << "[";
            for(int num:row)
            {
                cout << num << " ";
            }
            cout << "]";
        }
        cout << "\n";
    }
    void printNums(string indent, vector<int>& nums)
    {
        cout << indent << "nums = ";
            cout << "[";
            for(int num:nums)
            {
                cout << num << " ";
            }
            cout << "]";
        cout << "\n";

    }
    void gen_permute(vector<vector<int>>& ans, vector<int>& nums, int pivot)
    {
        // vector<int> opt;
        // if(pivot<0) return;    
        //add => pivot=1:
        // if(pivot==nums.size()-1)
        // {
        //     ans.push_back(nums);
        //     // for (int n : nums) cout << n << " ";
        //     // cout << "\n";
        // }
        string indent = string(pivot * 2, ' ');
        if(pivot == nums.size()-1)
        {
                ans.push_back(nums);
            printAns(indent, ans);
            return;

        }

        for(int i=pivot; i<nums.size(); i++)
        {
            //print
            // cout << indent;
            swap(nums[pivot], nums[i]);
            print(indent, pivot);
            print(indent, i);
            printNums(indent, nums);
            // cout << string(pivot * 2, ' ') // 根據層級印出縮排，打造樹狀結構
            //     << "pivot=" << pivot << ", i=" << i << " | nums: ";
            gen_permute(ans, nums, pivot+1);




            swap(nums[pivot], nums[i]);
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int>> testcases = {{1}, {1,2}, {1,2,3} };
    vector<vector<int>> ans;
    for(auto row:testcases)
    {
        ans = s.permute(row);
        cout << "final answer: ";
        s.printAns("", ans);
    }
}
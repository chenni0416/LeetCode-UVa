/*
[] 0 [-1, -1]
[5,7,7,8,8,10] 8 [3, 4]
[5,7,7,8,8,10] 6 [-1, -1]
[1] 1 [0, 0]
[1] 0 [-1, -1]
[1,1] 1 [0, 1]
[1,1] 0 [-1, -1]
1. binary serach find the first pos?
*/


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1, -1};
        int l = 0, r = nums.size()-1, mid;
        while (l <= r)
        {
            mid = (l+r)/2;
            if(nums[mid] < target) l = mid+1;
            else if (nums[mid] > target) r = mid-1;
            else {
                // cout << mid << "\n";
                ans = {mid, mid};
                break;
            }
        }
        //?? l or r include all targets?
        if(ans[0] == -1) return ans;
        else
        {
            int ori_l = l, ori_r = r;
            r = mid-1;
            // cout << l << ", "　<< r << "\n";
            while (l <= r)
            {
                mid = (l+r)/2;
                if(nums[mid] < target) l = mid+1;
                else if (nums[mid] > target) r = mid-1;
                else {
                    // cout << mid << "\n";
                    ans[0] = mid;
                    r = mid-1;
                }
            }

            l = mid+1;
            r = ori_r;
            while (l <= r)
            {
                mid = (l+r)/2;
                if(nums[mid] < target) l = mid+1;
                else if (nums[mid] > target) r = mid-1;
                else {
                    ans[1] = mid;
                    l = mid+1;

                }
            }
            return ans;
        }
    }

    // void binarySearch(vector<int>& nums, vector<int>& ans, int target, int l, int r)
    // {

    //     int mid;
    //     while (l != r)
    //     {
    //         mid = (l+r)/2;
    //         if(nums[mid] < target) l = mid+1;
    //         else if (nums[mid] > target) r = mid-1;
    //         else {
    //             ans = {mid, mid};
    //             break;
    //         }
    //     }
    // }
};
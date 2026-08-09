/*
find target
[0, 1, 2, 3]
[1, 2, 3, 0]
[2, 3, 0, 1]
[3, 0, 1, 2]

[0, 1, 2]
[1, 2, 0]
[2, 0, 1]

(nums[mid] < nums[r]) : if target > nums[mid] => binary search else:
(nums[l] < nums[mid]) :           <           =>               else: continue


*/

// solve for a long time
/*
First: Not Solved
REASON: Don't Know
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==1) return (nums[0] == target) ? 0 : -1;
        int l=0, r = nums.size()-1;
        // bool prev_status = false;
        int mid =((l+r)/2);
        // int prev = (nums[mid] < nums[mid-1])? nums[mid-1]: nums[mid];
        int prev = 
        
        //mid = 7, find smaller
        //mid = 0, find larger
        // false: larger
        // true: smaller

        
        while(l<=r)
        {
            
            // mid_n = nums[mid];

            //1. 
            cout << "prev=" << prev << " nums[mid]=" << nums[mid]<< "\n";

            if((nums[mid] < target) or ((nums[mid] > target) and (nums[mid] > prev))) //[4,5,6,7,0,1,2] 2 [BUG] (nums[mid] < target) X=> ((nums[mid] < target) and (nums[mid] < prev))
            {
                
                l = mid+1;
                prev = nums[mid];
            }
            else if ((nums[mid] > target) or ((nums[mid] < target) and (nums[mid] < prev))) //[4,5,6,0,1,2,3] 6 [BUG] 
            {
                r = mid-1;
                prev = nums[mid];

            }
            else
            {
                return mid;
            }
            mid= (l+r)/2;
        }
        return -1;
        
    }
};

/*
局部單調性：
nums[mid] there must be one side increase/
*/
/*
find target
[0, 1, 2, 3]
[1, 2, 3, 0]
[2, 3, 0, 1]
[3, 0, 1, 2]

[0, 1, 2]
[1, 2, 0]
[2, 0, 1]

(nums[mid] < nums[r]) : if nums[r] > target > nums[mid] => binary search else: r = mid-1
(nums[l] < nums[mid]) :    nums[l]  <         < nums[mid]  =>               else: l = mid+1



*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1, mid;

        while(l<=r)
        {
            mid = (l+r)/2;
            // cout << nums[l] << " " << nums[mid] << " " <<nums[r] << "\n";
            if(nums[mid] <= nums[r]) // mono increase //[BUG]: nums[mid] == nums[r] if l==r, size==1
            {
                if(nums[r] >= target && target >= nums[mid])
                {
                    return binarySearch(nums, target, l, r);
                }
                else
                {
                    r = mid-1;
                }
            }
            else if(nums[mid] >= nums[l]) //mono decrease //[BUG] not add = => [1,2,3,0] mid == l or mid == r
            {
                if(nums[l] <= target && target <= nums[mid])
                {
                    return binarySearch(nums, target, l, r);
                }
                else
                {
                    l = mid+1;
                }
            }
        }
        return -1;
    }

    int binarySearch(vector<int>& nums, int target, int l, int r)
    {
        int mid;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(nums[mid] > target) 
            {
                r = mid-1;
            }
            else if (nums[mid] < target)
            {
                l = mid+1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }
};
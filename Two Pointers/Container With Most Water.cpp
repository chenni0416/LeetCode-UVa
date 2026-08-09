class Solution {
public:
    //l, r
    //if l < r: l *(r-l), l++
    int maxArea(vector<int>& height) {
        int ans = 0, l=0, r=height.size()-1;
        while(l<r)
        {
            if( height[l] < height[r] )
            {
                ans = max(ans, height[l]*(r-l));
                l++;
            }
            else
            {
                ans = max(ans, height[r]*(r-l));
                r--;
            }
        }
        return ans;
    }
};
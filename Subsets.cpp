#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vvi ans;
        vi a = {};
        subset(nums, 0, ans, a);
        return ans;
    }
    void subset(vi& nums, int pivot, vvi& ans, vi& a)
    {
        if(pivot > nums.size()) return;
        ans.push_back(a);
        for(int i=pivot; i<nums.size(); ++i)
        {
            a.push_back(nums[i]);
            subset(nums, i+1, ans, a);
            a.pop_back();
        }
    }
};

void printAns(vvi& ans)
{
    cout << "ans = ";
    for(auto row:ans)
    {
        cout << "{";
        for(int i=0; i<row.size(); i++)
        {
            cout << row[i] << (i+1 == row.size() ? "} ": " ");
        }
        // cout << "} ";
    }
    cout << "\n";
}

int main()
{
    vvi testcases = {{1}, {1,2}, {1,2,3}, {1,2,3,4}};
    vvi ans = {{1,2,3}, {4,5,6}};
    Solution s;
    for(auto testcase: testcases)
    {
        ans = s.subsets(testcase);
        printAns(ans);
        cout<< "ans size = " << ans.size() << "\n";
    }

}
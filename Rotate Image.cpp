class Solution {
public:
    // first 
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> ori_matx = matrix;
        int n = matrix.size();
        for(int c=0; c<n; c++)
        {
            for(int r=n-1; r>=0; r--)
            {
                matrix[c][n-r-1] = ori_matx[r][c];
            }
        }
    }
};
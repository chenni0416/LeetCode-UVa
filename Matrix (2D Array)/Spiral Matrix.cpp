class Solution {
public:
    //[[1,2,3],[4,5,6],[7,8,9]]
    //[1]
    //[2]
    //[3]
    //up=0, down=2, right=0, 
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int up=0, down=matrix.size()-1, right=matrix[0].size()-1, left=0;
        vector<int> ans;
        #define C(X) cout << #X << " = "<< X << "\n";
        //[1, 2] up=0, down=3
        //[3, 4]
        //[5, 6]
        //[7, 8]

        while(true)
        {
            for(int i=left; i<=right; i++)
            {
                ans.push_back(matrix[up][i]);
            }
            up++;
            if(up>down) break;

            for(int i=up; i<=down; i++)
            {
                ans.push_back(matrix[i][right]);
            }
            right--;
            if(left>right) break;

            for(int i=right; i>=left; i--)
            {
                ans.push_back(matrix[down][i]);
            }
            down--;
            if(up>down) break;

            for(int i=down; i>=up; i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
            if(left>right) break;


            // C(left);
            // C(right);

            // C(up);

            // C(down);

        }
        //middle
            // for(int i=left; i<=right; i++)
            // {
            //     ans.push_back(matrix[up][i]);
            // }
        return ans;
    }
};
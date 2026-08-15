/*


*/
// first but slow
using vcc = vector<vector<char>>;
using vi = vector<int>;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // vi edges = {0, grid.size()-1, 0, grid[0].size()-1}; // up down left right
        int up = 0, down = grid.size(), left = 0, right = grid[0].size();
        int ans = 0;
        for(int i = 0; i < down; ++i){

            for(int j = 0; j < right; ++j){
                if(grid[i][j] == '1')
                {
                    // cout << "center = " << i << ", " << j << "\n";
                    search_1(grid, {i, j});
                    ans+=1;
                }
            }
            
        }

        // for(auto row: grid)
        // {
        //     for(char c: row)
        //     {
        //         cout << c << " ";
        //     }
        //     cout << "\n";
        // }
        return ans;
        
    }

    void search_1(vcc& grid, vi center){
        
        int up = 0, down = grid.size(), left = 0, right = grid[0].size();
        //up down left right
        // cout << "in search 1 center = " << center[0] << ", " << center[1] << "\n";
        grid[center[0]][center[1]] = '2';
        for(int i = center[0]-1; i >= 0; i--)
        {
            if(grid[i][center[1]] == '1')
            {
                search_1(grid, {i, center[1]});
            }
            else break;
        }
        for(int i = center[0]+1; i < down; i++)
        {
            if(grid[i][center[1]] == '1')
            {
                search_1(grid, {i, center[1]});
            }
            else break;

        }
        for(int i = center[1]-1; i >= 0; i--)
        {
            if(grid[center[0]][i] == '1')
            {
                search_1(grid, {center[0], i});
            }
            else break;

        }
        for(int i = center[1]+1; i < right; i++)
        {
            if(grid[center[0]][i] == '1')
            {
                
                search_1(grid, {center[0], i});
            }
            else break;

        }
    }
};


using vcc = vector<vector<char>>;
using vi = vector<int>;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // vi edges = {0, grid.size()-1, 0, grid[0].size()-1}; // up down left right
        int up = 0, down = grid.size(), left = 0, right = grid[0].size();
        int ans = 0;
        for(int i = 0; i < down; ++i){

            for(int j = 0; j < right; ++j){
                if(grid[i][j] == '1')
                {
                    // cout << "center = " << i << ", " << j << "\n";
                    search_1(grid, {i, j});
                    ans+=1;
                }
            }
            
        }

        // for(auto row: grid)
        // {
        //     for(char c: row)
        //     {
        //         cout << c << " ";
        //     }
        //     cout << "\n";
        // }
        return ans;
        
    }

    void search_1(vcc& grid, vi center){
        
        int up = 0, down = grid.size(), left = 0, right = grid[0].size();
        if(center[0] < down && center[0] >=0 && center[1] < right && center[1] >=0 && grid[center[0]][center[1]] == '1'){
            grid[center[0]][center[1]] = '2';
            search_1(grid, {center[0]+1, center[1]});
            search_1(grid, {center[0]-1, center[1]});
            search_1(grid, {center[0], center[1]+1});
            search_1(grid, {center[0], center[1]-1});
        }
        // //up down left right
        // // cout << "in search 1 center = " << center[0] << ", " << center[1] << "\n";
        // grid[center[0]][center[1]] = '2';
        // for(int i = center[0]-1; i >= 0; i--)
        // {
        //     if(grid[i][center[1]] == '1')
        //     {
        //         search_1(grid, {i, center[1]});
        //     }
        //     else break;
        // }
        // for(int i = center[0]+1; i < down; i++)
        // {
        //     if(grid[i][center[1]] == '1')
        //     {
        //         search_1(grid, {i, center[1]});
        //     }
        //     else break;

        // }
        // for(int i = center[1]-1; i >= 0; i--)
        // {
        //     if(grid[center[0]][i] == '1')
        //     {
        //         search_1(grid, {center[0], i});
        //     }
        //     else break;

        // }
        // for(int i = center[1]+1; i < right; i++)
        // {
        //     if(grid[center[0]][i] == '1')
        //     {
                
        //         search_1(grid, {center[0], i});
        //     }
        //     else break;

        // }
    }
};

//faster : 
if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == '0') {
            return;
        }


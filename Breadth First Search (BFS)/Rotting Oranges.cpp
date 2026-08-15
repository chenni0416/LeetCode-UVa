// using vi = vector<int>;
// using vii = vector<vi>;
// //BUG: [[2,1,1],[1,1,1],[1,1,1]]
// class Solution {
// public:
//     int orangesRotting(vector<vector<int>>& grid) {
//         int m = grid.size(), n = grid[0].size();
//         int n_rtn = 0, n_frs = 0;
//         vii rtn(100, {-1, -1});
//         for (int r = 0; r < m; ++r) {
//             for (int c = 0; c < n; ++c) {
//                 if (grid[r][c] == 1) n_frs++;
//                 else if (grid[r][c] == 2) {
//                     // n_rtn++;
//                     rtn[n_rtn++] = {r, c};
//                 }
//             }
//         }
//         if (n_frs == 0) return 0;
//         int ans = -1, cnt = n_rtn;
//         n_rtn = 0;
//         while(cnt) {
//             cout << "cnt = " << cnt << "\n";
//             ans++;
//             for (int i = 0; i < cnt; ++i) {
//                 int r = rtn[i][0], c = rtn[i][1];
//                 fun(grid, r+1, c, n_rtn, rtn, n_frs);
//                 fun(grid, r-1, c, n_rtn, rtn, n_frs);
//                 fun(grid, r, c+1, n_rtn, rtn, n_frs);
//                 fun(grid, r, c-1, n_rtn, rtn, n_frs);
//                 cout << "r, c = " << r << ", " << c << "\n";
//                 cout << "n_rtn = " <<n_rtn << "\n";
//                 //
//                 // if (grid[][] == 1) {
//                 //     grid[][] = 2;
//                 //     n_rtn++;
//                 // }

//             }
//             // cout << n_rtn << "\n";
//             cnt = n_rtn;
//             n_rtn = 0;
//         }
        
//         return (n_frs == 0) ? ans : -1;



        
//     }
//     void fun(vii& grid, int r, int c, int& n_rtn, vii&rtn, int& n_frs)
//     {
//         int m = grid.size(), n = grid[0].size();
        
//         if (r < 0 || r >= m || c < 0 || c >= n) return;
//                 if (grid[r][c] == 1) {
//                     cout << "in fun ";
//                     cout << "r, c = " << r << ", " << c << "\n";
//                     grid[r][c] = 2;
//                     rtn[n_rtn] = {r,c};
//                     cout << "n_rtn = " << n_rtn;

//                     cout << ", check r, c = " <<  rtn[n_rtn][0] << ", " <<  rtn[n_rtn][1] << "\n";


//                     n_rtn++;
//                     n_frs--;
//                 }
//         // grid[r][c] = 2;
//         // n_rtn++;
//     }
// };


//Notes: slow
using vi = vector<int>;
using vii = vector<vi>;
//BUG: [[2,1,1],[1,1,1],[1,1,1]]
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int n_rtn = 0, n_frs = 0;
        // vii rtn(100, {-1, -1});
        queue<pair<int, int>> q;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) n_frs++;
                else if (grid[r][c] == 2) {
                    // n_rtn++;
                    // rtn[n_rtn++] = {r, c};
                    n_rtn++;
                    q.push({r, c});
                }
            }
        }
        if (n_frs == 0) return 0;
        int ans = -1, cnt = n_rtn;
        n_rtn = 0;
        while(cnt) {
            // cout << "cnt = " << cnt << "\n";
            ans++;
            for (int i = 0; i < cnt; ++i) {
                pair<int, int> p = q.front();
                q.pop();
                // int r = rtn[i][0], c = rtn[i][1];
                int r = p.first, c = p.second;
                fun(grid, r+1, c, n_rtn, q, n_frs);
                fun(grid, r-1, c, n_rtn, q, n_frs);
                fun(grid, r, c+1, n_rtn, q, n_frs);
                fun(grid, r, c-1, n_rtn, q, n_frs);
                // cout << "r, c = " << r << ", " << c << "\n";
                // cout << "n_rtn = " <<n_rtn << "\n";
                //
                // if (grid[][] == 1) {
                //     grid[][] = 2;
                //     n_rtn++;
                // }

            }
            // cout << n_rtn << "\n";
            cnt = n_rtn;
            n_rtn = 0;
        }
        
        return (n_frs == 0) ? ans : -1;



        
    }
    void fun(vii& grid, int r, int c, int& n_rtn, queue<pair<int, int>>& q, int& n_frs)
    {
        int m = grid.size(), n = grid[0].size();
        
        if (r < 0 || r >= m || c < 0 || c >= n) return;
                if (grid[r][c] == 1) {
                    // cout << "in fun ";
                    // cout << "r, c = " << r << ", " << c << "\n";
                    grid[r][c] = 2;
                    // rtn[n_rtn] = {r,c};
                    q.push({r, c});
                    // cout << "n_rtn = " << n_rtn;

                    // cout << ", check r, c = " <<  rtn[n_rtn][0] << ", " <<  rtn[n_rtn][1] << "\n";


                    n_rtn++;
                    n_frs--;
                }
        // grid[r][c] = 2;
        // n_rtn++;
    }
};


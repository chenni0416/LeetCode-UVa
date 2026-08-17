/*
[0] => 0
[1] => 0

[0, 1] => 0
[1, 0] => 0
[1, 1] => 0

[0, 1, 2] => 0
[0, 1, 1] => 0
#
[0, 1, 0] => 0
[1, 1, 0]


[1, 1, 1]
[2, 1, 0] => 
[2, 1, 1] 
[2, 1, 2] => 1

has water
[2, 1, 2] => 1 : l - m 
[1, 0, 2] => 1 : l - m
[2, 0, 1] => 1 : r - m 
[2, 1, 0, 1, 2] => 4
[2, 1, 0, 1, 1, 2] => 1+2+1+1

[2, 0, 1, 0, 2]
[2, 0, 1, 0] => end process => r = 1
[2, 0, 1, 1] => r = 1
[3, 0, 1, 2] => 
[3, 0, 1, 1]
[3, 0, 1, 0] => r = 1
[3, 2, 2, 1]
[3, 2, 1, 2]
[4, 3, 1, 2]
or use medium run again the same logic?
or use l = 3? 

//r = end
[2, 1, 0, 1, 1] => 
l = 2, m = 1, 0, 1, 1 => r = 1

//l = front
//

// if h > 0 => l = h 
// if has l and h < l => m = h
// if has m ans h >= l => r = h, count water => l = h, m = empty
// if has m and end => ? 

l = ? ini: 0, then if > 0 = l
m = ? push if m < l
r = ? if has m 
1. m < r <= l => 
2. m < l <= r => count water



3. if find any num < curr r => count water
3. if end => count water 

when to add water? 
1. m < l <= r => l - m
2. m < r <= l => r - m
3. 


*/


/*
[2, 0, 1]
vi l = [0, 2, 2] from idx = 0 to n-2 l[0] = 0
vi r = [1, 1, 0] from idx = n-1 to 1 r[n-1] = 0
water = min(l, r) > h[idx] = max - h

[]

water = l[i-1]

*/


class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        // if (n <= 2) return 0;

        vector<int> l(n, 0);
        vector<int> r(n, 0);

        for (int i = 0; i < n-1; ++i) {
            l[i + 1] = max(l[i], height[i]);
        }

        for (int i = n - 1; i > 0; --i) {
            r[i - 1] = max(r[i], height[i]);
        }

        // for (int n : l) cout << n << " ";
        // cout << "\n";
        // for (int n : r) cout << n << " ";
        // cout << "\n";
        int ans = 0, water, mn; // ll??
        for (int i = 0; i < n; ++i) {
            mn = min(l[i], r[i]);
            water = (mn > height[i]) ? (mn - height[i]) : 0;
            // cout << "water = " << water << "\n";
            ans += water;
        }

        return ans;
    }
};
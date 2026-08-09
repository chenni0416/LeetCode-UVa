class Solution {
public:
    //[b, a, c, a, a, b, c]
    //[0, 1, 2, 3, 4, 5, 6]
// pos[0, 1, 2, ]
// r=3, l=0[]
// ans = 3-0 
    //[1, 2, 3, (3+1)-2, (2+1)-2, ] 
    //[0, 1, 2, 3]
    //1. appear or not? 2. remove
    //
    //[a, b, c] = [1, 0, 3]
    //
    //1. ans 2. array: [the last pos] 3. 
    //[a, b, c, a]
    //[c, b, a, a]
    #define cout(x) cout << #x << " = "<<x << "\n";
    int lengthOfLongestSubstring(string s) {
        // vector<int> pos(26, -1);
        unordered_map<char, int> pos;
        int l=0, ans = 0;
        for(int r = 0; r<s.size(); r++)
        {
            // cout << r << "\n";
            // cout(r);
            // cout(l);
            // cout <<"\n";
            if(pos.find(s[r]) != pos.end())
            {
                // cout << r << " "<< l << "\n";
                
                ans = max(r-l, ans);
                for(int i=l; i<pos[s[r]]; i++)
                {
                    // pos[s[i]-'a'] = -1;
                    pos.erase(s[i]);
                }
                l = pos[s[r]]+1;
                pos[s[r]] = r;



            }
            else
            {
                pos[s[r]] = r;
            }
            // cout << s[r] << ": "<< r << "\n";


        }
        int n = s.size();
        ans = max(n-l, ans);

        return ans;

    }
};
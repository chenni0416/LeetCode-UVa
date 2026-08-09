class Solution {
public:
    //key:26 bits
    //value:vector of idx
    //string => 26 bits => find idx => append in ans
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<int, int> find_idx;
        for(string s: strs)
        {
            int key = 0, pos; //initilize key
            for(char c: s)
            {
                pos = c-'a';
                key |= (1 << pos);
            }
            cout << key << "\n";

            if(find_idx.find(key) == find_idx.end()) // not find
            {
                find_idx[key] = ans.size();
                ans.push_back({s});
            }
            else
            {
                ans[find_idx[key]].push_back(s);
            }

        }
        return ans;
    }
};
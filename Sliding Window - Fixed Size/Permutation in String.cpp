class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()> s2.size()) return false;
        vector<int> freq_s1(27, 0);
        vector<int> freq_s2(27, 0);
        for(int i=0; i< s1.size(); i++)
        {
            freq_s1[s1[i]-'a'] += 1;
            freq_s2[s2[i]-'a'] += 1;

        }
        for(int i=0;i<=s2.size()-s1.size(); i++)
        {
            if(freq_s1 == freq_s2) return true;
            if(i+s1.size() != s2.size())
            {
                freq_s2[s2[i]-'a'] -= 1;

                freq_s2[s2[i+s1.size()]-'a'] += 1;

            }
        }
        return false;
    }
};
class Solution {
public:
    //compare vector == vector
    vector<int> findAnagrams(string s, string p) {
        if(p.size() > s.size()) return {};
        vector<int> freqs_p(27, 0);
        vector<int> freqs_s(27, 0);
        vector<int> ans;
        for(int i=0; i<p.size();i++)
        {
            freqs_p[p[i]-'a'] += 1;
            // cout << p[i]-'a' << " " << s[i]-'a' << "\n";
            freqs_s[s[i]-'a'] += 1;
        }
        // for(int i=0; i<27; i++)
        //     {
        //         if(freqs_p[i] == 0) continue;
        //         else 
        //         {
        //             cout <<i << ":" << freqs_p[i] << "\n";
        //         }
        //     }
        //     cout << "\n";
        for(int i=0; i<=s.size()-p.size(); i++) //10-3 = 7
        {
            // for(int i=0; i<27; i++)
            // {
            //     if(freqs_s[i] == 0) continue;
            //     else 
            //     {
            //         cout <<i << ":" << freqs_s[i] << "\n";
            //     }
            // }
            // cout << "\n";
            if(freqs_p == freqs_s) ans.push_back(i);
            if(i+p.size() != s.size())
            {

                freqs_s[s[i]-'a'] -= 1;
                freqs_s[s[i+p.size()]-'a'] += 1;
            }


        }
        return ans;

    }
};
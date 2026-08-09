class Solution {
public:
    // "  123   "
    // "123"
    // " 11   112  "
    // "112 11"
    // pointer from n-1 to 0: 
    // has char=> true: push to string
    // has space=> false and string to ans
    // has char/final+ans not empty => ans + space + string
    // touch space -> add string from pointer to ?
    // string = 211 ans = "112" string = ""
    // string = 11 ans = "112 11" string = "" 

    string reverseWords(string s) {
        // bool write = false;
        string word = "";
        string ans = "";
        for(int i=s.size()-1; i>=0; i--)
        {
            //not space => word+
            //space => word empty pass, word not empty => record and word = empty
            if(s[i] != ' ') 
            {
                word += s[i];
            }
            else if(word != "") //write = false and not space
            {
                if(ans != "") ans += ' ';
                for(int j=word.size()-1; j>=0; j--)
                {
                    ans += word[j];
                }
                word = "";
                // write = false;
            }
            
        }
        if (word != "")
        {
            if(ans != "") ans += ' ';
            for(int j=word.size()-1; j>=0; j--)
            {
                ans += word[j];
            }
        }
        return ans;
    }
};
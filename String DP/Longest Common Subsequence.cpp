class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // vector<vector<int>> maxSeq
        int n = text1.size(), m = text2.size();
        vector<int> maxSeq(n + 1, 0);
        for (int i = 0; i < m; ++i) {
            vector<int> prev = maxSeq;
            for (int j = 0; j < n; ++j) {
                if (text1[j] == text2[i]) {
                    maxSeq[j+1] = prev[j]+1;
                }
                else {
                    maxSeq[j+1] = max(maxSeq[j], prev[j+1]);
                }
            }
        }
        return maxSeq[n];

        
    }
};
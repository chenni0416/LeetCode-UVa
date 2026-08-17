class Solution {
public:
    struct element {
        int num;
        int frq;
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, int> freqs;
        for (int n : nums) {
            // no need to set 0
            freqs[n]++;
        }

        for (auto [num, freq] : freqs) {
            pq.push({freq, num});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> ans(k, 0);
        for (int i = 0; i < k; ++i) {
            ans[i] = pq.top().second;
            pq.pop();
        }
        return ans;



        // unordered_map<int, int> frqs;

        
        // struct comp {
        //     bool operator()(const int& a, const int& b) {
        //         return a > b;
        //     }
        // };
        // priority_queue<int, vector<int>, comp> pq;
        // for (int n:nums) {

        // }
        // return minHeap;

    }
};
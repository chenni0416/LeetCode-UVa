class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> courses(numCourses, vector<int>{}); 
        vector<int> numPre(numCourses, 0);
        // [0, 1] => 1 -> 0
        for (auto p : prerequisites) {
            courses[p[1]].push_back(p[0]);
            numPre[p[0]]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; ++i) {
            if (numPre[i] == 0) {
                q.push(i);
            }
        }
        // int cnt = 0;
        vector<int> ans;
        while (!q.empty()) {

            int pre = q.front();
            q.pop();
            ans.push_back(pre);
            for (int course : courses[pre]) {
                if (--numPre[course] == 0) {
                    q.push(course);
                }
            }

        }
        return (ans.size() == numCourses) ? ans : vector<int>{};
        
    }
};
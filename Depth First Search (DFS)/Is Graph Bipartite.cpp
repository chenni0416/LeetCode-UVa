//BUG: contain disconnected graph/ first [[], [2,3]...]

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int> q; //0-indexed
        // q.push(0); //[BUG] if 0 not connected!
        vector<bool>vsted(graph.size(), false);
        unordered_map<int, bool> group;
        // group[0] = false;
        // vsted[0] = true;
        
        //find not empty but not visted
        int cnt = 0;
        while(cnt != graph.size())
        {
            while(graph[cnt].empty() or vsted[cnt]){
                cnt++;
                if(cnt == graph.size()) return true;
            } 
            // cout << cnt;
            q.push(cnt);
            group[cnt] = false;
            while(!q.empty()){
            int node = q.front();
            q.pop();
            vsted[node] = true;
            for(int nbr:graph[node]){
                if(vsted[nbr]){
                    // if(group[nbr] == group[node]) return false;
                    continue;
                }
                // group by != node group
                if(group.find(nbr) == group.end()){
                    group[nbr] = !group[node];
                }
                else if(group[nbr] == group[node]) return false;


                q.push(nbr);
            }
            }
        }
        // for(auto g: graph)
        // {
        //     if(g.empty()) cnt++;
        //     else{
        //         q.push(cnt);
        //         break;
        //     }
             
        return true;
    }
        

};
// };


//1. find graph
//2. set1,2

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1); //-1:not vsted, 0, 1

        for (int i = 0; i < n; ++i) {
            if (color[i] != -1) continue;
            queue<int> q;
            q.push(i);
            color[i] = 0;

            while(!q.empty()) {
                int node = q.front();
                q.pop();

                for (auto nbr: graph[node]) {
                    if (color[nbr] == -1) {
                        color[nbr] = 1 - color[node];
                        q.push(nbr);
                    }
                    else if (color[nbr] == color[node]) return false;
                }
            }
            
        }
        return true;
        
    }
};

//testcase [[], [2], [1]] [[], [2,3], [1,3], [1,2]]
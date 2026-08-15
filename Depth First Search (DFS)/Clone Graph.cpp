/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

//[BUG] 
// class Solution {
// public:
//     Node* cloneGraph(Node* node) {
//         if(!node) return nullptr;
//         vector<int> vsts(100, 0);
//         vsts[0] = 1;
//         Node* curr = new Node(node->val);
//         Node* dummy = new Node(0, {curr});
//         dfs(node, curr, vsts);
//         print(curr);
//         return curr;
//     }
//     void dfs(Node* node, Node* curr, vector<int>& vsts){
//         // Node* curr = new Node(node->val);
//         for(auto neighbor: node->neighbors){
            
//             Node* n = new Node(neighbor->val); //[BUG]
//             // cout << n->val << "\n";
//             curr->neighbors.push_back(n);
//             if(vsts[neighbor->val-1] == 1) continue;
//             vsts[neighbor->val-1] = 1;
//             dfs(neighbor, n, vsts);
//         }

    

//     }
//     void dfs(Node* node, Node* curr, Node* prev){
//         // Node* curr = new Node(node->val);
//         for(auto neighbor: node->neighbors){
//             if(prev->val == neighbor->val){
//                 curr->neighbors.push_back(prev);
//             }
//             else{
//                 Node* n = new Node(neighbor->val); //[BUG]
//                 dfs(neighbor, n, vsts);
//             }
//             // // cout << n->val << "\n";
//             // if(vsts[neighbor->val-1] == 1) continue;
//             // vsts[neighbor->val-1] = 1;
//         }

    

//     }
//         void print(Node* node){
//         // Node* curr = new Node(node->val);
//         cout << "curr node number = " << node->val;
//         for(auto neighbor: node->neighbors){
//             cout << "neighbor node number = " << neighbor->val << " ";

//             // cout << neighbor->val << "\n";
//             // Node* n = new Node(neighbor->val);
//             // cout << n->val << "\n";
//             // curr->neighbors.push_back(n);
//             // if(vsts[neighbor->val-1] == 1) continue;
//             // vsts[neighbor->val-1] = 1;

//             // dfs(neighbor, n, vsts);
//             // print(neighbor);
//         }
//         cout << "\n";
//                 for(auto neighbor: node->neighbors){
//             // cout << "neighbor node number = " << neighbor->val;

//             // cout << neighbor->val << "\n";
//             // Node* n = new Node(neighbor->val);
//             // cout << n->val << "\n";
//             // curr->neighbors.push_back(n);
//             // if(vsts[neighbor->val-1] == 1) continue;
//             // vsts[neighbor->val-1] = 1;

//             // dfs(neighbor, n, vsts);
//             print(neighbor);
//         }

//         // cout << "\n";
    

//     }

// };


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        vector<Node*> vst(101, nullptr);
                    Node* nn = new Node(node->val);
            vst[node->val] = nn;
        dfs(nn, node, vst);
        return nn;
        
    }
    void dfs(Node* curr, Node* node, vector<Node*>&vst){
        
        for(auto n:node->neighbors)
        {
            if(vst[n->val]){
                curr->neighbors.push_back(vst[n->val]);
                continue;
            } 
            Node* nn = new Node(n->val);
            vst[n->val] = nn;
            curr->neighbors.push_back(nn);
            dfs(nn, n, vst);
        }
    }
};
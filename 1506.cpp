
// Definition for a Node.
// class Node {
// public:
//     int val;
//     vector<Node*> children;

//     Node() {}

//     Node(int _val) {
//         val = _val;
//     }

//     Node(int _val, vector<Node*> _children) {
//         val = _val;
//         children = _children;
//     }
// };


class Solution {
public:
    // Idea: Find the node which has no parent, because root is the only node without a parent in a tree
    // Time complexity is O(n)
    Node* findRoot(vector<Node*> tree) {
        map<Node*,Node*> mp; // node and its parent
        for(Node* n:tree){
            if(mp.count(n) == 0){
                mp[n] = NULL;
            }
            for(Node* c:n->children){
                mp[c] = n;
            }
        }
        Node* ans = NULL;
        for(auto x:mp){
            if(x.second == NULL){
                ans = x.first;
            }
        }
        return ans;
    }
};
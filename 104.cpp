/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Idea: traverse all nodes and update ans if necessary
    // Time complexity O(n)
    void traverse(TreeNode* root, int dep, int& ans){
        if(root == NULL){
            return;
        }
        dep++;
        ans = max(ans,dep);
        traverse(root->left,dep,ans);
        traverse(root->right,dep,ans);
    }
    int maxDepth(TreeNode* root) {
        int ans = 0;
        traverse(root,0,ans);
        return ans;
    }
};

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
    // Idea: in order traverse order for BST should be sorted
    // Time complexity is O(n)
    void check(TreeNode* root, vector<int>& values){
        if(root == NULL){
            return;
        }
        check(root->left,values);
        values.push_back(root->val);
        check(root->right,values);
    }

    bool isValidBST(TreeNode* root) {
        vector<int> values;
        check(root,values);
        for(int i=1;i<values.size();i++){
            if(values[i] <= values[i-1]){
                return false;
            }
        }
        return true;
    }
};

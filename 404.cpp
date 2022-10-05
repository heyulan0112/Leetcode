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
    // Time complexity is O(n)
    int sum(TreeNode* root, TreeNode* prev){
        if(root->left == NULL && root->right==NULL && prev!=NULL && root == prev->left){
            return root->val;
        }
        if(root->left == NULL && root->right==NULL){
            return 0;
        }
        int leftSum = 0, rightSum = 0;
        if(root->left != NULL){
            leftSum = sum(root->left,root);
        }
        if(root->right != NULL){
            rightSum = sum(root->right,root);
        }
        return leftSum + rightSum;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return sum(root,NULL);
    }
};
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
    // Idea: using pre order traverse template to build the tree from top to bottom
    // Time complexity is O(n)
    TreeNode* build(vector<int>& nums, int l, int r){
        if(l>r)
            return NULL;
        int max_val = INT_MIN;
        int index = -1;
        for(int i=l;i<=r;i++){
            if(nums[i]>max_val){
                index = i;
                max_val = nums[i];
            }
        }
        TreeNode* root = new TreeNode(max_val);
        root->left = build(nums,l,index-1);
        root->right = build(nums,index+1,r);
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums,0,nums.size()-1);
    }
};
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
    // Idea: use pre order and in order to construct a binary tree
    // Time complexity is O(n)
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int& pre_index, int l, int r, unordered_map<int,int>& mp){
        if(l>r){
            return NULL;
        }
        int val = preorder[pre_index];
        TreeNode* root = new TreeNode(val);
        int index = mp[val];
        pre_index++;
        root->left = build(preorder,inorder,pre_index,l,index-1,mp);
        root->right = build(preorder,inorder,pre_index,index+1,r,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        int pre_index = 0;
        return build(preorder,inorder,pre_index,0,preorder.size()-1,mp);
    }
};

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
    // Idea: level traverse and reverse all odd vectors in ans
    // Time complexity is O(nlogn)
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        int dep = 0;
        q.push(root);
        while(!q.empty()){
            ans.push_back({});
            int size = q.size();
            while(size--){
                TreeNode* node = q.front();
                q.pop();
                ans.back().push_back(node->val);
                if(node->left != NULL){
                    q.push(node->left);
                }
                if(node->right != NULL){
                    q.push(node->right);
                }
            }
            dep++;
        }
        for(int i=0;i<ans.size();i++){
            if(i%2 != 0){
                reverse(ans[i].begin(),ans[i].end());
            }
        }
        return ans;
    }
};

class Solution {
public:
    // Idea: permutation template
    // Time complexity O(n!) because this function is to enumerate all permutations
    // thus time complexity = no. permutations
    void perm(vector<int>& nums,vector<vector<int>>& ans, int begin, int end){
        if(begin > end){
            ans.push_back(nums);
            return;
        }
        for(int i=begin;i<nums.size();i++){
            swap(nums[i],nums[begin]);
            perm(nums,ans,begin+1,end);
            swap(nums[i],nums[begin]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        perm(nums,ans,0,nums.size()-1);
        return ans;
    }
};

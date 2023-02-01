class Solution {
public:
    // Idea: backtracking
    // Time complexity is O(2^n) = number of subsets
    void subsets(vector<vector<int>>& ans, vector<int>& nums, int start, vector<int> curr){
        ans.push_back(curr);
        for(int i=start;i<nums.size();i++){
            curr.push_back(nums[i]);
            subsets(ans,nums,i+1,curr);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        subsets(ans,nums,0,curr);
        return ans;
    }
};

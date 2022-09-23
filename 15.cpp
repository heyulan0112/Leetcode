class Solution {
public:
    // Idea: using Nsum template to solve it
    vector<vector<int>> twoSum(vector<int>& nums, int start, int target){
        vector<vector<int>> res;
        int left = start, right = nums.size()-1;
        while(left<right){
            int sum = nums[left] + nums[right];
            int n1 = nums[left];
            int n2 = nums[right];
            if(sum == target){
                res.push_back({left,right});
                while(left<right && nums[left] == n1)
                    left++;
                while(left<right && nums[right] == n2)
                    right--;
            }
            else if(sum > target){
                while(left<right && nums[right] == n2)
                    right--;
            }
            else if(sum < target){
                while(left<right && nums[left] == n1)
                    left++;
            }
        }
        return res;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        // To avoid reuse same value to be the fixed one
        unordered_map<int,int> mp;
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i=0;i<nums.size();i++){
            if(mp.count(nums[i]))
                continue;
            mp[nums[i]] = 1;
            vector<vector<int>> others = twoSum(nums,i+1,0-nums[i]);
            for(auto v:others){
                res.push_back({nums[i],nums[v[0]],nums[v[1]]});
            }
        }
        return res;
    }
};
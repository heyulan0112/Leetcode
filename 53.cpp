class Solution {
public:
    // Idea: dynamic programming
    // check each index current max sum
    // Time complexity O(n)
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int ans = dp[0];
        for(int i=1;i<nums.size();i++){
            // previous max sum + itself > itself then current max sum = previous max sum + itself
            if(nums[i] + dp[i-1] > nums[i]){
                dp[i] = nums[i] + dp[i-1];
            }
            // previous max sum + itself <= itself then current max sum = itself
            else{
                dp[i] = nums[i];
            }
            // update ans to be current max sum
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};

class Solution {
public:
    // Time complexity is O(n)
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1);
        int maxLen = 1;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i] % nums[j] == 0){
                    dp[i] = max(dp[j]+1,dp[i]);
                    maxLen = max(maxLen,dp[i]);
                }
            }
        }

        int prev = -1;
        vector<int> ans;
        for(int i=n-1;i>=0;i--){
            // 因为maxLen可能对应很多组数据 所以需要prev==-1 || prev % nums[i] == 0限定其中一组
            if(dp[i] == maxLen && (prev==-1 || prev % nums[i] == 0)){
                prev = nums[i];
                ans.push_back(nums[i]);
                maxLen--;
            }
        }
        return ans;
    }
};
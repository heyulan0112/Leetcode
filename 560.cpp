class Solution {
public:
    // Idea: using prefix sum to solve it
    // calculate every prefix sum and then check if corresponding smaller prefix sum exist
    // also record how many time the smaller prefix sum occour
    // Time complexity is O(n)
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp; // prefix sum = xxx [key] occor how many times [value]
        mp[0] = 1; // don't forget init state
        int prefix_sum = 0;
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            prefix_sum += nums[i];
            int prefix_sum2 = prefix_sum - k;
            if(mp.count(prefix_sum2) != 0){
                ans += mp[prefix_sum2];
            }
            if(mp.count(prefix_sum) == 0){
                mp[prefix_sum] = 1;
            }
            else{
                mp[prefix_sum]++;
            }
        }
        return ans;
    }
};
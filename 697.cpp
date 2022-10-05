class Solution {
public:
    // Time complexity is O(n)
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,vector<int>> mp; // value - {freq, min index, max index} 
        for(int i=0;i<nums.size();i++){
            if(mp.count(nums[i]) == 0){
                mp[nums[i]] = {0,INT_MAX,INT_MIN};
            }
            mp[nums[i]][0]++;
            mp[nums[i]][1] = min(mp[nums[i]][1],i);
            mp[nums[i]][2] = max(mp[nums[i]][2],i);
        }
        int ans = INT_MAX;
        int max_d = INT_MIN;
        for(auto x:mp){
            if(x.second[0] > max_d){
                max_d = x.second[0];
            }
        }
        for(auto x:mp){
            if(x.second[0] == max_d){
                ans = min(ans,x.second[2] - x.second[1] + 1);
            }
        }
        return ans;
    }
};
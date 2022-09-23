class Solution {
public:
    // Idea: using NSum template to solve it
    vector<vector<int>> nSum(vector<int>& nums, int n, int start, long long target){
        vector<vector<int>> res;
        int sz = nums.size();
        if(n<2 || sz<n){
            return res;
        }
        if(n==2){
            int left = start, right = nums.size()-1;
            while(left<right){
                long long sum = nums[left] + nums[right];
                int n1 = nums[left];
                int n2 = nums[right];
                if(sum == target){
                    res.push_back({nums[left],nums[right]});
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
        }
        else{
            for(int i=start;i<nums.size();i++){
                vector<vector<int>> others = nSum(nums,n-1,i+1,target-nums[i]);
                for(auto o:others){
                    o.push_back(nums[i]);
                    res.push_back(o);
                }
                // Don't forget to skip duplicated fixed ele otherwise res will contain duplicate answer
                while(i< nums.size()-1 && nums[i] == nums[i+1])
                    i++;
            }
        }
        return res;
    } 
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        return nSum(nums,4,0,target);
    }
};
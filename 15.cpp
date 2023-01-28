class Solution {
public:
    // Idea: using 1 fixed number + two sum
    // Time complexity O(n^2)
    vector<vector<int>> twoSum(int target, vector<int>& nums, int start){
        int left = start, right = nums.size()-1;
        vector<vector<int>> ans;
        while(left < right){
            int sum = nums[left] + nums[right];
            if(sum == target){
                ans.push_back({nums[left],nums[right]});
                left++;
                while(left<right && nums[left] == nums[left-1]){
                    left++;
                }
                right--;
                while(left<right && nums[right] == nums[right+1]){
                    right--;
                }
            }
            else if(sum > target){
                right--;
                while(left<right && nums[right] == nums[right+1]){
                    right--;
                }
            }
            else if(sum < target){
                left++;
                while(left<right && nums[left] == nums[left-1]){
                    left++;
                }
            }
        }
        return ans;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i = 0;
        vector<vector<int>> ans;
        while(i<nums.size()-2){
            int curr = nums[i];
            // go to two sum
            vector<vector<int>> temp = twoSum(0-curr,nums,i+1);
            for(auto v:temp){
                ans.push_back({nums[i],v[0],v[1]});
            }
            i++;
            while(i<nums.size()-2 && nums[i-1] == nums[i]){
                i++;
            }
        }
        return ans;
    }
};

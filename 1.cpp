class Solution {
public:
    // Idea: using a temp array arr to save the value and their original index
    // then sort then then use two pointer if sum == target then return
    // if > target then means the larger one should be smaller
    // if < target then smaller one should be larger
    // time complexity is O(n)
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> arr;
        for(int i=0;i<nums.size();i++){
            arr.push_back({nums[i],i});
        }
        sort(arr.begin(),arr.end());
        int left = 0, right = nums.size()-1;
        vector<int> ans;
        while(left<right){
            if(arr[left].first + arr[right].first == target){
                ans.push_back(arr[left].second);
                ans.push_back(arr[right].second);
                break;
            }
            else if(arr[left].first + arr[right].first > target){
                right--;
            }
            else{
                left++;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
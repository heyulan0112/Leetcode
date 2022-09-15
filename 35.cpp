class Solution {
public:
    // Idea: this is binary search left boundary case 2:
    // (index should be inserted) and use [left,right] template
    // Time complexity is O(logn)
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                right = mid - 1;
            }
            else if(nums[mid] < target){
                left = mid + 1;
            }
        }
        return left;
    }
};
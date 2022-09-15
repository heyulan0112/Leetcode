class Solution {
public:
    // Idea:
    // using binary search and if found then just walk through its neighbor elements
    // if it neighors also equals to target then update ans
    // time complexity is O(logn) worst case if O(n)
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1,-1};
        int left = 0,  right = nums.size()-1;
        while(left <= right){
            int mid = left + (right-left)/ 2;
            if(nums[mid] == target){
                ans[0] = mid;
                ans[1] = mid;
                int i = mid-1, j = mid+1;
                while(i>=0 && nums[i] == target){
                    ans[0] = i;
                    i--;
                }
                while(j<nums.size() && nums[j] == target){
                    ans[1] = j;
                    j++;
                }
                break;
            }
            else if(nums[mid] > target){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return ans;
    }
};
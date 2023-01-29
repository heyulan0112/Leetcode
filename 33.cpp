class Solution {
public:
    // Idea: using binary search to find minimal element's index
    // And use binary search in different sub array
    // Time complexity in average case O(logN)
    int findZero(vector<int>& nums, int left, int right){
        if(nums[right] >= nums[left]){
            return 0;
        }
        while(left < right){
            int mid = left + (right-left)/2;
            if(mid-1>=0 && nums[mid] < nums[mid-1]){
                return mid;
            }
            else if(mid+1<nums.size() && nums[mid] > nums[mid+1]){
                return mid+1;
            }
            // Key point
            else if(nums[left] <= nums[mid]){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return 0;
    }

    int binarySearch(vector<int>& nums, int target, int left, int right){
        while(left <= right){
            int mid = left + (right-left)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                left++;
            }
            else if(nums[mid] > target){
                right--;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int index = findZero(nums,0,nums.size()-1);
        if(index == 0){
            return binarySearch(nums,target,0,nums.size()-1);
        }
        else if(target > nums.back()){
            return binarySearch(nums,target,0,index-1);
        }
        return binarySearch(nums,target,index,nums.size()-1);
    }
};

class Solution {
public:
    //Idea: using slow and fast two pointer in array tamplate to solve it
    // left++ first and assign nums[left] later, so it maintain [0,slow], and result should be
    // left+1, because index starts from 0
    // Time complexity is O(N)
    int removeDuplicates(vector<int>& nums) {
        int left = 0, right = 0;
        while(right<nums.size()){
            if(nums[right] != nums[left]){
                left++;
                nums[left] = nums[right];
            }
            right++;
        }
        return left+1;
    }
};
class Solution {
public:
    // Idea: using slow fast two pointer array template to solve it
    // Time complexity is O(n)
    int removeElement(vector<int>& nums, int val) {
        int slow = 0, fast = 0;
        while(fast < nums.size()){
            // if nums[fast] != val then slow will move together with fast
            // so when fast points to fist val in nums then slow will also points to this val at
            // the same time
            if(nums[fast] != val){
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }
};
class Solution {
public:
    // Idea: using slow faster two pointer array in place delete template to delete all ele = 0
    // make every ele after slow pointer equal to 0
    // Time complexity is O(n)
    void moveZeroes(vector<int>& nums) {
        int slow = 0, fast = 0;
        while(fast<nums.size()){
            if(nums[fast] != 0){
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        for(;slow<nums.size();slow++){
            nums[slow] = 0;
        }
        return;
    }
};
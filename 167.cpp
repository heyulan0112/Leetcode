class Solution {
public:
    // Idea: left and right two pointer template in finding sum application
    // Time complexity is O(n)
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size()-1;
        while(left<right){
            int sum = numbers[left] + numbers[right];
            if(sum == target){
                return {left+1,right+1};
            }
            else if (sum > target){
                right--;
            }
            else if (sum < target){
                left++;
            }
        }
        return {-1,-1};
    }
};
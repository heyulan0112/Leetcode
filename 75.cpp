class Solution {
public:
    // Idea: this is a sort question
    // implement select sorting
    // Time complexity O(n^2)
    void sortColors(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int min = i;
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]<=nums[min]){
                    min = j;
                }
            }
            swap(nums[i],nums[min]);
        }
    }
};

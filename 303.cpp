class NumArray {
public:
    // Idea: using prefix sum to solve it
    // Prefix sum basic template
    // Time complexity of func sumRange is O(1)
    vector<int> presum;
    NumArray(vector<int>& nums) {
        presum = vector<int> (nums.size()+1,0);
        for(int i=1;i<presum.size();i++){
            presum[i] = presum[i-1] + nums[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        return presum[right+1] - presum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
class Solution {
public:
    // Idea: use fatest to track current farest place user can reach
    // if fatest < current place means farest can naver be updated, and also current place always <=
    // nums.size()-1 thus if fatest < current place which means fatest < nums.size()-1
    // thus it can never reach end index, return false
    // Time complexity O(n)
    bool canJump(vector<int>& nums) {
        int farest = 0;
        for(int i=0;i<nums.size();i++){
            if(farest < i){
                return false;
            }
            farest = max(farest,nums[i]+i);
        }
        return true;
    }
};

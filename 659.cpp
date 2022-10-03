class Solution {
public:
    // Idea: using the Greedy 
    // Time complexity is O(n)
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> freq;
        unordered_map<int,int> need;
        for(int i:nums){
            freq[i]++;
        }
        for(int i:nums){
            if(freq[i] == 0){
                // it is used up
                continue;
            }
            // check is exist subsequence need this i now
            if(need.count(i)>0 && need[i]>0){
                need[i]--;
                need[i+1]++;
                freq[i]--;
            }
            // if not then create another length 3 subsequence is i+1 and i+2 are also not used up
            else if(freq[i+1]>0 && freq[i+2]>0){
                freq[i]--;
                freq[i+1]--;
                freq[i+2]--;
                need[i+3]++;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
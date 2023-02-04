class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_map<int,int> mp;
        // O(n)
        for(int i:nums){
            mp[i] = 1;
        }
        // O(n+n)
        for(int i:nums){
            // Not all elements needs to walk through inner while loop
            if(mp.count(i-1)==0){
                int length = 1;
                int curr = i+1;
                // worst case is O(n)
                while(mp.count(curr)>0){
                    curr++;
                    length++;
                }
                ans = max(ans,length);
            }
        }
        return ans;
    }
};

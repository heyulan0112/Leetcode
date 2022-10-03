class Solution {
public:
    // Time complexity is O(n)
    int minDeletions(string s) {
        int ans = 0;
        unordered_map<int,bool> mp; // freq if is exist
        unordered_map<char,int> freq;
        for(char c:s){
            freq[c]++;
        }
        for(auto &x:freq){
            // x.second is special case
            while(mp[x.second]==true && x.second>0){
                // conflict occur
                ans++;
                x.second--;
            }
            mp[x.second] = true;
        }
        return ans;
    }
};
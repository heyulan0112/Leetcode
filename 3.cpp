class Solution {
public:
    // Idea: using sliding window
    // right is always moving and check curr new add ele if trigger left pointer moving
    // record every char is exist in curr substring and it right most index
    // if repeat then move out all ele between left pointer and repeated ele last right most index
    // remember handel if longest substring end at the end of string s
    // time complexity will be O(n)
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0){
            return 0;
        }
        // char if exist in substring - curr rightmost index
        unordered_map<char,pair<bool,int>> mp;
        int l=0, r=0;
        int ans = 1;
        while(r<s.size()){
            // adjust left and right pointers to the right place
            if(mp.count(s[r])!=0 && mp[s[r]].first == true){
                for(int i = l; i< mp[s[r]].second; i++){
                    mp[s[i]].first = false;
                }
                l = mp[s[r]].second + 1;
                mp[s[r]].second = r;
            }
            else{
                mp[s[r]] = {true,r};
            }
            // calculate or update ans based on left and right pointers' right place
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};
class Solution {
public:
    // Ides: using sliding window template to solve it
    // Time complexity is O(n)
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> need, window;
        int left = 0, right = 0;
        int valid = 0;
        vector<int> ans;
        for(char c:p){
            need[c]++;
        }
        while(right<s.size()){
            char c = s[right];
            right++;
            if(need.count(c)){
                window[c]++;
                if(window[c] == need[c])
                    valid++;
            }
            // This checking condition might be different in different problem but has same framework
            while(right - left == p.size()){
                if(valid == need.size()){
                    ans.push_back(left);
                }
                char d = s[left];
                left++;
                if(need.count(d)){
                    if(window[d] == need[d])
                        valid--;
                    window[d]--;
                }
            }
        }
        
        return ans;
    }
};
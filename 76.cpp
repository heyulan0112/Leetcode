class Solution {
public:
    // Idea: using sliding window classic tamplate to solve it
    // Time complexity is O(n)
    string minWindow(string s, string t) {
        unordered_map<char,int> need, window;
        int left = 0, right = 0;
        int valid = 0;
        int start = 0, len = INT_MAX;
        for(char c:t){
            need[c]++;
        }
        while(right<s.size()){
            char c = s[right];
            right++;
            if(need.count(c)){
                window[c]++;
                if(window[c] == need[c]){
                    valid++;
                }
            }
            while(need.size() == valid){
                if(right - left <= len){
                    start = left;
                    len = right-left;
                }
                char d = s[left];
                left++;
                if(need.count(d)){
                    if(need[d] == window[d]){
                        valid--;
                    }
                    window[d]--;
                }
            }
        }
        return (len == INT_MAX)? "":s.substr(start,len);
    }
};
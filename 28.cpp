class Solution {
public:
    // Idea: check the substr if they have common start char
    // Time complexity O(n)
    int strStr(string haystack, string needle) {
        int ans = -1;
        int len = needle.size();
        for(int i=0;i<haystack.size();i++){
            if(haystack[i] == needle[0]){
                string sub = haystack.substr(i,len);
                if(sub == needle){
                    return i;
                }
            }
        }
        return ans;
    }
};

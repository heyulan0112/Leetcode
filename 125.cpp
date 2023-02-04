class Solution {
public:
    // Idea: implement checking palindrome
    // Time complexity is O(n)
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        while(i<=j){
            while(i<s.size() && !(isalpha(s[i]) || isdigit(s[i]))){
                i++;
            }
            while(j>=0 && !(isalpha(s[j]) || isdigit(s[j]))){
                j--;
            }
            if(i<s.size() && j>=0 && tolower(s[i]) != tolower(s[j])){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};

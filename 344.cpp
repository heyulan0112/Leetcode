class Solution {
public:
    //Idea: using left and right array two pointer template
    // Time complexity is O(n)
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size()-1;
        while(left<right){
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
        }
        return;
    }
};
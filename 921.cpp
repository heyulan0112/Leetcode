class Solution {
public:
    // Idea: using parentheses min insertion template to solve it
    // Time complexity is O(n)
    int minAddToMakeValid(string s) {
        int res = 0;
        int need = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                need++;
            }
            else{
                need--;
                if(need == -1){
                    res++;
                    need = 0;
                }
            }
        }
        return res + need;
    }
};
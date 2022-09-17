class Solution {
public:
    // Idea: parentheses min valid insertion template application
    // Time complexity is O(n)
    int minInsertions(string s) {
        int res = 0;
        int need= 0; // how many ) are needed
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                need += 2;
                if(need % 2 == 1){
                    // odd then insert another ) res++ then need--
                    res++;
                    need--;
                }
            }
            else{
                need--;
                if(need == -1){
                    res++; // no need to add ) then add a ( but because ( needs two ), thus need = 1
                    need = 1;
                }
            }
        }
        return res + need;
    }
};
class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> freq;
        int ans = 0;
        int left = 0, right = 0;
        int A=0, B=0, C=0;
        while(left < s.size() && right < s.size()){
            if(s[right] == 'a'){
                A++;
            }
            if(s[right] == 'b'){
                B++;
            }
            if(s[right] == 'c'){
                C++;
            }
            while(A>0 && B>0 && C>0){
                ans += s.size()-right;
                if(s[left] == 'a'){
                    A--;
                }
                if(s[left] == 'b'){
                    B--;
                }
                if(s[left] == 'c'){
                    C--;
                }
                left++;
            }
            right++;
        }
        return ans;
    }
};
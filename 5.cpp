class Solution {
public:
    string pali(string s, int i, int j){
        int l = i-1;
        int r = j+1;
        while(l>=0 && r<s.size() && s[l] == s[r]){
            l--;
            r++;
        }
        l++;
        return s.substr(l,r-l);
    }
    string longestPalindrome(string s) {
        string ans = "";
        for(int i=0;i<s.size();i++){
            string tmp = pali(s,i,i);
            if(tmp.size() > ans.size()){
                ans = tmp;
            }
        }
        
        for(int i=0;i<s.size()-1;i++){
            if(s[i] == s[i+1]){
                string tmp = pali(s,i,i+1);
                if(tmp.size() > ans.size())
                    ans = tmp;
            }
        }
        return ans;
    }
};
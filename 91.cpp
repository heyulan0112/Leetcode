class Solution {
public:
    // Idea: dynamic programming
    // Time complexity O(n)
    int numDecodings(string s) {
        if(s.size()==0 || s[0] == '0'){
            return 0;
        }
        vector<int> dp(s.size()+1,0);
        dp[0] = 1;
        for(int i=1;i<s.size()+1;i++){
            // add number of cases that contains this 1 digit number
            if(s[i-1] != '0'){
                dp[i] = dp[i-1];
            }
            if(i-2<0){
                continue;
            }
            string str = s.substr(i-2,2);
            int num = stoi(str);
            // add number of cases that contains this 2 digits number
            if(num>=10 && num<=26){
                dp[i] += dp[i-2];
            }
        }
        return dp.back();
    }
};

class Solution {
public:
    // Idea: dynamic programming
    // Time complexity is O(n)
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1,false);
        dp.back() = true;
        unordered_map<char,vector<string>> mp;
        for(string s: wordDict){
            char key = s[0];
            if(mp.count(key) == 0){
                mp[key] = {};
            }
            mp[key].push_back(s);
        }
        for(int i=s.size()-1;i>=0;i--){
            if(mp.count(s[i])>0){
                for(string str:mp[s[i]]){
                    if(i+str.size()<s.size()+1 && s.substr(i,str.size()) == str && dp[i+str.size()]==true){
                        dp[i] = true;
                    }
                }
            }
        }
        return dp[0];
    }
};

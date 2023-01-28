class Solution {
public:
    // Idea: backtracking
    // Time complexity O(n)
    void explore(map<int,string>& mp, string digits, int i, vector<string>& ans, string s){
        if(i == digits.size()){
            if(s.size()>0){
                ans.push_back(s);
            }
            return;
        }
        int num = digits[i] - '0';
        // 3 or 4 times
        for(char c:mp[num]){
            s += c;
            explore(mp,digits,i+1,ans,s);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        map<int,string> mp;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        vector<string> ans;
        // O(n)
        explore(mp,digits,0,ans,"");
        return ans;
    }
};

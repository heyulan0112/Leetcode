class Solution {
public:
    unordered_map<char,vector<pair<int,string>>> mp; // init char pair<len,string>
    unordered_set<string> ans;
    void backtrack(unordered_set<string>& ans, vector<string> curr, int start, string& s){
        if(start == s.size()){
            // end
            string tmp;
            for(int i=0;i<curr.size();i++){
                tmp += curr[i];
                if(i != curr.size()-1){
                    tmp += " ";
                }
            }
            ans.insert(tmp);
            return;
        }
        char c = s[start];
        for(auto &p:mp[c]){
            int len = p.first;
            string str = p.second;
            if(s.substr(start,len) == str){
                // match one word
                curr.push_back(str);
                backtrack(ans,curr,start+len,s);
                curr.pop_back();
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(string s:wordDict){
            if(mp.count(s[0])==0){
                mp[s[0]] = {};
            }
            mp[s[0]].push_back({s.size(),s});
        }
        vector<string> curr;
        backtrack(ans,curr,0,s);
        vector<string> res;
        for(auto v:ans){
            res.push_back(v);
        }
        return res;
    }
};
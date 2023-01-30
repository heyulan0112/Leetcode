class Solution {
public:
    // Idea: anagram sorted result are always the same
    // Time complexity is O(n * klogk), k is the lenth of longest string in strs
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mp;
        for(string s:strs){
            string temp = s;
            sort(s.begin(),s.end());
            mp[s].push_back(temp);
        }
        for(auto x:mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};

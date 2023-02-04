class Solution {
public:
    // Idea: backtracking to find all possible cases and check if they are palindrom
    // if can traverse all string's char then this is one of the answers
    // Time complexity O(n * 2^n) in worst case
    bool pali(string s){
        int i = 0;
        int j = s.size()-1;
        while(i<j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void backtracking(vector<vector<string>>& ans, vector<string> curr, string s, int start){
        if(start == s.size()){
            ans.push_back(curr);
            return;
        }
        for(int i=start;i<s.size();i++){
            if(s[i] == s[start]){
                string tmp = s.substr(start,i-start+1);
                if(pali(tmp)){
                    curr.push_back(tmp);
                    backtracking(ans,curr,s,i+1);
                    curr.pop_back();
                }
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        backtracking(ans,curr,s,0);
        return ans;
    }
};

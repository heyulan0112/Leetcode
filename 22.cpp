class Solution {
public:
    // Idea: backtracking
    // add left iff left leftover > 0
    // add ) iff left usage > right usage and also right leftover > 0
    // Time complexity is O(2^n), because this is combination problem
    void generate(vector<string>& ans, int left, int right, string curr){
        if(left == 0 && right == 0){
            ans.push_back(curr);
            return;
        }
        if(left > 0){
            curr = curr + '(';
            generate(ans,left-1,right,curr);
            curr.pop_back();
        }
        if(right>0 && right>left){
            curr = curr + ')';
            generate(ans,left,right-1,curr);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(ans,n,n,"");
        return ans;
    }
};

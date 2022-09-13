class Solution {
public:
    // Idea: using mod, straight vertical line + diagonal line has total(2*numRows-2) numbers
    // and if mod >= numRows && mod<2*numRows-2 that means current char should be laid in diagonal
    // and its row number in ans should be (2*numRows-2-mod)
    // also need to handle special case: numRows = 1 (only on row) 
    // and string s size<= numRows(only on column)
    // Time complexity is O(n)
    string convert(string s, int numRows) {
        if(s.size() <= numRows || numRows < 2)
            return s;
        map<int,vector<char>> mp;
        for(int i=0;i<s.size();i++){
            int curr = i % (numRows+(numRows-2));
            if(curr>=numRows && curr<numRows+(numRows-2)){
                // diaglno
                mp[numRows+(numRows-2)-curr].push_back(s[i]);
            }
            else{
                mp[curr].push_back(s[i]);
            }
        }
        
        string ans;
        for(int i=0;i<numRows;i++){
            for(int j=0;j<mp[i].size();j++){
                ans += mp[i][j];
            }
        }
        return ans;
    }
};
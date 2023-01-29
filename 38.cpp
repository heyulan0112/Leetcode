class Solution {
public:
    // Idea: enumurate, implement the rules
    // Time complexity is O(n^2)
    string countAndSay(int n) {
        string ans = "1";
        // key point n>1 not n>0
        while(n>1){
            string temp = ans;
            ans = "";
            int cnt = 0;
            char curr = temp[0];
            for(int i=0;i<temp.size();i++){
                if(temp[i] == curr){
                    cnt++;
                }
                else{
                    ans += to_string(cnt) + curr;
                    // key point, here cnt = 1 not cnt = 0
                    cnt = 1;
                    curr = temp[i];
                }
            }
            if(cnt > 0){
                ans += to_string(cnt) + curr;
            }
            n--;
        }
        return ans;
    }
};

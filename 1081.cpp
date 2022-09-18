class Solution {
public:
    // Idea: Same as Question 316
    // Find lexicographic smallest string
    // remain order in origin string
    // no duplicate
    // Time complexity is O(n)
    string smallestSubsequence(string s) {
        vector<int> counter(256,0);
        vector<bool> inStack(356,false);
        string ans = "";
        stack<char> st;
        for(char c:s){
            counter[c]++;
        }
        for(char c:s){
            counter[c]--;
            if(inStack[c] == true)
                continue;
            while(!st.empty() && st.top() > c && counter[st.top()] != 0){
                char d = st.top();
                st.pop();
                inStack[d] = false;
            }
            st.push(c);
            inStack[c] = true;
        }
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
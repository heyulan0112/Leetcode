class Solution {
public:
    // Idea: using monotonic stack to maintain the lexicographical order
    // use inStack to maintain non duplicate
    // use counter to ensure monotonic stack never pop nesscessary char
    // Time complexity is O(n) because every char just push and pop once
    string removeDuplicateLetters(string s) {
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
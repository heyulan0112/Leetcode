class Solution {
public:
    // Idea: using recursive to handle ( and ) and if condition of ')' must after operator if module
    // because need recursive so need to use a string& s, and pop every used char
    // Time complexity is O(n)
    int cal(string& s){
        int num = 0;
        int sign = '+';
        stack<int> st;
        while(s.size()!=0){
            char c = s.back();
            s.pop_back();
            if(isdigit(c)){
                num = num*10 + (c-'0');
            }
            if(c == '(')
                num = cal(s);
            if((!isdigit(c) && c != ' ') || s.size() == 0){
                int st_top = 0;
                switch(sign){
                    case '+':
                        st.push(num);
                        break;
                    case '-':
                        st.push(-num);
                        break;
                    case '*':
                        st_top = st.top();
                        st.pop();
                        st.push(st_top * num);
                        break;
                    case '/':
                        st_top = st.top();
                        st.pop();
                        st.push(st_top / num);
                }
                num = 0;
                sign = c;
            }
            if(c == ')')
                break;
        }
        int ans = 0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
    
    int calculate(string s) {
        int l = 0, r = s.size()-1;
        while(l<r){
            swap(s[l],s[r]);
            l++;
            r--;
        }
        return cal(s);
    }
};
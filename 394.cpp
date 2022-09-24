class Solution {
public:
    string decode(string& s){
        stack<int> st;
        string ans;
        while(s.size() > 0){
            char c = s[0];
            if(isdigit(c)){
                string num_str = "";
                while(isdigit(c)){
                    num_str += c;
                    s.erase(s.begin());
                    c = s[0];
                }
                st.push(stoi(num_str));
            }
            else if(isalpha(c)){
                s.erase(s.begin());
                ans += c;
            }
            else if(c == '['){
                s.erase(s.begin());
                string sub = decode(s);
                int dup_times = st.top();
                while(dup_times--){
                    ans += sub;
                }
                st.pop();
                
            }
            else if(c == ']'){
                s.erase(s.begin());
                break;
            }
        }
        return ans;
    }

    string decodeString(string s) {
        return decode(s);
    }
};
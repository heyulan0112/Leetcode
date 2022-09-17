class Solution {
public:
    // Idea: using multi type parentheses valid template to solve it
    // Time complexity is O(n)
    char leftof(char c){
        if(c == '}'){
            return '{';
        }
        else if(c == ']'){
            return '[';
        }
        return '(';
    }
    
    bool isValid(string s) {
        stack<char> left;
        for(int i=0;i<s.size();i++){
            if(s[i] == '{' || s[i] == '(' || s[i] == '[')
                left.push(s[i]);
            else{
                if(!left.empty() && left.top() == leftof(s[i])){
                    left.pop();
                }
                else
                    return false;
            }
        }
        return left.empty();
    }
};
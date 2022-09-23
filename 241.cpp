class Solution {
public:
    // Idea: using recursive to solve
    // make calculations inside the parentheses be done by the lower level recurssion
    vector<int> diffWaysToCompute(string expression) {
        vector<int> res;
        for(int i=0;i<expression.size();i++){
            if(expression[i]=='+' || expression[i]=='-'||expression[i]=='*'||expression[i]=='/'){
                vector<int> nums1 = diffWaysToCompute(expression.substr(0,i));
                vector<int> nums2 = diffWaysToCompute(expression.substr(i+1));
                for(int n1:nums1){
                    for(int n2:nums2){
                        switch(expression[i]){
                            case '+':
                                res.push_back(n1+n2);
                                break;
                            case '-':
                                res.push_back(n1-n2);
                                break;
                            case '*':
                                res.push_back(n1*n2);
                                break;
                            case '/':
                                res.push_back(n1/n2);
                        }
                    }
                }
            }
        }
        // Don't forget the base case in recursive
        if(res.size()==0)
            return {stoi(expression)};
        return res;
    }
};
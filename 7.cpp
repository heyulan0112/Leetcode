class Solution {
public:
    // Idea: use string reverse all digits and also filter out all leading 0
    // But need to handel special case is leading zero is allowable when x = 0 (special case1)
    // also need to handel negative number (special case2)
    // result should be long long type to avoid overflow
    // Time complexity is O(n)
    int reverse(int x) {
        bool f = false;
        if(x<0){
            x = abs(x);
            f = true;
        }
        if(x == 0)
            return 0;
        string tmp;
        while(x>0){
            tmp += to_string(x%10);
            x /= 10;
        }
        int i=0;
        while(tmp[i] == '0'){
            i++;
        }
        string tmp2 = tmp.substr(i);
        long long res = stoll(tmp2);
        if(f){
            res = -res;
        }
        return (res>INT_MAX || res<INT_MIN)? 0 : res;
    }
};
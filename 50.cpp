class Solution {
public:
    // Idea: n =1 and n = 0 are edge cases, and use odd and even of n to prune some steps
    // Time complexity O(logn)
    double myPow(double x, int n) {
        if(n == 0){
            return 1;
        }
        if(n == 1){
            return x;
        }
        double ans = 1;
        bool neg = false;
        if(n<0){
            neg = true;
        }
        long nn = abs(n);
        // key point
        while(nn>0){
            // current n is odd, then ans = ans * x and n minus one
            if(nn%2 != 0){
                ans *= x;
                nn--;
            }
            // current n is even, then x updated to be x^2 then n can be updated to n/2
            else{
                x *= x;
                nn /= 2;
            }
        }
        if(neg){
            return double(1) / ans;
        }
        return ans;
    }
};

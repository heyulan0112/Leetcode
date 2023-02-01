class Solution {
public:
    // Idea: enumerate all integer
    // Time complexity O(n)
    int mySqrt(int x) {
        long long ans = 0;
        for(int i=1;i<=x;i++){
            if(i == x/i){
                return i;
            }
            if(i > x/i){
                return i-1;
            }
        }
        return 0;
    }
};

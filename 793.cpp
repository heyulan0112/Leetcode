class Solution {
public:
    // Idea: use LONG_MAX to be binary search up boundary
    // Time complexity is O(logN * logN)
    long find(long n){
        long res = 0;
        for(long d = n; d/5 > 0; d = d/5){
            res += d/5;
        }
        return res;
    }
    
    long left_bound(int target){
        long lo = 0, hi = LONG_MAX;
        while(lo<hi){
            long mid = lo + (hi-lo)/2;
            if(find(mid) == target){
                hi = mid;
            }
            else if (find(mid) > target){
                hi = mid;
            }
            else if (find(mid) < target){
                lo = mid+1;
            }
        }
        return lo;
    }
    
    long right_bound(int target){
        long lo = 0, hi = LONG_MAX;
        while(lo<hi){
            long mid = lo + (hi-lo)/2;
            if(find(mid) == target){
                lo = mid + 1;
            }
            else if (find(mid) > target){
                hi = mid;
            }
            else if (find(mid) < target){
                lo = mid + 1;
            }
        }
        return lo-1;
    }
    
    int preimageSizeFZF(int k) {
        return right_bound(k) - left_bound(k) + 1;
    }
};
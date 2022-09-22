class Solution {
public:
    // Idea: start use ascdesing end use descing order sort
    // becuase override problem we wanna same start ibtervals, the larger one always occur before smaller one
    // Time complexity is O(n)
    static bool comparator (vector<int>& v1, vector<int>& v2){
        if(v1[0] == v2[0])
            return v2[1] <= v1[1];
        return v1[0] <= v2[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int res = 0;
        sort(intervals.begin(),intervals.end(),comparator);
        int left = intervals[0][0];
        int right = intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][1] <= right)
                res++;
            else{
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
        return intervals.size() - res;
    }
};
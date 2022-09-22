class Solution {
public:
    // Idea: sort the intervals based on start
    // if curr in has override with previous in then just update the end to be larger one
    // if curr in don't have override area with the previous one then just insert it to be the latest previous interval
    // Time complexity is O(n)
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] <= res.back()[1]){
                res.back()[1] = max(res.back()[1],intervals[i][1]);
            }
            else{
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
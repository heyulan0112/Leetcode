class Solution {
public:
    // Idea: using greedy to always choose the longest and also can ensure it has intersection with prev interval one to be the next interval
    // Time complexity is O(n)
    static bool comparator(vector<int>& c1, vector<int>& c2){
        if(c1[0] == c2[0])
            return c2[1] <= c1[1];
        return c1[0] <= c2[0];
    }
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(),clips.end(),comparator);
        int res = 0;
        int currEnd = 0, nextEnd = 0;
        int i=0;
        while(i<clips.size() && clips[i][0] <= currEnd){
            while(i<clips.size() && clips[i][0]<=currEnd){
                nextEnd = max(nextEnd, clips[i][1]);
                i++;
            }
            res++;
            currEnd = nextEnd;
            if(currEnd>=time)
                return res;
        }
        return -1;
    }
};
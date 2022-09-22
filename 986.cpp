class Solution {
public:
    // Idea: finding interval intersection template
    // Time complexity O(n)
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int i = 0, j = 0;
        while(i<firstList.size() && j<secondList.size()){
            int a1 = firstList[i][0], a2 = firstList[i][1];
            int b1 = secondList[j][0], b2 = secondList[j][1];
            if(b2 >= a1 && a2 >= b1){
                // All intersection must satisfy this line
                res.push_back({max(a1,b1), min(a2,b2)});
            }
            if(a2 < b2)
                i++;
            else j++;
        }
        return res;
    }
};
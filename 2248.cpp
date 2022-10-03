class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int m = nums.size();
        vector<unordered_map<int,int>> v(m);
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                v[i][nums[i][j]] = j;
            }
        }
        vector<int> res;
        for(int i=0;i<nums[0].size();i++){
            int cnt = 1;
            int cur = nums[0][i];
            for(int j=1;j<m;j++){
                if(v[j].count(cur)>0){
                    cnt++;
                }
            }
            if(cnt == m){
                res.push_back(cur);
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};
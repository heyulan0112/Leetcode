class Solution {
public:
    // Idea: using interval template
    // must sort then use a counter to count curr population
    // meet start point then counter++ meet end point then counter--
    // Time complexity is O(n)
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<pair<int,char>> years;
        for(auto v:logs){
            years.push_back({v[0],'s'});
            years.push_back({v[1],'e'});
        }
        sort(years.begin(),years.end());
        int ans = years[0].first;
        int cnt = 0;
        int max_pop = INT_MIN;
        for(int i=0;i<years.size();i++){
            if(years[i].second == 's')
                cnt++;
            else
                cnt--;
            if(cnt > max_pop){
                max_pop = cnt;
                ans = years[i].first;
            }
        }
        return ans;
    }
};
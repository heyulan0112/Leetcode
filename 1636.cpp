class Solution {
public:
    // Time and space complexity is O(n)
    static bool comparator(pair<int,int>& p1, pair<int,int>& p2){
        if(p1.first == p2.first){
            return p2.second < p1.second;
        }
        return p1.first < p2.first;
    }
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> ans;
        vector<pair<int,int>> ve; // freq, value
        unordered_map<int,int> freq;
        for(int i:nums){
            freq[i]++;
        }
        for(auto x:freq){
            ve.push_back({x.second,x.first});
        }
        sort(ve.begin(),ve.end(),comparator);
        for(auto p:ve){
            while(p.first--){
                ans.push_back(p.second);
            }
        }
        return ans;
    }
};
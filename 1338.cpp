class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i:arr){
            mp[i]++;
        }
        priority_queue<int> pq;
        for(auto x:mp){
            pq.push(x.second);
        }
        int ans = 0;
        int n = arr.size();
        int curr = 0;
        while(curr < n/2){
            curr += pq.top();
            pq.pop();
            ans++;
        }
        return ans;
    }
};
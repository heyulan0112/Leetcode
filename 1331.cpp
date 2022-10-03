class Solution {
public:
    // Idea: use priority queue to solve it
    // Time and space complexity is O(n)
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> ans(arr.size(),0);
        for(int i=0;i<arr.size();i++){
            pq.push({arr[i],i});
        }
        int rank = 1;
        while(!pq.empty()){
            pair<int,int> curr = pq.top();
            pq.pop();
            ans[curr.second] = rank;
            if(!pq.empty() && curr.first != pq.top().first)
                rank++;
        }
        return ans;
    }
};
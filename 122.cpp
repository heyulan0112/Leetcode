class Solution {
public:
    // Idea: find all local peak and valley, then add up all peak-valley
    // Time complexity is O(n)
    // Difference between with 121 is it can sell and buy many times
    int maxProfit(vector<int>& prices) {
        int valley = INT_MAX;
        int peak = INT_MIN;
        int ans = 0;
        int i = 0;
        while(i<prices.size()){
            while(i+1<prices.size() && prices[i] >= prices[i+1]){
                i++;
            }
            if(i == prices.size()){
                return ans;
            }
            valley = prices[i];
            while(i+1<prices.size() && prices[i] <= prices[i+1]){
                i++;
            }
            peak = (i == prices.size())? prices.back() : prices[i];
            ans += peak - valley;
            i++;
        }
        return ans;
    }
};

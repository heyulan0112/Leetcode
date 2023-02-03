class Solution {
public:
    // Idea: because we loop prices in order so newly arrival data must appear later than current_min
    // update current_min to trach current minimum value and update ans
    // Time complexity is O(n)
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int curr_min = prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i] < curr_min){
                curr_min = prices[i];
            }
            ans = max(ans,prices[i]-curr_min);
        }
        return ans;
    }
};

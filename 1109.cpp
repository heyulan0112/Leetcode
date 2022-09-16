class Solution {
public:
    // Idea:Prefix Sum difference array
    // use difference array classic template can solve it
    // because init all flight have no bookings so no need to construct diff init values
    // just assign 0 to diff elements
    // Time complexity will be O(n)
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n);
        vector<int> diff(n,0);
        for(auto v:bookings){
            int i = v[0]-1;
            int j = v[1]-1;
            diff[i] += v[2];
            if(j+1<n){
                diff[j+1] -= v[2];
            }
        }
        // convert diff array back to origin array
        ans[0] = diff[0];
        for(int i=1;i<n;i++){
            ans[i] = ans[i-1] + diff[i];
        }
        return ans;
    }
};
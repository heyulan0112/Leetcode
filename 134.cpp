class Solution {
public:
    // Idea: if choose the minSum to be start place then total will start from a most likely succes place
    // Time complexity O(n)
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i = 0;
        int sum = 0;
        int minSum = INT_MAX;
        int res = 0;
        while(i<gas.size()){
            sum += gas[i] - cost[i];
            if(sum < minSum){
                minSum = min(minSum,sum);
                res = i+1;
            }
            i++;
        }
        if(sum < 0)
            return -1;
        return (res == gas.size())? 0:res;
    }
};
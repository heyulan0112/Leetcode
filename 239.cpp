// Implement monotonic max queue
class MonotonicQueue{
public:
    list<int> q;
    MonotonicQueue(){}
    void push(int n){
        // here is q.back() < n not <=
        while(!q.empty() && q.back() < n){
            q.pop_back();
        }
        q.push_back(n);
    }
    void pop(int n){
        if(n == q.front())
            q.pop_front();
    }
    int front(){
        return q.front();
    }
};

class Solution {
public:
    // Idea: using monotonic queue classic template to solve it
    // Time complexity is O(n)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonotonicQueue* mq = new MonotonicQueue();
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(i<k-1){
                mq->push(nums[i]);
            }
            else{
                mq->push(nums[i]);
                ans.push_back(mq->front());
                mq->pop(nums[i-k+1]);
            }
        }
        return ans;
    }
};
class MedianFinder {
public:
    // Idea: using small heap to maintain all numbers larger than median
    // using large heap to maintain all numers smaller than median
    // then use two heap top() and heap size to determain the median
    // Time complexity is  addNum: O(logN), findMedian: O(1)
    priority_queue<int,vector<int>,greater<int>> small;
    priority_queue<int> large;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(small.size() < large.size()){
            large.push(num);
            int t = large.top();
            large.pop();
            small.push(t);
        }
        else{
            small.push(num);
            int t = small.top();
            small.pop();
            large.push(t);
        }
    }
    
    double findMedian() {
        if(small.size() < large.size())
            return large.top();
        else if(small.size() > large.size()){
            return small.top();
        }
        // Because return double so must / 2.0 instead of /2 !!!
        return (small.top() + large.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
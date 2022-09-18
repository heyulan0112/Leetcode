class Solution {
public:
    // Idea: mapping all black numbers in valid area to invalid area (end of the array)
    // only pick numbers from valid area
    // Time complexity of pick() is O(1)
    unordered_map<int,int> mp;
    int sz = 0;
    Solution(int n, vector<int>& blacklist) {
        sz = n - blacklist.size();
        for(int b: blacklist){
            // black numbers are in mp now
            mp[b] = 1;
        }
        int last = n-1;
        for(int b:blacklist){
            if(b >= sz)
                continue;
            while(mp.count(last) != 0){
                // no need to handle any blacklist number in invalid area
                last--;
            }
            // map the blacklist number in valid area to whitelist number's index in invalid area
            mp[b] = last;
            last--; // remember to last-- after using this index
        }
    }
    
    int pick() {
        // only choose data from valid area
        int num = rand() % sz;
        while(mp.count(num) != 0){
            // return a whilt list number
            return mp[num];
        }
        return num;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
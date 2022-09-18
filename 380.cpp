class RandomizedSet {
public:
    // Idea: using map to track ele's index using O(1)
    // Insert, Delete, Search O(1) can be achieved by using vector + map(value to index)
    vector<int> nums;
    unordered_map<int,int> mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.count(val) != 0)
            return false;
        mp[val] = nums.size();
        nums.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(mp.count(val) == 0)
            return false;
        int index = mp[val];
        mp[nums.back()] = index;
        swap(nums.back(), nums[index]);
        mp.erase(val);
        nums.pop_back();
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
class Solution {
public:
    // Idea: using binary search left bound
    // save the index of all char in string t
    // then go through the string s then in mp[s[i]] that most left and > j element
    // Time complexity: O(MlogN) M is string s length N is string t length
    int leftBound(vector<int> v, int target){
        int left = 0, right = v.size();
        while(left < right){
            int mid = left + (right-left)/2;
            if(v[mid] == target){
                right = mid;
            }
            else if(v[mid] > target){
                right = mid;
            }
            else if(v[mid] < target){
                left = mid + 1;
            }
        }
        return left;
    }
    
    bool isSubsequence(string s, string t) {
        unordered_map<char,vector<int>> mp; // char in t and their corresponding index
        for(int i=0;i<t.size();i++){
            mp[t[i]].push_back(i);
        }
        int j = 0; // points to char in t
        //traverse string s
        for(int i=0;i<s.size();i++){
            if(mp.count(s[i])==0){
                return false;
            }
            int pos = leftBound(mp[s[i]],j);
            if(pos == mp[s[i]].size()){
                return false;
            }
            j = mp[s[i]][pos] + 1;
        }
        return true;
    }
};
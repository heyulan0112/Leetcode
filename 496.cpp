class Solution {
public:
    // Idea: using monotonic stack basic template to solve it
    // Time complexity is O(n)
    vector<int> nextGreater(vector<int>& nums){
        vector<int> ans(nums.size(),0);
        stack<int> st;
        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i])
                st.pop();
            ans[i] = (st.empty())? -1 : st.top();
            st.push(nums[i]);
        }
        return ans;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> ans(n,0);
        vector<int> next_g = nextGreater(nums2);
        unordered_map<int,int> mp;
        for(int i=0;i<nums2.size();i++){
            mp[nums2[i]] = next_g[i];
        }
        for(int i=0;i<nums1.size();i++){
            ans[i] = mp[nums1[i]];
        }
        return ans;
    }
};
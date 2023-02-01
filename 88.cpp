class Solution {
public:
    // Idea: compare elements from the end to begin in order to achieve in place sorting
    // Time complexity is O(m + n)
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int idx = nums1.size()-1;
        while(i>=0 && j>=0){
            if(nums1[i] > nums2[j]){
                nums1[idx] = nums1[i];
                i--;
            }
            else{
                nums1[idx] = nums2[j];
                j--;
            }
            idx--;
        }
        while(i>=0){
            nums1[idx] = nums1[i];
            i--;
            idx--;
        }
        while(j>=0){
            nums1[idx] = nums2[j];
            j--;
            idx--;
        }
    }
};

class Solution {
public:
    // Idea: implement add manually, edge case is need to add carry in every index and add 1 at index 0
    // Time complexity O(n)
    vector<int> plusOne(vector<int>& digits) {
        for(int i=digits.size()-1;i>=0;i--){
            if(digits[i] + 1 < 10){
                digits[i] = digits[i] + 1;
                return digits;
            }
            else{
                digits[i] = digits[i] + 1 - 10;
            }
        }
        digits.insert(digits.begin(),1);
        return digits;
    }
};

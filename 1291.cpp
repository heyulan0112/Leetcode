class Solution {
public:
    // Idea: use a sliding window on string "123456789"
    // remember to handle some starting digits cannot have long length sequential digits
    // Time complexity is O(1) because length is fixed
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string digits = "123456789";
        string ll = to_string(low);
        string hh = to_string(high);
        int left = 0;
        int right = (hh[0]-'0') - 1;
        // left points to start place
        while(left < digits.size()){
            int len = ll.size();
            while(len <= hh.size()){
                if(left+len>digits.size())
                    break;
                int curr = stoi(digits.substr(left,len));
                if(low<=curr && curr<=high)
                    ans.push_back(curr);
                len++;
            }
            left++;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
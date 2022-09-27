class Solution {
public:
    // Idea: traverse the s1 and s2 at the same time
    // record index of elements that are not match each other
    // swap and check if they are eaual
    // Time complexity is O(n)
    bool areAlmostEqual(string s1, string s2) {
        vector<int> indices;
        for(int i=0;i<s1.size();i++){
            if(s1[i] != s2[i])
                indices.push_back(i);
            if(indices.size()==2)
                break;
        }
        if(indices.size() == 0)
            return true;
        if(indices.size() == 1)
            return false;
        swap(s1[indices[0]],s1[indices[1]]);
        return s1 == s2;
    }
};